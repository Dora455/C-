//Dorota Dyczek
#include <iostream>
class TREE_CLASS;
class GARDEN_CLASS;
class FRUIT_CLASS;
class BRANCH_CLASS;
//garden
class GARDEN_CLASS{
    private:
        unsigned int trees_number;
        unsigned int branches_number;
        unsigned int fruits_number;
        unsigned int fruits_weight;
        TREE_CLASS* tree_head;
        TREE_CLASS* tree_last;
        
    public:
        unsigned int getTreesTotal();
        unsigned int getBranchesTotal();
        unsigned int getFruitsTotal();
        unsigned int getWeightsTotal();
        void plantTree();
        void extractTree(unsigned int x);
        void growthGarden();
        void fadeGarden();
        void harvestGarden(unsigned int h);
        TREE_CLASS* getTreePointer(unsigned int id);
        void cloneTree(unsigned int id);

        void increaseFruitWeight(unsigned int x);
        void decreaseFruitWeight(unsigned int x);

        void increaseFruitNum(unsigned int x);
        void decreaseFruitNum(unsigned int x);

        void increaseBranchNum(unsigned int x);
        void decreaseBranchNum(unsigned int x);

        void increaseTreeNumber(unsigned int x);
        void decreaseTreeNumber(unsigned int x);
      
        GARDEN_CLASS();
        ~GARDEN_CLASS();

};

class TREE_CLASS{
  private:
    unsigned int tree_id;
    unsigned int branches_num;
    unsigned int total_fruits_number;
    unsigned int total_fruits_weight;
    unsigned int tree_height;
    GARDEN_CLASS* this_garden;
    BRANCH_CLASS* branch_head;
    BRANCH_CLASS* branch_last;
    TREE_CLASS* next;
    TREE_CLASS* prev;
  public:
    unsigned int getBranchesTotal();
    unsigned int getFruitsTotal();
    unsigned int getWeightsTotal();
    unsigned int getNumber();
    unsigned int getHeight();
    void growthTree();
    void fadeTree();
    void harvestTree(unsigned int);
    void cutTree(unsigned int);
    void cloneBranch(BRANCH_CLASS* clone_branch);

    void increaseFruitWeight(unsigned int x);
    void decreaseFruitWeight(unsigned int x);

    void increaseFruitNumber(unsigned int x);
    void decreaseFruitNumber(unsigned int x);


    void increaseBranchNumber(unsigned int x);
    void decreaseBranchNumber(unsigned int x);
    GARDEN_CLASS* getGardenPointer(void);
    BRANCH_CLASS* getBranchPointer(unsigned int);
    TREE_CLASS(unsigned int id,GARDEN_CLASS* garden);

    TREE_CLASS* getNextTree();
    TREE_CLASS* getPrevTree();
    unsigned int getId();
   
    void setPrevTree(TREE_CLASS* pr);
    void setNextTree(TREE_CLASS* nx);
    TREE_CLASS();
    ~TREE_CLASS();
    TREE_CLASS(TREE_CLASS& tree);

    GARDEN_CLASS* getParent();
    void setParent(GARDEN_CLASS* parent);

    void setId(unsigned int i);
  
    
};

    void TREE_CLASS:: setId(unsigned int i){
        tree_id = i;
    }

   GARDEN_CLASS* TREE_CLASS::getParent(){
       return this_garden;
   }
void TREE_CLASS::setParent(GARDEN_CLASS* parent){
    this_garden = parent;
}
class BRANCH_CLASS{
    private:
        unsigned int number_of_fruits;
        unsigned int all_fruits_weight;
        unsigned int branch_height;
        unsigned int branch_length;
        FRUIT_CLASS* fruit_head;
        FRUIT_CLASS* fruit_last;
        TREE_CLASS* this_tree;

        BRANCH_CLASS* next;
        BRANCH_CLASS* prev;

    public:

