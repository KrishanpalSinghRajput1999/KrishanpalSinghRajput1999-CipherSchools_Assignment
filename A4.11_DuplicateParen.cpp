#include<iostream>
#include<stack>
using namespace std;
bool hasDuplicateParentheses(string str) {
   stack<char> stk;
   for (int i = 0; i<str.length(); i++) {
      char ch = str[i];
      if (ch == ')') {
         char top = stk.top();
         stk.pop();
         int count = 0;
         while (top != '(') {
            count++;
            top = stk.top();
            stk.pop();
         }
         if(count < 1) {
            return true;
         }
      }
      else
         stk.push(ch);
   }
   return false;
}
int main() {
   string str = "(5+((7-3)))";
   if (hasDuplicateParentheses(str))
      cout << "Duplicate parentheses has Found";
   else
      cout << "No Duplicates parentheses has Found ";
}
