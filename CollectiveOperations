//Dorota Dyczek
int start = 0;
int bit = 0;
int space = 0;
int number = 32;
int count = 0;
int result;
int numberR = 31;
void Symmetric (int z1,int z2,int* z){
    *z = z1^z2;
    }
void Union(int z1, int z2, int* z){
    *z = z1 | z2;
}
void Intersection(int z1, int z2, int* z){
    *z = z1 & z2;
}
void Difference(int z1, int z2, int* z){
    *z = z1 & (~z2);
}
void Complement(int z1, int* z){
    *z = ~z1;
}
bool Equality(int z1, int z2){
    if (z1 == z2)
        return true;
    return z1 == z2;
}
bool Inclusion(int z1, int z2){
    if((z1 & z2) == z1)   
        return true;
    return false;
}
bool Emptiness(int z){
    return z==0;
}
bool Nonempty(int z){
    if(z != 0)
        return true;
    return false;
    
}
bool Disjoint(int z1, int z2){
    if(z1&z2)  
        return false;
    return true;
}
bool Conjunctive(int z1, int z2){
    return !(Disjoint(z1,z2));
}

int Cardinality(int z){
    int one = 1;
    
    if(number >= 0){
        one = one<<number;
        if((one&z) == one){
            count++;
        }
        --number;
        if(number >= 0){
            Cardinality(z);
        }
        else{
        result = count;
        number = 31;
        count = 0;
        }
    }
return result;
}

bool LessThen(int z1, int z2) {
    if(Cardinality(z1) == Cardinality(z2)){
        return z1<z2;
    }
    else if(Cardinality(z1) < Cardinality(z2)){
        return true;
    }
    return false;
}
bool LessEqual(int z1, int z2) {
    if(Cardinality(z1)<Cardinality(z2)){
        return true;
    }
    else if(Cardinality(z1) == Cardinality(z2)){
        if(z1<=z2)
            return true;
    }
    return false;
}
bool GreatEqual(int z1, int z2){
        if(Cardinality(z1)>Cardinality(z2)){
        return true;
    }
    else if(Cardinality(z1) == Cardinality(z2)){
        if(z1>=z2)
            return true;
    }
    return false;
}
bool GreatThen(int z1, int z2){

     if(Cardinality(z1) == Cardinality(z2)){
        return z1>z2;
    }
    else if(Cardinality(z1) > Cardinality(z2)){
        return true;
    }
    return false;
}



void Emplace(char* num, int *set){
    if(start == 0){
        *set = 0;
    }
    if(*num !='\0'){
        if(*num == '0'){
            space = 1;
            bit  = bit <<1;
            start++;
        }
        else if(*num == '1'){
            space = 1;
            bit = (bit<<1) | 1;
            start++;
        }
        if(*(num+1) == ' ' | *(num+1) == '\0'){
            if(space){
            int temp = 1<<bit;
            *set = *set|temp;
            bit = 0;
            space = 0;
            }
        }
        num++;
        if(*num !='\0'){
            Emplace(num, set);
        }
        else{
            start = 0;
            bit = 0;
            space = 0;
        }
     
    }
}
void Insert(char* num,int*set){
   if(*num !='\0'){
        if(*num == '0'){
            space = 1;
            bit  = bit <<1;
            
        }
        else if(*num == '1'){
            space = 1;
            bit = (bit<<1) | 1;
        
        }
        if(*(num+1) == ' ' | *(num+1) == '\0'){
            if(space){
            int temp = 1<<bit;
            *set = *set|temp;
            bit = 0;
            space = 0;
            }
        }
        num++;
        if(*num !='\0'){
            Insert(num, set);
        }
        else{
            bit = 0;
            space = 0;
        }
     
    }

}

void Erase(char* num, int* set){
    if(*num !='\0'){
        if(*num == '0'){
            space = 1;
            bit  = bit <<1;
        }
        else if(*num == '1'){
            space = 1;
            bit = (bit<<1) | 1;
        }
        if(*(num+1) == ' ' | *(num+1) == '\0'){
            if(space){
            int temp = 1<<bit;
            *set = *set&(~temp);
            bit = 0;
            space = 0;
            }
        }
        num++;
        if(*num !='\0'){
            Erase(num, set);
        }
        else{
            bit = 0;
            space = 0;
        }
     
    }
}


int CharToDec(char* num,int liczba){
    if(*num !='\0'){
        if(*num == '0'){
            
            bit = bit << 1;
        }
        else if(*num == '1'){
           
            bit = (bit<<1) | 1;
        }
        num++; 
        if(*num !='\0'){
        CharToDec(num,liczba);
        liczba = 1<<bit;
        }
        
    }
   
    return liczba;
}  
bool Member(char* num,int set){
    int liczba = 1;
    liczba =  CharToDec(num,liczba);
    bit = 0; 
    if(liczba&set){
        return true;
    }
    return false;
    
}

void Print(int set ,char* num){

if(set == 0){
    *(num) = 'e';
    *(num+1) = 'm';
    *(num+2) = 'p';
    *(num+3) = 't';
    *(num+4) = 'y';
    *(num+5) = '\0';
}
else if((1<<numberR)&set){
    if((numberR/16)%2 == 1){
        *(num++) = '1';
    }
    else if((numberR/16)%2 == 0){
        *(num++) = '0';
    }
    if((numberR/8)%2 == 1){
        *(num++) = '1';
    }
    else if((numberR/8)%2 == 0){
        *(num++) = '0';
    }
        if((numberR/4)%2 == 1){
        *(num++) = '1';
    }
    else if((numberR/4)%2 == 0){
        *(num++) = '0';
    }
    if((numberR/2)%2 == 1){
        *(num++) = '1';
        
    }
    else if((numberR/2)%2 == 0){
        *(num++) = '0';
    }
    if(numberR%2 == 1){
        *(num++) = '1';
        
    }
    else if(numberR%2 == 0){
        *(num++) = '0';
    }
    *(num++) = ' ';

}
--numberR; 
if(numberR >= 0)
{
    Print(set, num);
}else{
    *(--num) = '\0';
}
numberR = 31;
}