        void decreaseTotalWeight(unsigned int x);
        void increaseTotalWeight(unsigned int x);
        unsigned int getFruitsTotal(void); 
        unsigned int getWeightsTotal(void);
        unsigned int getHeight(void);
        unsigned int getLength(void);
        void growthBranch(void);
        void fadeBranch(void);
        void harvestBranch(unsigned int);
        void cutBranch(unsigned int);
        FRUIT_CLASS* getFruitPointer(unsigned int);
        TREE_CLASS* getTreePointer(void);
       

        BRANCH_CLASS* getNextBranch();
        BRANCH_CLASS* getPrevBranch();
        void increaseFruitNumber(unsigned int x);
        void decreaseFruitNumber(unsigned int x);

           
        void setPrevBranch(BRANCH_CLASS* pr);
        void setNextBranch(BRANCH_CLASS* nx);

        void setParent(TREE_CLASS* parent);

        BRANCH_CLASS(BRANCH_CLASS& branch);
        BRANCH_CLASS();
        BRANCH_CLASS(unsigned int branch_h, unsigned int branch_l, TREE_CLASS* tree);
        ~BRANCH_CLASS();
        void setHeight(unsigned int h);

};

void BRANCH_CLASS::setHeight(unsigned int h){
    branch_height = h;
}
class FRUIT_CLASS{
    private:
        unsigned int fruit_length;
        unsigned int fruit_weight;
        BRANCH_CLASS* this_branch;
        FRUIT_CLASS* next;
        FRUIT_CLASS* prev;

    public:
       
        void setParent(BRANCH_CLASS* branch);
        unsigned int getLength(void);
        unsigned int getWeight(void);
        void growthFruit(void);
        void fadeFruit(void);
        void pluckFruit(void);
        BRANCH_CLASS* getBranchPointer(void);
        FRUIT_CLASS* getNextFruit();
        void setNextFruit(FRUIT_CLASS* new_fruit);
        void decreaseFruitWeight(unsigned int x);
        void increaseFruitWeight(unsigned int x);

        FRUIT_CLASS* getPrevFruit();
        void setPrevFruit(FRUIT_CLASS* fruit);
        FRUIT_CLASS();
        FRUIT_CLASS(unsigned int length, BRANCH_CLASS* branch);
        ~FRUIT_CLASS();

        FRUIT_CLASS(const FRUIT_CLASS& fruit);
       
};

BRANCH_CLASS* BRANCH_CLASS ::getPrevBranch(){
    return prev;
}
BRANCH_CLASS* BRANCH_CLASS::getNextBranch(){
    return next;
}

void BRANCH_CLASS:: decreaseTotalWeight(unsigned int x){
    all_fruits_weight-=x;
    if(this_tree !=NULL){
        this_tree->decreaseFruitWeight(x);
    }
}

void BRANCH_CLASS::increaseTotalWeight(unsigned int x){
    all_fruits_weight += x;
    if(this_tree !=NULL){
        this_tree->increaseFruitWeight(x);
    }
}

    void BRANCH_CLASS::setPrevBranch(BRANCH_CLASS* pr){
        prev=pr;
    }
    void BRANCH_CLASS:: setNextBranch(BRANCH_CLASS* nx){
        next=nx;
    }

unsigned int BRANCH_CLASS::getFruitsTotal(void){
    return number_of_fruits;
}

unsigned int BRANCH_CLASS::getWeightsTotal(void){
    return all_fruits_weight;
}

unsigned int BRANCH_CLASS::getHeight(void){
    return branch_height;
}

unsigned int BRANCH_CLASS::getLength(void){
    return branch_length;
}

