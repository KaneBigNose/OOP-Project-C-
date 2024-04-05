#include <iostream>
#include <cstring>
using namespace std;

class Employee //�߻�Ŭ����
{
private:
	char name[100];
public:
	Employee(const char* name)
	{
		strcpy_s(this->name, 100, name);
	}
	void ShowYourName() const
	{
		cout << "name: " << name << endl;
	}
	virtual int GetPay() const = 0; //���� �����Լ�
	virtual void ShowSalaryInfo() const = 0; //���� �����Լ�
};

class PermanentWorker : public Employee
{
private:
	int salary;
public:
	PermanentWorker(const char* name, int money)
		: Employee(name), salary(money) {}
	virtual int GetPay() const { return salary; }
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class TemporaryWorker : public Employee
{
private:
	int workTime;
	int payPerHour;
public:
	TemporaryWorker(const char* name, int pay)
		: Employee(name), workTime(0), payPerHour(pay) {}
	void AddWorkTime(int time)
	{
		workTime += time;
	}
	virtual int GetPay() const { return workTime * payPerHour; }
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

class SalesWorker : public PermanentWorker
{
private:
	int salesResult;    // �� �ǸŽ���
	double bonusRatio;    // �󿩱� ���� 
public:
	SalesWorker(const char* name, int money, double ratio)
		: PermanentWorker(name, money), salesResult(0), bonusRatio(ratio) {}
	void AddSalesResult(int value)
	{
		salesResult += value;
	}
	virtual int GetPay() const
	{
		return PermanentWorker::GetPay() + (int)(salesResult * bonusRatio);
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << GetPay() << endl << endl;
	}
};

enum RISK_LEVEL {RISK_A = 3, RISK_B = 2, RISK_C=1 };

class ForeignSalesWorker : public SalesWorker
{
private:
	int risk_level;
public:
	ForeignSalesWorker(const char* name, int money, double ratio, int risk_level) : SalesWorker(name, money, ratio), risk_level(risk_level) {}
	int GetRiskPay() const
	{
		return (int)(SalesWorker::GetPay() * 0.1 * risk_level);
	}
	virtual int GetPay() const
	{
		switch (this->risk_level)
		{
		case RISK_A:
			return (int)(SalesWorker::GetPay() + GetRiskPay());
		case RISK_B:
			return (int)(SalesWorker::GetPay() + GetRiskPay());
		case RISK_C:
			return (int)(SalesWorker::GetPay() + GetRiskPay());
		default:
			cout << "error!";
			return 0;
		}
	}
	virtual void ShowSalaryInfo() const
	{
		ShowYourName();
		cout << "salary: " << SalesWorker::GetPay() << endl;
		cout << "risky pay: " << GetRiskPay() << endl;
		cout << "sum: " << GetPay() << endl << endl;
	}
};

class EmployeeHandler
{
private:
	Employee* empList[50];
	int empNum;
public:
	EmployeeHandler() : empNum(0) { }
	void AddEmployee(Employee* emp)
	{
		empList[empNum++] = emp;
	}
	void ShowAllSalaryInfo() const
	{

		for (int i = 0; i < empNum; i++)
			empList[i]->ShowSalaryInfo();

	}
	void ShowTotalSalary() const
	{
		int sum = 0;

		for (int i = 0; i < empNum; i++)
			sum += empList[i]->GetPay();

		cout << "salary sum: " << sum << endl;
	}
	~EmployeeHandler()
	{
		for (int i = 0; i < empNum; i++)
			delete empList[i];
	}
};

int main(void)
{
	// ���������� �������� ����� ��Ʈ�� Ŭ������ ��ü����
	EmployeeHandler handler;
	
	// �ؿ� ������ ���
	ForeignSalesWorker* fseller1 = new ForeignSalesWorker("LEE", 1000, 0.1, RISK_LEVEL::RISK_A);
	fseller1->AddSalesResult(7000);
	handler.AddEmployee(fseller1);

	ForeignSalesWorker* fseller2 = new ForeignSalesWorker("KIM", 1000, 0.1, RISK_LEVEL::RISK_B);
	fseller2->AddSalesResult(7000);
	handler.AddEmployee(fseller2);

	ForeignSalesWorker* fseller3 = new ForeignSalesWorker("Park", 1000, 0.1, RISK_LEVEL::RISK_C);
	fseller3->AddSalesResult(7000);
	handler.AddEmployee(fseller3);

	// �̹� �޿� �����ؾ� �� �޿��� ����
	handler.ShowAllSalaryInfo();
	return 0;
}