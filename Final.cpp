#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<direct.h>
#include<fstream>
#include<STRING>
#include<algorithm>
#include<cstdlib>
#include <windows.h>
using namespace std;
void gotoxy (int x, int y)
{
    COORD coordinates;     
    coordinates.X = x;     
    coordinates.Y = y;     
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);       
}
void SentencePredictor(string inputstring,int choose);
int main();
class Node
{   public:
    string Data; 
    Node* next;
    Node()
    {
        Data="";
        next=NULL;
    }
    Node(string d,Node *a)
    {
        Data=d;
        next=a;
    }
};
class SLL
{
    public:
    int static count;
    int i=1;
    Node* head;
    SLL()
    {
        head=NULL;
    }
    Node *begin()
    {
        return head;
    }
    void AppendLast(string a)
    {
        if(head==NULL)
        {
            Node *n=new Node(a,NULL);
            head=n;
        }
        else
        {   
            Node *n=new Node(a,NULL);
            Node *curr;
            for (Node *p =begin(); p!=NULL; p=p->next)
            {
                curr=p;
            }
            curr->next=n;
            //n->next=NULL;
        }
    }
    void AppendFirst(string a)
    {
        if(head==NULL)
        {
            Node *n=new Node(a,NULL);
            head=n;
        }
        else
        {
            Node *n=new Node(a,begin());
            head=n;
        }
    }
    int Count()
    {
        for (Node *p =begin(); p!=NULL; p=p->next)
        {
            count++;
        }
        return(count);
    }
    void AppendMiddle(string a,int k)
    {
        Node *n=new Node(a,NULL);
        Node* temp;
        temp=head;
        for(int i=0;i<k-1;i++)
        {
            temp=temp->next;
        }
        Node *temp2;
        temp2=temp->next;       
        temp->next=n;
        n->next=temp2;
    }
    void DeleteFirst()
    {
        if(head==NULL)
        {
            cout<<"\nthere is no SLL";
        }
        else
        {
            Node*temp;
            temp=head;
            head=head->next;   
            delete temp;
        } 
    }
    void DeleteMiddle(int k)
    {
        Node *curr,*prev,*nextnode,*p=head;
        for(int i=1;i<=Count();i++)
        {
            if(i==k)
            {
                curr=p;
                break;
            }
            prev=p;
            p=p->next;
        }
        if(k==1)
        {
            DeleteFirst();
        }
        else if(curr->next==NULL)
        {
            DeleteLast();
        }
        else
        {
            prev->next=curr->next;
            delete curr;
        }
        

    }
    void DeleteLast()
    {
        if(head==NULL)
        {
            cout<<"\nType Again..";
            Sleep(2000);
        }
        else if(head->next==NULL)
        {
            DeleteFirst();
        }
        else
        {
            Node *curr,*prev;
            for(Node*p=begin();p!=NULL;p=p->next)
            {
                if(p->next->next==NULL)
                {
                    prev=p;
                    curr=p->next;
                    break;
                }
            }
            prev->next=NULL;
            delete curr;
        }
    }
    void print()
    {
        system("cls");
        gotoxy(41,1);
        cout<<"\nSearch: ";
        for (Node *p =begin(); p!=NULL; p=p->next)
        {
            cout<<p->Data<<" ";
        }
        // cout<<endl;
    }
    void EmptyLL()
    {
        if(begin()==NULL)
        {
            return;
        }
        else
        {
            for(Node *p =begin(); p!=NULL; p=p->next)
            {
                DeleteFirst();
            }
        }

    }
};
int SLL :: count =0;
int ElementInDic[9]={0};
string s[9];
int counter=0;
SLL lists[5];
int SentenceNumber[5]={-1,-1,-1,-1,-1};
char lower_alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
void ResetStrings()
{
    for(int i=0;i<9;i++)
    {
        s[i]="";
    }
    for(int i=0;i<5;i++)
    {
        lists[i].EmptyLL();
    }
}
int incorrectArrangement(string input)
{
	counter=0;
    string line;
    int found = 0;
    ifstream words ("engmix.txt");
    if (words)
    {
        while(getline(words,line))
        {
			counter++;
            string Xinput = input, Ninput, Tinput, Tline, Nline, Xline = line;
            int inputlength = Xinput.size(), linelength = line.size();
            if (inputlength == linelength)
            {
                for (int i=1; i<Xinput.length(); i++)//WHAT //HAT
                {
                    Ninput.push_back(input[i]);
                }
                for (int i = 1; i < linelength; i++)
                {
                    Nline.push_back(Xline[i]);
                }
                Xinput.resize(1);//W
                Xline.resize(1);
                sort(Nline.begin(),Nline.end());
                sort(Ninput.begin(), Ninput.end());//AHT 
                Tinput = Xinput + Ninput;
                Tline = Xline + Nline;
                if (Tinput == Tline)
                {
                    found = 1;
					ElementInDic[3]=counter;
					s[3]=line;
                    // cout<<line<<" "<<counter<<endl;
                    break;
                }
            }
        }
        words.close();
    }
    else
    {
        cout<<endl<<"Unexpected error occurred......."<<endl;
    }
    return found;
}

