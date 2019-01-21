#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

void printOutput(const vector<string> &);      //prints sorted output
vector<string> shortList(string[], int &size); //sorting function

int main()
{
    // int names_size;
    // cout << "How many names you wish to enter?" << endl;
    // cin >> names_size;
    // string names[names_size];
    // cout << "Input " << names_size << " names(press enter after each entry):" << endl;
    // for(int i=0; i<names_size; i++){
    //     cin >> names[i];
    // }
    
 ////For using User-Input names, Comment following array and Uncomment code above
    
    string names[7] = {"alison", "bob", "kate", "son", "carl", "ansen", "mike"}; //Input Array of names
    
    int size = sizeof(names)/sizeof(names[0]);
    
    printOutput(shortList(names,size));
    
    return 0;
}

vector<string> shortList(string names[], int &size){
     std::vector<char> alphabets;   //vector stores alphabets from names
     std::vector<string> output;   //vector contains final sorted output
     
     
       for(int i=0; i<size; i++){
       int count = 0;    //local counter for alphabets in each name
       int state = 0;    //counter decides which names to be included in shortlist
       
       //scan through alphabets in each name:
       while(count < names[i].length()){                  
       //check if current alphabet exists in our alphabets vector, if doen't then add it
           if(std::find(alphabets.begin(), alphabets.end(), names[i][count]) == alphabets.end()) {
              alphabets.push_back(names[i][count]);
              state++;
            }
            
    ///For same result but without std::find(algorithm lib):
    ///Uncomment the code below and comment the if() func above
        
        // int flag = 0;
        //     for(int j=0; j<alphabets.size(); j++){
        //         if (names[i][count] != alphabets[j]){
        //           flag++;
        //         }
        //     }
        //     if(flag == alphabets.size()){
        //         alphabets.push_back(names[i][count]);
        //         state++;
        //     }

            count++;
       }
       if(state != 0){
           output.push_back(names[i]);
       }
    }
    return output;
}

void printOutput(const vector<string> &output){
    cout << "short-listed array of names:" << endl;
    for(int i=0; i<output.size(); i++){
        cout << output[i] << " ";
    }
}

