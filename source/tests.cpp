#define CATCH_CONFIG_RUNNER
#include <catch.hpp>

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

