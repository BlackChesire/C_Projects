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
    
    double final_house_cost = 0, current_savings = initial_savings, current_monthly_salary = initial_monthly_salary;

    





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
