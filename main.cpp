#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int foo(vector<int> &a, vector<int> &b){

    int n = a.size();
    int empty_index = -1; //index of empty space
    int counter = 0; //number of necessary switches
    vector<vector<int>> temp; //hold state of array after every switch

    //find starting empty space
    for(int i = 0; i < n; i++)
        if(a[i] == 0) empty_index = i;
    if(empty_index == -1) throw string("No empty parking provided!");

    while(true){

        int match = b[empty_index]; //corresponding car in resulting array
        int switch_index = -1; //index of car to be switched with empty space

        //case when the empty space is positioned correctly
        if(match == 0){
            //check if all other cars are positioned correctly
            for(int j = 0; j < n ; j++){
                if(j != empty_index && a[j] != b[j])
                //index of first car that isn't positioned correctly
                    switch_index = j; break;
            }
        }else{
            //find the index of the matching car
            for(int j = 0; j < n; j++)
                if(a[j] == match) switch_index = j;

        }
        //all cars are positioned correctly
        if(switch_index == -1) break;

        //swap the two cars and update empty space index
        counter++;
        swap(a[empty_index], a[switch_index]);
        empty_index = switch_index;
        temp.push_back(a);
    }

    cout<<counter<<endl;
    for(int i = 0; i<temp.size(); i++){
         for(int j = 0; j < n; j++) cout<<temp[i][j]<<" ";
         cout<<endl;
    }

}


int main()
{
    /*input example:
        4
        2 0 1 3
        3 1 0 2
    */
    
    vector<int> a;
    vector<int> b;
    int n; //number of parking spaces
    cin>>n;

    for(int i = 0; i<n; i++){
        int x; cin>>x; a.push_back(x);
    }

    for(int i = 0; i<n; i++){
        int x; cin>>x; b.push_back(x);
    }

    try{
        foo(a,b);
    }catch(string err) {
        cout<<err;
    }



    return 0;
}
