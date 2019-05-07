#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
#include <opencv2/core/types.hpp>

constexpr auto CVGUI_BUTTON = 1;
constexpr auto CVGUI_TEXTBOX = 2;

using namespace cv;
using namespace std;

struct component
{
	Rect range;
	int type = -1;
	string label;
	Scalar color;
};

class cvgui
{
public:
	cvgui(const string&,const int&,const int&, const Scalar&);
	cvgui(const string&, const int&, const int&);
	~cvgui();

	Mat layout;
	string label;

	void addComponent(const Rect&,const int& , const string&,const Scalar&);
	void addComponent(const Rect&, const int&, const string&);
	void drawLayout(void);

private:
	Size layoutSize;
	Scalar layoutColor;
	vector<component> components;
};



inline void cvgui::addComponent(const Rect& range, const int& type, const string& label, const Scalar& color)
{
	if (range.width <= 10 && range.height <= 10)
		cerr << __FUNCTION__ << ": component size too small" << endl;
	component dst;
	dst.range = range;
	dst.type = type;
	dst.label = label;
	dst.color = color;
	this->components.push_back(dst);
}

inline void cvgui::addComponent(const Rect& range, const int& type, const string& label)
{
	if (range.width <= 10 && range.height <= 10)
		cerr << __FUNCTION__ << ": component size too small" << endl;
	component dst;
	dst.range = range;
	dst.type = type;
	dst.label = label;
	dst.color = Scalar(55, 51, 51, 0);
	this->components.push_back(dst);
}

inline cvgui::cvgui(const string& src, const int& row, const int& col, const Scalar& color)
{
	this->label = src;
	this->layoutSize = Size(row, col);
	this->layoutColor = color;
}

inline cvgui::cvgui(const string& src, const int& row, const int& col)
{
	this->label = src;
	this->layoutSize = Size(row, col);
	this->layoutColor = Scalar(48, 45, 45, 0);
}

cvgui::~cvgui()
{
}

void cvgui::drawLayout(void)
{
	//»æÖÆ±³¾°
	this->layout.create(this->layoutSize, CV_8UC4);
	this->layout = this->layoutColor;

	for (auto ptr = this->components.begin(), end = this->components.end(); ptr != end; ++ptr)
		switch ((*ptr).type)
		{
		//»æÖÆ°´¼ü
		case	CVGUI_BUTTON:
			this->layout((*ptr).range) = (*ptr).color;
			//»æÖÆ°´¼ü±ß¿ò
			rectangle(this->layout, (*ptr).range, (*ptr).color + Scalar(10, 10, 10, 0), 2, LINE_AA);
			break;
		default:
			cerr << "undefined component" << endl;
			break;
		}

	imshow(this->label, this->layout);
}

//Mat cvgui::botton_create(component src, string text)
//{
//	rectangle(this->layout, range, color + Scalar(10, 10, 10, 0), 2, LINE_AA);
//}