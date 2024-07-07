#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include <vector>
#include "computerRoom.h"
#include "globalFile.h"
#include "orderFile.h"

//ѧ����
class Student :public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι���
	Student(int id, string name, string pwd);
	//�˵�����
	virtual void openMenu();
	//����ԤԼ
	void applyOrder();
	//�鿴����ԤԼ
	void showMyOrder();
	//�鿴����ԤԼ
	void showAllOrder();
	//ȡ��ԤԼ
	void cancelOrder();
	//ѧ��ѧ��
	int m_id;
	//��������
	vector<ComputerRoom> vCom;
};