#include<iostream>
#include<math.h>

using namespace std;

class arrProg{
    int a[10];
    int n;
    public:                                         /***ele is element***/ 
        arrProg(){n=0;}                             // 'n' is number of elements in array
        void insertAtBeg(int ele);                  // To insert at arrays beginning 
        void insertAtEnd(int ele);                  // To insert at array's end
        void insertAtLoc(int ele, int loc);         // To insert at certain locations of array; 'loc' is location pointed
        void insertAfter(int ele, int loc_ele);     // To insert after element 'loc_ele'
        

        void display();                             // To display the data
        void deleteFromEnd();                       // To delete from end of array
        void deleteFromBeg();                       // To delete from beginning of array
        void deleteAtLoc(int loc);                  // To delete from certain location


        void bubbleSort();
        int linearSearch(int ele);
        int binarySearch(int ele);
        
};

void arrProg::insertAtBeg(int ele){                 // Shift all element to right and insert the element in first location
    if(n!=0)
    for(int i=n; i>0; --i){
        a[i] = a[i-1];
        }
    a[0] = ele;
    n++;
}

void arrProg::insertAtEnd(int ele){                 // Insert the element at last location
    if(n<10){
        a[n] = ele;
        n++;
    }
}

void arrProg::insertAtLoc(int ele, int loc){        // Insert at specific location
    if(n!=0 && n>=loc)                              // Will shift all element after given location to right
    for(int i=n;i>loc-1;--i){
        a[i] = a[i-1];
        }
    a[loc-1] = ele;
    n++;
    
    
}

void arrProg::insertAfter(int ele, int loc_ele){    // Locate the given element and insert 
    int loc = linearSearch(loc_ele) + 1;            // the given element
    if(n!=0 && n>=loc)
    for(int i=n;i>loc-1;--i){
        a[i] = a[i-1];
    }
    a[loc-1] = ele;
    n++;
}

void arrProg::deleteFromEnd(){
    n--;
}

void arrProg::deleteFromBeg(){
    for(int i=1; i<n; ++i){
        a[n-1] = a[n];
    }
    n--;
}

void arrProg::deleteAtLoc(int loc){
    for(int i=loc-1;i<n;++i){
        a[i] = a[i+1];
    }
    n--;
}

void arrProg::bubbleSort(){                     //Sorts the array in non-decreasing order //
    for(int i=0; i<n-1 ;++i){
        for(int j=1+i; j<n; ++j){
            if(a[i] > a[j]){
                swap(a[i],a[j]);
            } 
            
        }
    }
    
}

int arrProg::linearSearch(int ele){             //  Returns the location of given element in real location terms i.e. a[0] = 1  //
    for(int i=0; i<n; ++i){
        if(a[i] == ele)
            return (i+1);
    }
    return -1;
}

int arrProg::binarySearch(int ele){             // Also returns the location of given element //
    bubbleSort();
    if(n==0)
        return -1;
    int left = 0;
    int right = n-1;
    int mid = 0;
    while(left<=right){
        mid = floor(left + (right - left)/2);
        if(ele == a[mid]){
            return mid+1;
        }
        if(ele < a[mid]){
            right = mid-1;
        } 
        if(ele > a[mid]) {
            left = mid + 1;
        }
    }
    return -1;
}

void arrProg::display(){
    for(int i=0; i<n; ++i){
        cout << a[i] << ' ';
    }
    cout << endl;
}
int main(){
    arrProg a;
    cout<<"Karanbir Singh\nURN: 2203483\n";
    // cout<<"Insert At end: 10\n";
    // cout<<"Insert At end: 5\n";
    // cout<<"Insert 23 at location 5\n";
    // cout<<"Insert 10 after 3\n";
    // cout<<"\nDelete from end\n";
    // cout << "Delete from beginning\n";
    cout<<"\ndelete at location 4\n";

    a.insertAtBeg(3);
    a.insertAtBeg(25);
    a.insertAtEnd(10);
    a.insertAtEnd(5);
    // a.insertAtEnd(14);
    a.insertAtLoc(23,5);                //Inserting element 23 after position 4
    a.insertAfter(10,3);                //Inserting 11 after element 3
    a.deleteFromBeg();
    a.deleteFromEnd();
    a.deleteAtLoc(4);
    a.display();
    return 0;

}

