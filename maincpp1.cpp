#include "heard.h"
void Member::fileout(ppList &L)
{  
     L=new ppNode;
    L->next=NULL;
    L->prior=NULL;
    ppList r,p;
       r=L;
    string line;
    
    ifstream open("ͨѶ¼.txt");//��ȡ�ļ�
	if (!open)
	{
		cout << "open error!" << endl;
	}
	while (getline(open, line))
	{
		istringstream is(line);   
		p = new ppNode;
		is >>p->data.address>> p->data.class_n>>p->data.ID >> p->data.integral >> p->data.name >> p->data.rank >> p->data.sex >> p->data.telephonenumber>>p->data.time_p.day>>p->data.time_p.hour>>p->data.time_p.minute>>p->data.time_p.mouth>>p->data.time_p.second>>p->data.time_p.year;
		p->next = NULL;
		r->next = p;
		r = p;
	}
	open.close();
	cout<<"��ȡ���"<<endl;
}
void Member::filein(ppList &L)
{    
     ppList p;
     p=L->next;
     fstream fMember("ͨѶ¼.txt", ios::out);
	if (!fMember)
	{
		cout << "open error!" << endl;
		abort();
	}
	while (p != NULL)
	{
	  fMember <<p->data.address<<" "<< p->data.class_n<<" "<<p->data.ID <<" "<< p->data.integral <<" "<< p->data.name <<" "<< p->data.rank <<" "<<p->data.sex <<" "<< p->data.telephonenumber<<" "<<p->data.time_p.day<<" "<<p->data.time_p.hour<<" "<<p->data.time_p.minute<<" "<<p->data.time_p.mouth<<" "<<p->data.time_p.second<<" "<<p->data.time_p.year<<endl;
	   p=p->next;

	 }
	 	
	 fMember.close();
	 cout<<"д�����"<<endl;
}
int Member::GrateList(ppList &L)
{   L=new ppNode;
    L->next=NULL;
    L->prior=NULL;
	ppList p=L->next,r=L;
    SYSTEMTIME sys; 
	while(1)
    { GetLocalTime(&sys);//ʱ��ˢ�� 
	  p=new ppNode;
	  p->data.time_p.second=sys.wSecond;
	  p->data.time_p.minute=sys.wMinute;
      p->data.time_p.day=sys.wDay;
      p->data.time_p.mouth=sys.wMonth;
      p->data.time_p.year=sys.wYear;
      p->data.time_p.hour=sys.wHour;
      p->data.rank=0;
      p->data.integral=0;
      system("cls");
      cout<<"�뿪ʼ����ѧ����Ϣ"<<endl;
      cout<<"ѧ��:  "<<endl;   cin>>p->data.ID;
      cout<<"������ "<<endl;   cin>>p->data.name;
      cout<<"�Ա� "<<endl;   cin>>p->data.sex;
      cout<<"רҵ�༶�� "<<endl; cin>>p->data.class_n;
      cout<<"��ϵ�绰�� "<<endl; cin>>p->data.telephonenumber;
      cout<<"��ͥסַ�� "<<endl; cin>>p->data.address;
	   p->next=NULL; r->next=p; p->prior=r; r=p;
	  int n; cout<<"1:�������� 0������"<<endl; cin>>n; if(n==0) break;
      system("cls");
	 //cin.clear();
     //cin.ignore(888,'\n');//�����ǰ��
     //std::numeric_limits<std::streamsize>::max()
	 //cin.sync();
	 
	 }
	 system("pause");
	 system("cls");
	 return OK;
}
int Member::Llength(ppList &L)
{    
    ppList p=L->next;
    int i=0;
	while(p)
	{
	p=p->next;
     i++;
	}
	return i;
}
int Member::InsertList(ppList &L)
{   SYSTEMTIME sys; 
    ppList p,q=L->next;  int n=0;
    while(1)
    { GetLocalTime(&sys);//ʱ��ˢ�� 
	  p=new ppNode;
	  system("cls");
      cout<<"�뿪ʼ����ѧ����Ϣ"<<endl;
      cout<<"ѧ��:  "<<endl;   cin>>p->data.ID;
          while(q)
        { if(q->data.ID==p->data.ID)
            { cout<<"�Ѿ��д�����Ϣ"<<endl; n=1; system("pause");break;}
          q=q->next; 
		}
		if(n==1) {delete p; break;}
      cout<<"������ "<<endl;   cin>>p->data.name;
      cout<<"�Ա� "<<endl;   cin>>p->data.sex;
      cout<<"רҵ�༶�� "<<endl; cin>>p->data.class_n;
      cout<<"��ϵ�绰�� "<<endl; cin>>p->data.telephonenumber;
      cout<<"��ͥסַ�� "<<endl; cin>>p->data.address;
	  p->data.time_p.second=sys.wSecond;
	  p->data.time_p.minute=sys.wMinute;
      p->data.time_p.day=sys.wDay;
      p->data.time_p.mouth=sys.wMonth;
      p->data.time_p.year=sys.wYear;
      p->data.rank=999;
      p->data.integral=0;
	  p->next=L->next;   L->next=p;
      int n; cout<<"1:�������� 0������"<<endl; cin>>n; if(n==0) break;
      
	  system("cls");
    }
    system("cls");
    return OK;
}
int Member::display_member(ppList &L)
{  
  ppList p;
  p=L->next;
  system("cls");
  while(p)
  {   cout<<"ѧ��:  "<<p->data.ID<<endl;  
      cout<<"������ "<<p->data.name<<endl;  
      cout<<"�Ա� "<<p->data.sex<<endl;  
      cout<<"רҵ�༶�� "<<p->data.class_n<<endl;
      cout<<"��ϵ�绰�� "<<p->data.telephonenumber<<endl;
      cout<<"��ͥסַ�� "<<p->data.address<<endl; 
      cout<<"����ʱ�䣺 "<<p->data.time_p.year<<":"<<p->data.time_p.mouth<<":"<<p->data.time_p.day<<":"
	                     <<p->data.time_p.hour<<":"<<p->data.time_p.minute<<":"<<p->data.time_p.second<<endl;
      p=p->next;
  }
  system("pause");
  system("cls");
  return OK;
}
int  Member::rankquery(ppList &L)
{  ppList p=L->next;
   cout<<"������ѧ��"<<endl;
   string str; cin>>str;
   while(p)
   { if(p->data.ID==str)
     { 
      cout<<"��Ա�ȼ�:  "<<endl;
	  cout<<"ѧ��:  "<<p->data.ID<<endl;  
      cout<<"������ "<<p->data.name<<endl;  
      cout<<"�Ա� "<<p->data.sex<<endl;  
      cout<<"רҵ�༶�� "<<p->data.class_n<<endl;
      cout<<"��ϵ�绰�� "<<p->data.telephonenumber<<endl;
      cout<<"��ͥסַ�� "<<p->data.address<<endl; 
      cout<<"����ʱ�䣺 "<<p->data.time_p.year<<":"<<p->data.time_p.mouth<<":"<<p->data.time_p.day<<":"
	                     <<p->data.time_p.hour<<":"<<p->data.time_p.minute<<":"<<p->data.time_p.second<<endl;
	 }
	 p=p->next;
   }
   return OK;
}
double Member::rankaverage(ppList &L)
{ ppList p=L->next;
  double average=0;int i=0;
  while(p)
  { average+=p->data.integral;
     i++;
  }
  return average/i;
}
int Member::ranksort(ppList &L)
{   
   ppList p,q;
  /*
  while(i<=Llength(L))
  {  p=L->next;   //���� 
     while((p->data.rank!=0)&&p->next)
       p=p->next;
        q=p;p=p->next;
    while(p)
    {	 
	if((p->data.integral>q->data.integral)&&(p->data.rank==0))
		{ q=p;  cout<<q->data.name<<"<->"<<p->data.name<<endl; }
      p=p->next; 
	}
	q->data.rank=i;
	i++;
  }*/
  for(int i=1;i<=Llength(L);i++)
  {  p=L->next; 
		 while(p)
	 {
	   if(p->data.rank==i)
	   {
	  cout<<"��"<<i<<":"<<endl;
      cout<<"���֣�"<<p->data.integral<<"�ȼ�:  "<<p->data.integral/100<<endl;
	  cout<<"ѧ��:  "<<p->data.ID<<endl;  
      cout<<"������ "<<p->data.name<<endl;  
      cout<<"�Ա� "<<p->data.sex<<endl;  
      cout<<"רҵ�༶�� "<<p->data.class_n<<endl;
      cout<<"��ϵ�绰�� "<<p->data.telephonenumber<<endl;
      cout<<"��ͥסַ�� "<<p->data.address<<endl; 
      cout<<"����ʱ�䣺 "<<p->data.time_p.year<<":"<<p->data.time_p.mouth<<":"<<p->data.time_p.day<<":"
	                     <<p->data.time_p.hour<<":"<<p->data.time_p.minute<<":"<<p->data.time_p.second<<endl;
       }
	   p=p->next;
     }
	}
     system("pause");
     system("cls");
    return OK;
  
}
int Member::delete_ppList(ppList &L)
{   ppList p=L->next,r=L;  int n=0;
    cout<<"������Ҫɾ���˵�ѧ��"<<endl;
	string people;
	cin>>people;
	while(p)
    { 
     if(people==p->data.ID)
      {
	    r->next=p->next;
        cout<<"ɾ������Ϣ:"<<endl;
        cout<<"����:"<<p->data.name<<endl;
        cout<<"�Ա�:"<<p->data.sex<<endl;
        cout<<"ѧ��:"<<p->data.ID<<endl;
		delete p;   //�ͷſռ�    
		n=1;
	  }
	  p=p->next;
	}
	if(n==0) cout<<"δ�ҵ�����"<<endl;
	 else cout<<"ɾ���ɹ�"<<endl;
	system("pause");
   return OK;
}
int Member::sort_1(ppList &L,ppList p)
{   cout<<"*****"<<endl;
   //cout<<p->data.name<<"***"<<endl;
   int m_1=p->data.integral,m_2=1,n=0; // cout<<"��ʱ����Ϊ"<<m_1<<endl;
   ppList q=L->next; 
   while(q!=NULL)
   {     
   if(q->data.integral>m_1&&q->data.rank>=m_2)
      { m_2=q->data.rank;  n=1;}
	   //cout<<q->data.integral<<"-----   m2:"<<m_2<<endl;
     q=q->next;
   }        //�ҵ�Ҫ���������λ��  
              if(n==1) m_2++;
          //  cout<<"����λ��Ϊ"<<m_2<<endl;          
     q=L->next;
   while(q)
    {     
      if(q->data.rank>=m_2&&q->data.rank<p->data.rank)
        { 
		  q->data.rank++;// cout<<q->data.name<<":"<<q->data.rank;
		}  
	    q=q->next;      
    } //��λ�ú��λ�ú��� 
      p->data.rank=m_2;   //cout<<p->data.name<<":"<<p->data.rank;
      return OK;
}
int   Member::sort_2(ppList &L,ppList p)
{   int m_1=p->data.integral,m_2=999,n=0;
     ppList q=L->next; 
  while(q!=NULL)
   {     
   if(q->data.integral<m_1&&q->data.rank<=m_2)
      { m_2=q->data.rank;  n=1;}
	   //cout<<q->data.integral<<"-----   m2:"<<m_2<<endl;
     q=q->next;
    }        //�ҵ�Ҫ���������λ��  
              if(n==1) m_2--;
            cout<<"����λ��Ϊ"<<m_2<<endl;          
     q=L->next;
   while(q)
    {     
      if(q->data.rank<=m_2&&q->data.rank>p->data.rank)
        { 
		  q->data.rank--;// cout<<q->data.name<<":"<<q->data.rank;
		}  
	    q=q->next;      
    }  //��λ��ǰ��λ��ǰ�� 
     p->data.rank=m_2;
     system("pause");
	return 0;
}
int  Member::add_integral(ppList &L) 
{   ppList  p=L->next;;
	string people; int n_1=-1,n_2=0,n_3=0;
	while(1)
   {	system("cls");
      cout<<"������ѧ��"<<endl;
	    cin>>people; 
          p=L->next;   n_1=-1,n_2=0,n_3=0;
         	while(p)
    {  
     if(people==p->data.ID)
      { cout<<"������Ϣ:"<<endl;
        cout<<"����:"<<p->data.name<<endl;
        cout<<"�Ա�:"<<p->data.sex<<endl;
        cout<<"ѧ��:"<<p->data.ID<<endl;
		cout<<"1:ȷ��������Ϣ 2:��������"<<endl;
		 cin>>n_3;
		 if(n_3==1)
		{   n_2=1;  //��־�ҵ� 
		 cout<<"������Ҫ���ӵ�ѧ��"<<endl;   
	     cin>>n_1;
	     p->data.integral+=n_1;
		}
		else if(n_3==2)
		{  n_2=-1;
		}
        else  cout<<"�������"<<endl; 
        cout<<"n_2"<<n_2<<endl;
		break; 
	  }
	  p=p->next;
	}
	if(n_2==-1)    continue;  //���ñ�ʶ 
	if(n_2==0)    {cout<<"δ�ҵ�����"<<endl; continue;}
	 if(n_1>0) sort_1(L,p);
	  else if(n_1<0) sort_2(L,p);
	 cout<<"0:ֹͣ 1:����"<<endl;
	 cin>>n_1; if(n_1==0) break;
   }
   //�����ӻ��ֵ��������� 
   cout<<"�Ʒ����"<<endl;
	system("pause");
    return OK;   
}

