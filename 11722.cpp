#include <iostream>
#include <vector>

using namespace std;

vector<int> number;
vector<int> d;
vector<int> d_num;

void binary(int num);

int main() {
  int N, input;
  cin >> N;

  for(int i =0; i<N; i++){
    cin >> input;
    number.push_back(input);
  }

  d.push_back(number[0]);
  d_num.push_back(1);

  for(int i =1; i<N; i++){
    if(number[i] < d.back() ){
      d.push_back(number[i]);
    }
    else{
      binary(number[i]);
    }
    d_num.push_back(d.size());
  }

  int max = 0;

  for(int i =0 ;i<d_num.size(); i++){
    if(max < d_num[i]){
      max = d_num[i];
    }
  }

  cout << max;
  return 0;
}

void binary(int num){
  int start = 0;
  int end = d.size() - 1;
  int mid;
  int index = 1001;

  while (start<=end){
    mid = (start+end) /2;

    if(d[mid] <= num){
      end = mid-1;

      if(index > mid){
        index = mid;
      }
    }
    else{
      start = mid+1;
    }
  }

  d[index] = num;
}