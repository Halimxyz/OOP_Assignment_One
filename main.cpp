#include <bits/stdc++.h>
using namespace std;

class BigDecimalInt{
    string strBigInt;
public:
                // constructors
  BigDecimalInt();             
  BigDecimalInt (string decStr);
  BigDecimalInt (int decInt);

               /*** Operator Overloading ***/
  BigDecimalInt operator+ (BigDecimalInt anotherDec);
  BigDecimalInt operator- (BigDecimalInt anotherDec);  
  bool operator< (BigDecimalInt anotherDec); 
  bool operator==(BigDecimalInt anotherDec); 
  BigDecimalInt operator= (BigDecimalInt anotherDec); 
  
  int size(); 
  int sign(); 
  friend ostream& operator << (ostream& out, BigDecimalInt& ob);

};


/*  __________ implementaion ________*/ 
 BigDecimalInt :: BigDecimalInt(){
  strBigInt = "" ;
}

BigDecimalInt :: BigDecimalInt (int decInt){
    num = decInt ;  
} 

BigDecimalInt :: BigDecimalInt (string decStr)
{ 
    regex filter("(-?|\\+)[0-9]+");

    if(regex_match(decStr , filter)){
      strBigInt = decStr ;
      if(strBigInt[0] == '+'){strBigInt.erase(strBigInt.begin());}
    } 
    else{
      cout << "try valid num "  << endl ;
    }

}

// operator +
BigDecimalInt BigDecimalInt ::  operator+ (BigDecimalInt anotherDec )
{
  BigDecimalInt temp ;
  string str1 = strBigInt , res =  "" ;
  string str2 = anotherDec.strBigInt ;
  
        // str2 should be larger than str1 
  if(str1.length() > str2.length()){
    swap(str1 , str2) ;
  }
  
  int len1 = str1.size() , len2 = str2.size() ;
  int diff = len2 - len1 ;
  str1.insert(str1.begin(), diff , ' ' );

  int carry = 0 , i = len2 - 1 ;
  while (len1--)
  {
    int sum = (str2[i]-'0') + (str1[i]-'0') + carry ;
      res.push_back(sum % 10 + '0') ;
      carry = sum / 10 ;
      i-- ;
  }
  while (i >= 0)
  {
    int sum = (str2[i]-'0') + carry ;
      res.push_back(sum % 10 + '0') ;
      carry = sum / 10 ;
      i-- ;
  }
  
  if(carry){
    res.push_back(carry + '0');
  }

   reverse(res.begin(),res.end());
   temp.strBigInt = res ;
   return temp ; 
   
}

// Operator -
    // Operator -
    BigDecimalInt operator-(BigDecimalInt anotherDec)
    {
        if (strBigInt < anotherDec.strBigInt)
        {
            swap(strBigInt, anotherDec.strBigInt);
        }
        BigDecimalInt result;
        int carry = 0, diff = strBigInt.size() - anotherDec.strBigInt.size();
        // sub. the digits from right (H2H).
        for (int i = anotherDec.strBigInt.size() - 1; i >= 0; i--)
        {
            int step = ((strBigInt[i + diff] - '0') - (anotherDec.strBigInt[i] - '0') - carry);
            if (step < 0)
            { // There will be a carry
                step += 10;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            result.strBigInt += (step + '0');
        } // sub. the remining from bigger string (ALONE).
        for (int i = diff - 1; i >= 0; i--)
        {
            if (strBigInt[i] == '0' && carry != 0)
            {
                result.strBigInt += '9';
                continue;
            }
            int step = ((strBigInt[i] - '0') - carry);
            if (i > 0 || step > 0)
            {
                result.strBigInt += step + '0';
            }
            carry = 0;
        }
        reverse(result.strBigInt.begin(), result.strBigInt.end());
        return result;
    }

    // Operator <
    bool operator<(BigDecimalInt n2){
        // +    +
        if ((strBigInt[0]=='+' || isdigit(strBigInt[0])) && (n2.strBigInt[0]=='+'  || isdigit(n2.strBigInt[0]))){
            if (strBigInt.size() < n2.strBigInt.size()){
                return true;
            }
            else if (strBigInt.size()==n2.strBigInt.size()){
                for (int i=0; i<strBigInt.size(); i++){
                    if (strBigInt[i] < n2.strBigInt[i]){
                        return true;
                    }
                }
            }
        }
        //  -   -
        else if (strBigInt[0]=='-' && n2.strBigInt[0]=='-'){
            if (strBigInt.length() > n2.strBigInt.length()){
                return true;
            }
            else if (strBigInt.length()==n2.strBigInt.length()){
                for (int i=1; i<strBigInt.size(); i++){
                    if (strBigInt[i] < n2.strBigInt[i]){
                        return true;
                    }
                }
            }
        }
        //  -   +
        else if (strBigInt[0]=='-' && (n2.strBigInt[0]=='+'||isdigit(n2.strBigInt[0]))){
            return true;
        }
        //  +   - and opposite conditions
        else {
            return false;
        }
    }
    void print_value(){
        cout << "YES less" << endl;
    }
};


BigDecimalInt BigDecimalInt ::  operator= (BigDecimalInt anotherDec )
{
  BigDecimalInt temp ;
  strBigInt = anotherDec.strBigInt ; 
  return temp ;
}

ostream & operator <<(ostream & out , BigDecimalInt& ob)
 {
  out << ob.strBigInt << endl ;
  return out ;
 }





int main()
{
    //string num1("123456789012345678901234567890"), num2("113456789011345678901134567890"), num3("-200000000000000000000000000000"), num5="", num4="",temp="";
    BigDecimalInt num1("-100000000000000000000000000000");
    BigDecimalInt num2("-113456789011345678901134567890");
//    BigDecimalInt num3 = num1 - num2;
//    num3.print_value();
    if (num1 < num2){
        cout << "True";
    }else {cout << "False";}
    //236913578023691357802369135780

    return 0;
}
