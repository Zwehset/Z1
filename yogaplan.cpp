#include<iostream>
#include<iomanip>
using namespace std;
int Plan=0;
int customer=0;
int Postion=0;
//trainingclass
class TrainingPlan{
    	string TrainingPlanName;
    	int SessioninWeek;
    	float FeeforWeek;
    	public:
    	//trainingplanobject
        TrainingPlan()
		{
            TrainingPlanName="   ";
            SessioninWeek=0;
            FeeforWeek=0;
        }
		TrainingPlan(string n, int s, float f)
		{
            TrainingPlanName=n;
            SessioninWeek=s;
            FeeforWeek=f;
            Plan++;
        }
        //trainingplanfunction
        void Set_Plan(TrainingPlan plan[])
		{
            cout<<"Enter Plan Name  :: ";
            cin.get();
            getline(cin,TrainingPlanName);
            cout<<"Enter Sesion Per Week  :: ";
            cin>>SessioninWeek;
            cout<<"Enter fees per week : ";
            cin>>FeeforWeek;
            cout<<"Successfully created a training plan("<<TrainingPlanName<<")>_<"<<endl;
            Plan++;
        }
        //getplan
		string Get_PlanName() 
		{
		return TrainingPlanName;
		}
        float Get_FeesPerWeek() 
		{
		return FeeforWeek;
		}
        int Get_SessionsPerWeek() 
		{
		return SessioninWeek;
		} 
		//updateplan
        void Update_Plan()
		{
            cout<<"Plan Name[ "<<TrainingPlanName<<" ] :: "<<endl;
            cout<<"Enter Sessions Per Week [ "<<SessioninWeek<<" ] :: ";
            cin>>SessioninWeek;
            cout<<"Enter fees per week ("<<FeeforWeek<<") : ";
            cin>>FeeforWeek;
            cout<<"Successfully updated the training plan("<<TrainingPlanName<<")>_<"<<endl;
        } 
        //displayplan
		void Display_Plan()
		{
            cout<<setw(18)<<TrainingPlanName
				<<setw(15)<<SessioninWeek
				<<setw(17)<<FeeforWeek<<endl;     
        }
        
};
//customerclass
class Customer{
    string CustomerName;
    TrainingPlan Trainingplan;
    float CurrentWeight;
    int PrivateHours[4];
   	bool PrivateHourof[4];
   	int LearntPoses;
    string LearntPosesArr[10];
   	float Cost;
   	public:
   	Customer()
	{
	CustomerName="   ";
	CurrentWeight=0;
	Cost=0;
	LearntPoses=0;
	for(int i=0;i<4;i++)
	{
	PrivateHours[i]=0;
	PrivateHourof[i]=0;
	}
	}
	Customer(string n, TrainingPlan t, float w, int h[4], bool o[4], int l){
	CustomerName=n;
	Trainingplan=t;
	CurrentWeight=w;
	Cost=0;
    LearntPoses =l;
	for(int i=0;i<4;i++)
	{
	PrivateHours[i]=h[i];
	PrivateHourof[i]=o[i];
	}
	customer++;
   	}
   	//addlearntposes
    void addLearntPoses(string pose[])
    {
        char learnt='y';
        int ind=0;
        int learntInd=0;
        cout<<"Already learnt poses?(y/n) :: ";
        cin>>learnt;
        if(learnt=='y') 
	{
            for(int i=0;i<10;i++)
	{
                cout<<"("<<i+1<<")"<<pose[i];
                if(i+1 != 10)cout<<" , ";
            }
            while(true){
                char more = 'y';
                cout<<"\nEnter pose index : ";
                cin>>ind;
                cout<<"Got more?(y/n) : ";
                cin>>more;
                LearntPoses++;
                LearntPosesArr[learntInd] = pose[ind-1];
                learntInd++;
                if(more!='y') break;
            }
        }
        cout<<endl;
    }
	//setcustomer
    string Set_Customer(TrainingPlan plan[])
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
                cout<<"Enter week "<<i+1<<" private hours :: ";
                cin>>PrivateHours[i];
                if(PrivateHours[i]<0 || PrivateHours[i]>5) 
				{
                cout<<"More Than 5 or Less Than 0"<<endl;
                goto PrivateHourLabel;
                }
                
