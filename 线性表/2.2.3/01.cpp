// ��˳�����ɾ��������Сֵ��Ԫ�أ�����Ψһ�����ɺ������ر�ɾԪ�ص�ֵ��
// �ճ���λ�������һ��Ԫ�������˳���Ϊ�գ�����ʾ������Ϣ���˳����С�

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
    L.length = 0;
    int n, value;
    
    cout << "������˳���ĳ���:";
    cin >> n;
    
    cout << "������" << n << "������:" << endl;
    for(int i = 0; i < n; i++) {
        cin >> L.data[i];
        L.length++;
    }
    
    if(del_min(L, value)) {
        cout << "ɾ������СֵΪ:" << value << endl;
        cout << "ɾ�����˳���Ϊ:";
        for(int i = 0; i < L.length; i++) {
            cout << L.data[i] << " ";
        }
        cout << endl;
    } else {
        cout << "����:˳���Ϊ��!" << endl;
    }
    
    return 0;
}
