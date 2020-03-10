//Write your code here
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cstdio>
#include<cctype>
using namespace std;

void upper(string &a,int N){
    for(int i=0;i<N;i++){
        a[i]=toupper(a[i]);
    }
}

int main(){
     vector <string> nameStudent;
     vector <string> nameStudent_Capital;
     vector <int> scoreStudent;
     vector <string> gradeStudent;
     ifstream myfile("D:\\lab17\\lab17-2562-2-theeramet0793\\name_score.txt");
     string mystring;
     
     while(getline(myfile,mystring)){
         int a,b,c;
         char name[100];
         sscanf(mystring.c_str(),"%[^:]: %d %d %d",name,&a,&b,&c);
         nameStudent.push_back(name);
        for(int i=0;i<sizeof(name);i++){
             name[i]=toupper(name[i]);
         }
         nameStudent_Capital.push_back(name);
         int total=a+b+c;
         scoreStudent.push_back(a+b+c);
         string grade= (total>=80)?"A":(total>=70)?"B":(total>=60)?"C":(total>=50)?"D":"F";
         gradeStudent.push_back(grade);
          
     }
    

    
  while(true){
      string s;
      int have_grade=0;
      cout<<"Please input your command: ";
      getline(cin,s);
      cout<<"--------------------------------------\n";
      int idx=s.find_first_of(" ");
      string s1= s.substr(0,idx);
      string s2= s.substr(idx+1,(s.size()-idx));

       upper(s1,s1.size());
       upper(s2,s2.size());
      

      if(s1.compare("NAME")==0){
          for(int i=0;i<nameStudent_Capital.size();i++){
              if((nameStudent_Capital[i]==s2)){
                  cout<<nameStudent[i]<<"'s grade = "<<gradeStudent[i]<<endl;
                  cout<<"--------------------------------------\n";
                  break;
              }else if(i==nameStudent_Capital.size()-1){
                  cout<<"Cannot found\n";
                  cout<<"--------------------------------------\n";
              }
              
          }
      } 
      else if(s1.compare("GRADE")==0){
       for(int i=0;i<gradeStudent.size();i++){
           if((gradeStudent[i]==s2)){
                  cout<<nameStudent[i]<<endl;
                  have_grade+=1;
              }
         }cout<<"--------------------------------------\n";
         if(have_grade==0){
             cout<<"Cannot found\n";
             cout<<"--------------------------------------\n";
         }
      }
      else if(s1.compare("EXIT")==0){
       break;
      }
      else
      {
       cout<<"Invalid command\n";
      }
      
  }

    myfile.close();
   return 0; 
}