void BRANCH_CLASS::growthBranch(void){
    if(this == NULL)
        return;
    branch_length +=1; 

    if(branch_length%2 != 0){

        for(FRUIT_CLASS* add = fruit_head; add != NULL; add = add->getNextFruit() ){
            add->growthFruit();
        }
    }
    else{                 
        FRUIT_CLASS* add = fruit_head;
        if(fruit_head == NULL){                                                         
            FRUIT_CLASS* new_fruit = new FRUIT_CLASS(branch_length, this);

            new_fruit->setPrevFruit(NULL);
            new_fruit->setNextFruit(NULL);

            add = new_fruit; 
            fruit_head = new_fruit;
            fruit_last = new_fruit;             
        }
        else{

            FRUIT_CLASS* new_fruit = new FRUIT_CLASS(branch_length, this); 
            
            for(add; add != NULL; add = add->getNextFruit() ){
                add->growthFruit();
            }
            if(fruit_last!=NULL)
                fruit_last->setNextFruit(new_fruit);
            new_fruit->setNextFruit(NULL);
            new_fruit->setPrevFruit(fruit_last);
            
            fruit_last = new_fruit;
        }
        increaseFruitNumber(1);
    }

}

void BRANCH_CLASS::fadeBranch(void){

    if(this==NULL)
        return;
    if(branch_length>0){
        if(fruit_head != NULL){   
            FRUIT_CLASS* minus = fruit_last;      
            for(minus; minus != NULL; minus = minus->getPrevFruit() ){
                if(minus->getWeight() > 0)                                  
                    minus->fadeFruit();
                }

            FRUIT_CLASS* last = fruit_last;                                 
            if(last != NULL && last->getLength() >= branch_length){
   

                if(last == fruit_head){
                    fruit_head = NULL;
                }
                FRUIT_CLASS* todelete = last;
                last = last->getPrevFruit();
                fruit_last = last;
               if(fruit_last!=NULL)
                    fruit_last->setNextFruit(NULL);
                delete todelete;
                
            }

        }    
        branch_length -=1;
    }

}
void BRANCH_CLASS::harvestBranch(unsigned int h)        
{
    if(this==NULL)
        return;
    FRUIT_CLASS* go = fruit_last;
    for(go;go!=NULL;go=go->getPrevFruit()){

        if(go->getWeight() >= h){
            go->pluckFruit();
        }

    }

}

void BRANCH_CLASS::cutBranch(unsigned int l){
    FRUIT_CLASS* go = fruit_last;
    while(go != NULL && go->getLength() > l){
        go->pluckFruit();

        FRUIT_CLASS* todelete = go;
        
    
        fruit_last = fruit_last->getPrevFruit();
        
        if(go==fruit_head){
            fruit_head=NULL;
        }
        go=go->getPrevFruit();
        if(go!=NULL)
            go->setNextFruit(NULL);
        delete todelete;
    }
    branch_length = l;
}

FRUIT_CLASS* BRANCH_CLASS::getFruitPointer(unsigned int l){
    FRUIT_CLASS* find = fruit_head;
    for(find;find !=NULL;find = find->getNextFruit()){

        if(find->getLength() == l)
            return find;
    }
    return NULL;
}
TREE_CLASS* BRANCH_CLASS::getTreePointer(void){
    if(this_tree != NULL)
        return this_tree;
    return NULL;
}
 
void BRANCH_CLASS::increaseFruitNumber(unsigned int x){
    number_of_fruits+=x;
    if(this_tree !=NULL){
        this_tree->increaseFruitNumber(x);
    }
}
void BRANCH_CLASS::decreaseFruitNumber(unsigned int x){
    number_of_fruits-=x;
    if(this_tree !=NULL){
        this_tree->decreaseFruitNumber(x);
    }
}



unsigned int FRUIT_CLASS::getLength(void){
    return fruit_length;
}
unsigned int FRUIT_CLASS::getWeight(void){
    return fruit_weight;
}
void FRUIT_CLASS::growthFruit(void){
    fruit_weight+=1;
    if(this_branch!=NULL){
        this_branch->increaseTotalWeight(1);
    }
}

void FRUIT_CLASS::fadeFruit(){
    if(fruit_weight>0){
        fruit_weight-=1;
        if(this_branch!=NULL){
            this_branch->decreaseTotalWeight(1);
        }
    }
}
void FRUIT_CLASS::pluckFruit(){
    decreaseFruitWeight(fruit_weight);
    fruit_weight = 0;
}

BRANCH_CLASS* FRUIT_CLASS::getBranchPointer(){
    if(this_branch!=NULL)
        return this_branch;
    return NULL;
}

