//Dorota Dyczek
#include <iostream>
#include "memory_check.h"

struct Bond{    
    int Coral_id;
    char cord_one;
    char cord_two;
    char cord_three;
    Bond* next = NULL;
};
struct Coral{
    int id;
    Coral* next = NULL;
    Bond* b_head = NULL;
};
struct Cord{
    char ID_one;
    char ID_two;
    char ID_three;
    Cord* cord = NULL;
    Coral* coral = NULL;
};

void theCord(Cord** first ,char id_one,char id_two, char id_three){
    Cord* new_cord = new Cord;
    new_cord->ID_one = id_one;
    new_cord->ID_two = id_two;
    new_cord->ID_three = id_three;
    if(*first == NULL){
        new_cord->cord = NULL;
        *first = new_cord;
    }
    else{
        for(Cord* temp_cord = *first; temp_cord!=NULL; temp_cord = temp_cord->cord){
            Cord* nextElement = temp_cord->cord;           
            if(temp_cord == *first){                               
                if(temp_cord->ID_one>= id_one){
                    
                    if(temp_cord->ID_one> id_one){
                        new_cord->cord=*first;
                        *first = new_cord;
                        break;
                    }else {
                        if(temp_cord->ID_two>=id_two){
                            if(temp_cord->ID_two> id_two){
                                new_cord->cord=*first;
                                *first = new_cord;
                                break;
                            }else{     
                                if(temp_cord->ID_three>=id_three){
                                    new_cord->cord=*first;
                                    *first = new_cord;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if(temp_cord->cord != NULL && nextElement->ID_one >= id_one  ){
                
                if(nextElement->ID_one> id_one){
                    new_cord->cord = temp_cord->cord;
                    temp_cord->cord = new_cord;
                    break;
                }
                else{
                    if(nextElement->ID_two>=id_two){
                        if(nextElement->ID_two>id_two){
                            new_cord->cord = temp_cord->cord;
                            temp_cord->cord = new_cord;
                            break;
                        }
                        else{    
                            if(nextElement->ID_three>=id_three){
                                new_cord->cord = temp_cord->cord;
                                temp_cord->cord = new_cord;
                                break;
                            }
                        }
                    }            
                }
            }
            else if(temp_cord->cord == NULL){
                    temp_cord->cord = new_cord;
                    new_cord->cord = NULL;
            }
        }
    }
}
void Print(Cord* print){
    for(print;print != NULL; print=print->cord){
        Coral* coralP = print->coral;
        std::cout<<print->ID_one<<print->ID_two<<print->ID_three<<std::endl;
        while(coralP != NULL){
            std::cout<<coralP->id<<" ";
            bool u = true;
            Bond* bond = coralP->b_head;
            while(bond != NULL){
                std::cout<<bond->cord_one<<bond->cord_two<<bond->cord_three<<" "<<bond->Coral_id<<" ";
                bond = bond->next;
                if(bond == NULL){
                    std::cout<<std::endl;
                    u = false;
                }
            }
            coralP = coralP->next;
            if(u == true)
                std::cout<<std::endl;
        

        }
    }
}
void CoralCord(Cord** head, int coralId, char id_one,char id_two, char id_three){
    bool exist = false;
    
    for(*head; *head!=NULL;*head = (*head)->cord) {
        if((*head)->ID_one == id_one && (*head)->ID_two == id_two && (*head)->ID_three == id_three){
            exist = true;
            break;
        }
    }
    if(exist){
        Coral* new_coral = new Coral;
        new_coral->id = coralId;
        new_coral->next=NULL;
        if((*head)->coral == NULL) {
            new_coral->next = NULL;
            (*head)->coral = new_coral;
        }else{
            for(Coral* curr_coral = (*head)->coral; curr_coral != NULL; curr_coral = curr_coral->next){
                Coral* nextCoral = curr_coral->next;
                
                if(curr_coral == (*head)->coral){
                    if(curr_coral->id >= coralId){
                        new_coral->next=(*head)->coral;
                        (*head)->coral = new_coral;
                        break;                        
                    }
                }
                if(nextCoral != NULL && nextCoral->id >= coralId){
                    new_coral->next = nextCoral;
                    curr_coral->next = new_coral;
                    break;
                }
                else if(nextCoral == NULL){
                   
                    curr_coral->next = new_coral;
                    new_coral->next = NULL;
                    break;

                }
                    
            }
        }
            
        
    }
}

void CoralConnection( int startID, int endID, char startO, char startT, char startH, char endO, char endT, char endH,Cord** head){
    Cord* tempCord = *head;
    for(tempCord; tempCord!=NULL;tempCord = tempCord->cord) {
        if(tempCord->ID_one == startO  && tempCord->ID_two == startT && tempCord->ID_three == startH){
            break;
        }
    }
    Coral* tempCoral = tempCord->coral;
    for(tempCoral ; tempCoral != NULL; tempCoral = tempCoral->next){
        if(tempCoral->id == startID){
            break;
        }
    }
    Bond* currB = new Bond;
    currB->Coral_id = endID;
    currB->cord_one = endO;
    currB->cord_two = endT;
    currB->cord_three = endH;
    currB->next = NULL;
    if(tempCoral->b_head == NULL){ 
        tempCoral->b_head = currB;
    }
    else{
        for(Bond* tempBond = tempCoral->b_head; tempBond != NULL; tempBond= tempBond->next){
            Bond* nextBond = tempBond->next;
            if(tempBond == tempCoral->b_head){
                if(tempBond->cord_one>=endO){
                    if(tempBond->cord_one>endO){
                        currB->next=tempCoral->b_head;
                        tempCoral->b_head = currB;
                        break;
                    }else{
                        if(tempBond->cord_two>=endT){
                            if(tempBond->cord_two>endT){
                                currB->next=tempCoral->b_head;
                                tempCoral->b_head = currB;
                                break;
                            }else{
                                if(tempBond->cord_three>=endH){
                                    if(tempBond->cord_three>endH){
                                        currB->next=tempCoral->b_head;
                                        tempCoral->b_head = currB;
                                        break;
                                    }else{
                                        if(tempBond->Coral_id >= endID){
                                            currB->next=tempCoral->b_head;
                                            tempCoral->b_head = currB;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if(tempBond->next != NULL && nextBond->cord_one>=endO){
                if(nextBond->cord_one> endO){
                    currB->next = tempBond->next;
                    tempBond->next = currB;
                    break;
                }else{
                    if(nextBond->cord_two>= endT){
                        if(nextBond->cord_two> endT){
                            currB->next = tempBond->next;
                            tempBond->next = currB;
                            break;
                        }else{
                            if(nextBond->cord_three>=endH){
                                if(nextBond->cord_three>endH){
                                    currB->next = tempBond->next;
                                    tempBond->next = currB;
                                    break;
                                }else{
                                    if(nextBond->Coral_id>=endID){
                                        currB->next = tempBond->next;
                                        tempBond->next = currB;
                                        break;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            else if(tempBond->next == NULL){
                tempBond->next = currB;
                currB->next = NULL;
            }
        }
    }
    
}
void Unlink(int sID, int eID, char sOne, char sTwo, char sThree, char eOne, char eTwo, char eThree, Cord** head){
    Cord* tempCord = *head;
    for(tempCord; tempCord!=NULL;tempCord = tempCord->cord) {
        if(tempCord->ID_one == sOne  && tempCord->ID_two == sTwo && tempCord->ID_three == sThree){
            break;
        }
    }
    Coral* tempCoral = tempCord->coral;
    for(tempCoral ; tempCoral != NULL; tempCoral = tempCoral->next){
        if(tempCoral->id == sID){
            break;
        }
    }
 
   Bond* tempBond = tempCoral->b_head;
   Bond* nextBond = tempCoral->b_head;
    for(tempBond; tempBond != NULL; tempBond = tempBond->next){
        
        nextBond=tempBond->next;
        if(tempCoral->b_head == NULL){
            break;}
        if (tempBond == tempCoral->b_head && nextBond == NULL && tempBond->cord_one == eOne && tempBond->cord_two == eTwo && tempBond->cord_three == eThree && tempBond->Coral_id == eID){
            tempCoral->b_head = NULL;
            delete tempBond;
            break;
        }
        else if(tempBond == tempCoral->b_head && tempBond->cord_one == eOne && tempBond->cord_two == eTwo && tempBond->cord_three == eThree && tempBond->Coral_id == eID){
            tempCoral->b_head = nextBond;
            delete tempBond;
            break;
        }
        else if(nextBond->cord_one == eOne && nextBond->cord_two == eTwo && nextBond->cord_three==eThree &&nextBond->Coral_id == eID){
    
            tempBond->next = nextBond->next;
            delete nextBond;
            break;
        }
    }
}
void Delete(char id_o,char id_t,char id_th, int c, Cord** head){
    Cord* tempCord = *head;
    for(tempCord; tempCord!=NULL;tempCord = tempCord->cord) {
        if(tempCord->ID_one == id_o && tempCord->ID_two == id_t && tempCord->ID_three == id_th){
            break;
        }
    }
    Coral* tempCoral = tempCord->coral;
    Coral* nextCoral = tempCord->coral;
    int i = 0;
    if(tempCoral->next!=NULL){
        for(tempCoral; tempCoral->next != NULL; tempCoral = tempCoral->next){
            
            nextCoral = tempCoral->next;
            if(nextCoral->id == c){  
                i = 1;
                break;}
            
            if (tempCoral->id == c &&  tempCoral == tempCord->coral) {
                i = 0;
                break;
            }
        }
    }
    else{
        if (tempCoral->id == c){
            i = 3;
        }
    }
    Bond* tempBond;
    Bond* temp;
    if(i == 1)  {
        tempBond = nextCoral->b_head;
        temp = nextCoral->b_head;
        }
    else if(i == 0 || i == 3){
        tempBond = tempCoral->b_head;
        temp = tempCoral->b_head;
        }
    for(tempBond; tempBond !=NULL;temp = tempBond->next,delete tempBond,tempBond=temp ){}
    
    if(i == 0 ||i == 3){
        tempCord->coral = tempCoral->next;
        delete tempCoral;
    }
    else if(i==1){
        tempCoral->next = nextCoral->next;
        delete nextCoral;
    }
}
void Move(int id, char s_one, char s_two,char s_three, char d_one, char d_two, char d_three, Cord** head){
    Cord* tempCord = *head;
    for(tempCord; tempCord!=NULL;tempCord = tempCord->cord) {
        if(tempCord->ID_one == s_one && tempCord->ID_two == s_two && tempCord->ID_three == s_three){
            break;
        }
    }
    Cord* dCord = *head;
    for(dCord; dCord!=NULL; dCord = dCord->cord){
        if(dCord->ID_one == d_one && dCord->ID_two == d_two && dCord->ID_three == d_three){
            break;
        }
    }
    Coral* tempCoral = tempCord->coral;
    for(tempCoral ; tempCoral != NULL; tempCoral = tempCoral->next){
        if(tempCoral->id == id){
            break;
        }
    }
    for(Coral* nextC = tempCord->coral; nextC != NULL; nextC = nextC->next){
        if(nextC == tempCord->coral && nextC == tempCoral && nextC->next == NULL){
            tempCord->coral = NULL;
            break;
        }
        else if(nextC->next == tempCoral){
            nextC->next = tempCoral->next;
            break;
        }
        else if(nextC == tempCord->coral && nextC == tempCoral ){
            tempCord->coral = tempCoral->next;
            break;
        }
    }
    

    if(dCord->coral == NULL){
        tempCoral->next = NULL;
        dCord->coral = tempCoral;
    }
    else{
        Coral* t = dCord->coral;
         for(Coral* curr_coral = dCord->coral; curr_coral != NULL; curr_coral = curr_coral->next){
            Coral* nextCoral = curr_coral->next;
            if(curr_coral == dCord->coral ){
                if(curr_coral->id >= id){
                    tempCoral->next=dCord->coral;
                    dCord->coral = tempCoral;
                    break;                        
                }
            }
            if(nextCoral != NULL && nextCoral->id >= id){
                tempCoral->next = nextCoral;
                curr_coral->next = tempCoral;
                break;
            }
            else if(nextCoral == NULL){
                curr_coral->next = tempCoral;
                tempCoral->next = NULL;
                break;
            }
    }
    }
}

void Remove(char id_o, char id_t, char id_th, Cord** head){
    Cord* tempCord = *head;
    Cord* next = *head;
    for(tempCord; tempCord!=NULL;tempCord = tempCord->cord) {
       
        if(tempCord->ID_one == id_o && tempCord->ID_two == id_t && tempCord->ID_three == id_th){
            break;
        }
        else if(next->ID_one== id_o && next->ID_two == id_t && next->ID_three == id_th){
            tempCord = next;
            break;
        }
        next = tempCord;
    }
   
    
    Coral* Cdelete = tempCord->coral;
    for(Coral* tempCoral = tempCord->coral; tempCoral != NULL;Cdelete = tempCoral->next,  delete tempCoral, tempCoral = Cdelete ){
        Bond* Tdelete = tempCoral->b_head;
        for(Bond* tempBond = tempCoral->b_head; tempBond != NULL; Tdelete = tempBond->next,delete tempBond,  tempBond = Tdelete){
        }
    
    }
    for(Cord* cordD = *head; cordD != NULL; cordD = cordD->cord){
        if(cordD->cord == NULL && tempCord == cordD ){
            *head = NULL;
            break;
        }
        else if(cordD == *head && cordD == tempCord){
            *head = tempCord->cord;
            break;
        }
        else if(cordD == next){
            cordD->cord = tempCord->cord;
            break;
        }

    }
    for(Cord* startC = *head; startC!= NULL; startC = startC->cord){
        for(Coral* startCoral = startC->coral; startCoral!=NULL; startCoral = startCoral->next){
            Bond* nextBond = startCoral->b_head;
            Bond* temp = startCoral->b_head;
            for(Bond* startB = startCoral->b_head; startB != NULL; startB = startB->next){
                if( startB->cord_one == id_o && startB->cord_two == id_t && startB->cord_three == id_th){
                    if(startB->next == NULL && startB == startCoral->b_head){
                        startCoral->b_head = NULL;
                        if(startB != NULL){
                            delete startB;
                        }
                        break;
                    }
                    else if(startB == startCoral->b_head && startB->next != NULL){
                    
                        startCoral->b_head = startB->next;
                        temp = startB->next;
                        Bond* t = startB;
                        if(startB != NULL){
                            delete t;
                        }
                        startB = temp;
                    }
                    else if(startB->next != NULL){
                        nextBond->next = startB->next;
                        temp = startB->next;
                        Bond* t = startB;
                        if(startB != NULL){
                            delete t;
                        }
                        startB = temp;
                    }
                    else if(startB->next == NULL){
                        nextBond->next = NULL;
                        if(startB!=NULL){
                            delete startB;

                        }
                        break;
                    }

                }
                nextBond = startB;
            }
        }
    }
    if(tempCord != NULL){
        delete tempCord;
    }

}
int main(){
    char p;
    Cord* head = NULL;
    while(p != 'F'){
        std::cin>>p;
        if(p =='S'){
            char id_one,id_two,id_three;
            std::cin>>id_one>>id_two>>id_three;
            theCord(&head, id_one, id_two, id_three);
        }
        
        else if(p == 'P'){
            Cord* start = head;
            Print(start);
            
        }
        else if(p =='B'){
            Cord* start = head;
            int coralId;
            char id_one,id_two,id_three;
            std::cin>>coralId>>id_one>>id_two>>id_three;
            CoralCord(&start,coralId,id_one,id_two,id_three);
           
        }
        else if(p == 'L'){
            int startID, endID;
            char startO, startT, startH;
            char endO, endT, endH;
            std::cin>>startID>>startO>>startT>>startH>>endID>>endO>>endT>>endH;
            Cord* cordHead = head;
            CoralConnection(startID,endID,startO,startT,startH,endO,endT,endH ,&cordHead);

        } 
        else if(p == 'U'){
            int sID, eID;
            char sOne, sTwo, sThree;
            char eOne, eTwo, eThree;
            std::cin>>sID>>sOne>>sTwo>>sThree>>eID>>eOne>>eTwo>>eThree;
            Cord* start = head;
            Unlink(sID, eID, sOne, sTwo, sThree, eOne, eTwo, eThree, &head);
        }  
        else if(p == 'D'){
            Cord* start = head;
            char id_o, id_t, id_th;
            int C;
            std::cin>>C>>id_o>>id_t>>id_th;
            Delete(id_o,id_t,id_th,C,&head);
        }
        else if(p == 'M'){
            int C;
            char s_one, s_two, s_three;
            char d_one, d_two, d_three;
            Cord* start = head;
            std::cin>>C>>s_one>>s_two>>s_three>>d_one>>d_two>>d_three;
            Move(C,s_one,s_two,s_three,d_one,d_two,d_three,&start);
        }
        else if(p == 'R'){
            char id_o, id_t, id_th;
            std::cin>>id_o>>id_t>>id_th;
            Remove(id_o,id_t,id_th,&head);  
        }
    }
    Cord* del = head;
    for(Cord* todelete=head; todelete != NULL;){
        Coral* Cdel = todelete->coral;
        for(Coral* Cdelete = todelete->coral; Cdelete!= NULL;){
            Bond* Bdel = Cdelete->b_head;
            for(Bond* Bdelete = Cdelete->b_head; Bdelete != NULL;){
                Bond* temp = Bdelete;
                Bdel= Bdelete->next;
                delete temp;
                Bdelete=Bdel;
                } 
            Coral* temp = Cdelete;
            Cdel = Cdelete->next;
            delete temp;
            Cdelete = Cdel;
        }
        Cord* temp = todelete;
        del = todelete->cord;
        delete temp;
        todelete = del;
    }
    
_MemoryCheck();
    return 0;
}
