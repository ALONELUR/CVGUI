// Hello_world.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <opencv2/opencv.hpp>
#include "cvgui.h"

using namespace cv;
using namespace std;

static void mouse(int event, int x, int y, int flag, void* ustc)
{
	if (event == EVENT_LBUTTONDOWN)
	{
		*(int*)ustc += 1;
		cout << *(int*)ustc << endl;
	}
	
}

int main()
{
	cvgui gui("test gui", 800, 450);
	gui.addComponent(Rect(0, 0, 100, 100), CVGUI_BUTTON, "button", Scalar(55, 51, 51, 0));
	gui.drawLayout();
	int b = 0;
	int* a = &b;
	setMouseCallback("test gui", mouse,a);
	while (waitKey(10) != ' ')
	{
		
	}

	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

