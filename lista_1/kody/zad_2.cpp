#include <iostream>
#include <vector>
#include <cmath>

long long COMP = 0; // porównania elementów
long long ASS  = 0; // przypisania elementów

namespace vectors_1{
    std::vector<int> A7 = {7, 4, 5, 4, 2, 1, 9};
    // nie posortowana Lista wielkości n=7
    std::vector<int> A15 = {91, 43, 77, 13, 58, 62, 71, 26, 80, 41, 59, 2, 97, 34, 15};
    // nie posortowana Lista wielkości n=15
    std::vector<int> A100 = {864, 394, 776, 911, 430, 41, 265, 988, 523, 497,
                             414, 940, 802, 849, 310, 991, 488, 366, 597, 913,
                             929, 223, 516, 142, 289, 144, 774, 98, 634, 819,
                             257, 544, 961, 822, 437, 112, 82, 896, 340, 139,
                             952, 580, 360, 553, 517, 189, 121, 353, 923, 960,
                             995, 422, 598, 183, 454, 230, 37, 282, 394, 763,
                             89, 567, 912, 531, 604, 153, 293, 286, 105, 893,
                             674, 721, 957, 95, 818, 763, 947, 912, 56, 764,
                             632, 426, 900, 828, 845, 56, 912, 620, 456, 120,
                             259, 43, 699, 278, 684, 711, 265, 814, 694, 732};
    // nie posortowana Lista wielkości n=100   
}

void PRINT_VECTOR(std::vector<int>& A){
    for (int x : A) std::cout << x << " ";
    std::cout <<'\n';
}

void MERGE(std::vector<int>& A, int p, int s, int k){
    int n1 = s - p + 1;
    int n2 = k - s;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++) {
        L[i] = A[p + i];
        ASS++;                      
    }
    for (int j = 0; j < n2; j++) {
        R[j] = A[s + 1 + j];
        ASS++;                      
    }

    int i = 0, j = 0;
    for (int l = p; l <= k; l++) {
        if (i >= n1) {              
            A[l] = R[j++];
            ASS++;                  
        } 
        else if (j >= n2) {         
            A[l] = L[i++];
            ASS++;                  
        } 
        else {
            COMP++;                 
            if (L[i] <= R[j]) {
                A[l] = L[i++];
                ASS++;
            } else {
                A[l] = R[j++];
                ASS++;
            }
        }
    }
}

void MERGE_SORT(std::vector<int>& A, int p, int k) {
    if (p < k){
        int s = (int)std::floor((p + k) / 2.0);
        MERGE_SORT(A, p, s);
        MERGE_SORT(A, s + 1, k);
        MERGE(A, p, s, k);
    }
}

int main() {
    using namespace vectors_1;

    MERGE_SORT(A7, 0, (int)A7.size() - 1);
    PRINT_VECTOR(A7);

    MERGE_SORT(A15, 0, (int)A15.size() - 1);
    PRINT_VECTOR(A15);

    MERGE_SORT(A100, 0, (int)A100.size() - 1);
    PRINT_VECTOR(A100);


    std::cout << "\nCOMP = " << COMP << "\nASS  = " << ASS << "\n";
    return 0;
}