FRUIT_CLASS* FRUIT_CLASS::getNextFruit(){
    return this->next;
}
FRUIT_CLASS* FRUIT_CLASS::getPrevFruit(){
    return this->prev;
}
void FRUIT_CLASS::setNextFruit(FRUIT_CLASS* new_fruit){
        next = new_fruit;
}
void FRUIT_CLASS::setPrevFruit(FRUIT_CLASS* fruit){
    prev = fruit;                                       
}
void FRUIT_CLASS::decreaseFruitWeight(unsigned int x){
    fruit_weight-=x;
    if(this_branch != NULL){
        this_branch->decreaseTotalWeight(x);
    }
}
void FRUIT_CLASS::increaseFruitWeight(unsigned int x){
    fruit_weight+=x;
    if(this_branch != NULL){
        this_branch->increaseTotalWeight(x);
    }
}

void FRUIT_CLASS::setParent(BRANCH_CLASS* branch){
    this_branch = branch;
}

unsigned int TREE_CLASS::getBranchesTotal(void){
    return branches_num;
}
unsigned int TREE_CLASS::getFruitsTotal(void){
    return  total_fruits_number;
}
unsigned int TREE_CLASS::getWeightsTotal(void){
    return total_fruits_weight;
}
unsigned int TREE_CLASS::getNumber(void){
    return tree_id;
}
unsigned int TREE_CLASS::getHeight(void){
    return tree_height;
}
void TREE_CLASS::growthTree(void){
    if(this == NULL)
        return;
    tree_height+=1;
   
    BRANCH_CLASS* go = branch_head;
    for(go;go!=NULL;go=go->getNextBranch()){
        go->growthBranch();

    }
    if(tree_height%3==0){
        if(branch_head == NULL){
            BRANCH_CLASS* newBranch = new BRANCH_CLASS(tree_height,0,this);
            newBranch->setNextBranch(NULL);
            newBranch->setPrevBranch(NULL);
            branch_head=newBranch;
            branch_last=newBranch;
        }
        else{
    
        BRANCH_CLASS* newBranch = new BRANCH_CLASS(tree_height,0,this);
        branch_last->setNextBranch(newBranch);
        newBranch->setNextBranch(NULL);
        newBranch->setPrevBranch(branch_last);
      
        branch_last = newBranch;
        }
        increaseBranchNumber(1);
    }

}
void TREE_CLASS::fadeTree(){
    

    if(this == NULL)
        return;
    if(tree_height>0){
        if(branch_head!= NULL){
            
            for(BRANCH_CLASS* go = branch_last; go!=NULL; go = go->getPrevBranch()){
                    go->fadeBranch();

            }
            BRANCH_CLASS* last = branch_last;
            if(last!= NULL && last->getHeight() >= tree_height){

                BRANCH_CLASS* todelete = last;
                if (last->getPrevBranch() != NULL) {
                    last->getPrevBranch()->setNextBranch(NULL);
                }
               
                last = last->getPrevBranch();
                delete todelete;
                decreaseBranchNumber(1);
                branch_last = last;
                if(branch_last != NULL)
                    branch_last->setNextBranch(NULL);
            }
            
            tree_height -=1 ;
        }
    }
    
}

void TREE_CLASS::harvestTree(unsigned int h){
    if(this == NULL)
        return;
    BRANCH_CLASS* go = branch_last;
    while(go!=NULL){
        go->harvestBranch(h);
        go=go->getPrevBranch();
    }

}
void TREE_CLASS::cutTree(unsigned int l){
    
    BRANCH_CLASS* go = branch_last;

  
    while(go!=NULL && go->getHeight() > l){
        BRANCH_CLASS* todelete = go;

        branch_last=go->getPrevBranch();
        if(go==branch_head)
        {
            branch_head=NULL;
        }
        go = go->getPrevBranch();

        if(go!=NULL)
            go->setNextBranch(NULL);
        decreaseBranchNumber(1);
        delete todelete;
    }
    
    

    tree_height = l;
}

