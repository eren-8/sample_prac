// #include<queue>
// #include<vector>
// #include<functional>
// #include<iostream>

// int main(){
//     auto f1 = [](const int n1, const int n2)->bool{
//         return n1<n2;
//     };
//     std::priority_queue<int,std::vector<int>,decltype(f1)> pq(f1);
//     std::vector<int> v1 {1,2,3,4,5};
//     for(int i=0;i<5;i++){
//         pq.emplace(v1[i]);
//     }
//     std::cout<<pq.top()<<"\n";
// }
