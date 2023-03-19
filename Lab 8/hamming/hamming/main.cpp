#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

struct if_mistake{
    int num_of_mistakes = -1;
    int sum_of_mistakes = -1;
};

int is_parity(int n){
    if ((n & (n-1))==0){
        return 1;
    }
    else return 0;
}

vector <int> str_to_int (string input){
    vector <int> mess;
    for (int i=0; i<input.length(); i++){
        if (input[i] == '1'){
            mess[i] = 1;
        }
        else mess[i] = 0;
    }
    return mess;
}


if_mistake find_mistake(vector <int> input){
    int num_of_mistakes = 0;
    int sum_of_mistakes = -1;
    if_mistake mist;
    for (int i = 0; i < input.size(); i++) {
        int n = i + 1;
        int mistake = -1;
        if (is_parity(n)) {
            int step = n;
            int sum = 0;
            for (int j = n - 1; j < input.size(); j += 2 * step) {
                for (int z = j; z < j + step; z++){
                    if (input[j - 1] == 1) {
                        sum++;
                    }
                }
            }
            sum = sum % 2;
            if (sum == 0 and input[n - 1] == 0)
                mistake = -1;
            else if (sum == 1 and input[n - 1] == 1) {
                mistake = -1;
            } else {
                mistake = n;
            }
        }
        if (mistake){
            num_of_mistakes++;
            sum_of_mistakes+=n;
        }
        mist.num_of_mistakes = num_of_mistakes;
        mist.sum_of_mistakes = sum_of_mistakes;
    }
    return mist;
};



int main(){
    int n = 0;
    cin >> n;
    string input;
    vector<string> strings;
    if_mistake if_mistake;
    // strings.resize(n);
    while (cin >> input){
        vector <int> mess = str_to_int(input);
        int sum_of_mistakes = -1;
        string new_str = "";
        if_mistake = find_mistake(mess);
        if (if_mistake.num_of_mistakes > 0) {
            sum_of_mistakes = if_mistake.sum_of_mistakes;
            if (mess[sum_of_mistakes -1] == 0) {
                mess[sum_of_mistakes -1] = 1;
            } else mess[sum_of_mistakes -1] = 0;
        }
        for (int j=0; j<mess.size(); j++){
            if (is_parity(j+1) == 0){
                new_str += to_string(mess[j]);
            }
        }
        cout << new_str <<'\n';
    }


    return 0;
}