GARDEN_CLASS* TREE_CLASS::getGardenPointer(){
    if(this_garden!=NULL){
        return this_garden;
    }
    return NULL;
}
BRANCH_CLASS* TREE_CLASS::getBranchPointer(unsigned int height){
        BRANCH_CLASS* find = branch_head;
        for(find;find!=NULL;find =find->getNextBranch()){
            if (find->getHeight() == height){
                return find;
            }
        }
        return NULL;
}

void TREE_CLASS::setPrevTree(TREE_CLASS* pr){
    prev = pr;
}

void TREE_CLASS::setNextTree(TREE_CLASS* nx){
    next = nx;
}

void TREE_CLASS::increaseFruitWeight(unsigned int x){
    total_fruits_weight+= x;
    if(this_garden !=NULL){
        this_garden->increaseFruitWeight(x);
    }
}
void TREE_CLASS::decreaseFruitWeight(unsigned int x){
    total_fruits_weight -=x;
    if(this_garden !=NULL){
        this_garden->decreaseFruitWeight(x);
    }
}

void TREE_CLASS::increaseFruitNumber(unsigned int x){
    total_fruits_number+=x;
    if(this_garden !=NULL){
        this_garden->increaseFruitNum(x);
    }

}
void TREE_CLASS::decreaseFruitNumber(unsigned int x){
    total_fruits_number-=x;
    if(this_garden !=NULL){
    this_garden->decreaseFruitNum(x);
    }

}

void TREE_CLASS::increaseBranchNumber(unsigned int x){
    branches_num+=x;
    if(this_garden!=NULL){
         this_garden->increaseBranchNum(x);
    }
}
void TREE_CLASS::decreaseBranchNumber(unsigned int x){
    branches_num-=x;
    if(this_garden!=NULL){
        this_garden->decreaseBranchNum(x);
    }
}



TREE_CLASS* TREE_CLASS:: getNextTree(){
    return next;
}
TREE_CLASS* TREE_CLASS:: getPrevTree(){
    return prev;
    }

 unsigned int TREE_CLASS::getId(){
    return tree_id;
    }

  void BRANCH_CLASS::setParent(TREE_CLASS* parent){
      this_tree = parent;
  }


  void TREE_CLASS::cloneBranch(BRANCH_CLASS* clone_branch){
        if(branch_head == NULL)
            return;

        BRANCH_CLASS* clone = NULL;
        BRANCH_CLASS* go = branch_head;
        BRANCH_CLASS* temp = branch_head;
        while(temp !=NULL){
            if(temp->getLength() == 0){
                clone = temp;
                break;
            }
            else{
                temp = temp->getNextBranch();
            }
        }
        if(clone!=NULL){
            if(getParent() != NULL){
                increaseFruitNumber(clone_branch->getFruitsTotal());
                increaseFruitWeight(clone_branch->getWeightsTotal());
            }
            else{
                total_fruits_number += clone_branch->getFruitsTotal();
                total_fruits_weight += clone_branch->getWeightsTotal();
            }

            BRANCH_CLASS* newBranch = new BRANCH_CLASS(*clone_branch);
            newBranch->setParent(this);
            newBranch->setHeight(clone->getHeight());
            newBranch->setNextBranch(clone->getNextBranch());
            newBranch->setPrevBranch(clone->getPrevBranch());
            if(clone->getPrevBranch() != NULL)
                clone->getPrevBranch()->setNextBranch(newBranch);
            if(clone->getNextBranch() != NULL)
                clone->getNextBranch()->setPrevBranch(newBranch);
            if(clone == branch_head){
                branch_head = newBranch;
            }
            if(clone == branch_last)
                branch_last = newBranch;
            delete clone;
        }
      
  }


unsigned int GARDEN_CLASS::getTreesTotal(){
    return trees_number;
}
unsigned int GARDEN_CLASS::getBranchesTotal(){
    return branches_number;
}
unsigned int GARDEN_CLASS::getFruitsTotal(){
    return fruits_number;
}
unsigned int GARDEN_CLASS::getWeightsTotal(){
    return fruits_weight;
}

