#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// #include<math.h>
#define COUNT 5
#define PAYRATE 12.00
#define TAXRATE_300 0.15
#define TAXRATE_150 0.20
#define TAXRATE_REST 0.25
#define OVERTIME 40
#define MAX(x, y) ((x) > (y) ? x : y)
#define MONTH 12

int multiply(int a, int b);
int gcd(int a, int b);
int absValue(int x);
float sqrt(int x);

int main(int argc, char *argv[])
{

    // enum COMPANY {
    //     GOOGLE,
    //     FACEBOOK,
    //     XEROX,
    //     YAHOO,
    //     EBAY,
    //     MICROSOFT
    // };

    // enum COMPANY xeroxValue = XEROX;
    // enum COMPANY googleValue = GOOGLE;
    // enum COMPANY ebayValue = EBAY;

    // printf("%d\n%d\n%d", xeroxValue, googleValue, ebayValue);

    // double l,w,a,p;

    // if(argc < 3){
    //     printf("Valid Arguments are not there\n");
    //     return 404;
    // }

    // l = atof(argv[1]);
    // w = atof(argv[2]);

    // a = l*w;
    // p = 2*(l+w);

    // printf("Rectangle Measurements:\nLength->%0.2lf\nWidth->%0.2lf\nArea->%0.2lf\nPerimeter->%0.2lf\n", l,w,a,p);

    // int numberOfMinutes = atoi(argv[1]);

    // double minutesToDays = (numberOfMinutes / 60.0) / 24.0;
    // double minutesToYears = minutesToDays / 365.0;

    // printf("Minutes Entered -> %d\n", numberOfMinutes);
    // printf("Minutes to Days -> %0.2lf\n", minutesToDays);
    // printf("Minutes to Years -> %0.2lf\n", minutesToYears);

    // unsigned int a = 60; // 0011 1100
    // unsigned int b = 13; // 0000 1101

    // printf("a & b -> %d\n", a&b); //0000 1100

    // printf("int             size        = %zd\n", sizeof(int));
    // printf("char            size        = %zd\n", sizeof(char));
    // printf("float           size        = %zd\n", sizeof(float));
    // printf("long            size        = %zd\n", sizeof(long));
    // printf("long long       size        = %zd\n", sizeof(long long));
    // printf("double          size        = %zd\n", sizeof(double));
    // printf("long double     size        = %zd\n", sizeof(long double));

    // printf("Val -> %d\n", 5-4+2*5);

    // double numberOfHours = atof(argv[1]);
    // double totalPay = numberOfHours <= 40 ? numberOfHours * PAYRATE : (40 * PAYRATE) + (numberOfHours - 40) * (PAYRATE * 1.5);
    // printf("Total Pay before Taxes = %0.2lf\n", totalPay);
    // double totalTax = 0;

    // double t1, t2, t3;

    // t1 = totalPay > 300 ? 300 * TAXRATE_300 : totalPay * TAXRATE_300;
    // totalPay = totalPay - 300 > 0 ? totalPay - 300 : 0;

    // t2 = totalPay > 150 ? 150 * TAXRATE_150 : totalPay * TAXRATE_150;
    // totalPay = totalPay > 150 ? totalPay - 150 : 0;

    // t3 = totalPay > 0 ? totalPay * TAXRATE_REST : 0;

    // printf("Total Tax = %0.2lf\n", t1+t2+t3);

    // enum COMPANY companyValue = GOOGLE;

    // switch(companyValue){
    //     case GOOGLE:
    //         printf("Company Name is Google");
    //         break;

    //     case XEROX:
    //         printf("Company Name is Xerox");
    //         break;

    //     default:
    //         printf("Not from the list");
    //         break;
    // }

    //     int a = atoi(argv[1]);
    //     int b = atoi(argv[2]);

    //     if(b == 0) goto errMessage;
    //     printf("Dividing a by b -> %d\n", a/b);

    //     return 0;

    // errMessage:
    //     printf("Dividing by 0. Arithmetic Error");
    //     return 1;

    // unsigned int count;
    // printf("Enter Count -> ");
    // scanf("%i", &count);

    // unsigned int sum = 0;

    // for(unsigned int i = 0; i < count; i++){
    //     sum += i;
    // }

    // printf("Sum = %d\n", sum);
    // printf("Size to store Sum -> %zd bytes\n", sizeof(sum));

    // enum DAYS{
    //     MONDAY,
    //     TUESDAY,
    //     WEDNESAY,
    //     THURSDAY,
    //     FRIDAY,
    //     SATURAY,
    //     SUNDAY
    // };

    // for(enum DAYS day = MONDAY; day <= SUNDAY; day++){
    //     if(day == WEDNESAY) continue;
    //     printf("Its not Wednesday!!\n");
    // }

    // time_t t;
    // srand((unsigned) time(&t));
    // int randNum = rand() % 21;

    // int counter = 0;
    // int guessNum;
    // while(counter < COUNT){
    //     printf("Tries remaining - %d\n", COUNT - counter);
    //     printf("Guess the number -> ");
    //     scanf("%i", &guessNum);

    //     if(guessNum < randNum){
    //         printf("%d is not the answer! Answer is greater than %d\n\n", guessNum, guessNum);
    //     }

    //     if(guessNum > randNum){
    //         printf("%d is not the answer! Answer is less than %d\n\n", guessNum, guessNum);
    //     }

    //     if(guessNum == randNum){
    //         printf("Yes! %d is the answer\n", guessNum);
    //         break;
    //     }

    //     counter++;
    // }

    // if(guessNum != randNum){
    //     printf("Sorry Guesses were wrong! The correct number was -> %d\n\n", randNum);
    // }

    // printf("Max of two entered numbers are -> %d\n", MAX(atoi(argv[1]), atoi(argv[2])));

    enum MONTHS
    {
        JAN,
        FEB,
        MAR,
        APR,
        MAY,
        JUN,
        JUL,
        AUG,
        SEP,
        OCT,
        NOV,
        DEC
    };

    // int arr[MONTH];

    // for(enum MONTHS month = JAN; month <= DEC; month++){
    //     int days;
    //     printf("Enter the number of days in %d Month -> ", month+1);
    //     scanf("%i", &days);
    //     arr[month] = days;
    // }

    // printf("\n");

    // for(enum MONTHS month = JAN; month <= DEC; month++){
    //     switch(month){
    //         case JAN:
    //             printf("Number of Days in Jan -> %d\n", arr[month]);
    //             break;

    //         case FEB:
    //             printf("Number of Days in Feb -> %d\n", arr[month]);
    //             break;

    //         case MAR:
    //             printf("Number of Days in Mar -> %d\n", arr[month]);
    //             break;

    //         case APR:
    //             printf("Number of Days in Apr -> %d\n", arr[month]);
    //             break;

    //         case MAY:
    //             printf("Number of Days in May -> %d\n", arr[month]);
    //             break;

    //         case JUN:
    //             printf("Number of Days in Jun -> %d\n", arr[month]);
    //             break;

    //         case JUL:
    //             printf("Number of Days in Jul -> %d\n", arr[month]);
    //             break;

    //         case AUG:
    //             printf("Number of Days in Aug -> %d\n", arr[month]);
    //             break;

    //         case SEP:
    //             printf("Number of Days in Sep -> %d\n", arr[month]);
    //             break;

    //         case OCT:
    //             printf("Number of Days in Oct -> %d\n", arr[month]);
    //             break;

    //         case NOV:
    //             printf("Number of Days in Nov -> %d\n", arr[month]);
    //             break;

    //         case DEC:
    //             printf("Number of Days in Dec -> %d\n", arr[month]);
    //             break;
    //     }
    // }

    // int arr[100];

    // arr[0] = 1;
    // arr[1] = 1;

    // for(int i = 2; i < 100; i++){
    //     int numToCheck = i+1;
    //     int x = 2;
    //     _Bool isPrime = 1;

    //     if(numToCheck % 2 == 0) continue;

    //     while(x != numToCheck){
    //         if(numToCheck % x == 0){
    //             isPrime = 0;
    //             break;
    //         }

    //         x++;
    //     }

    //     // for(int j = 2; j*j < numToCheck; j++){
    //     //     if(numToCheck % j == 0){
    //     //         isPrime = 0;
    //     //         break;
    //     //     }
    //     // }

    //     arr[i] = isPrime;
    // }

    // for(int i = 0; i < 100; i++){
    //     if(arr[i] == 1){
    //         printf("%d is Prime\n", i+1);
    //     }
    // }

    // float data[5][12] = {
    //     {7.3, 7.3, 4.9, 3.0, 2.3, 0.6, 1.2, 0.6, 0.5, 1.7, 6.7, 7.0},
    //     {7.3, 7.3, 2.2, 3.0, 2.3, 0.6, 1.2, 0.6, 0.5, 1.7, 6.7, 7.0},
    //     {0.9, 7.3, 4.9, 3.0, 2.3, 0.6, 1.2, 0.6, 0.5, 1.7, 6.7, 7.0},
    //     {7.3, 7.3, 4.9, 8.5, 2.3, 0.6, 1.2, 0.6, 0.5, 1.7, 6.7, 7.0},
    //     {7.3, 7.3, 4.9, 8.5, 2.3, 0.6, 1.2, 0.6, 0.5, 1.7, 9.5, 7.0}};

    // int yr = 2010;
    // int totalRain = 0;

    // printf("Year\t\tRainfall\n");
    // for (int i = 0; i < 5; i++)
    // {
    //     for (int j = 0; j < 12; j++)
    //     {
    //         totalRain += data[j][i];
    //     }

    //     printf("%d\t\t%d\n", yr++, totalRain);
    //     totalRain = 0;
    // }

    // printf("\n\nJAN\t\t\tFEB\t\t\tMAR\t\t\tAPR\t\t\tMAY\t\t\tJUN\t\t\tJUL\t\t\tAUG\t\t\tSEP\t\t\tOCT\t\t\tNOV\t\t\tDEC\n");
    // int monthlyAvg = 0;
    // for (int i = 0; i < 12; i++){
    //     for (int j = 0; j < 5; j++){
    //         monthlyAvg += data[j][i]; // ✅ CORRECT: [year][month]
    //     }
    //     printf("%.2f\t\t", (float)monthlyAvg / 5);
    //     monthlyAvg = 0;
    // }

    
    // int a,b;
    // printf("Enter Numbers -> ");
    // scanf("%d", &a);
    // scanf("%d", &b);

    // printf("GCD(%d, %d) = %d\n", a, b, gcd(a, b));

    int a = atoi(argv[1]);
    printf("Absolute Value of %d -> %d\n", a, absValue(a));
    printf("Sqrt of %d -> %f\n", a, sqrt(a));


    return 0;
}

float sqrt(int x){
    printf("My SQRT\n");
    float n = x;
    float y = 1;

    while(n - y > 1){
        n = (n+y)/2;
        y = x / n;
    }

    return n;
}

int absValue(int a){
    if(a > 0) return a;
    return ~a + 1;
}

int gcd(int a, int b){
    int result = -1;
    while((a % b) > 0){
        result = a % b;
        a = b;
        b = result;
    }

    return b;
}

int multiply(int a, int b){
    auto int result =  a * b;
    return result;
}