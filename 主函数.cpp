#include"头文件和函数申明.h"
#include"数据类型.cpp"
#include"功能模块.cpp"
#include"界面函数.cpp"
int main(void) {
	system("title 学生选课系统"); 载入文件();
	system("title 登陆"); while (登陆());
	while (!菜单());
	退出();
	return -1;
}