#include <iostream>
#include <string>

using namespace std;

class Casino
{
protected:
    int bettingAmount;
    int guess;
    int n;
    char symbol;

public:
    void ini();
    void rules();
    void drawLine(int n, char symbol);
};

class get_info
{
public:
    string playerName;
    int amount;

    get_info()
    {
        cout << "\nEnter your name : ";
        cin >> playerName;

        cout << "\nEnetr Deposit amount to play game : $";
        cin >> amount;
    }
};

class play : public get_info, public Casino
{
protected:
    int dice;
    char choice;

public:
    play()
    {
        do
        {

            cout << "\nYour current balance is $" << amount << "\n";

            do
            {
                cout << playerName << " ,Enter money to bet :$";
                cin >> bettingAmount;

                if (bettingAmount > amount)
                    cout << "\nYour betting amount is more than your current amount"
                         << "\nRe-enter data\n";

            } while (bettingAmount > amount);

            do
            {
                cout << "\nGuess your number to bet between 1 to 10 :";
                cin >> guess;

                if (guess <= 0 || guess > 10)
                    cout << "\nPlease check the number !!  It should be between 1 to 10"
                         << "\nRe-enter data\n";

            } while (guess <= 0 || guess > 10);

            dice = rand() % 10 + 1;

            if (dice == guess)
            {
                cout << "\n\t** Good Luck!!**"
                     << "\n\t You won Rs." << bettingAmount * 10;
                amount = amount + bettingAmount * 10;
            }
            else
            {
                cout << "\n\t**Bad Luck this time !!**"
                     << "\n\tYou lost $"
                     << bettingAmount;
                amount = amount - bettingAmount;
            }

            cout << "\n\tThe winning number was : " << dice << "\n";
            cout << "\n"
                 << playerName << " ,you have $ " << amount << "\n";

            if (amount == 0)
            {
                cout << "\t\nYou have no money to play";
                break;
            }

 
            cout << "\n-->Do you want to play again (y/n)? ";
            cin >> choice;

        } while (choice == 'Y' || choice == 'y');

        cout << "\n\n";
        drawLine(70, '=');
    }
};

void Casino ::ini()
{
    drawLine(80, '_');
    cout << "\n\t\t\tCASINO GAME\n";
    drawLine(80, '_');
}

void Casino ::rules()
{
    // system("cls");
    cout << "\n";
    drawLine(76, '-');
    cout << "\t\t RULES OF THE GAME\n";
    drawLine(76, '-');
    cout << " 1.Choose any number between 1 to 10\n ";
    cout << "2.If you win you will get 10 times of money you bet\n ";
    cout << "3.If you bet on wrong number you will los eyour bettingAmount\n";
    drawLine(80, '-');
}

void Casino ::drawLine(int n, char symbol)
{
    for (int i = 0; i < n; i++)
    {
        cout << symbol;
    }
    cout << "\n";
}

int main()
{
    Casino c1;
    c1.ini();
    c1.rules();

    play c2;
    return 0;
}