#pragma once
#include <iostream>
using namespace std;
#include "identity.h"

//��ʦ�����
class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	//�вι���
	Teacher(int id, string name, string pwd);
	//�˵�����
	virtual void openMenu();
	//�鿴����ԤԼ
	void showAllOrder();
	//���ԤԼ
	void validOrder();

	int m_EmId;
};