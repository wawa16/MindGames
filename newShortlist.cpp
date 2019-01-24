#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

struct Sorted {
    std::string name;
    int id;
    int weight;
};

void printOutput(const vector<Sorted> &);      //prints sorted output
vector<Sorted> shortList(string[], int &size); //sorting function
void arrange(string[], int &size);


int main()
{
    ////////TEST CASES://///////////////////////////////////////////
     //string names[5] = {"a","b", "bab"};
    //string names[9] = {"a","b", "ab", "bab", "babel", "bebe", "bf", "c", "beb"}; //Input Array of names
     // string names[4] = {"dolly", "bab","bay", "ash"}; //Input Array of names
    //string names[6] = {"daf","bab", "c", "cab", "a", "b"};
    string names[4] = { "edd", "waleed", "lisa", "isac" };
     //string names[4] = {"noah", "john", "joan", "deb"};
     
     //string names[4] = {"sea", "rose", "roseland", "and"};

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
       int weight = 0;
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
       unique = names[i].length() - state;
       weight = state + unique;
       
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
                } else {
                    //   sorted.clear();
                    //   sorted.push_back({names[i], unique, dict-state});   
                }
           if(names[i].length() != dict){
               
           }
           //sorted.push_back({names[i], unique, dict-state});
       } 
        dict = dict + unique;
    }
    
    string arr[sorted.size()];
    int count = 0; int flag = 0; 

     for(int i=0; i<sorted.size(); i++){
    
         int g_flag = 0; int y=0; int elem_size = sorted[i].name.length();
         if(sorted[i].name != sorted[sorted.size()-1].name){
         for(int j=0; j<sorted[i].name.length(); j++){
             flag = 0; count=0; y = 0;
         while(y != i){
          while(count < (sorted[i].name.length()) ){
            
            if(sorted[i].name[j] != sorted[y].name[count]){
               flag++; 
            }
              count++;
           }
           y++;
            cout << sorted[i].name << " " << y << " G_Flag: " << g_flag;
               if(flag > g_flag){
                g_flag = flag;
                }
             if(g_flag != elem_size){
                sorted.erase(sorted.begin() + i);
             }  
         }
        
         }
                   
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
