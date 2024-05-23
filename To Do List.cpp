#include<iostream>
#include<string>
#include<windows.h>

using namespace std;
string task_list[10]={""};
int tasks=0;

void ADD_TASK()
{
    if(tasks > 9)
    {
        cout<<"...TASK LIST IS ALREADY FULL..."<<endl;
    }
    else
    {
        cout<<"ENTER A NEW TASK"<<endl;
        cin.ignore();
        getline(cin,task_list[tasks]);
        tasks++;
    }
}

void VIEW_TASK()
{
    cout<<"...TO DO LIST..."<<endl;
    cout<<"--------------------------------------"<<endl;
    for(int i = 0 ; i < tasks ; i++)
    {
        cout<<"Task "<<i+1<<" = "<<task_list[i]<<endl;
    }
    cout<<"--------------------------------------"<<endl;
}

void DELETE_TASK()
{
    int delete_task;
    cout<<"ENTER A TASK NUMBER TO DELETE IT...."<<endl;
    cin>>delete_task;
    delete_task = delete_task - 1;
    if(delete_task < 0 && delete_task > 9)
    {
        cout<<"INVALID TASK NUMBER"<<endl;
    }
    else
    {
        for(int i = delete_task ; i < tasks ; i++)
        {
            task_list[i] = task_list[i+1];
        }
        tasks = tasks - 1;
    }
}

int main()
{
    system("color 1");
    int choice=1;
    do
    {
        cout<<"......TO DO LIST......"<<endl;
        cout<<"1 = TO ADD NEW TASK"<<endl;
        cout<<"2 = TO VIEW TASK"<<endl;
        cout<<"3 = TO DELETE TASK"<<endl;
        cout<<"0 = TERMINATE THE TASK"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0:
            {
                break;
            }
            case 1:
            {
                ADD_TASK();
                break;
            }
            case 2:
            {
                system("cls");
                VIEW_TASK();
                break;
            }
            case 3:
            {
                system("cls");
                DELETE_TASK();
                break;
            }
            default:
            {
                cout<<"WRONG CHOICE ENTERED"<<endl;
                break;
            }
        }
    }while(choice!=0);
    return 0;
}