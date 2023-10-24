#include "main.h"
extern int MAXSIZE;

class Node
{
public:
    int data;
    Node* next;
    Node(int value) : data(value), next(nullptr) {}
};

class LinkedList
{
private:
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void push_back(int value)
    {
    Node* newNode = new Node(value);
    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
    size++;
}

    int get(int index)
    {
        if (index < 0 || index >= size)
        {

            return -1;
        }
        Node* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
     }

    void set(int index, int value)
    {
        if (index < 0 || index >= size) {

            return;
        }
        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        current->data = value;
    }

    int getSize()
    {
        return size;
    }

    int shellSort()
    {
        int hoandoi = 0;
        int n = size;
        for (int gap = n / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < n; i++) {
                int val = get(i);
                int j;
                for (j = i; j >= gap && get(j - gap) > val; j -= gap) {
                    int VAL = get(j - gap);
                    set(j, VAL);
                    hoandoi++;
                }
                set(j, val);
            }
        }
        return hoandoi;
    }

    void clear()
    {
        Node* current = head;
        while (current)
        {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }
};

class imp_res : public Restaurant
{
    private :
    customer*head;
    customer*tail;
    customer*vitri;
    customer*hangchodau;
    customer*hangchocuoi;
    customer*thutudau;
    customer*thutucuoi;

	public:
		imp_res()
		{
		this->head=nullptr;
		this->tail=nullptr;
		this->vitri=nullptr;
		this->hangchodau=nullptr;
		this->hangchocuoi=nullptr;
		this->thutudau=nullptr;
		this->thutucuoi=nullptr;
		};

        int soluongkhachtrongban()
        {
            if(head==nullptr){return 0;}
            int dem=0;
            if(head==tail){return 1;}
            customer*temp=head;
            while(temp!=nullptr)
            {
                dem++;
                temp=temp->next;
            }
            return dem;
        }

        bool kiemtratrungtentrongban(string NAME)
        {
         customer*temp=head;
         while(temp!=nullptr)
         {
             if(temp->name==NAME){return false;}
             temp=temp->next;
         }
         return true;
        }

        void newthutu(string NAME, int ENERGY)
        {
             customer *cus = new customer (NAME, ENERGY, nullptr, nullptr);
             thutudau=cus;
             thutudau->prev=nullptr;
             thutudau->next=nullptr;
             thutucuoi=thutudau;
        }

        void themthutu(string NAME,int ENERGY)
        {
             customer *cus = new customer (NAME, ENERGY, nullptr, nullptr);
             cus->prev=thutucuoi;
             cus->next=nullptr;
             thutucuoi->next=cus;
             thutucuoi=cus;
        }

        void themcungchieukim(customer*cus)
        {
             customer*temp=cus;
            if(vitri==tail)
            {
                temp->prev=tail;
                temp->next=nullptr;
                tail->next=temp;
                tail=temp;
                vitri=temp;
                return;
            }

            customer*p=head;
            while(p!=vitri)
            {
               p=p->next;
            }
              temp->prev= p;
	          temp->next = p->next;
	          p->next->prev = temp;
	          p->next=temp;
	          vitri=temp;
        }

        void themnguocchieukim(customer*cus)
        {
            customer*temp=cus;
            if(vitri==head)
            {
                temp->prev=tail;
                temp->next=nullptr;
                tail->next=temp;
                tail=temp;
                vitri=temp;
                return ;
            }
            customer*p=head;
            while(p!=vitri)
            {
               p=p->next;
            }
              temp->next= p;
	          temp->prev = p->prev;
	          p->prev->next = temp;
	          p->prev = temp;
	          vitri=temp;
        }

        void themvaohangcho(customer*cus)
        {
            customer*temp=cus;
            temp->prev=hangchocuoi;
            temp->next=nullptr;
            hangchocuoi->next=temp;
            hangchocuoi=temp;
        }

