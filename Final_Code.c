#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE *fp;

struct Reg
{
    char name[30];
    char state[30];
    int gender;
    int bg;
    int cov_rec;
    int Disease;
    char age[30];
    char pin[30];
    char phone[30];
};
struct Reg d;

void display();
void mainMenu();
void addNewPerson();
void searchBloodGroup();
void searchPin();
void searchBAP();
void deletedetails();
void common();

#define user "Plasma_Bank"
#define pass "Error404"

int main()
{
    display();

    char username[20], password[20];

    printf("\n\t\tPlease Enter username: ");
    scanf("%s", &username);

    printf("\n\t\tPlease enter password: ");
    scanf("%s", &password);
    while (strcmp(username, user) != 0 || strcmp(password, pass) != 0)
    {

        printf("Wrong username or password try again!\n");

        printf("\n\t\tPlease Enter Username: ");
        scanf("%s", &username);

        printf("\n\t\tPlease Enter Password: ");
        scanf("%s", &password);
    }

    printf("\n\n\t\t\t\t\t\t\t  Welcome Login Success!");
    mainMenu();
}
void display()
{
    printf("\n\n\t\t\t\t\t\t\t---------------------");
    printf("\n\t\t\t\t\t\t\t| Covid Plasma Bank |\n");
    printf("\t\t\t\t\t\t\t---------------------\n");
}
void mainMenu()
{
    int ch;

    while (1)
    {
        printf("\n\n\n\t\t\t\t\t  MAIN MENU\n");
        printf("\t\t\t\t\t*************\n");

        printf("\n\n\t\t1.Add New Person\n");
        printf("\t\t2.Search By Blood Group\n");
        printf("\t\t3.Search By Pin Code\n");
        printf("\t\t4.Search By Blood Group And Pin Code\n");
        printf("\t\t5.Delete Data\n");
        printf("\t\t6.Exit\n");
        printf("\n\t\tPlease Enter Your Choice: ");

        fflush(stdin);
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            addNewPerson();
            break;
        case 2:
            searchBloodGroup();
            break;
        case 3:
            searchPin();
            break;
        case 4:
            searchBAP();
            break;
        case 5:
            deletedetails();
            break;
        case 6:
            printf("\nThank You For Using COvid Plasma Bank.");

            printf("\n@ Copyright February,2021 || All Rights Reserved By DST CIMS, BHU\n");
            exit(1);
        default:
            printf("\t\tSorry,invalid choice...!\n");
        }
    }
}

