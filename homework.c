#include <stdio.h> 
int main(){
    double house_cost = 0,down_payment = 0,intial_savings=0,mortgage_annual_rate=0,intial_monthly_salary=0,raise_fraction=0;
    double fraction_house_buying = 0, monthly_rent = 0;
    printf("Please enter house coust:");
    scanf("%lf",&house_cost);
    printf("Please enter down payment:");
    scanf("%lf", &down_payment);
    printf("please enter intial savings:");
    scanf("%lf",&intial_savings);
    printf("plese enter mortgage annual rate:");
    scanf("%lf", &mortgage_annual_rate);
    printf("please enter intial monthly salary:");
    scanf("%lf",&intial_monthly_salary);
    printf("please enter raise fraction:");
    scanf("%lf",&raise_fraction);
    printf("please enter fraction house buying:");
    scanf("%lf",&fraction_house_buying);
    printf("please enter monthly rate:");
    scanf("%lf",&monthly_rent);
    return 0;
}