        int chenhlechlonnhat(int  ENERGY)
        {
            customer*p=head;
            int RES=abs(ENERGY-p->energy);
            int RES2=ENERGY-p->energy;
            vitri=p;
            while(p!=nullptr)
            {
               if(abs(ENERGY-p->energy)>RES)
               {
                   RES=abs(ENERGY-p->energy);
                   RES2=ENERGY-p->energy;
                   vitri=p;
               }
               p=p->next;
            }
            return RES2;
        }

        int soluongkhachcho()
        {
            if(hangchodau==nullptr){return 0;}
            int dem=0;
            customer*temp=hangchodau;
            while(temp!=nullptr)
            {
                dem++;
                temp=temp->next;
            }
            return dem;
        }

        bool kiemtratrungtenkhachcho(string NAME)
        {
         customer*temp=hangchodau;
         while(temp!=nullptr)
         {
             if(temp->name==NAME){return false;}
             temp=temp->next;
         }
         return true;
        }

        void xoakhachtrongban(string NAME)
        {
            customer*temp=head;
            while(temp!=nullptr)
            {
                if(temp->name==NAME){break;}
                temp=temp->next;
            }

            if(temp==tail)
                {
                     if(temp->energy>0)
                      {vitri=head;}
                     else {vitri=temp->prev;}
                     customer *p = tail->prev;
                     p->next = nullptr;
                     tail = p;
                     delete(temp);
                }
                else if(temp==head)
                {
                    if(temp->energy>0)
                      {vitri=head->next;}
                     else {vitri=tail;}
                   customer*p=head->next;
                   p->prev=nullptr;
                   head=p;
                   delete(temp);
                }
                else
                {
                if(temp->energy>0)
                    {vitri=temp->next;}
                 else {vitri=temp->prev;}
                  customer*TEMP=temp->prev;
                  customer*p=temp->next;
                  p->prev=TEMP;
                  TEMP->next=p;
                  temp=nullptr;
                  delete(temp);
                }

        }

        void xoathutu()
        {
            if(thutudau->next!=nullptr)
            {
            customer*p=thutudau->next;
            customer*temp=thutudau;
            p->prev=nullptr;
            thutudau=p;
            delete(temp);
            return;
            }
            if(thutudau==thutucuoi)
            {
            customer*temp=thutudau;
            thutudau=nullptr;
            thutucuoi=thutudau;
            delete(temp);
            return;
            }
        }

        void xoadau()
        {
            if(head->next!=nullptr)
            {
            xoathutu();
            customer*p=head->next;
            customer*temp=head;
            p->prev=nullptr;
            head=p;
            vitri=nullptr;
            delete(temp);
            return;
            }
            if(head==tail)
            {
                xoathutu();
                customer*temp=head;
                head=nullptr;
                tail=head;
                 delete(temp);
                 return;
            }
        }

        void xoahetkhach()
        {
            while(head!=nullptr)
            {
                xoadau();
            }
        }

        void timdayconver1()
        {
            if(soluongkhachtrongban()<4){return;}
            customer*temp=head;
            customer*luuvitri=nullptr;
            int MIN=0;
            int dem=0;
            while(dem<4)
            {
                MIN+=temp->energy;
                if(soluongkhachtrongban()==4)
                  {
                      temp->print();
                  }
                dem++;
                temp=temp->next;
            }
            luuvitri=temp;
            if(soluongkhachtrongban()==4){return ;}
            int n=soluongkhachtrongban();
            temp=head;
            int tong=dem+1;
            int MIN1=0;

            while(tong<n)
            {
                temp=head;
                for(int i=0;i<tong;i++)
                {
                   MIN1+=temp->energy;
                   temp=temp->next;
                }
                if(MIN1<MIN)
                {
                    MIN=MIN1;
                    luuvitri=temp;
                }
                tong+=1;
            }
            temp=head;
            while(temp!=luuvitri)
            {
                temp->print();
                temp=temp->next;
            }
        }

