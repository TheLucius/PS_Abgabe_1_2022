#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>

int gcd(int a, int b){
    int sol;
    int temp;
    if(a<=b){
        temp = a;
    } else{
        temp = b;
    }

    for (int x=1; x<=temp; x++){
        if(a % x ==0){
            if (b % x == 0){
                sol = x;
            }
        }
    }
    return sol;

}

unsigned int checksum (int a){                  //checksum function
    unsigned int sum;
    std::string splitted = std::to_string(a);       //split input into string
    for (unsigned int x = 0; x<splitted.length();x++){  //iterate over string
        sum += splitted[x] - '0';                             //added all single charachters
    }
    return sum;
}

unsigned int sum_multiplies(unsigned int limit){    //sum mult function
    unsigned int sum=0;
    for(int x=0; x<=limit; x++){                    //count up to limit
        if (x % 3 == 0) {                           //check if divideable by 3
            sum = x + sum;
        }
        else if(x % 5 == 0){                        //check if divedable by 5
            sum = x + sum;
        }
    }
    return sum;
}

float fract (float a){
    float frac = a - int(a);    //calculate the fraction by subtracting an int cast
    return frac;
}

float vol_cylinders (float h, float r){
    float g = M_PI * r * r;     //formula for calculating ground area
    float vol = g * h;          //formula for volume
    return vol;
}

TEST_CASE("calc_vol_cylinder", "[vol]")
{
    REQUIRE(vol_cylinders(2.0f,1.0f)==Approx(2*M_PI));
    REQUIRE(vol_cylinders(200.0f,13.7f)==Approx(117929.11f));
    REQUIRE(vol_cylinders(99.0f,0.5f)==Approx(77.75442f));
}


TEST_CASE("ret_frac", "[frac]")
{
    REQUIRE(fract(2.24f)==Approx(0.24f));
    REQUIRE(fract(0.01f)==Approx(0.01f));
    REQUIRE(fract(-1.12f)==Approx(-0.12f));
}


TEST_CASE("calc_gcd", "[gcd]")
{
    REQUIRE(gcd(2,4)== 2);
    REQUIRE(gcd(6,9)== 3);
    REQUIRE(gcd(3,7)== 1);

}

TEST_CASE("calc_checksum", "[cs]")
{
    REQUIRE(checksum(123) == 6);
    REQUIRE(checksum(121808) == 20);
    //REQUIRE(checksum(-120) == 1);
}

TEST_CASE("calc_sum_of_multiplies", "[summult]")
{
    REQUIRE(sum_multiplies(10)==33);
    REQUIRE(sum_multiplies(20)==98);
    REQUIRE(sum_multiplies(1000)==234168);
    //REQUIRE(sum_multiplies(-1)==1);
}



int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}

