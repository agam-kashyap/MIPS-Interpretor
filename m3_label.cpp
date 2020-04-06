#include<bits/stdc++.h>
// #include <sstream>
#include <fstream>
using namespace std;
#define s string
#define pb push_back

map<string,string> reg={
  {"$0", "00000"},
  {"$zero", "00000"},
  {"$at", "00001"},
  {"$v0", "00010"},
  {"$v1", "00011"},
  {"$a0", "00100"},
  {"$a1", "00101"},
  {"$a2", "00110"},
  {"$a3", "00111"},
  {"$t0", "01000"},
  {"$t1", "01001"},
  {"$t2", "01010"},
  {"$t3", "01011"},
  {"$t4", "01100"},
  {"$t5", "01101"},
  {"$t6", "01110"},
  {"$t7", "01111"},
  {"$s0", "10000"},
  {"$s1", "10001"},
  {"$s2", "10010"},
  {"$s3", "10011"},
  {"$s4", "10100"},
  {"$s5", "10101"},
  {"$s6", "10110"},
  {"$s7", "10111"},
  {"$t8", "11000"},
  {"$t9", "11001"},
  {"$k0", "11010"},
  {"$k1", "11011"},
  {"$gp", "11100"},
  {"$sp", "11101"},
  {"$fp", "11110"},
  {"$ra", "11111"}
};

map<int,string> hex={
  {0,"0"},
  {1,"1"},
  {2,"2"},
  {3,"3"},
  {4,"4"},
  {5,"5"},
  {6,"6"},
  {7,"7"},
  {8,"8"},
  {9,"9"},
  {10,"a"},
  {11,"b"},
  {12,"c"},
  {13,"d"},
  {14,"e"},
  {15,"f"},
};

map<string,int> m;
vector<string> v;
vector<pair<int,string>> vj;
vector<pair<int,string>> vb;


vector<string> abt(string l)  //
{
  vector<string> l1;
  string st;
  int i=0;
  while(l[i]!='\0'){
    if(l[i]==':') l1.pb(":");
    if(l[i]!=' ' && l[i]!='\t' && l[i]!=',' && l[i]!='(' && l[i]!=')' && l[i]!=':') st+=l[i];
    else if(st.size() != 0){
      l1.pb(st);
      st="";
    }
    i++;
  }
  if(st.size() != 0) l1.pb(st);
  return l1;
}

