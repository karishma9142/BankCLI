#include <bits/stdc++.h>

// JAI SHREE RAM

using namespace std;
class bank
{
public:
    int code = 1234;
    int amount = 10000;
    int saving_amount = 50000;
    // vector<int>v;

    int cheak_code(int n)
    {
        if (n == code)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    void saving_debit(int n)
    {
        saving_amount = saving_amount - n;
        cout << saving_amount << endl;
    }
    void debit(int n)
    {
        amount = amount - n;
        cout << amount << endl;
    }
    void saving_credit(int n)
    {
        saving_amount = saving_amount + n;
        cout << saving_amount << endl;
    }
    void credit(int n)
    {
        amount = amount + n;
        cout << amount << endl;
    }
    void saving_show()
    {
        cout << saving_amount << endl;
    }
    void show()
    {
        cout << amount << endl;
    }
    void show_payment(vector<int> v)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i] << ' ';
            
        }
        cout<<endl;
    }
};

int main()
{

    bank obj;
    int n;
    int amount;
    vector<int> debit_current;
    vector<int> debit_saving;
    vector<int> credit_current;
    vector<int> credit_saving;

    cout << "enter the code" << endl;
    cin >> n;
    int a = obj.cheak_code(n);
    if (a == 0)
    {
        cout << "incorect code" << endl;
    }

    int num;
    int c;
    if (a == 1)
    {
        while (true)
        {

            cout << "enter a number" << endl;
            cout << "1 : credit\n"
                    "2 : debit\n"
                    "3 : show amount\n"
                    "4 : show payment history\n"
                    "5 : exit\n"
                 << endl;
            cin >> num;

            switch (num)
            {
            case 1:
                cout << "chose account" << endl;
                cout << "1 : current account\n"
                        "2 : saving account\n";
                cin >> c;

                cout << "enter amount" << endl;
                cin >> amount;
                if (c == 2)
                {
                    credit_saving.push_back(amount);
                    obj.saving_credit(amount);
                    break;
                }
                else if (c == 1)
                {
                    credit_current.push_back(amount);
                    obj.credit(amount);
                    break;
                }
                else
                {
                    cout << "jada dimah mat lagav (try again)" << endl;
                    break;
                }

            case 2:
                cout << "chose account" << endl;
                cout << "1 : current account\n"
                        "2 : saving account\n";
                cin >> c;
                cout << "enter amount" << endl;
                cin >> amount;
                if (c == 2)
                {
                    if (amount > obj.saving_amount)
                    {
                        cout << "know your limit";
                        break;
                    }

                    debit_saving.push_back(amount);
                    obj.saving_debit(amount);
                    break;
                }
                else if (c == 1)
                {
                    if (amount > obj.amount)
                    {
                        cout << "aukat se jada bol rha hai";
                        break;
                    }
                    debit_current.push_back(amount);
                    obj.debit(amount);
                    break;
                }
                else
                {
                    cout << "tyr again" << endl;
                    break;
                }
            case 3:
                cout << "chose account" << endl;
                cout << "1 : current account\n"
                        "2 : saving account\n";
                cin >> c;
                if (c == 2)
                {
                    obj.saving_show();
                    break;
                }
                else if (c == 1)
                {
                    obj.show();
                    break;
                }
                else
                {
                    cout << "try again" << endl;
                }
            case 4:

                int account;
                cout << "chose account\n"
                        "1 : current account\n"
                        "2 : saving account\n";
                cin >> account;
                if (account == 1)
                {
                    cout << "debit : ";
                    obj.show_payment(debit_current);
                    cout << "credit : ";
                    obj.show_payment(credit_current);
                    break;
                }
                else if (c == 2)
                {
                    cout << "debit : ";
                    obj.show_payment(debit_saving);
                    cout << "credit : ";
                    obj.show_payment(credit_saving);
                    break;
                }
                else
                {
                    cout << "try again" << endl;
                    break;
                }

            case 5:
                return 0;
                break;
            default:
                cout << "wrong number" << endl;
                break;
            }
        }
    }
}
