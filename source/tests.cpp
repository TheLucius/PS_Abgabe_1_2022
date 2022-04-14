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

TEST_CASE("calc_gcd", "[gcd]")
{
    REQUIRE(gcd(2,4)== 2);
    REQUIRE(gcd(6,9)== 3);
    REQUIRE(gcd(3,7)== 1);

}



int main(int argc, char* argv[])
{
  return Catch::Session().run(argc, argv);
}