void addNewPerson()
{
    {
        fp = fopen("donor.txt", "ab+");

        printf("\n Enter Your Name: ");
        fflush(stdin);
        gets(d.name);

        printf("\n Your Age : ");
        fflush(stdin);
        gets(d.age);

        printf("\n Gender: ");
        printf("\n 1.Male  2.Female  3.Other \n");
        fflush(stdin);
        scanf("%d", &d.gender);

        printf("\n Please Select Your Blood Group Type:\n");
        printf("\n 1.A+   2.A-   3.B+   4.B- \n 5.O+   6.O-   7.AB+  8.AB-\n");
        fflush(stdin);
        scanf("%d", &d.bg);

        printf("\n Please select if you have any of the following disease.\n");
        printf("\n 1.Cancer\t\t2.Cardiac disease\t3.Sever lung disease\t4.Hepatitis B and C \n 5.HIV infection, AIDS  6.Chronic alcoholism\t7.Underweight\t\t8.Low or High iron level\n 9.None of these\n");
        fflush(stdin);
        scanf("%d", &d.Disease);
        printf("\n Whether Covid-19 Recovered ?\n");
        printf("\n 1.Yes  2.No  3.Didn't have COVID till now\n");
        fflush(stdin);
        scanf("%d", &d.cov_rec);

        printf("\n State You Are Living in : ");
        fflush(stdin);
        gets(d.state);

        printf("\n Area PIN Code : ");
        fflush(stdin);
        gets(d.pin);

        printf("\n Phone Number : ");
        fflush(stdin);
        gets(d.phone);

        fwrite(&d, sizeof(d), 1, fp);
    }

    printf("\n\n\t\t\t\t\t*************\n");
    printf("\n Name            : %s ", d.name);
    printf("\n Age             : %s ", d.age);

    switch (d.gender)
    {
    case 1:
        printf("\n Gender          : Male");
        break;
    case 2:
        printf("\n Gender          : Female");
        break;
    case 3:
        printf("\n Gender          : Other");
        break;
    default:
        printf("\n Gender          : Unknown {invalid input by user}");
        break;
    }
    switch (d.bg)
    {
    case 1:
        printf("\n Blood group     : A+ ");
        break;
    case 2:
        printf("\n Blood group     : A- ");
        break;
    case 3:
        printf("\n Blood group     : B+ ");
        break;
    case 4:
        printf("\n Blood group     : B- ");
        break;
    case 5:
        printf("\n Blood group     : O+ ");
        break;
    case 6:
        printf("\n Blood group     : O- ");
        break;
    case 7:
        printf("\n Blood group     : AB+ ");
        break;
    case 8:
        printf("\n Blood group     : AB- ");
        break;
    default:
        printf("\n Blood group     : Unknown {invalid input by user} ");
    }

    switch (d.Disease)
    {
    case 1:
        printf("\n Disease         : Cancer");
        break;
    case 2:
        printf("\n Disease         : Cardiac disease");
        break;
    case 3:
        printf("\n Disease         : Sever lung disease ");
        break;
    case 4:
        printf("\n Disease         : Hepatitis B and C ");
        break;
    case 5:
        printf("\n Disease         : HIV infection, AIDS ");
        break;
    case 6:
        printf("\n Disease         : Chronic alcoholism ");
        break;
    case 7:
        printf("\n Disease         : Underweight ");
        break;
    case 8:
        printf("\n Disease         : Low or High iron level ");
        break;
    case 9:
        printf("\n Disease         : None  ");
        break;
    default:
        printf("\n Disease         : Unknown {invalid input by user}  ");
    }

    switch (d.cov_rec)
    {
    case 1:
        printf("\n Covid Recovered : Yes ");
        break;
    case 2:
        printf("\n Covid Recovered : No ");
        break;
    case 3:
        printf("\n Covid Recovered : Didn't have COVID till now ");
        break;
    default:
        printf("\n Covid Recovered : Unknown {invalid input by user}");
    }
    printf("\n State           : %s ", d.state);
    printf("\n Pin Code        : %s ", d.pin);
    printf("\n Phone Number    : %s ", d.phone);
    switch (d.Disease)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
        printf("\n\nNote - Sorry !  You are not eligible for donating Plasma Blood\n");
    }

    printf("\n\n\t\tSuccessfully saved your information...!\n");

    fclose(fp);
    mainMenu();
}

void searchBloodGroup()
{

    int temp_blood;

    fp = fopen("donor.txt", "rb");

    printf("\n\nEnter Plasma blood group that you need :\t");
    printf("\n 1.A+   2.A-   3.B+   4.B- \n 5.O+   6.O-   7.AB+  8.AB-\n");
    scanf("%d", &temp_blood);
    int t = 0;

    while (fread(&d, sizeof(d), 1, fp) == 1)
    {

        if (temp_blood == d.bg && d.Disease == 9)
        {
            t = 1;
            common();
        }
    }
    fclose(fp);
    if (t == 0)
    {
        printf("\n\t\t\t\t\tSorry! Data Not Available...");
    }

    mainMenu();
}

void searchPin()
{

    char temp_Pin[10];

    fp = fopen("donor.txt", "rb");

    printf("\n\nPlease, Enter Your Area Pin Code  :\t");
    fflush(stdin);
    gets(temp_Pin);
    int t = 0;

    while (fread(&d, sizeof(d), 1, fp) == 1)
    {

        if (strcmp(temp_Pin, d.pin) == 0 && d.Disease == 9)
        {
            t = 1;
            common();
        }
    }
    fclose(fp);
    if (t == 0)
    {
        printf("\n\t\t\t\t\tSorry! Data Not Available...");
    }

    mainMenu();
}

