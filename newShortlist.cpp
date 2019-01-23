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
void arrangethis(string[], int &size);


int main()
{
    // int names_size;
    // cout << "How many names you wish to enter?" << endl;
    // cin >> names_size;
    // string names[names_size];
    // cout << "Input " << names_size << " names(in all lower-caps, press enter after each entry):" << endl;
    // for(int i=0; i<names_size; i++){
    //     cin >> names[i];
    // }
    
 ////For using User-Input names, Comment following array and Uncomment code above
    
    string names[6] = {"a","b","bab", "babe", "bgf", "bf"}; //Input Array of names
    //string names[9] = {"a","b","bab", "babe", "bebe", "bebef", "bf", "c", "beb"}; //Input Array of names
    
    
    int size = sizeof(names)/sizeof(names[0]);
    arrangethis(names, size);

    
    
    return 0;
}

void arrangethis(string arr[], int &size){
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
    int m; 
        for (m=0; m < size; m++) 
            cout << arr[m] << " " << arr[m].size() << " "; 
            
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
                       sorted.push_back({names[i], i, weight});
                      //short_list.push_back(names[i]);          
                    }
                } else {
                      sorted.clear();
                      sorted.push_back({names[i], i, weight});   
                }
                //cout << flag << endl;
           } else {
                sorted.push_back({names[i], i, weight});
                //short_list.push_back(names[i]);
           }
   
       } else if (state < dict && unique != 0){
           sorted.push_back({names[i], i, weight});
       } else if (state < dict && unique == 0){
           auto iterator = std::find_if(sorted.begin(), sorted.end(), [&](const Sorted& p) {
            return p.weight == max_weight;
            });
          if (iterator == sorted.end()) {
          } else {
            //   iterator->name = names[i];
            //   iterator->id = i;
            //   iterator->weight = weight;
              int index = std::distance(sorted.begin(), iterator);
              //cout << "weight: " << iterator->weight << endl;
              //sorted.erase(sorted.begin() + index);
          }
           //sorted.push_back({names[i], i, weight});
       }
            // if(weight > max_weight){
            //          auto iterator = std::find_if(sorted.begin(), sorted.end(), [&](const Sorted& p) {
            //             return p.weight == max_weight;
            //             });
            //           if (iterator == sorted.end()) {
            //             // the id wasn't found
            //           } else {
            //               iterator->name = names[i];
            //               iterator->id = i;
            //               iterator->weight = weight;
            //               int index = std::distance(sorted.begin(), iterator);
            //               cout << "ID: " << index<< endl;
            //               sorted.erase(sorted.begin() + index);
            //           }
            //     }
        auto minmax_values = std::minmax_element(sorted.begin(), sorted.end(),[]
        (Sorted const& lhs, Sorted const& rhs) {return lhs.id < rhs.id;});
        max_weight = minmax_values.second->weight;
        dict = dict + unique;
    }

       
    return sorted;
}

void printOutput(const vector<Sorted> &output){
    cout << "short-listed array of names:" << endl;
    for(int i=0; i<output.size(); i++){
        cout << "name: " << output[i].name << " ID: " << output[i].id << " weight: " << output[i].weight << "\n";
    }
}
