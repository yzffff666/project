#include "manager.h"

//默认构造
Manager::Manager()
{

}
//有参构造
Manager::Manager(string name, string pwd)
{
	//初始化管理员信息
	this->m_name = name;
	this->m_pwd = pwd;

	//初始化容器 获取到所有文件中 学生、老师信息
	this->initVector();

	//初始化机房信息
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom com;
	while (ifs >> com.m_comId && ifs >> com.m_maxNum)
	{
		vCom.push_back(com);
	}
	ifs.close();
	cout << "机房的数量为：" << vCom.size() << endl;
}
//选择菜单
void Manager::openMenu()
{
	cout << "欢迎管理员：" << this->m_name << "登录！" << endl;
	cout << "\t\t|-------------------------------------|\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|             1.添加账号              |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|             2.查看账号              |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|             3.查看机房              |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|             4.清空预约              |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|             0.注销登录              |\n";
	cout << "\t\t|                                     |\n";
	cout << "\t\t|-------------------------------------|\n";
	cout << "请选择您的操作：" << endl;
}
//添加账号
void Manager::addPerson()
{
	cout << "请输入添加账号类型" << endl;
	cout << "1.添加学生" << endl;
	cout << "2.添加老师" << endl;

	string fileName;//操作文件名
	string tip;//提示id号
	string errorTip;//重复提示

	ofstream ofs;//文件操作对象

	int select = 0;
	cin >> select;//接收用户选项

	if (select == 1)//添加学生
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入";
	}
	else
	{
		fileName = TEACHER_FILE;
		tip = "请输入职工号：";
		errorTip = "职工号重复，请重新输入";
	}

	//用追加的方式写文件
	ofs.open(fileName, ios::out | ios::app);

	int id; //学号 职工号
	string name;//姓名
	string pwd;//密码

	cout << tip << endl;//请输入学号

	while (true)//判断输入学号是否重复
	{
		cin >> id;//输入学号
		bool ret = checkRepeat(id, select);
		if (ret)//有重复
		{
			cout << errorTip << endl;//重新输入
		}
		else
		{
			break;
		}
	}

	cout << "请输入姓名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	//向文件中添加数据
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;

	system("pause");
	system("cls");

	ofs.close();

	//添加后重新初始化容器
	this->initVector();

	//if (select == 1)//更新学生容器
	//{
	//	Student s;
	//	s.m_id = id;
	//	s.m_name = name;
	//	s.m_pwd = pwd;
	//	vStu.push_back(s);
	//}
	//else//更新老师容器
	//{
	//	Teacher t;
	//	t.m_EmId = id;
	//	t.m_name = name;
	//	t.m_pwd = pwd;
	//	vTea.push_back(t);
	//}
}

//仿函数
void printStudent(Student& s)
{
	cout << "学号：" << s.m_id << "姓名：" << s.m_name << "密码：" << s.m_pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "职工号：" << t.m_EmId << "姓名：" << t.m_name << "密码：" << t.m_pwd << endl;
}

//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容" << endl;
	cout << "1.查看所有学生" << endl;
	cout << "2.查看所有老师" << endl;

	int select = 0;//接收用户选择
	cin >> select;

	if (select == 1)
	{
		//查看学生
		cout << "所有学生信息如下：" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		//查看老师
		cout << "所有老师信息如下：" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}

	system("pause");
	system("cls");
}
//查看机房信息
void Manager::showComputer()
{
	cout << "机房的信息如下：" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "机房编号：" << it->m_comId << " 机房最大容量：" << it->m_maxNum << endl;
	}

	system("pause");
	system("cls");
}
//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}
//初始化容器
void Manager::initVector()
{
	//确保容器清空状态
	vStu.clear();
	vTea.clear();
	
	//读取信息 学生
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		return;
	}

	//读取学生信息
	Student s;
	while (ifs >> s.m_id && ifs >> s.m_name && ifs >> s.m_pwd)
	{
		vStu.push_back(s);
	}
	cout << "当前的学生数量为：" << vStu.size() << endl;
	ifs.close();

	//读取信息 老师
	ifs.open(TEACHER_FILE, ios::in);
	Teacher t;
	while (ifs >> t.m_EmId && ifs >> t.m_name && ifs >> t.m_pwd)
	{
		vTea.push_back(t);
	}
	cout << "当前老师的数量为：" << vTea.size() << endl;
	ifs.close();
}

//检测重复 参数1 学号/职工号 参数2 类型
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		//检测学生
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
		//检测老师
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
