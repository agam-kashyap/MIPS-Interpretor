#include<bits/stdc++.h>
#include <sstream>
#include <fstream>
using namespace std;
#define s string
#define at "00001"
#define v0 "00010"
#define v1 "00011"
#define a0 "00100"
#define a1 "00101"
#define a2 "00110"
#define a3 "00111"
#define t0 "01000"
#define t1 "01001"
#define t2 "01010"
#define t3 "01011"
#define t4 "01100"
#define t5 "01101"
#define t6 "01110"
#define t7 "01111"
#define s0 "10000"
#define s1 "10001"
#define s2 "10010"
#define s3 "10011"
#define s4 "10100"
#define s5 "10101"
#define s6 "10110"
#define s7 "10111"
#define t8 "11000"
#define t9 "11001"
#define k0 "11010"
#define k1 "11011"
#define gp "11100"
#define sp "11101"
#define fp "11110"
#define ra "11111"

map<string,int> m;


string decode(string st)
{
	if(st=="$0") return "00000";
	else if(st=="$at") return s(at);
	else if(st=="$v0") return s(v0);
	else if(st=="$v1") return s(v1);
	else if(st=="$a0") return s(a0);
	else if(st=="$a1") return s(a1);
	else if(st=="$a2") return s(a2);
	else if(st=="$a3") return s(a3);
	else if(st=="$t0") return s(t0);
	else if(st=="$t1") return s(t1);
	else if(st=="$t2") return s(t2);
	else if(st=="$t3") return s(t3);
	else if(st=="$t4") return s(t4);
	else if(st=="$t5") return s(t5);
	else if(st=="$t6") return s(t6);
	else if(st=="$t7") return s(t7);
	else if(st=="$t8") return s(t8);
	else if(st=="$t9") return s(t9);
	else if(st=="$s0") return s(s0);
	else if(st=="$s1") return s(s1);
	else if(st=="$s2") return s(s2);
	else if(st=="$s3") return s(s3);
	else if(st=="$s4") return s(s4);
	else if(st=="$s5") return s(s5);
	else if(st=="$s6") return s(s6);
	else if(st=="$s7") return s(s7);
	else if(st=="$gp") return s(gp);
	else if(st=="$sp") return s(sp);
	else if(st=="$fp") return s(fp);
	else if(st=="$ra") return s(ra);
}

string abt(string l,int i)
{
	string st;
	while(l[i]!=' ' && l[i]!=':'){
		st+=l[i];
		i++;
	}
	return st;
}

string abt_r(string l, int i, int f)
{
	string st="",st1="";
	while(l[i]!='\0')
	{
		if(l[i]!=',')
			st1+=l[i];
		else
		{
			st+=decode(st1);
			st1="";
		}
		i++;
	}
	if(f==0)
	{
		st+=decode(st1);
		string st2="";
		for(int j=0;j<15;j++)
		{
			st2+=st[(j+5)%15];
		}		
		return st2;
	}
	else if(f==1)
	{
		string st2=decode(st1);
		for(int j=0;j<10;j++)
		{
			st2+=st[(j+5)%10];
		}
		return st2;
	}
	st+=decode(st1);
	return st;
}

string abt_i(string l,int i,int of)
{
	string st="",st1="",st2="";
	int j=0,f=0;
	while(l[i]!='\0')
	{
		if(l[i]!=',')
			st1+=l[i];
		else if(j<2)
		{
			st+=decode(st1);
			st1="";
			j++;
		}
		else if(l[i]!='-')
			st1+=l[i];
		else
			f=1;
		i++;
	}
	if(of!=1)
	{
		for(int k=0;k<10;k++)
		{
			st2+=st[(k+5)%10];
		}
	}
	int immidiate=0;
	if(of==1)
		immidiate=m[st1];
	else
	{
		stringstream g(st1);
		g>>immidiate;
	}
	string im="";
	while(immidiate/2 != 0){
		if(immidiate%2 == 1) im='1'+im;
		else im='0'+im;
		immidiate=immidiate/2;
	}
	if(immidiate%2 == 1) im='1'+im;
	// else im='0'+im;
	int p=(of==2)? 10:5;
	for(int k=im.size();k<p;j++){
		im='0'+im;
	}
	if(f==1)
	{
		for(int j=0;j<16;j++)
		{
			if(im[j]=='0') im[j]='1';
			else im[j]='0';
		}
		for(int j=15;j>=0;j--)
		{
			if(im[j]=='1') im[j]='0';
			else{
				im[j]='1';
				break;
			}
		}
	}
	return st2+im;	
}