//function to show correct spelling if exchanged character is present in the given word
int exchangedCharacters (string input)
{
    // ResetStrings();
	counter=0;
    string line, Xinput;
    int found = 0;
    ifstream words ("engmix.txt");
    if (words)
    {
        while (getline(words,line))
        {
			counter++;
            int inputlength = input.size(), linelength = line.size();
            if (inputlength == linelength)
            {
                for (int i = 0; i <linelength ; i++)
                {
                    Xinput = input;
                    for (int j=0; j<26; j++)
                    {
                        Xinput[i] = lower_alpha[j];
                        if (Xinput == line)
                        {
                            found = 1;
							ElementInDic[4]=counter;
							s[4]=line;
                            // cout<<line<<" "<<counter<<endl;
                            break;
                        }
                    }
                    if (found == 1 ) 
                    {
                        break;
                    }
                    else 
                    {
                        continue;
                    }   
                }
            }
        }
        words.close();
    }
    else cout<<"\nUnexpected error occurred"<<endl;
    return found;
}
int extraCharacter (string input)
{
	counter=0;
    string Xinput, line, Ninput, Tinput;
    int found = 0;
    ifstream words ("engmix.txt");
    if (words)
    {
        while (getline(words,line))
        {
			counter++;
            int inputlength = input.size(), linelength = line.size();
            if ((inputlength-1) == linelength)
            {
                for (int i = 0; i < inputlength; i++)
                {
                    Xinput = input;
                    Xinput.erase(Xinput.begin()+i);
                    if (Xinput == line)
                    {
                        found=1;
						ElementInDic[0]=counter;
						s[0]=line;
                        // cout<<line<<" "<<counter<<endl;
                        break;
                    } 
                }
            }
        }
        words.close();
    }
    else
    {
        cout<<"\nUnexpected error occurred\n";
    }
    return found;
}
//function to show right spelling when given word has wrong extra character and right one is missing.
int mixedExtraMissing (string input)
{
	counter=0;
    string Xinput, line, Xline;
    int found = 0;
    ifstream words ("engmix.txt");
    if (words)
    {	
        while (getline(words,line))
        {
			counter++;
            int inputlength = input.size(), linelength = line.size();
            if (inputlength == linelength)
            {
                for (int i = 1; i < inputlength; i++)
                {
                    for (int j = 0; j < 26; j++)
                    {
                        Xinput = input; Xline = line;
                        Xinput.erase(Xinput.begin()+i);
                        Xinput.resize(inputlength, '0');
                        Xinput[inputlength-1] = lower_alpha[j];
                        sort(Xinput.begin()+1,Xinput.end());
                        sort(Xline.begin()+1,Xline.end());
                        if (Xinput == Xline)
                        {
                            found = 1;
							ElementInDic[2]=counter;
							s[2]=line;
                            // cout<<line<<" "<<counter<<endl;
                            break;
                        }
                    }
                    if (found == 1) 
                    {
                        break;
                    }
                }
                if (found == 1) 
                {   
                    break;
                }
            }
        }
        words.close();
    }
    return found;
}
int missingCharacter (string input)
{
	int counter=0;
    string Xinput, line, Tinput, Tline, Xline;
    int found = 0;
    ifstream words ("engmix.txt");
    if (words)
    {
        while (getline(words,line))
        {
			counter++;
            for (int i = 0; i < 26; i++)
            {
                int len = input.size(), flen = line.size();
                Xinput = input;
                Xline = line;
                Xinput.resize(len+1,'0');
                Xinput[len] = lower_alpha[i];
                len = Xinput.size();
                string Ninput, Nline;
                if (len == flen)
                {
                    for (int j = 1; j <len; j++)
                    {
                        Ninput.push_back(Xinput[j]);
                    }
                    for (int j = 1; j < flen; j++)
                    {
                        Nline.push_back(Xline[j]);
                    }
                    Xinput.resize(1);
                    Xline.resize(1);
                    sort(Nline.begin(),Nline.end());
                    sort(Ninput.begin(),Ninput.end());
                    Tinput = Xinput + Ninput;
                    Tline = Xline + Nline;
                    if (Tinput == Tline)
                    {
                        found = 1;
                        ElementInDic[1]=counter;
					    s[1]=line;
                        break;
                    }
                }
                if (found == 1)
                {
                    break;
                }
            }
            if (found == 1) 
            {
                break;
            }
        }
        words.close();
    }
    else
    {
        cout<<"\nUnexpected error occurred\n";
    }
    return found;
}
int countNumberofSentences=0;
int Frequency[100]={0};
void GetSentenceFreqs();
void IncSentenceFreq(int x);
int CountSentences();
void copyLL(SLL &list,SLL &l)
{
    for(Node*p=list.begin();p!=NULL;p=p->next)
    {
        l.AppendLast(p->Data);
    }
}
void SortFrequencyLL()
{
    GetSentenceFreqs();
    int a=0;
    for(int i=0;i<5;i++)
    {
        if(SentenceNumber[i]==-1)
        {
            continue;
        }
        for(int j=i+1;j<5;j++)
        {
            if(Frequency[SentenceNumber[i]]==0 && Frequency[SentenceNumber[j]]==0)
            {
                continue;
            }
            if(Frequency[SentenceNumber[i]] < Frequency[SentenceNumber[j]])
            {
                SLL temp;
                copyLL(lists[i],temp);
                lists[i].EmptyLL();
                copyLL(lists[j],lists[i]);
                lists[j].EmptyLL();
                copyLL(temp,lists[j]);
                temp.EmptyLL();
                int t;
                t=Frequency[i];
                Frequency[i]=Frequency[j];
                Frequency[j]=t;
                //break;
                int t2;
                t2=SentenceNumber[i];
                SentenceNumber[i]=SentenceNumber[j];
                SentenceNumber[j]=t2;
				//break;
            }
        }        
    }
}
int CountSentences()
{
    countNumberofSentences=0;
    ifstream in("SentencesFile.txt");
    string s;
    while(getline(in,s))
    {
       // cout<<"Y "<<s<<endl;
        countNumberofSentences++;
    }
    return countNumberofSentences;
    in.close();
}
void SentenceFrequency()
{
    int c1=0,c2=0;
    string sLine,tempstring="",s;
    char ch='0';
    ifstream read2("SentenceFrequencyFile.txt");
    while(ch != '\n')
    {
        read2.get(ch);
        if(ch>='a' && ch<='z' || ch==' ' ||ch=='?' || ch=='!' || ch=='.')
        {
            tempstring = tempstring + ch;
        }
    }
    tempstring.resize(tempstring.length()-1);
    //cout<<tempstring<<tempstring.length()<<endl;
    read2.close();
    //cout<<countNumberofSentences<<endl;
    int i=0;
    ch='0';
    ifstream read1("SentencesFile.txt");
    while(getline(read1,sLine))
    {
        int j=0;
        string temp;
        while(j<=sLine.length())
        {
            if(sLine[j]>='a' && sLine[j]<='z' || sLine[j]==' ' ||sLine[j]=='?' || sLine[j]=='!' || sLine[j]=='.')
            {
                temp=temp+sLine[j];
            }
            j++;
        }
        //cout<<temp<<temp.length()<<endl;
        if(temp==tempstring)
        {
            IncSentenceFreq(i);
           // Frequency[i]++;
            break;
        }
        i++;
    }
    read1.close();
    // for(int i=0;i<CountSentences();i++)
    // {
    //     cout<<i<<" "<<Frequency[i]<<endl;
    // } 
}
void GetSentenceFreqs()        //Function to get frequency from file
{
	int i=0,j=0;
	ifstream in;
    char c;
	in.open("Sentencefreq.txt",ios::in);
    if(in.is_open())
    {
    	while(!in.eof())
		{
            in.get(c);
			if(i==SentenceNumber[j])
	    	{
                int num=c-'0';
				Frequency[i]=num;
	    		j++; 
			}
            i++;
            
	    }
	}
	else
	{
        fstream append0;
        append0.open("Sentencefreq.txt",ios::app);
        for(int x=0;x<1000;x++)
        {
            append0<<0;		    
        }
		//cout<<"Freq File not Created yet\n";
	}
	in.close();                   //sorting freqs to display frequency wise   
}
void IncSentenceFreq(int x)
{
	int i=0,pos=0,c2=0,j=0;;
	char c;
	fstream both;
	both.open("Sentencefreq.txt",ios::out |ios::in);
    if(both.is_open())
    {
    	while(!both.eof())
		{
			both.get(c);
			if(i==x)
	    	{
                j++;
				c2=c-'0';
				c2++;
				pos=both.tellp();
				both.seekp(pos-1);
				both<<c2;
			}
            i++;
            
	    }
	}
	else
	{
		cout<<"Freq not opened\n";
	}
	both.close();
}
void incfreq(int x)
{
	int i=0,pos=0,c2=0;
	char c;
	fstream both;
	both.open("freq.txt",ios::out |ios::in);
    if(both.is_open())
    {
    	while(!both.eof())
		{
			i++;
			both.get(c);
			if(i==x)
	    	{
				c2=c-'0';
				c2++;
				pos=both.tellp();
				both.seekp(pos-1);
				both<<c2;
			}
	    }
    }
	else
	{
		cout<<"Freq not opened\n";
	}
	both.close();
}
void sortfreqs(char wordfreq[])        //Function to sort frequency
{	
	string temp;
	int temp2;
	for(int i=0;i<9;i++)
	{
		for(int j=i+1;j<9;j++)
		{
			if(wordfreq[i]<wordfreq[j])
			{
				temp=s[i];
				s[i]=s[j];
				s[j]=temp;
				
				temp2=wordfreq[i];
				wordfreq[i]=wordfreq[j];
				wordfreq[j]=temp2;
				temp2=0;
				
				temp2=ElementInDic[i];
				ElementInDic[i]=ElementInDic[j];
				ElementInDic[j]=temp2;
			}
		}
	}
	
}
void getfreqs()        //Function to get frequency from file
{
	int i=0,j=0;
	char c,wordfreq[9];
	ifstream both;
	both.open("freq.txt",ios::in);
    if(both.is_open())
    {
    	while(!both.eof())
		{
			both.get(c);
			i++;
			if(i==ElementInDic[j])
	    	{
				wordfreq[j]=c;
	    		j++; 
                both.seekg(0);
                i=0;	
			}
	    }
	}
	else
	{
        fstream append0;
        append0.open("freq.txt",ios::app);
        for(int x=0;x<100000;x++)
        {
            append0<<0;		    
        }

	}
	both.close();
	sortfreqs(wordfreq);                       //sorting freqs to display frequency wise   
}