int   Member::change(ppList &L)
{    ppList p=L->next;
    cout<<"������ѧ��"<<endl;
	string people;  cin>>people; int i,n=0;
		while(p)
    { 
     if(people==p->data.ID)
      {  cout<<"������Ҫ�޸ĵ��"<<endl;
      cout<<"1-���֣� " <<p->data.integral<<endl;
	  cout<<"2-ѧ��:  "<<p->data.ID<<endl;  
      cout<<"3-������ "<<p->data.name<<endl;  
      cout<<"4-�Ա� "<<p->data.sex<<endl;  
      cout<<"5-רҵ�༶�� "<<p->data.class_n<<endl;
      cout<<"6-��ϵ�绰�� "<<p->data.telephonenumber<<endl;
      cout<<"7-��ͥסַ�� "<<p->data.address<<endl; 
      cout<<"����ʱ�䣺 "<<p->data.time_p.year<<":"<<p->data.time_p.mouth<<":"<<p->data.time_p.day<<":"
	                     <<p->data.time_p.hour<<":"<<p->data.time_p.minute<<":"<<p->data.time_p.second<<endl;
      cin>>i;
	    switch(i)
		{
		  case 1:  cout<<"������"<<endl;  i=8; n=p->data.integral; cin>>p->data.integral;break;
		  case 2:  cout<<"������"<<endl;   cin>>p->data.ID; break;
		  case 3:  cout<<"������"<<endl;   cin>>p->data.name; break;
		  case 4:  cout<<"������"<<endl;   cin>>p->data.sex;break;
		  case 5:  cout<<"������"<<endl;   cin>>p->data.class_n; break;
		  case 6:  cout<<"������"<<endl;   cin>>p->data.telephonenumber; break;
		  case 7:  cout<<"������"<<endl;   cin>>p->data.address; break;
		   default :  cout<<"�������"<<endl; i=0; cin.clear(); cin.sync();
		} 
		break;
	   }
		p=p->next;
	  
    } 
    if(i==0) cout<<"�޸�ʧ��"<<endl;
       else  cout<<"�޸ĳɹ�"<<endl;
	if(i==8)
	 {   
	 if(n<p->data.integral)
	 sort_1(L,p);  
	 else if(n>p->data.integral)
	 sort_2(L,p);  
	 }
  return OK;
}
void show_ppList(Member &cc,ppList &L)
{
    int n=1;
    while(n!=-1)
	{
	system("cls");
	cout<<"1��ͨѶ¼����"<<endl;
    cout<<"2�����ֽ���鿴"<<endl;
    cout<<"3�����ӳ�Ա"<<endl;
    cout<<"4��ɾ����Ա"<<endl;
    cout<<"5: ��Ա��������"<<endl;
	cout<<"6����Ա��Ϣ�޸�"<<endl;
    cout<<"7: �˳�"<<endl;
    cout<<""<<endl;
	cin>>n;
	switch(n)
     {
    	case 1:    cc.display_member(L); break;
    	case 2:    cc.ranksort(L);  break;
    	case 3:    cc.InsertList(L); break;
    	case 4:    cc.delete_ppList(L); break;
    	case 5:    cc.add_integral(L); break;
    	case 6:    cc.change(L);  break;
    	case 7:    n=-1; break;
	 }
   }
    
}
int main()
{   Member cc;  ppList L;
   //cc.GrateList(L);
    cc.fileout(L);
    show_ppList(cc,L);
	cc.filein(L);
	return 0;
}