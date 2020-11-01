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
    double current_monthly_salary = initial_monthly_salary;
    double own_furtune_needed = (house_cost * down_payment);
    double salary_for_houses = (current_monthly_salary *  fraction_house_buying); //included the rent and the salary of the wanted house 
    double salary_to_save = (salary_for_houses - monthly_rent); //the part of salary for the house wants to buy
    double saving_monthly_rate = (saving_annual_rate / 12);
    double mortgage_monthly_rate = (mortgage_annual_rate / 12);
    int count_months = 0;
    int count_years = 0;


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
<<<<<<< HEAD
<<<<<<< HEAD
        printf("Error, must be 9 values");
=======
        printf("Error, must be 9 values\n");
>>>>>>> a7248e1ee87d78c83eebd1c253216a30e5287d2a
=======
        printf("Error,you must enter 9 values\n");
>>>>>>> efcc69500596707279d92c528c3dac1f617a7ba6
        return 1;
    }
    
    
    return 0;
}

<<<<<<< HEAD
double house_rent(double monthly_rent)
=======
// double house_rent(double monthly_rent);
>>>>>>> efcc69500596707279d92c528c3dac1f617a7ba6

// {
//     for(int i=0; i < monthly_rent; i++)
//     {

<<<<<<< HEAD
        return -1;
    }
 }
=======
//         return NULL;
//     }
//  }
>>>>>>> efcc69500596707279d92c528c3dac1f617a7ba6



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
