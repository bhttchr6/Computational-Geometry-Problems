#include <vector>
#include <set>
#include <map>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

int evaluate(int val2, std::vector<int> keys, int &route, std::multimap<int, int> connectivity)
{
    
    if(val2 == keys.size()-1)
    {
        //std::cout << "*** route found ***" << std::endl;
        route ++;
        
        //return route;
    }
    else
    {
        auto range = connectivity.equal_range(val2);
        for (auto i = range.first; i != range.second; ++i)
        {
            auto val1 = i->first;
            auto val2 = i->second;
            /*
            std::cout << "=== outer loop ===" << std::endl;
            std::cout << "val1=" << val1 <<std::endl;
            std::cout << "val2=" << val2 <<std::endl;
            */
            if(val2>val1)
            {
                evaluate(val2, keys, route, connectivity);
            }
        }
    }

    

    
    return route;
    

};

int main()
{   
    int numPad = 2;
    int origRows = 7;
    int origCols = 3;
    int numRows = origRows + numPad, numCols = origCols + numPad; // add paddings
    std::vector<std::vector<int>> graph(numRows, std::vector<int>(numCols, -1));

    //create the graph
    std::vector<int> keys;
    for(int i = 1; i < numRows - (numPad-1); i++)
    {
        for(int j = 1; j < numCols - (numPad - 1); j++)
        {
            graph[i][j] = (numCols - (numPad)) * (i-1) + j-1;
            keys.push_back(graph[i][j]);
            
        }
    }

    //create connectivity matrix
    std::multimap<int, int> connectivity;
    
    
    //print the graph
    for(int i = 1; i < numRows - (numPad - 1); i++)
    {
        for(int j = 1; j < numCols - (numPad - 1); j++)
        {
            
            connectivity.emplace(graph[i][j], graph[i - 1][j]);
            connectivity.emplace(graph[i][j], graph[i][j - 1]);
            connectivity.emplace(graph[i][j], graph[i][j + 1]);
            connectivity.emplace(graph[i][j], graph[i + 1][j]);
            
        }
    }

    //show elements associated with a specific key
    auto range = connectivity.equal_range(11);
    auto i = range.second;

    
    
    /*
    for (auto i = range.first; i != range.second; ++i)
        std::cout << i->first << ": " << i->second << '\n';
    */
    std::set<int> visited;
    
    

    int route = 0;
    int flag = 0;
    for(int i = 0; i< 1; i++)
    {   
        visited.insert(i);

        auto range = connectivity.equal_range(keys[i]);
        for (auto i = range.first; i != range.second; ++i)
        {
            auto val1 = i->first;
            auto val2 = i->second;

            route = evaluate(val2, keys,  route,  connectivity);
            
        }
        
    

    }
    

    std::cout << "number of routes = "<< route <<std::endl;



}