void GARDEN_CLASS::plantTree(){

    if(tree_head != NULL){
        if(tree_last->getId() == (trees_number - 1)){

            int id = tree_last->getId() + 1;
            TREE_CLASS* newTree = new TREE_CLASS(id,this);
        
            newTree->setNextTree(NULL);
            newTree->setPrevTree(tree_last);
            
            
            tree_last->setNextTree(newTree);
            tree_last = newTree;
            
        }
        else
        {
            TREE_CLASS* find = tree_head;
            int id = 0;
            while(find !=NULL){
                if(find->getId() == id)   
                    id++;
                else{

                    TREE_CLASS* newTree = new TREE_CLASS(id,this);
                    newTree->setNextTree(find);
                    newTree->setPrevTree(find->getPrevTree());
                    
                    if(newTree->getNextTree() != NULL)      
                        newTree->getNextTree()->setPrevTree(newTree);
                    if( newTree->getPrevTree() != NULL)
                        newTree->getPrevTree()->setNextTree(newTree);
                    
                    if(find == tree_head){
                        tree_head=newTree;
                    }
                    break;
                }
                find = find->getNextTree();
            }
        }
    }
    else{
        TREE_CLASS* newTree = new TREE_CLASS(0,this);
        
        newTree->setNextTree(NULL);
        newTree->setPrevTree(NULL);
    
        tree_head = newTree;
        tree_last = newTree;
    }
    trees_number++;
    
   
}

void GARDEN_CLASS::growthGarden(){ 
    
    if(this == NULL)
        return;
    TREE_CLASS* tree = tree_head;
    for(tree; tree!=NULL;tree=tree->getNextTree()){
        tree->growthTree();
    }

}

void GARDEN_CLASS::extractTree(unsigned int x){
    
    if(tree_head == NULL)
        return;
    else if(x > tree_last->getId())
        return;
    if (tree_head->getId() == x){
        TREE_CLASS* todelete = tree_head;
        tree_head = tree_head->getNextTree();

        if(tree_head!=NULL)
            tree_head->setPrevTree(NULL);
       
        trees_number--;
            if(trees_number == 0){
                tree_head = NULL;
                tree_last = NULL;
            }
        delete todelete;

    }
    else if(tree_last->getId() == x){
        TREE_CLASS* todelete = tree_last;
        if(tree_last != NULL){
            tree_last= tree_last->getPrevTree();
            if(tree_last!=NULL)
                tree_last->setNextTree(NULL);
            trees_number--;
            if(trees_number == 0){
                tree_head = NULL;
                tree_last = NULL;
            }
            delete todelete;
        }
    }
    else{
        TREE_CLASS* find;
        find = getTreePointer(x);
    
        if(find!=NULL){
            if(find->getPrevTree()!=NULL && find->getNextTree() != NULL){
                find->getPrevTree()->setNextTree(find->getNextTree());
     
                find->getNextTree()->setPrevTree(find->getPrevTree());
            }
            trees_number--;  
             if(trees_number == 0){
                tree_head = NULL;
                tree_last = NULL;
            }                           
            delete find;
        }
    }
    
}

