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
    
    string names[9] = {"a","b", "ab", "bab", "babel", "bebe", "bf", "c", "beb"}; //Input Array of names
   // string names[6] = {"bab","bay", "ash", "doll", "dolla", "dolly"}; //Input Array of names
    int size = sizeof(names)/sizeof(names[0]);
    arrange(names, size);
    return 0;
}

void arrange(string arr[], int &size){
    int i,j;
       for(j=0; j<size-1; j++){
            for(i=0; i<size-1; i++){
             if(arr[i] > arr[i+1]){
                string z = arr[i];
                arr[i] = arr[i+1];
                arr[i+1] = z;
             }
        }
      }
    printOutput(shortList(arr,size));       
}

vector<Sorted> shortList(string names[], int &size){
     std::vector<char> alphabets;   //vector stores alphabets from names
     std::vector<Sorted> sorted;
     int dict = 0;                  //dictionary counter
     int max_weight = 0;

       for(int i=0; i<size; i++){
       int count = 0;               //local counter for alphabets in each name
       int state = 0;               //counter decides which names to be included in shortlist
       int unique = 0;              //counter for unique letters in a name; 
       int flag = 0; int update; int g_flag = 0;
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
                   flag = 0; count=0; update = 0;
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
                   flag = 0; count=0; update = 0;
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
    return sorted;
}

void printOutput(const vector<Sorted> &output){
    string arr[output.size()];
    int size = output.size();
    cout << "short-listed array of names:" << endl;
    for(int i=0; i<output.size(); i++){
        cout << output[i].name << " ";
    }
}





