//Include statements 
#include <iostream> 
#include <string> 
using namespace std;

/*Creating factorial for loop for n.
It will take every number up to and including the input value and multiply them together to
find the factorial value.*/
double fact(double n)
{
    double factorial = 1.0;
    for(double i=1.0; i<=n; i++){
        factorial = i*factorial;
    }
    return factorial;

}

int main()
{

    double n, r, combinations;

    //Gathering information for variables n and r. n is the total number of pople, r is the number of groups.
    cout << "Input number for n: " << '\n';
    cin >> n;
    cout << "Input number for r: " << '\n';
    cin >> r;

    //Combinations takes the values input for n and r and puts them into the equation n!/(r!*(n-r)!)
    combinations = fact(n) / (fact(n-r)*fact(r));

//Outputting total number of possible combinations
    cout << "Total number of combinations: " << combinations << endl;

return 0;
}
