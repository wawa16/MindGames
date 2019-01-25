#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

struct Sorted {                    ///no need for struct (this for experimenting), simple 1D struct/array would suffice  
    std::string name;
    int id;
    int weight;
};

void printOutput(const vector<Sorted> &);        //prints sorted output
vector<Sorted> shortList(string[], int &size);   //sorting functions
void arrange(string[], int &size);
bool checkval(const vector<Sorted> &, string &elem); 

bool checkval(const vector<Sorted> &output, string &elem){
    bool flag; int state = 0;
    std::vector<char> vec;
    for(int i=0;i<output.size();i++){
        int j = 0; int count = 0; 
        while(j < output[i].name.length()){
            if(output[i].name != elem){
            vec.push_back(output[i].name[j]);
              }
              j++;
            }
        }
        for(int count=0;count < elem.length();count++){                  
           if(std::find(vec.begin(), vec.end(), elem[count]) != vec.end()) {
               state++;
            } 
       }
       if(state == elem.length()){
             state = 0;
            return true;
         } else {
             return false;
        }
}

int main()
{
    ////////SAMPLE TEST CASES://///////////////////////////////////////////
         //string names[5] = {"a","b", "bab"};
         //string names[9] = {"a","b", "ab", "bab", "babel", "bebe", "bf", "c", "beb"}; //Input Array of names
         //string names[4] = {"dolly", "bab","bay", "ash"}; //Input Array of names
         //string names[6] = {"daf","bab", "c", "cab", "a", "b"};
         //string names[4] = { "edd", "lisa", "waleed", "isac"};
         //string names[4] = {"noah", "john", "joan", "deb"};
     
     string names[5] = {"zoo", "sea", "rose", "roseland", "and"};

    int size = sizeof(names)/sizeof(names[0]);
    arrange(names, size);
    return 0;
}

void arrange(string arr[], int &size){
    for (int i=1; i<size; i++) 
        { 
        string temp = arr[i]; 
        int j = i - 1; 
        while (j >= 0 && temp.length() > arr[j].length()) 
         { 
            arr[j+1] = arr[j]; 
            j--; 
          } 
            arr[j+1] = temp; 
        } 

    printOutput(shortList(arr,size));       
}

vector<Sorted> shortList(string names[], int &size){
     std::vector<char> alphabets;   //vector stores alphabets from names
     std::vector<Sorted> sorted;
     int dict = 0;                  //dictionary counter

       for(int i=0; i<size; i++){
       int count = 0;               //local counter for alphabets in each name
       int state = 0;               //counter decides which names to be included in shortlist
       int unique = 0;              //counter for unique letters in a name; 
       int flag = 0; int g_flag = 0;
       //scan through alphabets in each name:
       while(count < names[i].length()){                  
       //check if current alphabet exists in our alphabets vector, if doen't then add it
           if(std::find(alphabets.begin(), alphabets.end(), names[i][count]) == alphabets.end()) {
              alphabets.push_back(names[i][count]);
            } else {
              state++;
            }
            count++;
       }
       unique = names[i].length() - state;          //calculates uniqueness
       
       if(state >= dict){
           if(sorted.size() != 0){
               for(int j=0; j<alphabets.size(); j++){
                   flag = 0; count=0;
                   while(count < (names[i].length())){
                       if(alphabets[j] != names[i][count]){
                           flag++;
                       }
                       count++;
                   }
                   if(flag > g_flag){
                       g_flag = flag;
                   }
                }
                if(g_flag == names[i].length()){
                     if(unique != 0){
                       sorted.push_back({names[i], unique, dict-state});
                    }
                } else {
                      sorted.clear();
                      sorted.push_back({names[i], unique, dict-state});   
                }
           } else {
                sorted.push_back({names[i], unique, dict-state});
           }
   
       } else if (state < dict){
           for(int j=0; j<alphabets.size(); j++){
                   flag = 0; count=0;
                   while(count < (names[i].length())){
                       if(alphabets[j] != names[i][count]){
                           flag++;
                       }
                       count++;
                   }
                   if(flag > g_flag){
                       g_flag = flag;
                   }
                }
                if(g_flag == names[i].length()){
                     if(unique != 0){
                       sorted.push_back({names[i], unique, dict-state});
                    }
                }
       } 
        dict = dict + unique;
    }
    
    int count = 0; int flag = 0; 
    
     for(int i=0; i<sorted.size(); i++){              //final Check for redundant elements to be erased
        if(checkval(sorted, sorted[i].name)){
             sorted.erase(sorted.begin() + i);
            }
        }
    return sorted;
}

void printOutput(const vector<Sorted> &output){
    
    cout << "short-listed array of names:" << endl;
    for(int i=0; i<output.size(); i++){
        cout << output[i].name << " ";
    }
}
