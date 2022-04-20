#include "iostream"
#include "math.h"

float mile_to_kilomter(float mile_count){
    float kilometer_count = mile_count * 1.60934f;
    return kilometer_count;
}


int main()
{
    std::cout << "Bitte geben sie die Menge an Meilen an, die Sie in Kilometer umrechnen wollen: \n";
    float mile_count_unprocessed;
    std::cin >> mile_count_unprocessed;
    float mile_count_squared = mile_count_unprocessed*mile_count_unprocessed;
    float mile_count = sqrt(mile_count_squared);
    std::cout << mile_to_kilomter(mile_count);

    return 0;
}
