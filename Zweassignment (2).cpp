#include<iostream>
#include<iomanip>
using namespace std;
int Plan=0;
int customer=0;
int Postion=0;
class TrainingPlan{
    string TrainingPlanName;
    int SessionPerWeek;
    float FeesPerWeek;
    public:
        TrainingPlan()
		{
            TrainingPlanName = "";
            SessionPerWeek = 0;
            FeesPerWeek = 0;
        }
        TrainingPlan(string n, int s, float f)
		{
            TrainingPlanName = n;
            SessionPerWeek = s;
            FeesPerWeek = f;
            Plan++;
        }
        
        void Set_Plan(TrainingPlan plan[])
		{
            cout<<"Enter Plan Name  :: ";
            cin.get();
            getline(cin, TrainingPlanName);
            cout<<"Enter Sesion Per Week  :: ";
            cin>>SessionPerWeek;
            feeLabel:
            cout<<"Enter fees per week : ";
            cin>>FeesPerWeek;
            cout<<"Successfully created a training plan("<<TrainingPlanName<<")!"<<endl;
            cin.get();
            Plan++;
        }
        void Update_Plan(){
            cout<<"Plan Name[ "<<TrainingPlanName<<" ] :: "<<endl;
            cout<<"Enter Sessions Per Week [ "<<SessionPerWeek<<" ] :: "<<endl;
            cin>>SessionPerWeek;
            feeLabel:
            cout<<"Enter fees per week ("<<FeesPerWeek<<") : ";
            cin>>FeesPerWeek;
            cout<<"Successfully updated the training plan("<<TrainingPlanName<<")!\n";
            cin.get();
        } 
        string Get_PlanName() 
		{
		return TrainingPlanName;
		}
        float Get_FeesPerWeek() 
		{
		return FeesPerWeek;
		}
        int Get_SessionsPerWeek() 
		{
		return SessionPerWeek;
		}
        void Display_Plan()
		{
            cout<<setw(20)<<TrainingPlanName<<setw(20)<<SessionPerWeek<<setw(15)
			<<FeesPerWeek<<endl;     
        }
};

