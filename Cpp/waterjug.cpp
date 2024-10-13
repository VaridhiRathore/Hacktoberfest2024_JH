//Given two jugs with the maximum capacity of m and n liters respectively. The jugs don’t have markings on them which can help us to measure smaller quantities. The task is to measure d liters of water using these two jugs. Hence our goal is to reach from initial state (m, n) to final state (0, d) or (d, 0). Examples:

Input: 4 3 2 Output: (0, 0) –> (4, 0) –> (4, 3) –> (0, 3) –> (3, 0) –> (3, 3) –> (4, 2) –> (0, 2) Input: 5 2 4 Output: (0, 0) –> (5, 0) –> (5, 2) –> (0, 2) –> (2, 0) –> (2, 2) –> (4, 0)

// C++ Program for the above approach
#include <bits/stdc++.h>
using namespace std;

// jug1 and jug2 contain the value
// for max capacity in respective jugs
// and aim is the amount of water to be measured.
int jug1 = 4;
int jug2 = 3; 
int aim = 2;

// Initialize dictionary with
// default value as false.
int visited[10000][10000]={false};

// Recursive function which prints the
// intermediate steps to reach the final
// solution and return boolean value
// (True if solution is possible, otherwise False).
// amt1 and amt2 are the amount of water present
// in both jugs at a certain point of time.
bool waterJugSolver(int amt1, int amt2){

	// Checks for our goal and
	// returns true if achieved.
	if ((amt1 == aim && amt2 == 0) || (amt2 == aim && amt1 == 0)){
		cout<<amt1<<" "<<amt2<<endl;
		return true;
	}
	
	// Checks if we have already visited the
	// combination or not. If not, then it proceeds further.
	if (visited[amt1][amt2] == false){
		cout<<amt1<<" "<<amt2<<endl;
	
		// Changes the boolean value of
		// the combination as it is visited.
		visited[amt1][amt2] = true;
	
		// Check for all the 6 possibilities and
		// see if a solution is found in any one of them.
		return (waterJugSolver(0, amt2) ||
				waterJugSolver(amt1, 0) ||
				waterJugSolver(jug1, amt2) ||
				waterJugSolver(amt1, jug2) ||
				waterJugSolver(amt1 + min(amt2, (jug1-amt1)),
				amt2 - min(amt2, (jug1-amt1))) ||
				waterJugSolver(amt1 - min(amt1, (jug2-amt2)),
				amt2 + min(amt1, (jug2-amt2))));
	}
	
	// Return False if the combination is
	// already visited to avoid repetition otherwise
	// recursion will enter an infinite loop.
	else
		return false;
}

int main() {
	
cout<<("Steps: ")<<endl;

// Call the function and pass the
// initial amount of water present in both jugs.
waterJugSolver(0, 0);

	return 0;
}

// This code is contributed by Pushpesh Raj