void searchBAP()
{
    int temp_blood;
    char temp_Pin[10];

    fp = fopen("donor.txt", "rb");

    printf("\n\nPlease, Enter Plasma Blood Group that You Need :\t");
    printf("\n 1.A+   2.A-   3.B+   4.B- \n 5.O+   6.O-   7.AB+  8.AB-\n");
    scanf("%d", &temp_blood);

    printf("\n\nPlease, Enter Your Area Pin Code Blood :\t");
    fflush(stdin);
    gets(temp_Pin);
    int t = 0;

    while (fread(&d, sizeof(d), 1, fp) == 1)
    {

        if (temp_blood == d.bg && strcmp(temp_Pin, d.pin) == 0 && d.Disease == 9)
        {
            t = 1;
            common();
        }
    }
    fclose(fp);
    if (t == 0)
    {
        printf("\n\t\t\t\t\tSorry! Data Not Available...");
    }

    mainMenu();
}
void common()
{
    printf("\n Name             : %s", d.name);

    printf("\n Age              : %s", d.age);

    switch (d.gender)
    {
    case 1:
        printf("\n Gender           : Male");
        break;
    case 2:
        printf("\n Gender           : Female");
        break;
    case 3:
        printf("\n Gender           : Other");

        break;
    default:
        printf("\n Gender          : Unknown {invalid input by user}");
    }

    switch (d.bg)
    {
    case 1:
        printf("\n Blood group      : A+ ");
        break;
    case 2:
        printf("\n Blood group      : A- ");
        break;
    case 3:
        printf("\n Blood group      : B+ ");
        break;
    case 4:
        printf("\n Blood group      : B- ");
        break;
    case 5:
        printf("\n Blood group      : O+ ");
        break;
    case 6:
        printf("\n Blood group      : O- ");
        break;
    case 7:
        printf("\n Blood group      : AB+ ");
        break;
    case 8:
        printf("\n Blood group      : AB- ");
        break;
    default:
        printf("\n Blood group      : Unknown {invalid input by user}");
    }

    switch (d.Disease)
    {
    case 1:
        printf("\n Disease          : Cancer");
        break;
    case 2:
        printf("\n Disease          : Cardiac disease");
        break;
    case 3:
        printf("\n Disease          : Sever lung disease ");
        break;
    case 4:
        printf("\n Disease          : Hepatitis B and C ");
        break;
    case 5:
        printf("\n Disease          : HIV infection, AIDS ");
        break;
    case 6:
        printf("\n Disease          : Chronic alcoholism ");
        break;
    case 7:
        printf("\n Disease          : Underweight ");
        break;
    case 8:
        printf("\n Disease          : Low or High iron level ");
        break;
    case 9:
        printf("\n Disease          : None  ");

        break;
    default:
        printf("\n Disease          : Unknown {invalid input by user}");
    }

    switch (d.cov_rec)
    {
    case 1:
        printf("\n Covid Recovered  : Yes ");
        break;
    case 2:
        printf("\n Covid Recovered  : No ");
        break;
    case 3:
        printf("\n Covid Recovered  : Didn't have COVID till now ");
        break;
    default:
        printf("\n Covid Recovered  : Unknown {invalid input by user}");
    }

    printf("\n State            : %s", d.state);

    printf("\n Pin              : %s", d.pin);

    printf("\n Phone Number     : %s", d.phone);

    printf("\n\n\t\t\t\t\t*************\n");
    printf("\n");
}

void deletedetails()
{
    FILE *fitmp;

    char Delete_Id[20];
    int temp = 1;

    fp = fopen("donor.txt", "r");

    printf("\nDelete user with phone number: ");
    scanf("%s", &Delete_Id);

    fitmp = fopen("copy.txt", "wb");

    while (fread(&d, sizeof(d), 1, fp) == 1)
    {
        if (strcmp(d.phone, Delete_Id) != 0)
            fwrite(&d, sizeof(d), 1, fitmp);
        else
            temp = 0;
    }

    fclose(fp);
    fclose(fitmp);

    remove("donor.txt");

    rename("copy.txt", "donor.txt");
    if (temp == 1)
        printf("\n No data found !!!");
    else
        printf("\n Record deleted successfully...!!\n");
}
