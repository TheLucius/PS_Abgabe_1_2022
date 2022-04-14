#include <iostream>

int one_to_twenty(){
    for (int i = 21; i>20; i++){
        for (int x = 20; x < 21; x--) {
            if (i % x != 0){
                break;
            } else
            {
                if (x == 2){
                    return i;
                }
            }
        }
    }
}


int main()
{
  std::cout << "Hello, Anton!\n";
  std::cout << one_to_twenty();
  return 0;
}
