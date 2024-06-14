#include<iostream>
#include<iomanip>
using namespace std;
int Plan_count=0;
int Customer_count=0;
int Position_count=0;
class TrainingPlan{
    string planname;
    float feesperweek;
    int sessionperweek;
    public:
    TrainingPlan()
		{
            planname ="   ";
            sessionperweek=0;
            feesperweek=0;
        }
        TrainingPlan(string n, int s, float f)
		{
            planname=n;
			feesperweek=f;
            sessionperweek=s;
            Plan_count++;
        }
        string get_PlanName() 
		{
            return planname;
        }
        float get_FeesPerWeek() 
		{
            return feesperweek;
        }
        int get_SessionsPerWeek() 
		{
            return sessionperweek;
        }
        void set_Plan()
		{
            cout<<"Enter plan name ::: ";
            cin.get();
            getline(cin, planname);
            cout<<"Enter sesion per week ::: ";
            cin>>sessionperweek;
            feeLabel:
            cout<<"Enter fees per week ::: ";
            cin>>feesperweek;
            cout<<"Successfully created ("<<planname<<")!!! plan"<<endl;
            cin.get();
            Plan_count++;
        }
        void edit_Plan()
		{
            cout<<"Plan name("<<planname<<") ::: "<<endl;
            cout<<"Enter sessions per week ("<<sessionperweek<<") ::: ";
            cin>>sessionperweek;
            feeLabel:
            cout<<"Enter fees per week ("<<feesperweek<<") ::: ";
            cin>>feesperweek;
            cout<<"Successfully updated ("<<planname<<")!!! plan"<<endl;
            cin.get();
        } 
        void display_Plan()
		{
            cout<<setw(20)<<planname
                <<setw(20)<<sessionperweek
                <<setw(15)<<feesperweek;
        }
};
class Customer{
    string customername;
    TrainingPlan trainingplan;
    float Weight;
    int privatehours[4];
    bool privatehoursOF[4];
    int posecounts;
    float cost;
    public:
        Customer(){
            customername="   ";
            Weight=0;
            cost=0;
            posecounts=0;
            for(int i=0;i<4;i++)
			{
                privatehours[i] = 0;
                privatehoursOF[i] = 0;
            }
        }
        Customer(string n, TrainingPlan t, float w, int h[4], bool OnOff[4], int p){
            customername=n;
            trainingplan=t;
            Weight = w;
            cost = 0;
            for(int i=0;i<4;i++)
			{
                privatehours[i]=h[i];
                privatehoursOF[i]=OnOff[i];
            }
            posecounts=p;
            Customer_count++;
        }
        void set_Customer(TrainingPlan plan[])
			{
            int planindex=0;
            cout<<"Enter customer name ::: ";
            cin.get();
            getline(cin, customername);
            trainingplanlabel:
            cout<<"Enter training plan - Available plans :::"<<endl;
            for(int i=0;i<Plan_count;i++)
			{
                cout<<"Plan ::: "<<i+1<<"   "<<plan[i].get_PlanName();
                if(i+1!=Plan_count) 
				{
				cout<<" ,"<<endl;
				}
            }
            cout<<"Choose the index ::: ";
            if(planindex<0||planindex>Plan_count) 
			{
			goto trainingplanlabel;	
			}
            cin>>planindex;
            trainingplan=plan[planindex-1];
            cout<<"Enter weight(kg) ::: ";
            cin>>Weight;
            for(int i=0;i<4;i++)
			{
                char o='0';
                privatehourlabel:
                cout<<endl<<"Enter "<<i+1<<" week private hours ::: ";
                cin>>privatehours[i];
                if(privatehours[i]<0||privatehours[i]>5) 
				{
                    cout<<"It is not more than 5 or less than 0"<<endl;
                    goto privatehourlabel;
                }
                onlineofflinelabel:
                cout<<"Online/Offline(0/1) ::: ";
                cin>>o;
                if(o=='0') 
				{
				privatehoursOF[i]=0;
				}
                else 
				{
				privatehoursOF[i]=1;
				}
            }
            cout<<"Enter learnt poses counts ::: ";
            cin>>posecounts;
            Customer_count++;
            display_CustomerDetails();
        }
        void edit_Customer(TrainingPlan plan[])
			{
            int planindex=0;
            cout<<"Customer name("<<customername<<") ::: "<<endl;
            trainingplanlabel:
            cout<<"Enter training plan - Available plans ::: "<<endl;
            for(int i=0;i<Plan_count;i++)
			{
                cout<<"Plan ::: "<<i+1<<"    "<<plan[i].get_PlanName();
                if(i+1!=Plan_count) 
				{
				cout<<" ,"<<endl;
				}
            }
            cout<<endl<<"Choose the index ::: ";
            if(planindex<0||planindex>Plan_count) 
			{
			goto trainingplanlabel;
			}
            cin>>planindex;
            trainingplan=plan[planindex-1];
            cout<<"Enter current weight(kg) ::: ";
            cin>>Weight;
            for(int i=0;i<4;i++){
                char o='0';
                privatehourlabel:
                cout<<endl<<"Enter "<<i+1<<"  week private hours ::: ";
                cin>>privatehours[i];
                if(privatehours[i]<0||privatehours[i]>5) 
				{
                    cout<<"It is not more 5 or less than 0"<<endl;
                    goto privatehourlabel;
                }
                onlineofflinelabel:
                cout<<"Online/Offline(0/1) ::: ";
                cin>>o;
                if(o=='0') 
				{
				privatehoursOF[i]=0;
				}
                else 
				{
				privatehoursOF[i]=1;
				}
            }
            display_CustomerDetails();
        }
        float get_FinalCost()
		{
            cost=0;
            cost+=trainingplan.get_FeesPerWeek()*4;
            int count=posecounts;
            if(count>=5) 
			{
			count=5;
			}
            for(int i=0;i<4;i++)
			{
                if(privatehoursOF[i]) 
				{
				cost+=15000*privatehours[i];
				}
                else 
				{
				cost += 17000*privatehours[i];
				}
            }
            return cost-(cost*count)/100;
        }
        float getCost() 
		{
            cost=0;
            cost+=trainingplan.get_FeesPerWeek()*4;
            for(int i=0;i<4;i++)
		{
                if(privatehoursOF[i]) 
				{
				cost+=15000*privatehours[i];
				}
                else 
				{
				cost+=17000*privatehours[i];
				}
            }
            return cost;
        }
        void display_CustomerDetails()
			{
            int online=0,offline=0;
            int count=min(5,posecounts);
            for(int i=0;i<4;i++)
			{
                if(privatehoursOF[i])
				{
				online++;	
				} 
                else 
				{
				offline++;
				}
            }
            cout<<setw(30)<<"Customer name ::: "<<setw(20)<<customername<<endl
                <<setw(30)<<"Weight ::: "<<setw(20)<<Weight<<endl
                <<setw(30)<<"Learnt poses counts ::: "<<setw(20)<<count<<endl
                <<setw(30)<<"Training plan ::: "<<setw(20)<<trainingplan.get_PlanName()<<endl
                <<setw(30)<<"Sessions per week ::: "<<setw(20)<<trainingplan.get_SessionsPerWeek()
                <<setw(20)<<trainingplan.get_FeesPerWeek()*4<<endl
                <<setw(30)<<"Private(Online-15000) ::: "<<setw(20)<<online<<setw(20)<<15000*online<<endl
                <<setw(30)<<"Private(Offline-17000) ::: "<<setw(20)<<offline<<setw(20)<<17000*offline<<endl
                <<setw(30)<<"DISCOUNT(%) ::: "<<setw(20)<<count<<setw(20)<<getCost()*count/100<<endl
                <<setw(30)<<"Total Cost ::: "<<setw(20)<<"  "<<setw(20)<<get_FinalCost()<<endl;
        }
        void display_Customer()
		{
            cout<<setw(20)<<customername
                <<setw(25)<<trainingplan.get_PlanName()
                <<setw(10)<<Weight
                <<setw(20)<<posecounts
                <<setw(20)<<get_FinalCost();
        }
};
class Position{
    string positionname;
    int posecount;
    string posetype[10];
    string posename[10];
    public:
        Position(){
            positionname="   ";
            posecount=0;
        }
        Position(string n,string na[],string ptype[],int p){
            positionname = n;
            posecount = p;
            Position_count++;
            for(int i=0;i<p;i++)
		{
                posetype[i]=ptype[i];
                posename[i]=na[i];
            }
        }
        void add_Poses()
		{
            cout<<"Position name ::: "<<positionname<<endl;
            cout<<"Positions ::: "<<endl;
            for(int i=0;i<posecount;i++) 
			{
                cout<<posename[i];
                if(i+1!=posecount) 
				{
				cout<<" , ";
				}
                else 
				{
				cout<<endl;
				}
            }
            if(posecount == 10) 
			{
                cout<<"10 poses already added"<<endl;
                cin.get();
                return;
            }
            cin.get();
            char More='y';
            while(true){
                addmorelabel:
                if(posecount==10) 
				{
				break;
				}
                cout<<"Enter position name("<<posecount+1<<") ::: ";
                getline(cin, posename[posecount]);
                cout<<"Enter position type("<<posecount+1<<") ::: ";
                getline(cin, posetype[posecount]);
                cout<<"Successfully added("<<posename[posecount]<<")"<<endl;
                posecount++;
                morelabel:
                cout<<"Add more?(y/n) ::: ";
                cin>>More;
                if(More=='n') 
				{
				break;
				}
                else 
				{
				goto addmorelabel;
				}
            }
        }
        void setPosition()
		{
            cout<<"Enter position name ::: ";
            cin.get();
            getline(cin,positionname);
            add_Poses();
            Position_count++;
        }
        void display_Position(){
            cout<<setw(20)<<positionname<<endl;
            for(int i=0;i<posecount;i++){
                cout<<setw(25)<<"  "
                    <<setw(20)<<posetype[i]
                    <<setw(20)<<posename[i]
                    <<endl;
            }
        }
};
void display_TrainingPlans(TrainingPlan plan[]){
    cout<<setw(5)<<"No"
        <<setw(20)<<"Plan name"
        <<setw(20)<<"Session per week"
        <<setw(15)<<"Fees per week"
        <<endl;
    for(int i=0;i<Plan_count;i++) 
	{
        cout<<setw(5)<<i+1;
        plan[i].display_Plan();
        cout<<endl;
    }
}
void display_Customers(Customer customer[])
	{
    cout<<setw(5)<<"No"
        <<setw(20)<<"Customer name"
        <<setw(25)<<"Training plan"
        <<setw(10)<<"Weight(kg)"
        <<setw(20)<<"Learnt poses count"
        <<setw(20)<<"Cost(current month)"
        <<endl;
    for(int i=0;i<Customer_count;i++) 
	{
        cout<<setw(5)<<i+1;
        customer[i].display_Customer();
        cout<<endl;
    }
}
void display_YogaPositions(Position pose[]){
    cout<<setw(5)<<"No"
        <<setw(20)<<"Position names"
        <<setw(20)<<"Pose type"
        <<setw(20)<<"Pose name"
        <<endl;
    for(int i=0; i<Position_count;i++) 
	{
        cout<<setw(5)<<i+1;
        pose[i].display_Position();
        cout<<endl;
    }
}
int main(){
    int menucode;
    Position pose[5];
    string basicposetypes[] = {"Standing Pose","Standing Pose","Standing Pose","Standing Pose",
    "Balancing Pose","Balancing Pose","Balancing Pose","Balancing Pose","Seat Pose","Backend Pose"};
    string basicposenames[] ={"Archer Pose","Dolphin Pose","Frog Pose","Fallen Triangle","Big Toe Pose",
    "Lion Pose","Airplane Pose","Side Lunge","Side Reclining","Bird Dog Pose"};
    Position pose1("BASIC",basicposenames,basicposetypes,10);
    string intermediateposetypes[] = {"Standing Pose","Standing Pose","Standing Pose","Standing Pose","Balancing Pose",
    "Balancing Pose","Balancing Pose","Balancing Pose","Seat Pose","Backend Pose"};
    string intermediateposenames[] ={"Downward Facing Pose","Mountain Pose","Warrior Pose","Traingle Triangle",
    "Low Lunge","Tree Pose","Plank Pose","Bridge Lunge","Staff Pose","Cobbler's Pose"};
    Position pose2("INTERMEDIATE",intermediateposenames,intermediateposetypes,10);
    pose[0] = pose1;
    pose[1] = pose2;
    TrainingPlan plans[7];
    TrainingPlan basicplan("BASIC",3,25000);
    TrainingPlan intermediateplan("INTERMEDIATE",3,35000);
    TrainingPlan advancedplan("ADVANCED",2,50000);
    plans[0]=basicplan;
    plans[1]=intermediateplan;
    plans[2]=advancedplan;

    Customer customer[100];
    int c1Private[4]={1,1,3,2};
    bool c1OnOff[4]={true,true,true,true};
    int c2Private[4]={1,1,3,2};
    bool c2OnOff[4]={true,false,true,false};
    int c3Private[4]={1,1,3,2};
    bool c3OnOff[4]={true,false,false,true};
    int c4Private[4]={1,1,3,2};
    bool c4OnOff[4]={true,false,true,true};
    int c5Private[4]={1,1,3,2};
    bool c5OnOff[4]={true,false,false,true};
    Customer cu1("Phone Thant",plans[0],50,c1Private,c1OnOff,10);
    Customer cu2("Nyi Nyi Aung",plans[0],55,c2Private,c2OnOff,3);
    Customer cu3("Ye Htet Naing",plans[0],60,c3Private,c3OnOff,0);
    Customer cu4("Kaung Myat Wai",plans[1],65,c4Private,c4OnOff,1);
    Customer cu5("Mi Thiha Aung",plans[2],70,c5Private,c5OnOff,0);
    customer[0]=cu1;
    customer[1]=cu2;
    customer[2]=cu3;
    customer[3]=cu4;
    customer[4]=cu5;
    cout<<" "<<endl<<" "<<endl<<" "<<endl<<" "<<endl<<" "<<endl;
    menulabel:
    cout<<"Welcome from The Amazing Sport Yoga System!!!"<<endl
        <<setw(20)<<"1. Training plan"<<endl
        <<setw(15)<<"2. Customer"<<endl
        <<setw(20)<<"0. Quit program"<<endl
		<<"Choose :::";
    cin>>menucode;
    if(menucode==1)
	 {
        trainingplanscreenlabel:
        int trainingmenucode=0;
        cout<<endl<<"1. Display all training plans."
            <<endl<<"2. Create a training plan."
            <<endl<<"3. Edit a training plan."
            <<endl<<"4. Display all yoga plans."
            <<endl<<"5. Create a yoga plan."
            <<endl<<"6. Add yoga poses to an existing plan."
            <<endl<<"0. Return to main screen."<<endl;
        cin>>trainingmenucode;
        if(trainingmenucode<0||trainingmenucode>6) 
		{
		goto trainingplanscreenlabel;
		}
        if(trainingmenucode==0) 
		{
		goto menulabel;
		}
        else if(trainingmenucode == 1) 
		{
		display_TrainingPlans(plans);	
		}
		
        else if(trainingmenucode==2) plans[Plan_count].set_Plan();
        else if(trainingmenucode==3) 
		{
            int index = 0;
            display_TrainingPlans(plans);
            cout<<"Enter number to update ::: ";
            cin>>index;
            plans[index-1].edit_Plan();
        }
        else if(trainingmenucode==4) 
		{
		display_YogaPositions(pose);
		}
        else if(trainingmenucode==5) 
		{
		pose[Position_count].setPosition();	
		}
        else if(trainingmenucode==6) 
		{
            int index = 0;
            display_YogaPositions(pose);
            cout<<endl<<"Enter yoga plan index to add ::: ";
            cin>>index;
            pose[index-1].add_Poses();
        }
        goto trainingplanscreenlabel;
    } 
    else if(menucode==2){
        customerScreenLabel:
        int customerScreenCode = 0;
        cout<<"1. Create a new customer."
            <<endl<<"2. Display all customers."
            <<endl<<"3. Edit customer info."
            <<endl<<"4. Cost details for a customer."
            <<endl<<"0. Return to main screen. "<<endl;
        cin>>customerScreenCode;
        if(customerScreenCode<0||customerScreenCode>4)
		{
		goto customerScreenLabel;	
		} 
        if(customerScreenCode == 0) 
		{
		goto menulabel;	
		}
		
        else if(customerScreenCode == 1) 
		{
            customer[Customer_count].set_Customer(plans);
        }
        else if(customerScreenCode == 2) 
		{
		display_Customers(customer);
		}
        else if(customerScreenCode == 3) 
		{
            int index = 0;
            display_Customers(customer);
            cout<<"Enter number to update ::: ";
            cin>>index;
            customer[index-1].edit_Customer(plans);
        }
        else if(customerScreenCode == 4) 
		{
            int index = 0;
            display_Customers(customer);
            cout<<"Enter number to calculate costs ::: ";
            cin>>index;
            customer[index-1].display_CustomerDetails();
        }
        goto customerScreenLabel;
    }
    else if(menucode==0) 
	{
	return 0;
	}
    else  
	{
	goto menulabel;
	}
}