void IfCorrect(string input)
{
	counter=0;
	int len=input.length(),templen=0;
	string temp=" ";
	int j=5;
	int lengthCount=0;
	ifstream in("engmix.txt");
	while(!in.eof())
	{
		lengthCount=0;
		getline(in,temp);
		counter++;
		for(int i=0;i<=len;i++)
		{
			if(input[i]==temp[i])
			{
				lengthCount++;
			}
			else
			{
				break;
			}
		}
		if(lengthCount==len)
		{
			
			s[j]=temp;
			ElementInDic[j]=counter;
			j++;
			if(j==9)
			{
				break;
			}
			
		}
	}
	in.close();
}
void display(string input ,int choice, SLL &l)
{
    getfreqs();
	for(int j=0;j<9;j++)
	{
        for(int k=j+1;k<9;k++)
        {
            if(s[j]==s[k])
            {
                s[k]="";
                ElementInDic[k]=0;
            }
        }
    }
    for(int l=0;l<9;l++)
    {
        for(int j=0;j<9;j++)
        {
            if(s[j]=="")
            {
                for(int k=j;k<9;k++)
                {
                    s[k]=s[k+1];
                    ElementInDic[k]=ElementInDic[k+1];
                }
                s[8]="";
                ElementInDic[8]=0;
            }
        }
    }
    cout<<"\n------0.Go with the Same word------\n";
    for(int j=0;j<9;j++ )
    {
        if(s[j]=="")
        {
            continue;
        }
		cout<<" "<<j+1<<"."<<s[j]<<" "<<endl;
	}
    SortFrequencyLL();
    for(int i = 0; i < 5; i++)
    {
        if(lists[i].begin()==NULL)
        {
            continue;
        }
        cout<<i+10<<".";
	    for(Node *p =lists[i].begin(); p != NULL; p = p->next)
	    {
	        cout<<p->Data<<" ";
	    }
        cout<<endl;
    }
    string temp;
    int a;
    cout<<"\nPick a Word or Sentence From Above Suggestions.\n";
    cin>>a;
    if (a==0)
    {
        temp=input;
    }
    else if(a==1)
    {
        temp=s[0];
        incfreq(ElementInDic[0]);
    }
    else if(a==2)
    {
        temp=s[1];
        incfreq(ElementInDic[1]);
    }
    else if(a==3)
    {
        temp=s[2];
        incfreq(ElementInDic[2]);
    }
    else if(a==4)
    {
        temp=s[3];
        incfreq(ElementInDic[3]);
    }
    else if(a==5)
    {
        temp=s[4];
        incfreq(ElementInDic[4]);
    }
    else if(a==6)
    {
        temp=s[5];
        incfreq(ElementInDic[5]);
    }
    else if(a==7)
    {
        temp=s[6];
        incfreq(ElementInDic[6]);
    }
    else if(a==8)
    {
        temp=s[7];
        incfreq(ElementInDic[7]);
    }
    else if(a==9)
    {
        temp=s[8];
        incfreq(ElementInDic[8]);
    }
    else if(a==10)
    { 
        l.EmptyLL();
        copyLL(lists[0],l);//SOURCE,DEST
        fstream write;
        write.open("SentenceFrequencyFile.txt",ios::out);
        for (Node *p =l.begin(); p!=NULL; p=p->next)
        {
            write<<p->Data<<" ";
        }
        write<<endl;
        write.close();
        SentenceFrequency();
        //Frequency[0]++;
    }
    else if(a==11)
    {
        l.EmptyLL();
        copyLL(lists[1],l);
        fstream write;
        write.open("SentenceFrequencyFile.txt",ios::out);
        for (Node *p =l.begin(); p!=NULL; p=p->next)
        {
            write<<p->Data<<" ";
        }
        write<<endl;
        write.close();
        SentenceFrequency();
        //Frequency[1]++;
    }
    else if(a==12)
    {
        l.EmptyLL();
        copyLL(lists[2],l);
        fstream write;
        write.open("SentenceFrequencyFile.txt",ios::out);
        for (Node *p =l.begin(); p!=NULL; p=p->next)
        {
            write<<p->Data<<" ";
        }
        write<<endl;
        write.close();
        SentenceFrequency();
        //Frequency[2]++;
    }
    else if(a==13)
    {
        l.EmptyLL();
        copyLL(lists[3],l);
        fstream write;
        write.open("SentenceFrequencyFile.txt",ios::out);
        for (Node *p =l.begin(); p!=NULL; p=p->next)
        {
            write<<p->Data<<" ";
        }
        write<<endl;
        write.close();
        SentenceFrequency();
        //Frequency[3]++;
    }
    else if(a==14)
    {
        l.EmptyLL();
        copyLL(lists[4],l);
        fstream write;
        write.open("SentenceFrequencyFile.txt",ios::out);
        for (Node *p =l.begin(); p!=NULL; p=p->next)
        {
            write<<p->Data<<" ";
        }
        write<<endl;
        write.close();
        SentenceFrequency();
        //Frequency[4]++;
    }

    if(choice==1 && a>9)
    {
        l.print();
    }
    else if(choice==1 && a<=9)
    {
        l.print();
        cout<<endl;
        l.AppendLast(temp);
        // cout<<"\nYou entered:";
        l.print();
    }
    else if(choice==3)
    {
        l.print();
        cout<<endl;
        int index;
        cout<<"\nEnter Index to after u want to add word.";
        cin>>index;
        l.AppendMiddle(temp,index);
        // cout<<"\nYou entered:";
        l.print();
    }
    else if(choice==4)
    {
        l.print();
        cout<<endl;
        l.AppendFirst(temp);
        // cout<<"\nYou entered:";
        l.print();
    }
    else
    {
        return;    
    }
}
void IfWrong(string input)
{
    counter=0;
	int len=input.length(),templen=0;
	string temp;
	int j=5;
	int lengthCount=0;
	ifstream in("engmix.txt");
	while(!in.eof())
	{
		lengthCount=0;
		getline(in,temp);
		counter++;
        int templength=temp.length();
        string Ninput,Ntemp;
        for(int i=0;i<len;i++)
        {
            Ninput.push_back(input[i]);
        }
        for(int i=0;i<templength;i++)
        {
            Ntemp.push_back(temp[i]);
        }
		for(int i=0;i<=len;i++)
		{
			if(Ninput[i]==Ntemp[i])
			{
				lengthCount++;
			}
			else
			{
				break;
			}
		}
		if(lengthCount==len)
		{
			s[j]=temp;
			ElementInDic[j]=counter;
            
			j++;
			if(j==9)
			{
				break;
			}
		}
        //counter=0;
	}
	in.close();
}
void SentencePredictor(string inputstring)
{
    int LineNumberOfFile=0;
    int a=0;
	int listnumber = 0;
	string sentence;
	int count = 0, len, l, flag = 0;
	char ch, c;
    len = inputstring.length();
    char s1[len];
    fstream sen;
    sen.open("SentencesFile.txt", ios :: in);
    if(sen)
    {
        CountSentences();
        while(!sen.eof())
        {
            sen.get(ch);
            ch = tolower(ch);
            while(ch != '\n')
            {
                sentence = sentence + ch;
                sen.get(ch);
                ch = tolower(ch);
            }
            // cout<<sentence<<endl;
            flag = 0;
            for(int i = 0; i < sentence.length(); i++)
            {
                if(inputstring[0] == sentence[i])
                {
                    int count = i + 1;
                    for(int j = 1; j < len; j++)
                    {
                        if(inputstring[j] == sentence[count])
                        {
                            flag = flag + 1;
                        }		
                        count++;
                    }
                    
                }
            }
            if(flag != len-1)
            {
                sentence = '\0';
            }
            else if(flag == len - 1)
            {
                SentenceNumber[a]=LineNumberOfFile;
                a++;
                string temp;
                for(int i = 0; i < sentence.length(); i++)
                {
                    if(sentence[i] != ' ') 
                    {
                        temp = temp + sentence[i];
                    }
                    else 
                    {
                        lists[listnumber].AppendLast(temp);
                        temp = '\0';
                    }	
                    
                }
                lists[listnumber].AppendLast(temp);
                listnumber++;
                if(listnumber == 6)
                    break;
                sentence = '\0';
            }
            LineNumberOfFile++;
           
        }
        // for(int i=0;i<5;i++)
        // {
        //     cout<<i<<" "<<SentenceNumber[i]<<endl;
        // }
    }
    else
    {
        cout<<"\nno Sentence file found..";
    }

}
void Suggestion_Spelling(string input ,int choice,SLL &s)
{
	string line;
	int inputlength,linelength,correct=0;
	inputlength = input.length();
	for (int i=0; i < inputlength; i++)
	{
		input[i] = tolower(input[i]);
	}
	ifstream words ("engmix.txt");
	if(words)
	{
		while (getline(words,line))
		{

			if (line==input)
			{
				correct=1;
			}
			else 
			{
				continue;
			}
		}
		words.close();
		if (correct==1)
		{
            ResetStrings();
			cout<<endl<<"\nSpelling is correct\n"<<endl;
            int extra = 0,missing=0 ,mixed = 0, incorrect = 0, exchanged = 0;
			cout<<endl<<"Possible suggestions are given below:- "<<endl<<endl;
			IfCorrect(input);
            extra = extraCharacter(input);
			missing = missingCharacter(input);
			mixed = mixedExtraMissing(input);
			incorrect = incorrectArrangement(input);
			exchanged = exchangedCharacters(input);
            SentencePredictor(input);
			display(input ,choice,s);
			if (missing==0 && extra == 0 && mixed == 0 && incorrect == 0 && exchanged == 0)
			{
				cout<<endl<<"No such word exist"<<endl;
			}
		}
		if (correct==0)
		{
            ResetStrings();
			int extra = 0,missing=0 ,mixed = 0, incorrect = 0, exchanged = 0;
			cout<<endl<<"Spelling is wrong. Possible right suggestions are given below:- "<<endl<<endl;
            IfWrong(input);
			extra = extraCharacter(input);
			missing = missingCharacter(input);
			mixed = mixedExtraMissing(input);
			incorrect = incorrectArrangement(input);
			exchanged = exchangedCharacters(input);
            SentencePredictor(input);
			display(input ,choice,s);
			if (missing==0 && extra == 0 && mixed == 0 && incorrect == 0 && exchanged == 0)
			{
				cout<<endl<<"No such word exist"<<endl;
			}
		}
	}
	else
	{
		cout<<"Not able to open engmix.txt"<<endl;
	}
    return ;
}
int main()
{
    int n,data,n1,a;
    SLL l;
    lists[0].EmptyLL();
    lists[1].EmptyLL();
    lists[2].EmptyLL();
    lists[3].EmptyLL();
    lists[4].EmptyLL();
    system("cls");
	gotoxy(40,5);
//    system ("color 0C");
//  	Sleep(500);
//  	cout<<"   888888888    88     888   8888888    ";
//  	gotoxy(40,6);
//    system ("color 0B");
//  	Sleep(500);
//	cout<<"  88      88    88   88  88  88    88   ";
//  	gotoxy(40,7);
//    system ("color 0D");
//  	Sleep(500);
//	cout<<"   8888   88888888  88    88 88  888    ";
//  	gotoxy(40,8);
//    system ("color 0E");
//  	Sleep(500);
//	cout<<"      88  88    88 888888888 88    88   ";
//  	gotoxy(40,9);
//    system ("color 0F");
//  	Sleep(500);
//	cout<<"8888888   88    88 88     88 8888888	   ";  	
//	Sleep(2500);
//	system ("cls");
//	system ("color F0");        
	start:
	gotoxy(40,3);
    cout<<"1- Continue To Write Word By Word.";
    gotoxy(40,4);
	cout<<"2- End Senentence.";
    gotoxy(40,5);
	cout<<"3- Enter Index To Insert Word After That Index.";
	gotoxy(40,6);
    cout<<"4- To Insert At  The Beginning.";
	gotoxy(40,7);
    cout<<"5- To Delete.";
	gotoxy(40,8);
    cout<<"6- Start Search from the beginning..\n";
    gotoxy(0,10);
    cout<<"***********************************************************************************************************************************************************";
    gotoxy(40,12);
	int choice,choice2;
    cin>>choice;
    if(choice==1)
    {
        string temp;
        l.print();//cout<<" ";
        int flag=0;
        cin>>temp;
        // for(int i=0;i<temp.length();i++)
        // {
        //     if(temp[i]<'a' || temp[i]>'z' || temp[i]<'A' || temp[i]>'Z' )
        //     {
        //          flag=0;
        //          break;
        //     }
        //     else 
        //     {
        //          flag=1;
        //     }
        // }
        // if(flag==0)
        // {
        //     ResetStrings();
        //     s[0]=64; //@
        //     s[1]=33; //!
        //     s[2]=34; //"
        //     s[3]=35; //#
        //     s[4]=63; //?
        //     s[5]=36; //$
        //     s[6]=38; //&
        //     s[7]=58; //:
        //     s[8]=59; //;
        //     display(temp ,choice,l);
        //     goto start;
        // }
        // else if(flag==1)
        // {
            Suggestion_Spelling(temp,1,l);
            goto start;
        //}
       
    }
    else if(choice==2)
    {
        ofstream write;
        if(l.begin()==NULL)
        {
            cout<<"\nEmpty Sentence..";
            Sleep(2000);
            system("cls");
            cout<<"\n---------------------------------------Starting From the beginning---------------------------------------";
            main();
        }
        write.open("SentencesFile.txt",ios::app);
        for (Node *p =l.begin(); p!=NULL; p=p->next)
        {
            write<<p->Data<<" ";
        }
        write<<endl;
        write.close();
        system("cls");
        cout<<"\n---------------------------------------Starting From the beginning---------------------------------------";
        main();
    }
    else if(choice==3)
    {
        string temp;
        cout<<"\nEnter word: ";
        cin>>temp;
        if(l.head==NULL)
        {
            cout<<"\nSearch Bar is Empty !!! ";
            Sleep(2000);
            system("cls");
            main();
        }
        else
        {
            Suggestion_Spelling(temp,3,l);
            goto start;
        }
    }
    else if(choice==4)
    {
        string temp;
        cout<<"\nEnter word: ";
        cin>>temp;
        Suggestion_Spelling(temp,4,l);
        l.print();cout<<" ";
        goto start;
    }
    else if(choice==5)
    {
    	system("cls");
        l.print();cout<<" "<<endl;
    	gotoxy(40,3);
    	cout<<"1.Delete From First";
 		gotoxy(40,4);
    	cout<<"2.Delete From End";
		gotoxy(40,5);
    	cout<<"3.Delete From Any desired position (Starting Index 1)";
		gotoxy(40,6);
    	cin>>choice2;
    	if(choice2==1)
    	{
	        l.print();
	        l.DeleteFirst();
	        l.print();
	        goto start;
        }
        else if(choice2==2)
        {
        	l.print();
	        l.DeleteLast();
	        l.print();
	        goto start;
		}
		else
		{
			system("cls");
			l.print();
	        cout<<endl;
	        int index;
	        cout<<"\nEnter Index to after u want to delete word.";
	        cin>>index;
	        l.DeleteMiddle(index);
	        cout<<"\nYour Entered: "<<endl;
	        l.print();
	        goto start;
		}
    }
    else if(choice==6)
    {
        system("cls");
        main();
    }
    else
    {
        exit(2);
    }
}