void GARDEN_CLASS::fadeGarden(){
    
    TREE_CLASS* tree = tree_last;
    if(tree_head!=NULL){
        for(tree; tree!=NULL;tree=tree->getPrevTree()){
            tree->fadeTree();
        }
    }
}
void GARDEN_CLASS::harvestGarden(unsigned int h){
    if(this == NULL)
        return;
    TREE_CLASS* go = tree_last;
    while(go!=NULL){
        go->harvestTree(h);
        go = go->getPrevTree();
    }
}
void GARDEN_CLASS::cloneTree(unsigned int id){
    TREE_CLASS* clone = getTreePointer(id);
    if(clone == NULL)
        return;
    if( (trees_number - 1) == tree_last->getId()){
        int id_num = tree_last->getId()+1;
        TREE_CLASS* newTree = new TREE_CLASS(*clone);
        newTree->setParent(this);
        newTree->setId(id_num);

        increaseBranchNum(clone->getBranchesTotal());
        increaseFruitNum(clone->getFruitsTotal());
        increaseFruitWeight(clone->getWeightsTotal());
        tree_last->setNextTree(newTree);
        newTree->setPrevTree(tree_last);

        tree_last= newTree;
        tree_last->setNextTree(NULL);
        trees_number++;
    }
    else{
        TREE_CLASS* find = tree_head;
        int id_num = 0;
        while(find != NULL){
            if(find->getId() == id_num)
                id_num++;
            else{
                TREE_CLASS* newTree = new TREE_CLASS(*clone);
            
                newTree->setParent(this);
                newTree->setId(id_num);
                newTree->setNextTree(find);
                newTree->setPrevTree(find->getPrevTree());

                if(newTree->getNextTree() != NULL)      
                    newTree->getNextTree()->setPrevTree(newTree);
                if( newTree->getPrevTree() != NULL)
                    newTree->getPrevTree()->setNextTree(newTree);
            
                if(find == tree_head){
                    tree_head=newTree;
                }
                
            

                increaseBranchNum(clone->getBranchesTotal());
                increaseFruitNum(clone->getFruitsTotal());
                increaseFruitWeight(clone->getWeightsTotal());
                trees_number++;
                break;

            }
            find = find->getNextTree();
        }
    
    }
}


TREE_CLASS* GARDEN_CLASS::getTreePointer(unsigned int id){
    TREE_CLASS* find = tree_last;
    if(tree_last->getId() < id)
        return NULL;
    while(find!=NULL){
        if(find->getId() == id){
            return find;
        }
        find = find->getPrevTree();
    }
    return NULL;
}



void GARDEN_CLASS::increaseFruitWeight(unsigned int x){
    fruits_weight +=x;
}
void GARDEN_CLASS::decreaseFruitWeight(unsigned int x){
    fruits_weight-=x;
}

void GARDEN_CLASS::increaseFruitNum(unsigned int x){
    fruits_number+=x;
}

void GARDEN_CLASS::decreaseFruitNum(unsigned int x){
    fruits_number-=x;
}

void GARDEN_CLASS::increaseBranchNum(unsigned int x){
    branches_number+=x;
}
void GARDEN_CLASS::decreaseBranchNum(unsigned int x){
    branches_number-=x;
}


void GARDEN_CLASS::increaseTreeNumber(unsigned int x){
    trees_number+=x;
}

void GARDEN_CLASS::decreaseTreeNumber(unsigned int x){
    trees_number-=x;
}



 GARDEN_CLASS::GARDEN_CLASS(){
        trees_number = 0;
        branches_number = 0;
        fruits_number = 0;
        fruits_weight = 0;
        tree_head = NULL;
        tree_last = NULL;
        
}
 
GARDEN_CLASS::~GARDEN_CLASS(){
     TREE_CLASS* temp = NULL;
    for(TREE_CLASS* d = tree_last;d!=NULL;d=temp){                     
        
       temp= d->getPrevTree();
      
        d->cutTree(0);
      
       delete d;
    }
    fruits_weight = 0;
    fruits_number = 0;
    trees_number = 0;
    branches_number = 0;
    tree_head=NULL;
    tree_last=NULL;

}

TREE_CLASS::TREE_CLASS(unsigned int id,GARDEN_CLASS* garden){
    
    tree_id = id;
    tree_height = 0;
    branches_num = 0;
    total_fruits_number = 0;
    total_fruits_weight = 0;
    this_garden = garden;
    branch_head = NULL;
    branch_last = NULL;
    prev=NULL;
    next=NULL;
}
TREE_CLASS::TREE_CLASS(){

    branches_num = 0;
    total_fruits_number = 0;
    total_fruits_weight = 0;
    tree_height = 0;
    
    branch_head = NULL;
    branch_last = NULL;
    prev=NULL;
    next=NULL;
    this_garden = NULL;
}

