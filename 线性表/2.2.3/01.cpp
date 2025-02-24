// 从顺序表中删除具有最小值的元素（假设唯一）并由函数返回被删元素的值。
// 空出的位置由最后一个元素填补，若顺序表为空，则显示出错信息并退出运行。

#include <iostream>
using namespace std;

#define MAXSIZE 10

struct SQList
{
    int data[MAXSIZE];
    int length;
};

bool del_min(SQList &L, int &value)
{
    if (L.length == 0)
        return false;
    value = L.data[0];
    int post = 0;
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] < value)
        {
            value = L.data[i];
            post = i;
        }
    }
    L.data[post] = L.data[L.length - 1];
    L.length--;
    return true;
}

int main()
{
    SQList L;
    L.length = 5;
    L.data[0] = 3;
    L.data[1] = 1;
    L.data[2] = 5;
    L.data[3] = 2;
    L.data[4] = 4;

    cout << "原始顺序表:";
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;

    int value;
    if (del_min(L, value))
    {
        cout << "删除的最小值为:" << value << endl;
        cout << "删除后的顺序表:";
        for (int i = 0; i < L.length; i++)
        {
            cout << L.data[i] << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "顺序表为空,无法删除!" << endl;
    }

    return 0;
}
