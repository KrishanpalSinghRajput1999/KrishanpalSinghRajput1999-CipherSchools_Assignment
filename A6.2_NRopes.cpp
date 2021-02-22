#include <iostream>       // std::cout
#include <queue>          // std::priority_queue
#include <vector>         // std::vector
#include <functional>     // std::greater
int ConnectRopes(std::vector<int> vecInput)
{
    int result = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int> >
        connectEdges(vecInput.begin(), vecInput.end());
    int interimResult = 0;
    while (!connectEdges.empty())
    {
        int minFirst = connectEdges.top();
        int minSecond = 0;
        connectEdges.pop();
        if (!connectEdges.empty())
        {
            minSecond = connectEdges.top();
            connectEdges.pop();
        }
        int addUp = minFirst+minSecond;
        interimResult += addUp;
        if(connectEdges.size() != 0)
            connectEdges.push(addUp);
        
    }
    return interimResult;
}
int main()
{
    std::vector<int> vecIn = {2,2,3,3};// { 1, 2, 5, 10, 35, 89 }; //{8, 4, 6, 12};//
    std::cout<< ConnectRopes(vecIn);
    return 0;
}