        void timdayconver2()
        {
          if(soluongkhachtrongban()<4){return;}
          customer*temp=vitri;
          customer*luuvitri=nullptr;
          int MIN=0;
          int dem=0;
          int luugiatri;
          while(dem<4&&(temp!=nullptr))
            {
                MIN+=temp->energy;
                if(soluongkhachtrongban()==4)
                  {
                      temp->print();
                  }
                dem++;
                temp=temp->next;
            }
            customer*p=head;
            if(dem<4)
            {
                 while(dem<4&&(p!=vitri))
            {
                MIN+=p->energy;
                if(soluongkhachtrongban()==4)
                  {
                      p->print();
                  }
                dem++;
                p=p->next;
            }
            }
            luugiatri=dem;
            luuvitri=p;
            if(soluongkhachtrongban()==4){return ;}
            int n=soluongkhachtrongban();
            temp=vitri;
            int tong=dem+1;
            int MIN1=0;

            while(tong<n)
            {
                temp=vitri;
                dem=0;
                p=head;
                while(dem<tong&&(temp!=nullptr))
                {
                     MIN1+=temp->energy;
                     dem++;
                     temp=temp->next;
                }
                if(dem<tong)
                {
                 while(dem<tong&&(p!=vitri))
                   {
                   MIN+=p->energy;
                   dem++;
                   p=p->next;
                   }
                }

               if(MIN1<MIN)
               {
                    MIN=MIN1;
                    luuvitri=p;
                    luugiatri=dem;
               }
                tong+=1;
            }
            temp=vitri;
            p=head;
            dem=0;
            while(dem<luugiatri&&(temp!=nullptr))
            {
                temp->print();
                dem++;
                temp=temp->next;
            }
            if(dem<luugiatri)
            {
                 while(dem<luugiatri&&(p!=luuvitri))
                   {
                   p->print();
                   dem++;
                   p=p->next;
                   }
            }
        }

        void xoakhachcho(string NAME)
        {
            if(hangchodau==nullptr){return;}
            customer*temp=hangchocuoi;
            while(temp!=nullptr)
            {
                if(temp->name==NAME){break;}
                temp=temp->prev;
            }
            if(temp!=nullptr)
             {
                 if(temp==hangchocuoi)
                {   temp->print();
                    if(hangchocuoi!=hangchodau)
                  {
                     customer *p = hangchocuoi->prev;
                     p->next = nullptr;
                     hangchocuoi = p;
                     delete(temp);
                     return ;
                  }
                  else
                  {
                       hangchodau=nullptr;
                       hangchocuoi=hangchodau;
                       return ;
                  }
                }
                else if(temp==hangchodau)
                {    temp->print();
                    if(temp->next!=nullptr)
                   {
                   customer*p=hangchodau->next;
                   p->prev=nullptr;
                   hangchodau=p;
                   delete(temp);
                   }
                   else
                   {
                       hangchodau=nullptr;
                       hangchocuoi=hangchodau;
                       return ;
                   }
                }
                else
                {
                  temp->print();
                  customer*TEMP=temp->prev;
                  customer*p=temp->next;
                  p->prev=TEMP;
                  TEMP->next=p;
                  temp=nullptr;
                  delete(temp);
                }
             }
        }

