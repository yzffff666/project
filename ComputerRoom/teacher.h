#pragma once
#include <iostream>
using namespace std;
#include "identity.h"

//教师类设计
class Teacher :public Identity
{
public:
	//默认构造
	Teacher();
	//有参构造
	Teacher(int id, string name, string pwd);
	//菜单界面
	virtual void openMenu();
	//查看所有预约
	void showAllOrder();
	//审核预约
	void validOrder();

	int m_EmId;
};