string abt_i(string st,int sa)
{
  int immidiate=0,f=0;
  string im="";
  int n=0;
  if(sa == 0) n=16;
  else if(sa == 1) n=5;
  else n=32;
  if(st.size()>2 && st[1]=='x')
  {
    int i=st.size()-1;
    while(i>1)
    {
      string m="";
      int j;
      if(st[i]>='A') j=st[i]-'A'+10;
      else j=st[i]-'0';
      while(j/2 != 0){
      if(j%2 == 1) m='1'+m;
      else m='0'+m;
      j=j/2;
      }
      if(j%2 == 1) m='1'+m;
      for(int k=m.size();k<4;k++){
        m='0'+m;
      }
      im=m+im;
      i--;
    }
    for(int k=im.size();k<n;k++){
      im='0'+im;
    }
  }
  else
  {
    // stringstream g(st);
    // g>>immidiate;
    immidiate = stoi(st);
    if(immidiate<0){
      immidiate=immidiate*(-1);
      f=1;
    }
    while(immidiate/2 != 0){
      if(immidiate%2 == 1) im='1'+im;
      else im='0'+im;
      immidiate=immidiate/2;
    }
    if(immidiate%2 == 1) im='1'+im;
    for(int k=im.size();k<n;k++){
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
  }
  return im;
}

string bintohex(string st)
{
  string s1="";
  int i=0;
  while(st[i]!='\0')
  {
    int k=0;
    for(int j=0;j<4;j++)
    {
      k=k + (stoi(st.substr(i,1)) * pow(2,3-j));
      i++;
    }
    string temp=::hex[k];
    s1+=temp;
  }
  return s1;
}

string lower(string st)
{
  for(int i=0;i<st.size();i++)
  {
    st[i] = tolower(st[i]);
  }
  return st;
}

int main()
{
  string line;
  ifstream myfile ("test2.asm");

  if (myfile.is_open())
  {
    int pc = 0;
    while(getline(myfile,line))
    {
      string ans = "";
      vector<string> l=abt(line);

      int index=0;

      if(l.size() == 0 || l[0][0]=='#') continue;

      else if(l[0] == ":"){
        m.insert({l[1],pc});
        l.erase(l.begin());
        l.erase(l.begin());
      }

      if(l.size() == 0) continue;

      // arithmetic start
      else if(lower(l[0]) == "add"){
        ans = "000000"+reg[l[2]]+reg[l[3]]+reg[l[1]]+"00000100000"; //
      }

      else if(lower(l[0]) == "addi"){
        ans += "001000"+reg[l[2]]+reg[l[1]]+abt_i(l[3],0); //
      }

      else if(lower(l[0]) == "addiu"){
        ans += "001001"+reg[l[2]]+reg[l[1]]+abt_i(l[3],0); //
      }

      else if(lower(l[0]) == "addu"){
        ans += "000000"+reg[l[2]]+reg[l[3]]+reg[l[1]]+"00000100001"; //
      }

      else if(lower(l[0]) == "and"){
        ans += "000000"+reg[l[2]]+reg[l[3]]+reg[l[1]]+"00000100100";
      }

      else if(lower(l[0]) == "andi"){
        ans += "001100"+reg[l[2]]+reg[l[1]]+abt_i(l[3],0);
      }

      else if(lower(l[0]) == "lui"){////
        ans += "001111"+reg[l[1]]+abt_i(l[2],0);
      }

      else if(lower(l[0]) == "nor"){
        ans += "000000"+reg[l[2]]+reg[l[3]]+reg[l[1]]+"00000100111";
      }

      else if(lower(l[0]) == "or"){
        ans += "000000"+reg[l[2]]+reg[l[3]]+reg[l[1]]+"00000100101";
      }

      else if(lower(l[0]) == "ori"){
        ans += "001101"+reg[l[2]]+reg[l[1]]+abt_i(l[3],0);
      }

      else if(lower(l[0]) == "slt"){
        ans += "000000"+reg[l[2]]+reg[l[3]]+reg[l[1]]+"00000101010";
      }

      else if(lower(l[0]) == "slti"){
        ans += "001010"+reg[l[2]]+reg[l[1]]+abt_i(l[3],0);
      }

      else if(lower(l[0]) == "sltiu"){
        ans += "001011"+reg[l[2]]+reg[l[1]]+abt_i(l[3],0);
      }

      else if(lower(l[0]) == "sltu"){
        ans += "000000"+reg[l[2]]+reg[l[3]]+reg[l[1]]+"00000101011";
      }

      else if(lower(l[0]) == "sub"){
        ans += "000000"+reg[l[2]]+reg[l[3]]+reg[l[1]]+"00000100010";
      }

      else if(lower(l[0]) == "subu"){
        ans += "000000"+reg[l[2]]+reg[l[3]]+reg[l[1]]+"00000100011";
      }

      else if(lower(l[0]) == "xor"){
        ans += "000000"+reg[l[2]]+reg[l[3]]+reg[l[1]]+"00000100110";
      }

      else if(lower(l[0]) == "xori"){
        ans += "001110"+reg[l[2]]+reg[l[1]]+abt_i(l[3],0);
      }
      //arithmetic end

      //multiply start 
      else if(lower(l[0]) == "div"){
        ans += "000000"+reg[l[1]]+reg[l[2]]+"0000000000011010";
      }

      else if(lower(l[0]) == "divu"){
        ans += "000000"+reg[l[1]]+reg[l[2]]+"0000000000011011";
      }

      else if(lower(l[0]) == "mfhi"){
        ans += "0000000000000000"+reg[l[1]]+"00000010000";
      }

      else if(lower(l[0]) == "mflo"){
        ans += "0000000000000000"+reg[l[1]]+"00000010010";
      }

      else if(lower(l[0]) == "mthi"){
        ans += "000000"+reg[l[1]]+"000000000000000010001";
      }

      else if(lower(l[0]) == "mtlo"){
        ans += "000000"+reg[l[1]]+"000000000000000010011";
      }

      else if(lower(l[0]) == "mult"){
        ans += "000000"+reg[l[1]]+reg[l[2]]+"0000000000011000";
      }

      else if(lower(l[0]) == "multu"){
        ans += "000000"+reg[l[1]]+reg[l[2]]+"0000000000011001";
      }
      //multiply end

      //shifter start
      else if(lower(l[0]) == "sll"){
        ans += "00000000000" + reg[l[2]] + reg[l[1]] + abt_i(l[3],1) + "000000";
      }

      else if(lower(l[0]) == "sllv"){
        ans += "000000" + reg[l[3]] + reg[l[2]] + reg[l[1]] + "00000000100";
      }

      else if(lower(l[0]) == "sra"){
        ans += "00000000000" + reg[l[2]] + reg[l[1]] + abt_i(l[3],1)+ "000011";
      }

      else if(lower(l[0]) == "srav"){
        ans += "000000" + reg[l[3]] + reg[l[2]] + reg[l[1]] + "00000000111";
      }

      else if(lower(l[0]) == "srlv"){
        ans += "000000" + reg[l[3]] + reg[l[2]] + reg[l[1]] + "00000000110";
      }

      else if(lower(l[0]) == "srl"){
        ans += "000000" + reg[l[2]] + reg[l[1]] + abt_i(l[3],1) + "000010";
      }
      //shifter end

      //Branch start
      else if(lower(l[0]) == "beq"){
        ans += "000100"+reg[l[1]]+reg[l[2]];//+abt_i(l[3],0);
        // ans += "000100"+reg[l[1]]+reg[l[2]];
        vb.pb({pc,l[3]});
      }

      else if(lower(l[0]) == "bgez"){
        ans += "000001"+reg[l[1]]+"00001";//+abt_i(l[2],0);
        vb.pb({pc,l[3]});
      }

      else if(lower(l[0]) == "bgezal"){
        ans += "000001"+reg[l[1]]+"10001";//+abt_i(l[2],0);
        vb.pb({pc,l[2]});
      }

      else if(lower(l[0]) == "bgtz"){
        ans += "000111"+reg[l[1]]+"00000";//+abt_i(l[2],0);
        vb.pb({pc,l[2]});
      }

      else if(lower(l[0]) == "blez"){
        ans += "000110"+reg[l[1]]+"00000";//+abt_i(l[2],0);
        vb.pb({pc,l[2]});
      }

      else if(lower(l[0]) == "bltz"){
        ans += "000001"+reg[l[1]]+"00000";//+abt_i(l[2],0);
        vb.pb({pc,l[2]});
      }

      else if(lower(l[0]) == "bltzal"){
        ans += "000001"+reg[l[1]]+"10000";//+abt_i(l[2],0);
        vb.pb({pc,l[2]});
      }

      else if(lower(l[0]) == "bne")
      {
        ans += "000101"+reg[l[1]]+reg[l[2]];//+abt_i(l[3],0);
        vb.pb({pc,l[3]});
        // index += 4;
        // ans += abt_i(line,index,1);
      }
      // /*Jump, Break,*/
      // //Branch end
      
      //Memory access start
      else if(lower(l[0]) == "lb"){
        ans="100000"+reg[l[3]]+reg[l[1]]+abt_i(l[2],0);
      }

      else if(lower(l[0]) == "lbu"){
        ans="100100"+reg[l[3]]+reg[l[1]]+abt_i(l[2],0);
      }

      else if(lower(l[0]) == "lh"){
        ans="100001"+reg[l[3]]+reg[l[1]]+abt_i(l[2],0);
      }

      else if(lower(l[0]) == "lhu"){
        ans="100101"+reg[l[3]]+reg[l[1]]+abt_i(l[2],0);
      }

      else if(lower(l[0]) == "lw"){
        ans="100011"+reg[l[3]]+reg[l[1]]+abt_i(l[2],0);
      }

      else if(lower(l[0]) == "sb"){
        ans="10q000"+reg[l[3]]+reg[l[1]]+abt_i(l[2],0);
      }

      else if(lower(l[0]) == "sh"){
        ans="101001"+reg[l[3]]+reg[l[1]]+abt_i(l[2],0);
      }

      else if(lower(l[0]) == "sw"){
        ans="101011"+reg[l[3]]+reg[l[1]]+abt_i(l[2],0);
      }
      //Memory access end

      else if(lower(l[0]) == "jr"){
        ans="000000"+reg[l[1]]+"000000000000000001000";
      }

      else if(lower(l[0]) == "mfco"){
        ans="01000000000"+reg[l[1]]+reg[l[2]]+"00000000000";
      }

      else if(lower(l[0]) == "mtco"){
        ans="01000000100"+reg[l[1]]+reg[l[2]]+"00000000000";
      }

      else if(lower(l[0]) == "syscall"){
        ans="00000000000000000000000000001100";
      }



      else if(lower(l[0]) == "lwl"){
        ans += "100010" + reg[l[3]] + reg[l[1]] + abt_i(l[2],0); 
      }

      else if(lower(l[0]) == "bal"){
        ans += "0000010000010001" + abt_i(l[1],0);
      }

      else if(lower(l[0]) == "b"){
        ans += "0001000000000000" + abt_i(l[0],0);
      }

      else if(lower(l[0]) == "mul"){
        ans += "011100" + reg[l[2]] + reg[l[2]] + reg[l[1]] + "00000000010";
      }

      else if(lower(l[0]) == "msubu"){
        ans += "011100" + reg[l[1]] + reg[l[2]] + "0000000000000101";
      }

      else if(lower(l[0]) == "msub"){
        ans += "011100" + reg[l[1]] + reg[l[2]] + "0000000000000100";
      }

      else if(lower(l[0]) == "maddu"){
        ans += "011100" + reg[l[1]] + reg[l[2]] + "0000000000000001";
      }

      else if(lower(l[0]) == "madd"){
        ans += "011100" + reg[l[1]] + reg[l[2]] + "0000000000000000";
      }

      else if(lower(l[0]) == "swr"){
        ans += "101110" + reg[l[3]] + reg[l[1]] + abt_i(l[2],0);
      }

      else if(lower(l[0]) == "swl"){
        ans += "101010" + reg[l[3]] + reg[l[1]] + abt_i(l[2],0);
      }

      else if(lower(l[0]) == "bgt"){
        string aw = "";
      }

      else if(lower(l[0]) == "clo"){
        ans = "011100" + reg[l[2]] + "00000" + reg[l[1]] +"00000100001";
      }

      else if(lower(l[0]) == "clz"){
        ans = "011100" + reg[l[2]] + "00000" + reg[l[1]] +"00000100000";
      }

      else if(lower(l[0]) == "nop"){
        ans += "00000000000000000000000000000000";
      }

      else if(lower(l[0]) == "moven"){
        ans += "000000" + reg[l[3]] + reg[l[1]] + reg[l[2]] + "00000001011";
      }

      else if(lower(l[0]) == "movz"){
        ans += "000000" + reg[l[3]] + reg[l[1]] + reg[l[2]] + "00000001010";
      }

      else if(lower(l[0]) == "lwr"){
        ans += "100110" + reg[l[3]] + reg[l[1]] + abt_i(l[2],0);
      }

      else if(lower(l[0]) == "move"){
        ans = "000000"+reg[l[2]]+reg["$0"]+reg[l[1]]+"00000100000";
      }

      // else if(l[0]=="j"){
      //   ans="000010"+abt_i(l[1],2);
      // }
      // else if(l[0]=="jal"){
      //   ans="000011"+abt_i(l[1],2);
      // }



      else if(lower(l[0]) == "j"){
      	ans="000010";
      	vj.pb({pc,l[1]});
      }

      else if(lower(l[0]) == "jal"){
      	ans="000011";
      	vj.pb({pc,l[1]});
      }
      // // check for jalr

      v.pb(ans);
      pc++;
    }

    for(int i=0;i<vb.size();i++)
    {
      int j=vb[i].first;
      int k=m[vb[i].second];
      v[j] += abt_i(to_string(k-j-1),0);
    }

    for(int i=0;i<vj.size();i++)
    {
      int j=vj[i].first;
      int k=m[vj[i].second];
      // v[j] += abt_i(to_string(k-j-1),2);
      string st = abt_i(to_string(4*pow(16,5) + 4*(k)),2);
      v[j] += st.substr(4,26);
    }

    // for(int i=0;i<v.size();i++)
    //   cout<<bintohex(v[i])<<endl;

    ofstream ouroutput("output.txt");
    if( ouroutput.is_open())
    {
      for(int i=0;i<v.size();i++)
      {
        cout<<bintohex(v[i])<<endl;
        ouroutput << bintohex(v[i]) << endl;
      }
    }
  }
  else
  {
    cout << "Unable to open file";
  }  

  return 0;

}