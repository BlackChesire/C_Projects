//Avicahi Aziz 316373497 & Asaf Ben Shabat 312391774
#include <stdio.h> 

double house_cost = 0, down_payment = 0, initial_savings = 0, saving_annual_rate = 0, mortgage_annual_rate = 0;
double fraction_house_buying = 0, monthly_rent = 0;
double initial_monthly_salary = 0, raise_fraction = 0;
int main() {
    
    printf("Enter (House-cost, down-payment, savings, savings-annual-rate, mortgage-annual-rate, salary, fraction-saving, annual-raise, house-rent):\n");
    if (scanf("(%lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf)",&house_cost, &down_payment, &initial_savings, &saving_annual_rate, 
    &mortgage_annual_rate, &initial_monthly_salary, &fraction_house_buying, &raise_fraction, &monthly_rent) == 9) {
    
    double final_house_cost = 0;
    double current_savings = initial_savings;
    double own_furtune_needed = (house_cost * down_payment);
    double salary_for_houses = (current_monthly_salary *  fraction_house_buying); //included the rent and the salary of the wanted house 
    double salary_to_save = (salary_for_houses - monthly_rent); //the part of salary for the house wants to buy
    double saving_monthly_rate = (saving_annual_rate / 12);
    double mortgage_monthly_rate = (mortgage_annual_rate / 12);
    int count_months = 0;
    int count_years = 0;
    int current_savings = house_rent(int count_months);

    while (current_savings < own_furtune_needed) {
        
        if ((salary_for_houses) >= (monthly_rent)) {
            
            while (count_months != 13) { //unequal to 13 couse we want to count from 1-12
            
                if (count_months == 12) { //count years

                    current_monthly_salary += (current_monthly_salary * raise_fraction); //add the raise to salary
                    salary_for_houses = (current_monthly_salary *  fraction_house_buying); //the money saved for the rent house and the wish house
                    ++count_years; //add 1 each year
                    count_months = 0; //equate to zero after 12 month (1 year)
                }
                
                current_savings += (current_savings * saving_monthly_rate); //add the monthly rate to the savings
                salary_to_save = (salary_for_houses - monthly_rent); //the part of salary for the wanted house each month
                current_savings += salary_to_save; //add the saved salary for the house, to the savings every month            
                
                ++count_months;

                if (current_savings > own_furtune_needed) { //check if we have enough money to pay the first down payment
                    
                    printf("After %d years and %d months you will have enough money for the down payment\n", count_years,
                    count_months);

                    break;
                }
                
            }
        }

        else 
        {
            printf("Error: housing portion of the salary is insufficient to cover rent\n");
            
            return 2;
        }
    }

    double house_payment = (house_cost - current_savings); //the rest payment for the house
    current_savings = 0; //after the payment for the bank        
    salary_to_save = (current_monthly_salary * fraction_house_buying); //the payment for the mortgage each month
    
    if (salary_to_save >= (house_payment * mortgage_monthly_rate)) {
    
    /*
    **
    ASAF START FROM HERE!
    LEFT TO DO- QUESTIONS NUMBER: 7, 8 AND THE FUNCTION OF THE RENT HOUSE!
    איזה משתנה זה מספר החודשים -
    -איזה משתנה זה הסכום שנותר לשלם כדי שאעשה while
    *
    */










    }

    else
    {
        printf("Error: The monthly repayment amount is lower than the amount to be paid as a monthly repayment\n");

        return 3;
    }




    }   


    else
    {
        printf("Error,you must enter 9 values\n");
        return 1;
    }
    
    
    return 0;
}

double house_rent(double count_months){
    for(int i = 0; i < count_months;i++){
        if (i % 12 == 0){
            current_monthly_salary = current_monthly_salary + current_monthly_salary*raise_fraction;
            // savings must be global!
            // savings += savings*saving_annual_
            // savings += salary_to_save - monthly_rent;
            
        }
    }
    return savings;
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
