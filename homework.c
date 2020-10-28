//Avicahi Aziz 316373497 & Asaf Ben Shabat 312391774
#include <stdio.h> 

double house_cost = 0, down_payment = 0, initial_savings = 0, saving_annual_rate = 0, mortgage_annual_rate = 0;
double fraction_house_buying = 0, monthly_rent = 0;
double initial_monthly_salary = 0, raise_fraction = 0;

int main()
{
    printf("Enter (House-cost, down-payment, savings, savings-annual-rate, mortgage-annual-rate, salary, fraction-saving, annual-raise, house-rent):\n");
    if (scanf("(%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf)",&house_cost, &down_payment, &initial_savings, &saving_annual_rate, 
    &mortgage_annual_rate, &initial_monthly_salary, &fraction_house_buying, &raise_fraction, &monthly_rent) == 9) {
    
    double final_house_cost = 0;
    double current_savings = initial_savings;
    double current_monthly_salary = initial_monthly_salary;
    double own_furtune_needed = (house_cost * down_payment);
    double house_payment = (house_cost - current_savings); //the rest payment for the house
    double salary_for_houses = (current_monthly_salary *  fraction_house_buying); //included the rent and the salary of the wanted house 
    double salary_to_save = 0; //the part of salary for the house wants to buy
    int count_months = 0;
    int count_years = 0;

    if (current_savings != own_furtune_needed) {
        
        while (current_savings != own_furtune_needed) {
            salary_to_save = (salary_for_houses - monthly_rent); //the part of salary for the house wants to buy
            current_savings += salary_to_save; //add the saved salary for the house, to the savings
            ++count_months;

            if (count_months == 12) {
                ++count_years;
                count_months = 0;
            }




        }
    }

    else
    {
        current_savings = 0; //the current savings is 0 because we pay it for the house
        
    }
    






    }

    else
    {
        printf("Error, must be 9 values\n");
        return 1;
    }
    

    printf("After...\n");
    printf("After..\n");
    printf("Actual payment..\n");
    printf("house worth is:\n");
    printf("Done !");
    
    return 0;
}

double house_rent(double monthly_rent);

{
    for(int i=0; i < monthly_rent; i++)
    {

        return NULL;
    }
 }



/* RUN EXAMPLE :
Enter (House-cost, down-payment, savings, savings-annual-rate, mortgage-annual-rate, salary, fraction-saving, 
annual-raise, house-rent):
(600000, 0.15, 50000, 0.02, 0.03, 10000, 0.3, 0.03, 2000)
After 2 years and 10 months you will have enough money for the down payment
After 16 years and 2 months you will cover the cost of the house
Actual payment for the house: 734099.0
House worth is 600000.0
Alternatively, if you rent you will end up with 467616.2
*/
