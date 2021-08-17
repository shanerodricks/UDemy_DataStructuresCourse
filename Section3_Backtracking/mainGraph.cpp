#include <iostream>
#include <vector>
using std::vector;

int main(int argc, const char * argv[]) {
  const vector<vector<int>> graphMatrix = {
    {0,1,0,1,0},
    {1,0,1,0,1},
    {0,1,0,1,0},
    {1,1,1,0,1},
    {0,0,0,1,0}
  };

  constexpr int numOfColors = 3;

  GraphColoring graphColoring(graphMatrix, numOfColors);
  graphColoring();

  return 0;
}