class Customer{
    string CustomerName;
    TrainingPlan Trainingplan;
    float CurrentWeight;
    int PrivateHours[4];
   	bool PrivateHourof[4];
   	int LearntPoses;
   	float Cost;
   	public:
   	Customer()
	{
	CustomerName="";
	CurrentWeight=0;
	Cost=0;
	LearntPoses=0;
	for(int i=0;i<4;i++)
	{
	PrivateHours[i]=0;
	PrivateHourof[i]=0;
	}
	}
	Customer(string n, TrainingPlan t, float w, int h[4], bool of[4]){
	CustomerName= n;
	Trainingplan= t;
	CurrentWeight= w;
	Cost=0;
	for(int i=0;i<4;i++)
	{
	PrivateHours[i] = h[i];
	PrivateHourof[i] = of[i];
	}
	customer++;
   	}
    void Set_Customer(TrainingPlan plan[])
	{
            int Planin=0;
            cout<<"Enter Customer Name :: ";
            cin.get();
            getline(cin, CustomerName);
            TrainingPlanLabel:
            cout<<"Enter Training plan"<<endl<<"Chooseable Plans are described :: "<<endl;
            for(int i=0;i<Plan;i++)
			{
                cout<<"Plan :: "<<i+1<<"    "<<plan[i].Get_PlanName();
                if(i+1!=Plan) 
				cout<<" /"<<endl;
            }
            cout<<endl<<"Choose The Index : ";
            if(Planin<0 || Planin > Plan) 
			goto TrainingPlanLabel;
            cin>>Planin;
            Trainingplan = plan[Planin-1];
            cout<<"Enter current weight : ";
            cin>>CurrentWeight;
            for(int i=0;i<4;i++)
			{
                char O='0';
                PrivateHourLabel:
                cout<<"Enter"<<i+1<<" week private hours :: "<<endl;
                cin>>PrivateHours[i];
                if(PrivateHours[i]<0 || PrivateHours[i]>5) 
				{
                cout<<"More Than 5 or Less Than 0"<<endl;
                goto PrivateHourLabel;
                }
                
                OnlineOfflineLabel:
                cout<<"Online=0 OR Offline=1 :: ";
                cin>>O;
                if(O!='0'||O!='1') 
				goto OnlineOfflineLabel;
                if(O=='0') 
                {
                PrivateHourof[i]=0;	
                }
                else 
				{
				PrivateHourof[i]=1;
				}
            }
            cout<<"Enter Learnt Poses Counts :: ";
            cin>>LearntPoses;
            customer++;
        }
        string Update_Customer(TrainingPlan plan[]){
            int Planin = 0;
            cout<<"Customer name("<<CustomerName<<") :: "<<endl;

            TrainingPlanLabel:
            cout<<"Enter training plan"<<endl<<"Chooseable Plans are described :: "<<endl;
            for(int i=0;i<Plan;i++)
			{
                cout<<"Plan :: "<<i+1<<"    "<<plan[i].Get_PlanName();
                if(i+1!=Plan) 
				{
				cout<<" /"<<endl;
				}
            }
            cout<<"Choose The Index :: ";
            if(Planin<0 || Planin > Plan) 
			{
			goto TrainingPlanLabel;
			}
            cin>>Planin;
            Trainingplan=plan[Planin-1];
            cout<<"Enter Current weight(kg) :: ";
            cin>>CurrentWeight;
            for(int i=0;i<4;i++)
			{
                char O='0';
                cout<<"Enter"<<i+1<<"  week private hours :: "<<endl;
                cin>>PrivateHours[i];
                OnOffLabel:
                cout<<"Online(0) OR Offline(1) : ";
                cin>>O;
                if(O!='0'||O!='1') 
				{
				goto OnOffLabel;
				}
                if(O=='0') 
				{
				PrivateHourof[i]=0;
				}
                else 
				{
				PrivateHourof[i] = 1;
				}
            }
            return Trainingplan.Get_PlanName();
        }
        float Get_FinalCost(){
            Cost=0;
            Cost += Trainingplan.Get_FeesPerWeek()*4;
            
            for(int i=0;i<4;i++)
			{
                if(PrivateHourof[i]) 
				{
				Cost+=15000*PrivateHours[i];
				}
                else 
				{
				Cost+=17000*PrivateHours[i];
				}
            }
            return Cost-(Cost*LearntPoses)/100;
        }
        float Get_Cost() {
            Cost=0;
            Cost+=Trainingplan.Get_FeesPerWeek()*4;
            
            for(int i=0;i<4;i++)
			{
                if(PrivateHourof[i]) 
				{
				Cost+=15000*PrivateHours[i];
				}
                else 
				{
				Cost+=17000*PrivateHours[i];
				}
            }
            return Cost;
        }
        void Display_Customer(){
            cout<<setw(20)<<CustomerName
                <<setw(20)<<Trainingplan.Get_PlanName()
                <<setw(10)<<LearntPoses
                <<setw(20)<<Get_FinalCost();
        }
        void Display_CustomerDetails(){
            int Online=0,Offline=0;
            for(int i=0;i<4;i++)
			{
                if(PrivateHourof[i]) 
				{
				Online++;
				}
                else 
				{
				Offline++;
				}
            }
            cout<<setw(30)<<"Customer name :: "<<setw(20)<<CustomerName<<endl
                <<setw(30)<<"Weight :: "<<setw(20)<<CurrentWeight<<endl
                <<setw(30)<<"Training plan :: "<<setw(20)<<Trainingplan.Get_PlanName()<<endl
                <<setw(30)<<"Learnt poses  :: "<<setw(20)<<LearntPoses<<endl
                <<setw(30)<<"Sessions per week :: "<<setw(20)
				<<Trainingplan.Get_SessionsPerWeek()
                <<setw(20)<<Trainingplan.Get_FeesPerWeek()*4<<endl
                <<setw(30)<<"Private(Online-15000) :: "<<setw(20)
				<<Online<<setw(20)<<15000*Online<<endl
                <<setw(30)<<"Private(Offline-17000) :: "<<setw(20)
				<<Offline<<setw(20)<<17000*Offline<<endl
                <<setw(30)<<"DISCOUNT(%) :: "<<setw(20)<<LearntPoses
				<<setw(20)<<Get_Cost()*LearntPoses/100<<endl
                <<setw(30)<<"Total Cost :: "<<setw(20)<<"   "<<setw(20)
				<<Get_FinalCost()<<endl;
            	cin.get();
        }
};
class Position{
    string Name;
    int PoseCount;
    public:
        string PoseType[10];
        string PoseName[10];
        Position(){
            Name="   ";
            PoseCount=0;
        }
        Position(string Name,string type[10],string name[10]){
            name=name;
            for(int i=0; i<10; i++)
		{
                PoseType[i]=type[i];
                PoseName[i]=name[i];
                PoseCount++;
            }
            Postion++;
        }
        void Add_Position()
		{
            cout<<"Position name :: "<<Name<<endl;
            cout<<"Positions :: "<<endl;
            for(int i=0;i<PoseCount;i++) 
		{
                cout<<PoseName[i];
                if(i+1!=PoseCount) 
				{
				cout<<"  /  ";
				}
                else 
				{
				cout<<endl;
				}
            }
            if(PoseCount == 10) 
			{
                cout<<"10 poses have been added"<<endl;
                cin.get();
                return;
            }
            char More = 'y';
            while(true){
                if(PoseCount==10) 
				{
				break;
				}
                cout<<"Enter position name ("<<PoseCount+1<<")  ::";
                cin.get();
                getline(cin,PoseName[PoseCount]);
                cout<<"Enter position type( "<<PoseCount+1<<" ) : ";
                getline(cin,PoseType[PoseCount]);
                cout<<"Successfully added ("<<PoseName[PoseCount]<<") "<<endl;
                PoseCount++;
                MoreLabel:
                cout<<"Add more? (y/n) : ";
                cin>>More;
                if(More=='n') 
				{
				break;
				}
                if(More!='n'||More!='y') 
				{
				goto MoreLabel;
				}
            }
        }
        void Create_Position()
		{
            cout<<"Enter position name :: ";
            cin.get();
            getline(cin,Name);
            Add_Position();
        }
        void Display_Position()
		{
            cout<<setw(20)<<Name<<endl;
            for(int i=0;i<PoseCount;i++)
			{
                cout<<setw(25)<<"  "
                    <<setw(20)<<PoseType[i]
                    <<setw(20)<<PoseName[i]
                    <<endl;
            }
        }
};
void Display_TrainingPlans(TrainingPlan plan[]);
void Display_YogaPositions(Position pose[]);
void Display_Customers(Customer customer[]);
int main(){
    int MenuCode;
    Position pose[5];
    string BasicPoseType[10] = {"Standing Pose","Standing Pose","Standing Pose",
	"Standing Pose","Balancing Pose","Balancing Pose","Balancing Pose",
	"Balancing Pose","Seat Pose","Backend Pose"};
    string BasicPoseNames[10] ={"Archer Pose","Dolphin Pose","Frog Pose","Fallen Triangle","Big Toe Pose","Lion Pose","Airplane Pose","Side Lunge","Side Reclining","Bird Dog Pose"};
    Position Pose1("Basic",BasicPoseType,BasicPoseNames);
    string intermediatePoseType[10] = {"Standing Pose","Standing Pose","Standing Pose",
	"Standing Pose","Balancing Pose","Balancing Pose","Balancing Pose","Balancing Pose",
	"Seat Pose","Backend Pose"};
    string intermediatePoseNames[10] ={"Downward Facing Pose","Mountain Pose",
	"Warrior Pose","Traingle Triangle","Low Lunge","Tree Pose","Plank Pose",
	"Bridge Lunge","Staff Pose","Cobbler's Pose"};
    Position Pose2("Intermediate",intermediatePoseType,intermediatePoseNames);
    pose[0] = Pose1;
    pose[1] = Pose2;
    TrainingPlan plan[7];
    TrainingPlan basic("Basic",3,25000);
    TrainingPlan intermediate("Intermediate",3,35000);
    TrainingPlan advanced("Advance",2,50000);
    plan[0] = basic;
    plan[1] = intermediate;
    plan[2] = advanced;
    Customer customers[50];
    int customer1Private[4] = {1,1,3,2};
    bool customer1OnOff[4] = {true,false,true,true};
    int customer2Private[4] = {1,1,3,2};
    bool customer2OnOff[4] = {true,true,true,false};
    int customer3Private[4] = {1,1,3,2};
    bool customer3OnOff[4] = {true,true,false,true};
    int customer4Private[4] = {1,1,3,2};
    bool customer4OnOff[4] = {false,false,true,true};
    int customer5Private[4] = {1,1,3,2};
    bool customer5OnOff[4] = {true,false,false,true};
    Customer customer1("Min Thiha Aung",plan[0],70,customer1Private,customer1OnOff);
    Customer customer2("Nyi Nyi Aung",plan[0],60,customer2Private,customer2OnOff);
    Customer customer3("Zwe Hset Naing",plan[0],50,customer3Private,customer3OnOff);
    Customer customer4("Kaung Myat Wai",plan[0],40,customer4Private,customer4OnOff);
    Customer customer5("Thurein Kyaw Htay",plan[0],55,customer5Private,customer5OnOff);
    customers[0] = customer1;
    customers[1] = customer2;
    customers[2] = customer3;
    customers[3] = customer4;
    customers[4] = customer5;
    MenuLabel:
    cout<<"Welcome from Amazing Sport Yoga System!"<<endl
        <<setw(20)<<"1. Training plan."<<endl
        <<setw(15)<<"2. Customer"<<endl
        <<setw(20)<<"0. Quit program."<<endl;
    cin>>MenuCode;
    if(MenuCode==1) 
	{
        TrainingPlanScreenLabel:
        int TrainingMenuCode=0;
        cout<<"1. Add a training plan."<<endl<<"2. Show all training plans."<<endl
		<<"3. Update a training plan."<<endl<<"4. Add a yoga plan."<<endl
		<<"5. Display yoga plans."<<endl<<"6. Add yoga poses."<<endl
		<<"0. Return to main screen."<<endl;
        cin>>TrainingMenuCode;
        if(TrainingMenuCode<0 || TrainingMenuCode>6) 
		{
		goto TrainingPlanScreenLabel;
		}
        if(TrainingMenuCode == 0) 
		{
		goto MenuLabel;
		}
        else if(TrainingMenuCode == 1) 
		{
		plan[Plan].Set_Plan(plan);
		}
        else if(TrainingMenuCode == 2) 
		{
		Display_TrainingPlans(plan);
		}
        else if(TrainingMenuCode == 3) 
		{
            int index=0;
            Display_TrainingPlans(plan);
            cout<<"Enter number to update :: ";
            cin>>index;
            plan[index-1].Update_Plan();
        }
        else if(TrainingMenuCode==4) 
		{
		pose[Postion].Create_Position();
		}
        else if(TrainingMenuCode==5) 
		{
		Display_YogaPositions(pose);
		}
        else if(TrainingMenuCode==6) 
		{
            int index=0;
            Display_YogaPositions(pose);
            cout<<endl<<"Enter yoga plan index :: ";
            cin>>index;
            pose[index-1].Add_Position();
        }
        goto TrainingPlanScreenLabel;
    } 
    else if(MenuCode==2){
        CustomerScreenLabel:
        int CustomerScreenCode=0;
        cout<<"1. Register a customer."<<endl<<"2. Display all customers."<<endl
		<<"3. Update customer data."<<endl<<"4. Calculate all cost for the customer."<<endl<<
		"0. Return to main menu."<<endl;
        cin>>CustomerScreenCode;
        if(CustomerScreenCode<0 || CustomerScreenCode>4) 
		{
		goto CustomerScreenLabel;
		}
        if(CustomerScreenCode==0) 
		{
		goto MenuLabel;
		}
        else if(CustomerScreenCode==1) 
		{
            customers[customer].Set_Customer(plan);
        }
        else if(CustomerScreenCode==2) 
		{
		Display_Customers(customers);
		}
        else if(CustomerScreenCode==3) 
		{
            int index=0;
            Display_Customers(customers);
            cout<<"Enter number to update :: ";
            cin>>index;
            customers[index-1].Update_Customer(plan);
        }
        else if(CustomerScreenCode==4) 
		{
            int index=0;
            Display_Customers(customers);
            cout<<"Enter number to calculate all cost :: ";
            cin>>index;
            customers[index-1].Display_CustomerDetails();
        }
        goto CustomerScreenLabel;
    }
    else if(MenuCode==0) 
	{
	return 0;
	}
    else 
	{
	goto MenuLabel;
	}
}
void Display_TrainingPlans(TrainingPlan plan[]){
    cout<<setw(5)<<" No "
        <<setw(20)<<" Plan name "
        <<setw(20)<<" Session per week "
        <<setw(15)<<" Fees per week "
        <<endl;
    for(int i=0;i<Plan;i++) 
	{
        cout<<setw(5)<<i+1;
        plan[i].Display_Plan();
        cout<<endl;
    }
}

void Display_YogaPositions(Position pose[]){
    cout<<setw(5)<<" No "
        <<setw(20)<<" Position name "
        <<setw(20)<<" Pose type "
        <<setw(20)<<"Pose name"
        <<endl;
    for(int i=0;i<Postion;i++) 
	{
        cout<<setw(5)<<i+1;
        pose[i].Display_Position();
        cout<<endl;
    }
}
void Display_Customers(Customer customers[])
	{
    cout<<setw(5)<<" No "
        <<setw(20)<<" Customer name "
        <<setw(20)<<" Training plan "
        <<setw(10)<<" Learnt poses count "
        <<setw(20)<<" Cost(current month) "
        <<endl;
    for(int i=0;i<customer;i++) 
	{
        cout<<setw(5)<<i+1;
        customers[i].Display_Customer();
        cout<<endl;
    }
}