        void xoakhachdoi(string NAME)
        {
    if(hangchodau==nullptr){return;}
            customer*temp=hangchocuoi;
            while(temp!=nullptr)
            {
                if(temp->name==NAME){break;}
                temp=temp->prev;
            }
            if(temp!=nullptr)
             {
                 if(temp==hangchocuoi)
                {
                    if(hangchocuoi!=hangchodau)
                  {
                     customer *p = hangchocuoi->prev;
                     p->next = nullptr;
                     hangchocuoi = p;
                     delete(temp);
                     return ;
                  }
                  else
                  {
                       hangchodau=nullptr;
                       hangchocuoi=hangchodau;
                       return ;
                  }
                }
                else if(temp==hangchodau)
                {
                    if(temp->next!=nullptr)
                   {
                   customer*p=hangchodau->next;
                   p->prev=nullptr;
                   hangchodau=p;
                   delete(temp);
                   }
                   else
                   {
                       hangchodau=nullptr;
                       hangchocuoi=hangchodau;
                       return ;
                   }
                }
                else
                {
                  customer*TEMP=temp->prev;
                  customer*p=temp->next;
                  p->prev=TEMP;
                  TEMP->next=p;
                  temp=nullptr;
                  delete(temp);
                }
             }
        }


        void xoathutucodieukien(string NAME)
        {
            customer*temp=thutucuoi;
            while(temp!=nullptr)
            {
                if(temp->name==NAME){break;}
                temp=temp->prev;
            }
             if(temp!=nullptr)
                {
                if(temp==thutucuoi)
                {
                      temp->print();
                     customer *p = thutucuoi->prev;
                     p->next = nullptr;
                     thutucuoi = p;
                     delete(temp);
                }
                else if (temp==thutudau)
                {
                    temp->print();
                   customer*p=thutudau->next;
                   p->prev=nullptr;
                   thutudau=p;
                   delete(temp);
                }
                else
                {
                  temp->print();
                  customer*TEMP=temp->prev;
                  customer*p=temp->next;
                  p->prev=TEMP;
                  TEMP->next=p;
                  temp=nullptr;
                  delete(temp);
                }
                }
        }

        int demsokhachduong()
        {
            int tong=0;
            customer*temp=head;
            while(temp!=nullptr)
            {
                if(temp->energy>0)
                {
                    tong+=1;
                }
                temp=temp->next;
            }
            return tong;
        }

        int demsokhacham()
        {
            int tong=0;
            customer*temp=head;
            while(temp!=nullptr)
            {
                if(temp->energy<0)
                {
                    tong+=1;
                }
                temp=temp->next;
            }
            return tong;
        }

        void daovitriduong(int a)
        {
            customer*temp=head;
            string ten=vitri->name;
            customer*p=tail;
            int n=(a%2==0)? 0:1;
            for(int i=a;i!=n;i-=2)
            {
                while(temp!=p)
                {
                    if(temp->energy>0){break;}
                    temp=temp->next;
                }
                while(p!=temp)
                {
                    if(p->energy>0){break;}
                    p=p->prev;
                }
                int ENERGY=temp->energy;
                string NAME=temp->name;
                temp->energy=p->energy;
                temp->name=p->name;
                p->energy=ENERGY;
                p->name=NAME;
            }
            temp=head;
            while(temp!=nullptr)
            {
                if(temp->name==ten){vitri=temp;}
                temp=temp->next;
            }
        }

        void daovitriam(int a)
        {
            customer*temp=head;
            string ten=vitri->name;
            customer*p=tail;
            int n=(a%2==0)? 0:1;
            for(int i=a;i!=n;i-=2)
            {
                while(temp!=p)
                {
                    if(temp->energy<0){break;}
                    temp=temp->next;
                }
                while(p!=temp)
                {
                    if(p->energy<0){break;}
                    p=p->prev;
                }
                int ENERGY=temp->energy;
                string NAME=temp->name;
                temp->energy=p->energy;
                temp->name=p->name;
                p->energy=ENERGY;
                p->name=NAME;
            }
            temp=head;
            while(temp!=nullptr)
            {
                if(temp->name==ten){vitri=temp;}
                temp=temp->next;
            }
        }

