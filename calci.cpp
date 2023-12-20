

# include <iostream>
using namespace std;

int main() {

  char op;
  float num1, num2;


  cout << "Enter first number: ";
  cin >> num1 ; 
  cout << "Enter second number: ";
  cin >> num2;

  cout << "Enter operator: add(+), subtract(-), multiply(*), divide(/): ";
  cin >> op;


  switch(op) {

    case 'add(+)':
      cout << num1 << " + " << num2 << " = " << num1 + num2;
      break;

    case 'subtract(-)':
      cout << num1 << " - " << num2 << " = " << num1 - num2;
      break;

    case 'multiply(*)':
      cout << num1 << " * " << num2 << " = " << num1 * num2;
      break;

    case 'divide(/)':
      cout << num1 << " / " << num2 << " = " << num1 / num2;
      break;

    default:
      // If the operator is other than +, -, * or /, error message is shown
      cout << "Error! operator is not correct";
      break;
  }

  return 0;
}
















