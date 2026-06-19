#include<iostream>
using namespace std;

// Strategy Interface for Walk
class WalkableRobot{
public:
    virtual void walk() = 0;
    virtual ~WalkableRobot(){};
};

// concrete Strategies for Walk
class normalWalk : public WalkableRobot{
public:
    void walk()override{
        cout<<"Walking Normally ..."<<endl;
    }
};

class NoWalk : public WalkableRobot{
public:
    void walk()override{
        cout<<"Cannot Walk."<<endl;
    }
};

// Strategy Interface for Talk
class TalkableRobot{
public:
    virtual void talk() = 0;
    virtual ~TalkableRobot(){}
};

//concrete Strategies for Talk
class NormalTalk : public TalkableRobot{
public:
    void talk()override{
        cout<<"Talking Normally ..."<<endl;
    }
};

class NoTalk : public TalkableRobot{
public:
    void talk()override{
        cout<<"Cannot Talk."<<endl;
    }
};

//Strategy Interface for Fly
class FlyableRobot{
public:
    virtual void fly() = 0;
    virtual ~FlyableRobot(){}
};

//concrete Strategies for Fly
class NormalFly : public FlyableRobot{
public:
    void fly()override{
        cout<<"Flying Normally ..."<<endl;
    }
};

class NoFly : public FlyableRobot{
public:
    void fly()override{
        cout<<"Cannot Fly."<<endl;
    }
};


// Robot Base Class
class Robot{
protected:
    WalkableRobot* walkBehaviour;
    TalkableRobot* talkBehaviour;
    FlyableRobot* flyBehaviour;

public:
    Robot(WalkableRobot*w,TalkableRobot*t,FlyableRobot* f){
        this->walkBehaviour = w;
        this->talkBehaviour = t;
        this->flyBehaviour = f;
    }

    void walk(){
        walkBehaviour->walk();
    }
    void talk(){
        talkBehaviour->talk();
    }
    void fly(){
        flyBehaviour->fly();
    }

    virtual void projection() = 0;
};


//concrete Robot Class
class CompanionRobot : public Robot{
public:
    CompanionRobot(WalkableRobot* w,TalkableRobot* t, FlyableRobot* f):Robot(w,t,f){}

    void projection()override{
        cout<<"Displaying friendly companion features";
    }
};

class WorkerRobot : public Robot{
public:
    WorkerRobot(WalkableRobot* w,TalkableRobot* t, FlyableRobot* f):Robot(w,t,f){}

    void projection()override{
        cout<<"Displaying worker efficiency stats";
    }
};


int main(){
    Robot* robot1 = new CompanionRobot(new normalWalk(),new NormalTalk(),new NoFly());
    robot1->walk();
    robot1->talk();
    robot1->fly();
    robot1->projection();

    Robot* robot2 = new WorkerRobot(new NoWalk(),new NoTalk(),new NormalFly());
    robot2->walk();
    robot2->talk();
    robot2->fly();
    robot2->projection();

    return 0;
}