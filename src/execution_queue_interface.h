#ifndef _EXECUTION_QUEUE_INTERFACE_H_
#define _EXECUTION_QUEUE_INTERFACE_H_

#include <condition_variable>

// ����� ����������� ���� ��������� ������ ������������ ������������������ ������� ���������� ������� (��� �� ��� �� �������).
//
// ������ �����, ������� ��������� ���������������� � ������� �������, ������ ������� WaitSignal, ����� ����� ������� ����� ������� � �������� ������� �� �������� ������.
// ������� ����� ����� ������� ExecuteAll ��� ������������ (!) ���������� ���� ������� ������� � ��������, ������ � ��� ������� � ������� ��� �������� � ��������.
// ������� ����� ��������� ������ ������ �����, ����� ��� ������ �� ������� ����� ���������.
// ���� ���� ��� ����� �� ������� ��������� �� ������ ������������������ � ���� �� �������� ������ ����� ���������� ���� ��������� ������� �� ���� ����� ������� (��� ��� ������� � ExecuteAll � WaitSignal)
//
// ������� ���������� ������������ ��������� � ExecutionQueueInterface ����� SignalExecutor.
class ExecutionQueueInterface
{
public:
    // ������ ������� ����� � �������� �������, ���������� ���������� ����� condition_variable � notify
    virtual void WaitSignal(std::condition_variable& condition_variable, bool& notify) = 0;

    // ����� ������ ���������� ������� � ���������� ���������� ������������ �������
    virtual void Executed() = 0;

    // ��������� ��� ������ �� �������
    virtual void ExecuteAll() = 0;

    virtual ~ExecutionQueueInterface() {}
};

#endif // !_EXECUTION_QUEUE_INTERFACE_H_