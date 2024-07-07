#pragma once
#include <iostream>
using namespace std;
#include "identity.h"
#include <fstream>
#include "globalFile.h"
#include <vector>
#include "student.h"
#include "teacher.h"
#include <algorithm>
#include "computerRoom.h"

class Manager :public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���
	Manager(string name, string pwd);
	//ѡ��˵�
	virtual void openMenu();
	//����˺�
	void addPerson();
	//�鿴�˺�
	void showPerson();
	//�鿴������Ϣ
	void showComputer();
	//���ԤԼ��¼
	void cleanFile();
	//��ʼ������
	void initVector();
	//����ظ� ѧ��ְ���� ��ʦѧ��
	bool checkRepeat(int id, int type);
	//ѧ������
	vector<Student>vStu;
	//��ʦ����
	vector<Teacher>vTea;
	//������Ϣ
	vector<ComputerRoom>vCom;
};