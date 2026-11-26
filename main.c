// Online C compiler (editor)
// Write and run C online using this editor.

#include <stdio.h>
#include <string.h>

struct Campaign
{
    int id;
    char name[50];
    char platform[30];
    float budget;
    float sales;
};

struct Campaign c[100];
int count = 0;

void addCampaign()
{
    printf("\nEnter Campaign ID: ");
    scanf("%d", &c[count].id);

    printf("Enter Campaign Name: ");
    scanf(" %[^\n]", c[count].name);

    printf("Enter Marketing Platform: ");
    scanf(" %[^\n]", c[count].platform);

    printf("Enter Budget: ");
    scanf("%f", &c[count].budget);

    printf("Enter Sales Amount: ");
    scanf("%f", &c[count].sales);

    count++;

    printf("\nCampaign Added Successfully!\n");
}

void viewCampaign()
{
    int i;

    if (count == 0)
    {
        printf("\nNo Campaign Record Found!\n");
        return;
    }

    for (i = 0; i < count; i++)
    {
        printf("\nCampaign ID: %d", c[i].id);
        printf("\nCampaign Name: %s", c[i].name);
        printf("\nPlatform: %s", c[i].platform);
        printf("\nBudget: %.2f", c[i].budget);
        printf("\nSales: %.2f\n", c[i].sales);
    }
}

void searchCampaign()
{
    int id, i, found = 0;

    printf("\nEnter Campaign ID to Search: ");
    scanf("%d", &id);

    for (i = 0; i < count; i++)
    {
        if (c[i].id == id)
        {
            printf("\nCampaign Found!");
            printf("\nName: %s", c[i].name);
            printf("\nPlatform: %s", c[i].platform);
            printf("\nBudget: %.2f", c[i].budget);
            printf("\nSales: %.2f\n", c[i].sales);
            found = 1;
        }
    }

    if (found == 0)
    {
        printf("\nCampaign Not Found!\n");
    }
}

void budgetReport()
{
    float total = 0;
    int i;

    for (i = 0; i < count; i++)
    {
        total = total + c[i].budget;
    }

    printf("\nTotal Marketing Budget = %.2f\n", total);
}

void salesReport()
{
    float totalSales = 0;
    int i;

    for (i = 0; i < count; i++)
    {
        totalSales = totalSales + c[i].sales;
    }

    printf("\nTotal Sales = %.2f\n", totalSales);
}

int main()
{
    int choice;

    do
    {
        printf("\n==================================");
        printf("\n INTERNET MARKETING MANAGEMENT");
        printf("\n==================================");
        printf("\n1. Add Campaign");
        printf("\n2. View Campaign");
        printf("\n3. Search Campaign");
        printf("\n4. Marketing Budget Report");
        printf("\n5. Sales Report");
        printf("\n6. Exit");
        printf("\nEnter Your Choice: ");

        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                addCampaign();
                break;

            case 2:
                viewCampaign();
                break;

            case 3:
                searchCampaign();
                break;

            case 4:
                budgetReport();
                break;

            case 5:
                salesReport();
                break;

            case 6:
                printf("\nThank You!");
                break;

            default:
                printf("\nInvalid Choice!");
        }

    } while (choice != 6);

    return 0;
}