		void RED(string name, int energy)
		{
		    customer *cus = new customer (name, energy, nullptr, nullptr);
		    if(energy==0){return ;}
		    if(head==nullptr)
            {
              head=cus;
              tail=cus;
              head->next=cus;
              tail->next=nullptr;
              newthutu(name,energy);
              vitri=tail;
            }
            else
            {
            if(kiemtratrungtentrongban(name))
            {

             if(soluongkhachtrongban()<(int)(MAXSIZE/2))
             {
                if(energy>=(vitri->energy))
                {
                    themcungchieukim(cus);
                    themthutu(name,energy);
                }
                else
                {
                    themnguocchieukim(cus);
                    themthutu(name,energy);
                }
             }
               else if((soluongkhachtrongban()>=(int)(MAXSIZE/2))&&(soluongkhachtrongban()<(MAXSIZE)))
             {
              int RES=chenhlechlonnhat(energy);
              if(RES<0){themnguocchieukim(cus); themthutu(name,energy);}
              else {themcungchieukim(cus); themthutu(name,energy);}

             }
             else if(soluongkhachtrongban()==MAXSIZE)
             {
              if(soluongkhachcho()==0)
              {
                   hangchodau=cus;
                   hangchodau->prev=nullptr;
                   hangchodau->next=nullptr;
                   hangchocuoi=hangchodau;
              }
              else
              {
              if(kiemtratrungtenkhachcho(name))
              {
                  if(soluongkhachcho()<MAXSIZE)
                  {
                      themvaohangcho(cus);
                  }
              }
              }
             }

            }

            }
		}

		void BLUE(int num)
		{
		    if(num==0){return;}
		    if(head==nullptr){return;}
		    if(num>=MAXSIZE||num>=soluongkhachtrongban())
                {
                    int a=soluongkhachcho();
                    xoahetkhach();
                    vitri=nullptr;
                    if(hangchodau!=nullptr)
                    { customer*temp=hangchodau;
                    for(int i=0;i<a;i++)
                    {
                    if(hangchodau==nullptr){break;}
                    RED(temp->name,temp->energy);
                    xoakhachdoi(temp->name);
                    temp=hangchodau;
                    }
                    }
                    return;
                }
            else if(num<soluongkhachtrongban())
            {

            int n = (num>soluongkhachtrongban())?soluongkhachtrongban(): num;
		    for(int i=0;i<n;i++)
			{
			    xoakhachtrongban(thutudau->name);
			    customer*p=thutudau->next;
			    customer*P=thutudau;
                p->prev=nullptr;
                thutudau=p;
                delete(P);
			}
			if(hangchodau!=nullptr)
            {
                for(int i=0;i<n;i++)
                {
                    if(hangchodau==nullptr){break;}
                    string NAME=hangchodau->name;
                    int ENERGY=hangchodau->energy;
                    RED(NAME,ENERGY);
                    if(hangchodau->next!=nullptr)
                    {customer *p = hangchodau->next;
                    customer*temp=hangchodau;
	                hangchodau=p;
	                p->prev=nullptr;
	                delete(temp);
                    }
                    if(hangchocuoi==hangchodau)
                    {
                        customer*temp=hangchodau;
                        hangchodau=nullptr;
                        hangchocuoi=hangchodau;
                        delete(temp);
                    }
                }
            }
            }
		}

		void PURPLE()
		{
		    if(head==nullptr){return;}
			int num=soluongkhachcho();
			if(num==0){BLUE (0); return ;}
			customer*temp=hangchodau;
			customer*chocheck=hangchodau;
			int val=temp->energy;
			int VAL=abs(val);
			while(temp!=nullptr)
            {
                if(abs(temp->energy)>=VAL)
                {
                    if(temp->energy>0)
                    {
                       val=temp->energy;
			           VAL=abs(temp->energy);
			           chocheck=temp;
                    }
                    else
                    {
                        if(abs(temp->energy)>VAL)
                        {
                        val=temp->energy;
			            VAL=abs(temp->energy);
                        chocheck=temp;
                        }
                    }
                }
                temp=temp->next;
            }
            temp=hangchodau;
            LinkedList arr;
            while(temp!=chocheck)
            {
                arr.push_back(temp->energy);
                temp=temp->next;
            }
            int hoandoi=arr.shellSort();
            BLUE(hoandoi);
            arr.clear();
		}