TREE_CLASS::~TREE_CLASS(){
    cutTree(0);
  
   
}

BRANCH_CLASS::BRANCH_CLASS(unsigned int branch_h, unsigned int branch_l, TREE_CLASS* tree){
    branch_height = branch_h;
    branch_length = 0;
    this_tree = tree;
    fruit_head = NULL;
    fruit_last=NULL;
    prev=NULL;
    next=NULL;
    number_of_fruits = 0;
    all_fruits_weight = 0;
}
    BRANCH_CLASS::BRANCH_CLASS(){
        number_of_fruits = 0;
        all_fruits_weight = 0;
        branch_height = 0;
        branch_length = 0;
        fruit_head = NULL;
        fruit_last=NULL;
        prev=NULL;
        next=NULL;
        this_tree=NULL;
    }
 

 BRANCH_CLASS::~BRANCH_CLASS(){
     cutBranch(0);
     
 }


 FRUIT_CLASS::~FRUIT_CLASS(){
    if(this_branch != NULL){
        this_branch->decreaseTotalWeight(fruit_weight);
        this_branch->decreaseFruitNumber(1);   
     }
     else{
        fruit_weight = 0;
     }
    
 }

FRUIT_CLASS::FRUIT_CLASS(){
    fruit_length=0;
    fruit_weight=0;
    next=NULL;
    prev=NULL;
    this_branch=NULL;
}

FRUIT_CLASS::FRUIT_CLASS(unsigned int length, BRANCH_CLASS* branch){
    fruit_length=length;
    fruit_weight=0;
    next = NULL;
    prev= NULL;
    this_branch = branch;
}

FRUIT_CLASS::FRUIT_CLASS(const FRUIT_CLASS& fruit){
    fruit_length = fruit.fruit_length;
    fruit_weight = fruit.fruit_weight;
    this_branch = fruit.this_branch;
    next=NULL;
    prev=NULL;
}
BRANCH_CLASS::BRANCH_CLASS(BRANCH_CLASS& branch){
    all_fruits_weight = branch.all_fruits_weight;
    number_of_fruits = branch.number_of_fruits ;
    branch_height = branch.branch_height;
    branch_length = branch.branch_length;
    next = NULL;
    prev = NULL;
    this_tree = branch.this_tree;
    if(branch.fruit_head == NULL){      
        fruit_head=NULL;
        fruit_last=NULL;
    }
    else{
        fruit_head = new FRUIT_CLASS(*branch.fruit_head);
        fruit_head->setParent(this);
        fruit_last=fruit_head;
        FRUIT_CLASS* go = fruit_head;
        FRUIT_CLASS* n = branch.fruit_head->getNextFruit();
        while(n != NULL){
            FRUIT_CLASS* tfu = new FRUIT_CLASS(*n);
            tfu->setParent(this);
            tfu->setPrevFruit(go);
            go->setNextFruit(tfu);
            n= n->getNextFruit();
            go = go->getNextFruit();
            fruit_last = go;
        }
    }

}

TREE_CLASS::TREE_CLASS(TREE_CLASS& tree){
    tree_id = tree.tree_id;
    tree_height = tree.tree_height;

    total_fruits_number = tree.total_fruits_number;
    total_fruits_weight = tree.total_fruits_weight;
    branches_num = tree.branches_num;

    next = NULL;
    prev = NULL;
    this_garden = tree.this_garden;

    if(tree.branch_head == NULL){
        branch_head = NULL;
        branch_last = NULL;

    }else{
        branch_head = new BRANCH_CLASS(*tree.branch_head);
        branch_head->setParent(this);
        branch_last = branch_head;
        BRANCH_CLASS* go = branch_head;
        BRANCH_CLASS* n = tree.branch_head->getNextBranch();
        while(n != NULL){
            BRANCH_CLASS* tfu = new BRANCH_CLASS(*n);
            tfu->setParent(this);
            tfu->setPrevBranch(go);
            go->setNextBranch(tfu);

            n= n->getNextBranch();
            go = go->getNextBranch();
            branch_last = go;
         }
    }      
}
