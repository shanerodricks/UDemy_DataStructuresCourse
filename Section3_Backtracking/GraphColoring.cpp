#include iostream
using namespace std;

GraphColoring::GraphColoring(const vector<vector<int>> &graph, int _numofColors)
      : graphMatrix(graph)
      , numOfColors(_numofColors)
{
  colors.resize(graphMatrix.size());
}

void GraphColoring::operator()(){

  if(solve(0)) {
    showResult();
  }
  else{
    cout << "No solution with the given parameters...\n";
  }
}

//function to assign colors recursively
bool GraphColoring::solve(size_t nodeIndex) {
  //if we have considered as all the nodes in the graph and assign colors accordingly, then we are done
  // so we have solved the coloring problem with backtracking

  if (nodeIndex == graphMatrix.size()) {
    return true;
  }

  //try all colors(every color has an index)
  for (int colorIndex = 1; colorIndex <= numOfColors; colorIndex++){
    //check if the given color is valid(no noeds can share same color)
    if(isColorValid(nodeIndex, colorIndex)){
      colors[nodeIndex] = colorIndex;

      //try to find the color for the next node
      if(solve(nodeIndex + 1))
        return true;

      //Backtrack: we keep checking the next colorIndex
    }
  }

  //we have condeired all colors without any result, meaning no solution
  //we are not able to use different colors for adjacent nodes in the graphMatrix
  //so we backtrack -> maybe we have to change the color of the previous node
  return false;
}

//function to check if it is valid to use that color to a given vertex
bool GraphColoring::isColorValid(size_t nodeIndex, size_t colorIndex) {
  for(size_t i = 0; i < graphMatrix.size(); i++) {
    //we have to check the adjacent nodes (where matrix value is 1) AND whether they have the same color or another
    if (graphMatrix[nodeIndex][i] == 1 && colorIndex == colors[i]) {
      return false;
    }
  }
  return true;
}

void GraphColoring::showResult() {
  for(size_t i = 0; i < graphMatrix.size(); i++)
    cout << "Node " << (i + 1) << " has color index: " << colors[i] << "\n";
}
