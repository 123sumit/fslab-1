#include <iostream>
#include<fstream>
#define max 100
using namespace std;
class coseq
	{
	string list1[max],list2[max];
	int count1,count2;
	public:
		void load()
		{
			fstream fp1,fp2;
			string buf;
			count1=0;
			count2=0;
			fp1.open("/home/ise-075/workspace1/lab5/src/file1.txt");
			while(!fp1.eof())
				{
					buf.erase();
					getline(fp1,buf);
					list1[count1++]=buf;
					cout<<list1[count1-1]<<"  ";
				}
			fp1.close();
			cout<<endl;
			fp2.open("/home/ise-075/workspace1/lab5/src/file2.txt");
			while(!fp2.eof())
				{
					buf.erase();
					getline(fp2,buf);
					list2[count2++]=buf;
					cout<<list2[count2-1]<<"  ";
				}
			fp2.close();
			cout<<endl;
		}
		void match()
		{
			int i=0,j=0;
			cout<<"Common names are : ";
			while(i<=count1&&j<=count2)
				{
				if(list1[i]==list2[j])
					{
					cout<<list1[i]<<"  ";
					i++;
					j++;
					}
				if(list1[i]<list2[j])
					i++;
				if(list1[i]>list2[j])
					j++;
				}
			cout<<endl;
		}
	};
int main()
	{
		coseq C;
		C.load();
		C.match();
		return 0;
	}
