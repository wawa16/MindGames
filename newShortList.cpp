#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

void printOutput(const vector<string> &);        //prints sorted output
vector<string> shortList(string[], int &size);   //sorting functions
void arrange(string[], int &size);
bool checkval(const vector<string> &, string &elem); 

bool checkval(const vector<string> &output, string &elem){
    unsigned int state = 0;
    std::vector<char> vec;
    for(unsigned int i=0;i<output.size();i++){
        unsigned int j = 0;
        while(j < output[i].length()){
            if(output[i] != elem){
            vec.push_back(output[i][j]);
              }
              j++;
            }
        }
        for(unsigned int count=0;count < elem.length();count++){                  
           if(std::find(vec.begin(), vec.end(), elem[count]) != vec.end()) {
               state++;
            } 
       }
       if(state == elem.length()){
            state = 0; return true;} else {return false;}
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
         //string names[5] = {"mikel", "micheal", "ulrich", "martha", "jonah"};
     
    string names[5] = {"zoo", "sea", "rose", "roseland", "and"};

    int size = sizeof(names)/sizeof(names[0]);
    arrange(names, size);
    return 0;
}

void arrange(string arr[], int &size){
    for (int i=1; i<size; i++)               //arrange initial array with word sizes in ascending order
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

    printOutput(shortList(arr,size));       //pass arranged array to sorting algorithm
}

vector<string> shortList(string names[], int &size){
     std::vector<char> alphabets;            //vector stores alphabets from names
     std::vector<string> sorted;
     int dict = 0;                           //dictionary counter

       for(int i=0; i<size; i++){
       unsigned int count = 0;               //local counter for alphabets in each name
       int state = 0;                        //counter decides which names to be included in shortlist
       int unique = 0;                       //counter for unique letters in a name; 
       int flag = 0; int g_flag = 0;
       //scan through alphabets in each name:
       while(count < names[i].length()){                  
       //check if current alphabet exists in our alphabets vector, if doen't then add it
           if(std::find(alphabets.begin(), alphabets.end(), names[i][count]) == alphabets.end()) {
              alphabets.push_back(names[i][count]);
            } else {state++;}
            count++;
       }
       unique = names[i].length() - state;            //calculates no. of unique chars
       
       if(state >= dict){                             //state = frequency of chars in word occuring in dictionary
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
                       sorted.push_back(names[i]);
                    }
                } else {
                      sorted.clear();
                      sorted.push_back(names[i]);   
                }
           } else {
                sorted.push_back(names[i]);
           }
   
       } else if (state < dict){
           for(unsigned int j=0; j<alphabets.size(); j++){
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
                       sorted.push_back(names[i]);
                    }
                }
       } 
        dict = dict + unique;                                  //updates dictionary with unique chars
    }
     for(unsigned int i=0; i<sorted.size(); i++){              //final Check for redundant elements to be erased
        if(checkval(sorted, sorted[i])){
             sorted.erase(sorted.begin() + i);
            }
        }
    return sorted;
}

void printOutput(const vector<string> &output){
    cout << "short-listed array of names:" << endl;
    for(unsigned int i=0; i<output.size(); i++){
        cout << output[i] << " ";
    }
}