string abt_b(string l, int i, string l1)
{
	string st="",st1="";
	int j=0;
	while(l[i]!='\0')
	{
		if(l[i]!=',')
			st1+=l[i];
		else if(j<1)
		{
			st+=decode(st1);
			st1="";
			j++;
		}
		i++;
	}
	int immidiate=0;
	stringstream g(st1);
	g>>immidiate;
	string im="";
	while(immidiate/2 != 0){
		if(immidiate%2 == 1) im='1'+im;
		else im='0'+im;
		immidiate=immidiate/2;
	}
	if(immidiate%2 == 1) im='1'+im;
	// else im='0'+im;
	for(int k=im.size();k<16;j++){
		im='0'+im;
	}
	return st+l1+im;
}

int main()
{
	  string line;
  ifstream myfile ("example.txt");

  if (myfile.is_open())
  {
    int pc = 0;
    while(getline(myfile,line))
    {
       string ans = "";


      string op = abt(line, 0);
      int index=0;

      //arithmetic start
      if(op == "add")
      {
        ans += "000000"; //
        index+=4;
        ans+=abt_r(line,index,0);
        ans+= "00000100000";

      }

      else if(op == "addi")
      {
        ans += "001000"; //
        index+=5;
        ans+=abt_i(line,index,0);

      }

      else if(op == "addiu")
      {
        ans += "001001"; //
        index+=6;
        ans+=abt_i(line,index,0);
      }

      else if(op == "addu")
      {
        ans += "000000"; //
        index+=5;
        ans+=abt_r(line,index,0);
        ans+= "00000100001";
      }

      else if(op == "and")
      {
        ans += "000000";
        index += 4;
        ans += abt_r(line, index,0);
        ans += "00000100100"; 
      }

      else if(op == "andi")
      {
        ans += "001100";
        index += 5;
        ans += abt_i(line,index,0);
      }

      else if(op == "lui")
      {
        ans += "001111";
        index += 4;
        ans += abt_i(line, index,0);
      }

      else if(op == "or")
      {
        ans += "000000";
        index += 3;
        ans += abt_r(line,index,0);
        ans += "00000100101";
      }

      else if(op == "ori")
      {
        ans += "001101";
        index += 4;
        ans += abt_i(line,index,0);
      }

      else if(op == "slt")
      {
        ans += "000000";
        index += 4;
        ans += abt_r(line,index,0);
        ans += "00000101010";
      }

      else if(op == "slti")
      {
        ans += "001010";
        index += 5;
        ans += abt_i(line, index,0);
      }

      else if(op == "sltiu")
      {
        ans += "001011";
        index += 6;
        ans += abt_i(line, index,0);
      }

      else if(op == "sltu")
      {
        ans += "000000";
        index += 5;
        ans += abt_r(line, index,0);
        ans += "00000101011"; 
      }

      else if(op == "sub")
      {
        ans += "000000";
        index += 4;
        ans += abt_r(line, index,0);
        ans += "00000100010";
      }

      else if(op == "subu")
      {
        ans += "000000";
        index += 4;
        ans += abt_r(line, index,0);
        ans += "00000100011";
      }

      else if(op == "xor")
      {
        ans += "000000";
        index += 4;
        ans += abt_r(line, index,0);
        ans += "00000100110";
      }

      else if(op == "xori")
      {
        ans += "001110";
        index += 5;
        ans += abt_i(line, index,0);
      }
      //arithmetic end

      //multiply start 
      else if(op == "div")
      {
        ans += "000000";
        index += 4;
        ans += abt_r(line, index,2);
        ans += "0000000000011010";
      }

      else if(op == "divu")
      {
        ans += "000000";
        index += 5;
        ans += abt_r(line, index,2);
        ans += "0000000000011011";
      }

      else if(op == "mfhi")
      {
        ans += "0000000000000000";
        index += 5;
        ans += abt_r(line, index,2);
        ans += "00000010000";
      }

      else if(op == "mflo")
      {
        ans += "0000000000000000";
        index += 5;
        ans += abt_r(line, index,2);
        ans += "00000010010";
      }

      else if(op == "mthi")
      {
        ans += "000000";
        index += 5;
        ans += abt_r(line,index,2);
        ans += "000000000000000010001";
      }

      else if(op == "mtlo")
      {
        ans += "000000";
        ans += abt_r(line,index,2);
        ans += "000000000000000010011";
      }

      else if(op == "mult")
      {
        ans += "000000";
        index += 5;
        ans += abt_r(line, index,2);
        ans += "0000000000011000";
      }

      else if(op == "multu")
      {
        ans += "000000";
        index += 6;
        ans += abt_r(line, index,2);
        ans += "0000000000011001";
      }
      //multiply end
      //shifter start
      else if(op == "sll")
      {
        ans += "000000"+ "00000" + reg[l[2]] + reg[l[1]] + abt_i(reg[l[3]],1) + "000000";
      }

      else if(op == "sllv")
      {
        ans += "000000" + reg[l[3]] + reg[l[2]] + reg[l[1]] + "00000000100";
      }

      else if(op == "sra")
      {
        ans += "00000000000" + reg[l[2]] + reg[l[1]] + abt_i(reg[l[3]],1)+ "000011";
      }

      else if(op == "srav")
      {
        ans += "000000" + reg[l[3]] + reg[l[2]] + reg[l[1]] + "00000000111";
      }

      else if(op == "srlv")
      {
        ans += "000000" + reg[l[3]] + reg[l[2]] + reg[l[1]] + "00000000110";
      }

      else if(op == "srl")
      {
        ans += "000000" + reg[l[2]] + reg[l[1]] + abt_i(reg[l[3]],1) + "000010";
      }      
      //shifter end

      //Branch start
      else if(op == "beq")
      {
        ans += "000100";
        index += 4;
        ans += abt_i(line, index,1);
      }
      //Need to think on how to go about this
      else if(op == "bgez")
      {
        ans += "000001";
        index += 5;
        ans += abt_b(line,index,"00001"); // Send the value of rt in the function itself and concatenate in between
      }
      else if(op == "bgezal")
      {
        ans += "000001";
        index += 7;
        ans += abt_b(line,index,"10001"); // Send the value of rt in the function itself and concatenate in between
      }
      else if(op == "bgtz")
      {
        ans += "000111";
        index += 5;
        ans += abt_b(line,index,"00000"); // Send the value of rt in the function itself and concatenate in between
      }
      else if(op == "blez")
      {
        ans += "000110";
        index += 5;
        ans += abt_b(line,index,"00000"); // Send the value of rt in the function itself and concatenate in between
      }
      else if(op == "bltz")
      {
        ans += "000001";
        index += 5;
        ans += abt_b(line,index,"00000"); // Send the value of rt in the function itself and concatenate in between
      }
      else if(op == "bltzal")
      {
        ans += "000001";
        index += 7;
        ans += abt_b(line,index,"10000"); // Send the value of rt in the function itself and concatenate in between
      }
      else if(op == "bne")
      {
        ans += "000101";
        index += 4;
        ans += abt_i(line,index,1);
      }
      /*Jump, Break, Coprocessor left*/
      //Branch end
      //Memory access start
      else if(op == "lb")
      {

      }
      else if(op == "lbu")
      {

      }
      else if (op == "lh")
      {

      }
      else if(op == "lhu")
      {

      }
      else if(op == "lw")
      {

      }
      else if (op == "sb")
      {

      }
      else if(op == "sh")
      {

      }
      else if(op == "sw")
      {

      }
      //Memory access end
      else
      {
        m[op] = pc; //counter for while loop
      }
      cout<<ans<<endl;

      pc++;
    }
  }
  else
  {
    cout << "Unable to open file";
  }  

  return 0;

}