#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <functional>

using namespace std;
bool UserInput(string input)
{
    char ENG [] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char eng [] = "abcdefghijklmnopqrstuvwxyz";
    for (auto i : input)
    {
        for (int h = 0;h <= 26;h++)
        {
            if(i == ENG[h]) return false;
            if(i == eng[h]) return false;
        }
    }
    if(input.empty()) return false;
    try
    {
        int number = stoi(input);
    }
    catch(...)
    {
        return false;
    }
    int number = stoi(input);
    if (number < 0) return false;
    return true;
}
int integ(string label = "")
{
    cout << label << endl;
    int new_int = 0;
    string raw_input;
    getline(cin, raw_input);
    while (!UserInput(raw_input))
    {
      getline(cin, raw_input);
    };
    new_int = stoi(raw_input);
    return new_int;
}
void EnterDigit(double& varlink, const string& label)
{
    string raw_input;
    cout << label << " = ";
    getline(cin, raw_input);
    while(!UserInput(raw_input))
    {
        cout << label << " = ";
        getline(cin, raw_input);
    }
    varlink = stod(raw_input);
}

double middle_grade(double num1, double num2, double num3)
{
        return (num1 + num2 + num3) / 3;
}
void show_middle(double num1, double num2, double num3)
{
    cout << middle_grade(num1, num2, num3);
}
void is_good(double num1, double num2, double num3)
{
    if(middle_grade(num1, num2, num3) > 4)
    {
        cout << "The council has decided that you deserve to live";
    }
}
int main()
{
    double math{0}, phys{0}, chem{0};
    cout << endl;
    vector<string> opt_vec{
        "\n1.Math grade",
        "2.Physics grade",
        "3.Chemestry grade",
        "4.Show average grade",
        "5.If average grade good"
    };
    int choice{0};
    while (true)
    {
        for (const auto& opt : opt_vec)
        {
            cout << opt << endl;
        }
        choice = integ("Choose an option:");
        switch (choice)
        {
        case 1:
            EnterDigit(math, "Input math grade:");
            break;
        case 2:
            EnterDigit(phys, "Input physics grade:");
            break;
        case 3:
            EnterDigit(chem, "Input chemestry grade:");
            break;
        case 4:
            show_middle(math, phys, chem);
            break;
        case 5:
            is_good(math, phys, chem);
            break;
        default:
            cout << "wrong number" << endl;
            break;
        }
    };
};