//Avicahi Aziz 316373497 & Asaf Ben Shabat 312391774
#include <stdio.h> 
int main(){
    double house_cost = 0,down_payment = 0,intial_savings=0,mortgage_annual_rate=0;
    double fraction_house_buying = 0, monthly_rent = 0;
    double intial_monthly_salary=0, raise_fraction=0;
    printf("Please enter house cost:");
    scanf("%lf",&house_cost);
    printf("Please enter down payment:");
    scanf("%lf", &down_payment);
    printf("please enter intial savings:");
    scanf("%lf",&intial_savings);
    printf("please enter mortgage annual rate:");
    scanf("%lf", &mortgage_annual_rate);
    printf("please enter intial monthly salary:");
    scanf("%lf",&intial_monthly_salary);
    printf("please enter raise fraction:");
    scanf("%lf",&raise_fraction);
    printf("please enter fraction house buying:");
    scanf("%lf",&fraction_house_buying);
    printf("please enter monthly rate:");
    scanf("%lf",&monthly_rent);

    int house_rent(double monthly_rent){
        for(int i=0; i < monthly_rent; i++){


        }
        return 0;
    }
    printf("After...\n");
    printf("After..\n");
    printf("Actual payment..\n");
    printf("house worth is:\n");
    printf("Done !");
    return 0;
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
