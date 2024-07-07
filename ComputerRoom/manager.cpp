#include "manager.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}
//�вι���
Manager::Manager(string name, string pwd)
{
	//��ʼ������Ա��Ϣ
	this->m_name = name;
	this->m_pwd = pwd;

	//��ʼ������ ��ȡ�������ļ��� ѧ������ʦ��Ϣ
	this->initVector();

	//��ʼ��������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_comId && ifs >> com.m_maxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "����������Ϊ��" << vCom.size() << endl;
}
//ѡ��˵�
void Manager::openMenu()
{
	cout << "��ӭ����Ա��" << this->m_name << "��¼��" << endl;
	cout << "\t\t|-------------------------------------|\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|             1.����˺�              |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|             2.�鿴�˺�              |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|             3.�鿴����              |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|             4.���ԤԼ              |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|             0.ע����¼              |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|-------------------------------------|\n";
	cout << "��ѡ�����Ĳ�����" << endl;
}
//����˺�
void Manager::addPerson()
{
	cout << "����������˺�����" << endl;
	cout << "1.���ѧ��" << endl;
	cout << "2.�����ʦ" << endl;

	string fileName;//�����ļ���
	string tip;//��ʾid��
	string errorTip;//�ظ���ʾ

	ofstream ofs;//�ļ���������

	int select = 0;
	cin >> select;//�����û�ѡ��

	if (select == 1)//���ѧ��
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "������ְ���ţ�";
		errorTip = "ְ�����ظ�������������";
	}

	//��׷�ӵķ�ʽд�ļ�
	ofs.open(fileName, ios::out | ios::app);

	int id; //ѧ�� ְ����
	string name;//����
	string pwd;//����

	cout << tip << endl;//������ѧ��

	while (true)//�ж�����ѧ���Ƿ��ظ�
	{
		cin >> id;//����ѧ��
		bool ret = checkRepeat(id, select);
		if (ret)//���ظ�
		{
			cout << errorTip << endl;//��������
		}
		else
		{
			break;
		}
	}

	cout << "������������" << endl;
	cin >> name;

	cout << "���������룺" << endl;
	cin >> pwd;

	//���ļ����������
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//��Ӻ����³�ʼ������
	this->initVector();

	//if (select == 1)//����ѧ������
	//{
	//	Student s;
	//	s.m_id = id;
	//	s.m_name = name;
	//	s.m_pwd = pwd;
	//	vStu.push_back(s);
	//}
	//else//������ʦ����
	//{
	//	Teacher t;
	//	t.m_EmId = id;
	//	t.m_name = name;
	//	t.m_pwd = pwd;
	//	vTea.push_back(t);
	//}
}

//�º���
void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_id << "������" << s.m_name << "���룺" << s.m_pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ְ���ţ�" << t.m_EmId << "������" << t.m_name << "���룺" << t.m_pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴����" << endl;
	cout << "1.�鿴����ѧ��" << endl;
	cout << "2.�鿴������ʦ" << endl;

	int select = 0;//�����û�ѡ��
	cin >> select;

	if (select == 1)
	{
		//�鿴ѧ��
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		//�鿴��ʦ
		cout << "������ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}
//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "��������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_comId << " �������������" << it->m_maxNum << endl;
	}

	system("pause");
	system("cls");
}
//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}
//��ʼ������
void Manager::initVector()
{
	//ȷ���������״̬
	vStu.clear();
	vTea.clear();
	
	//��ȡ��Ϣ ѧ��
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		return;
	}

	//��ȡѧ����Ϣ
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	cout << "��ǰ��ѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	//��ȡ��Ϣ ��ʦ
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmId && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	cout << "��ǰ��ʦ������Ϊ��" << vTea.size() << endl;
	ifs.close();
}

//����ظ� ����1 ѧ��/ְ���� ����2 ����
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//���ѧ��
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;
			}
		}
	}
	else
	{
		//�����ʦ
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmId)
			{
				return true;
			}
		}
	}

	return false;
}
