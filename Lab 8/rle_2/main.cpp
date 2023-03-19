#include <iostream>
#include <string>
using namespace std;

int each_ekv( int a, int b, int c) {
    if (a=c){
        return a;
    }
    else return b;

}

int main() {
    int difference = 0;
    string input1;
    string input2;
    int len1;
    int len2;
    int flag = 0;
    string count1 = "";
    string count2 = "";
    int count1_1;
    int count2_2;
    int k;
    cin >> len1 >> len2 >> k;
    cin >> input1 >> input2;

    int max_len = max(len1, len2);
    int min_len = min(len1, len2);
    int p1 = 0, p2 = 0;
    while (p1 < max_len and p2<max_len) {
        while (difference < k) {
            count1 = "";
            count2 = "";
            if (input1[p1] == input2[p2]) {
                p1++;
                p2++;
                count1 = "";
                count2 = "";
                while (isdigit(input1[p1])) {
                    p1++;
                    count1 += input1[p1];
                }
                while (isdigit(input2[p2])) {
                    p2++;
                    count2 += input2[p2];
                }
                count1_1 = stoi(count1);
                count2_2 = stoi(count2);
                difference += abs(count1_1 - count2_2);
            }
            if (input1[p1] != input2[p2]) {
                p1++;
                p2++;
                count1 = "";
                count2 = "";
                while (isdigit(input1[p1])) {
                    count1 += input1[p1];
                    p1++;
                }
                while (isdigit(input2[p2])) {
                    count2 += input2[p2];
                    p2++;
                }
                count1_1 = stoi(count1);
                count2_2 = stoi(count2);
                difference = difference + count2_2 + count1_1;

            }
            if (difference >= k) {
                flag += 1;
                break;
            }
            if (p1 == min_len || p2 == min_len) {
                if (difference >= k) {
                    flag += 1;
                    break;
                }
                else {
                    p2++;
                    p1++;
                    if (p1 > min_len) {
                        while (isdigit(input1[p1])) {
                            count1 += input1[p1];
                            p1++;
                        }
                        difference += stoi(count1);
                    }
                    if (p2 > min_len) {

                        while (isdigit(input2[p2])) {
                            count2 += input2[p2];
                            p2++;
                        }
                        difference += stoi(count2);
                    }
                }
            }
        }
        if (difference >= k) {
            flag += 1;
            break;
        }
    }
    if (flag)
        cout << "No";
    else cout << "Yes";

    return 0;
}
