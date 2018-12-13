#include <stdio.h>
#include <math.h>

void showMenu();
void imperial();
double BMI(double height, double weight);
void printBMI(double bmi);
void metric();

int main() {
    int option;
    double height;
    double weight;
    printf("Hullo, Mate!\n Checking your weight again?  Let's see how are you faring with your BMI!\n");
    printf("In fact, let's see how all of your mates are doing!");
    do {
        showMenu();
        scanf("%d", &option);

        if (option != 0) {
            switch(option) {
                case 1:
                    imperial();
                    break;
                case 2:
                    metric();
                    break;
                default:
                    printf("Not a valid option, mate! Can't work with that.  Try again!\n");
            }
            printf("\nNext!\n");
        }
    } while (option != 0);

    return 0;
}

void showMenu() {
    printf("1. Imperial system units.\n");
    printf("2. Metric system units.\n");
    printf("0. Exit.\n\n");
    printf("Option: ");
}

void imperial() {
    double feet;
    double inches;
    double pounds;
    double bmi;

    printf("Give me your height in feet and inches:\n");
    printf("How many feet? ");
    scanf("%lf", &feet);
    printf("How many inches? ");
    scanf("%lf", &inches);
    printf("\ngive me your weight in pounds: ");
    scanf("%lf", &pounds);

    bmi = BMI(feet*0.3048 + inches*0.0254, pounds*0.453592);
    printBMI(bmi);
}

void metric() {
    double meters;
    double kilograms;

    printf("Give me your height in meters: ");
    scanf("%lf", &meters);
    printf("Give me your height in kilograms: ");
    scanf("%lf", &kilograms);

    printBMI(BMI(meters, kilograms));
}

double BMI(double height, double weight) {
    return weight / pow(height, 2);
}

void printBMI(double bmi) {
    printf("Your Body Mass Index (BMI) is: %lf\n", bmi);
    printf("This means you ");
    if (bmi < 18.5) {
        printf("have underweight.\n");
    } else {
        if (bmi < 25) {
            printf("have a healty weight.\n");
        } else {
            if (bmi < 30) {
                printf("have overweight.\n");
            } else {
                if (bmi < 35) {
                    printf("are obese (class I).\n");
                } else {
                    if (bmi < 40) {
                        printf("are severely obese (class II).\n");
                    } else {
                        if (bmi < 50) {
                            printf("are morbidly obese (class III).\n");
                        } else {
                            printf("are super obese (class IV).\n");
                        }
                    }
                }
            }
        }
    }
}