                OnlineOfflineLabel:
                cout<<"Online=0 OR Offline=1 :: ";
                cin>>O;
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
            return Trainingplan.Get_PlanName();
        }
        //updatecustomer
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
                cout<<"Enter week "<<i+1<<" private hours :: ";
                cin>>PrivateHours[i];
                OnOffLabel:
                cout<<"Online(0) OR Offline(1) : ";
                cin>>O;
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
        //getfinalcost
        float Get_FinalCost(){
            Cost=0;
            Cost += Trainingplan.Get_FeesPerWeek()*4;
            int Count = LearntPoses;
            if(Count > 5) Count = 5;
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
            return Cost-(Cost*Count)/100;
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
            cout<<setw(19)<<CustomerName
                <<setw(19)<<Trainingplan.Get_PlanName()
                <<setw(10)<<LearntPoses
                <<setw(22)<<Get_FinalCost();
        }
        void Display_CustomerDetails(){
            int Online=0,Offline=0;
            int Count = LearntPoses;
            if(Count > 5) Count = 5;
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
                <<setw(30)<<"Learnt poses  :: "<<setw(20)<<LearntPoses;
            for(int i=0; i<LearntPoses; i++) 
			{
			cout<<LearntPosesArr[i];
			}
            cout<<endl<<setw(30)<<"Sessions per week :: "<<setw(20)
				<<Trainingplan.Get_SessionsPerWeek()
                <<setw(20)<<Trainingplan.Get_FeesPerWeek()*4<<endl
                <<setw(30)<<"Private(Online-15000) :: "<<setw(20)
				<<Online<<setw(20)<<15000*Online<<endl
                <<setw(30)<<"Private(Offline-17000) :: "<<setw(20)
				<<Offline<<setw(20)<<17000*Offline<<endl
                <<setw(30)<<"DISCOUNT(%) :: "<<setw(20)<<Count
				<<setw(20)<<Get_Cost()*Count/100<<endl
                <<setw(30)<<"Total Cost :: "<<setw(20)<<"   "<<setw(20)
				<<Get_FinalCost()<<endl;
            	cin.get();
        }
};
void swap(Customer &p1, Customer &p2)
{
    Customer swapped = p1;
    p1 = p2;
    p2 = swapped;
}
int partition(Customer arr[],int low,int high)
{
  Customer pivot=arr[high];
  int i=(low-1);
  for(int j=low;j<=high;j++)
  	{
    if(arr[j].Get_FinalCost()<pivot.Get_FinalCost()){
      i++;
      swap(arr[i],arr[j]);
    }
}
  swap(arr[i+1],arr[high]);
  return (i+1);
}
void quickSort(Customer arr[],int low,int high){
  if(low<high){
    int pi=partition(arr,low,high);
    quickSort(arr,low,pi-1);
    quickSort(arr,pi+1,high);
  }
} 
//positionclass
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
        Position(string n,string type[10],string name[10], int pc){
            Name=n;
            PoseCount = pc;
            for(int i=0; i<10; i++)
		{
                PoseType[i]=type[i];
                PoseName[i]=name[i];
            }
            Postion++;
        }
        //addposition
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
                cin.get();
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
                cout<<"Add more? (y/n) : ";
                cin>>More;
                if(More=='n') 
				{
				break;
				}
            }
        }
        //createposition
        void Create_Position()
		{
            cout<<"Enter position name :: ";
            cin.get();
            getline(cin,Name);
            Postion++;
            Add_Position();
        }
        //displayposition
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
//displaytrainingplan
void Display_TrainingPlans(TrainingPlan plan[])
{
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
//display_yogaposition
void Display_YogaPositions(Position pose[])
{
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
//displaycustomers
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
int main()
{
	//menu
    int MenuCode;
    //yogapose
    Position pose[10];
    string BasicPoseType[10] = {"Standing Pose","Standing Pose","Standing Pose",
	"Standing Pose","Balancing Pose","Balancing Pose","Balancing Pose",
	"Balancing Pose","Seat Pose","Backend Pose"};
    string BasicPoseNames[10] ={"Archer Pose","Dolphin Pose","Frog Pose","Fallen Triangle",
	"Big Toe Pose","Lion Pose","Airplane Pose","Side Lunge","Side Reclining","Bird Dog Pose"};
    Position Pose1("Basic",BasicPoseType,BasicPoseNames,10);
    string intermediatePoseType[10] = {"Standing Pose","Standing Pose","Standing Pose",
	"Standing Pose","Balancing Pose","Balancing Pose","Balancing Pose","Balancing Pose",
	"Seat Pose","Backend Pose"};
    string intermediatePoseNames[10] ={"Downward Facing Pose","Mountain Pose",
	"Warrior Pose","Traingle Triangle","Low Lunge","Tree Pose","Plank Pose",
	"Bridge Lunge","Staff Pose","Cobbler's Pose"};
    Position Pose2("Intermediate",intermediatePoseType,intermediatePoseNames,10);
    pose[0] = Pose1;
    pose[1] = Pose2;
    //Trainingplan
    TrainingPlan plan[10];
    TrainingPlan basic("Basic",3,25000),intermediate("Intermediate",3,35000),advanced("Advance",2,50000);
    plan[0] = basic;
    plan[1] = intermediate;
    plan[2] = advanced;
    //customer
    Customer customers[100];
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
    Customer customer1("Min Thiha Aung",plan[0],70,customer1Private,customer1OnOff,5);
    Customer customer2("Nyi Nyi Aung",plan[0],60,customer2Private,customer2OnOff,4);
    Customer customer3("Zwe Hset Naing",plan[0],50,customer3Private,customer3OnOff,1);
    Customer customer4("Kaung Myat Wai",plan[0],40,customer4Private,customer4OnOff,3);
    Customer customer5("Thurein Kyaw Htay",plan[0],55,customer5Private,customer5OnOff,3);
    customers[0] = customer1;
    customers[1] = customer2;
    customers[2] = customer3;
    customers[3] = customer4;
    customers[4] = customer5;
    MenuLabel:
    //Welcomepose
    cout<<"-------------------------------------------------------------"<<endl;
    cout<<"         Welcome from The Amazing Sport Yoga System!!        "<<endl;
	cout<<"-------------------------------------------------------------"<<endl;
    cout<<setw(20)<<"1. Training plan."<<endl
        <<setw(14)<<"2. Customer"<<endl
        <<setw(19)<<"0. Quit program."<<endl
		<<"Choose the option :: ";
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
            string planName = customers[customer].Set_Customer(plan);
            if(planName == "Intermediate") customers[customer-1].addLearntPoses(BasicPoseNames);
            else if(planName == "Advance") customers[customer-1].addLearntPoses(intermediatePoseNames);
            customers[customer-1].Display_CustomerDetails();
        }
        else if(CustomerScreenCode==2) 
		{
        quickSort(customers, 0, customer-1);
		Display_Customers(customers);
		}
        else if(CustomerScreenCode==3) 
		{
            int index=0;
            Display_Customers(customers);
            cout<<"Enter number to update :: ";
            cin>>index;
            string planName = customers[index-1].Update_Customer(plan);
            if(planName == "Intermediate") customers[index-1].addLearntPoses(BasicPoseNames);
            else if(planName == "Advance") customers[index-1].addLearntPoses(intermediatePoseNames);
            customers[index-1].Display_CustomerDetails();
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
