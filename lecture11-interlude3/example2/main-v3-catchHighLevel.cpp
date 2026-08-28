#include <iostream>
#include <string>

using namespace std;

void encodeChar(int i, string &str)
{
  int base = static_cast<int>('a');
  if (isupper(str[i]))
    base=int('A');

  char newChar = (static_cast<int>(str[i]-base+3))%26+base;
  str.replace(i, 1, 1, newChar);

}

void encodeString(int numChar, string &str)
{
  try
    {
      for (int j=numChar -1; j>=0; j--)
	encodeChar(j, str);
    }
  catch (out_of_range e)
    {
      cout << "The string does not contain " << numChar;
      cout << " characters.\n";
      cout << e.what() << endl;
    }

}
    

int main()
{
  string str1 = "Sarah";
  encodeString(100, str1);
  cout << str1 << endl;
  return 0;
}