		void REVERSAL()
		{
		    int dem=soluongkhachtrongban();
		    if(dem==0||dem==1){return ;}
		    int duong=demsokhachduong();
		    int am=demsokhacham();
		    customer*temp=head;
		    if(temp->energy>0)
            {
                daovitriduong(duong);
                daovitriam(am);
            }
            else
            {
                daovitriam(am);
                daovitriduong(duong);
            }
		}

		void UNLIMITED_VOID()
		{
		    if(vitri==nullptr)
            {
                return ;
            }
		    if(vitri==head)
            {
                timdayconver1();
            }
            else
            {
                timdayconver2();
            }
		}

		void DOMAIN_EXPANSION()
		{
           int NUM1=0;
           int NUM2=0;
           customer*temp=head;
           while(temp!=nullptr)
           {
               if(temp->energy>0){NUM1+=temp->energy;}
               else {NUM2+=temp->energy;}
               temp=temp->next;
           }
           temp=hangchodau;
            while(temp!=nullptr)
           {
               if(temp->energy>0){NUM1+=temp->energy;}
               else {NUM2+=temp->energy;}
               temp=temp->next;
           }
           int n= (NUM1>=abs(NUM2))?1:2;
           switch(n)
           {
           case 1 :
               if(hangchocuoi!=nullptr)
               {
                   temp=hangchocuoi;
                   while(temp!=nullptr)
                   {
                       if(temp->energy<0)
                       {
                           string NAME=temp->name;
                           xoakhachcho(NAME);
                           temp=hangchocuoi;
                       }
                       else
                       {
                           temp=temp->prev;
                       }
                  }
               }

               if(thutucuoi!=nullptr)
               {
                   temp=thutucuoi;
                   while(temp!=nullptr)
                   {
                       if(temp->energy<0)
                       {
                           string NAME=temp->name;
                           xoakhachtrongban(NAME);
                           xoathutucodieukien(NAME);
                           temp=thutucuoi;
                       }
                       else
                       {
                           temp=temp->prev;
                        }
                   }
               }
            break;

           case 2 :
               if(hangchocuoi!=nullptr)
               {
                   temp=hangchocuoi;
                   while(temp!=nullptr)
                   {
                       if(temp->energy>0)
                       {
                           string NAME=temp->name;
                           xoakhachcho(NAME);
                           temp=hangchocuoi;
                       }
                       else
                       {temp=temp->prev;}
                  }
               }
               if(thutucuoi!=nullptr)
               {
                   temp=thutucuoi;
                   while(temp!=nullptr)
                   {
                       if(temp->energy>0)
                       {
                           string NAME=temp->name;
                           xoakhachtrongban(NAME);
                           xoathutucodieukien(NAME);
                           temp=thutucuoi;
                       }
                       else
                       {
                           temp=temp->prev;
                       }
                   }
               }
            break;
           default :
            break;
           }
		}

		void LIGHT(int num)
		{
		    if(num==0)
            {
                customer*temp=hangchodau;
                while(temp!=nullptr)
                {
                    temp->print();
                    temp=temp->next;
                }
            }
            else if(num>0)
            {
                customer*temp=vitri;
                while(temp!=nullptr)
                {
                    temp->print();
                    temp=temp->next;
                }
                temp=head;
                while(temp!=vitri)
                {
                    temp->print();
                    temp=temp->next;
                }
            }
            else if(num<0)
            {
                customer*temp=vitri;
                while(temp!=nullptr)
                {
                    temp->print();
                    temp=temp->prev;
                }
                 temp=tail;
                 while(temp!=vitri)
                {
                    temp->print();
                    temp=temp->prev;
                }
            }
		}
};
