//************************************************* swap() - START ***********************************************************

// Purpose: Consumes a table, co-ordinates, and swap direction, then returns the swapped table.
// Arguments: Table, X-coordinate, Y-coordinate, and Swap direction
// Retrun: int

int swap(int (&table)[10][10], int x, int y, int z){
	int temp;	//Temporary Variable for swap.
	if((x < 10 && x >= 0) && (y < 10 && y >= 0)){
		
		if(z == 0 && x > 0)	{ // Can swap NORTH check
			temp = table[x][y];
			table[x][y] = table[x-1][y];
			table[x-1][y] = temp; 
		}
		
		else if(z == 1 && x < 9) { // Can swap SOUTH check
			temp = table[x][y];
			table[x][y] = table[x+1][y];
			table[x+1][y] = temp; 
		}
		
		else if(z == 2 && y > 0) { // Can swap WEST check
			temp = table[x][y];
			table[x][y] = table[x][y-1];
			table[x][y-1] = temp; 
		}
		
		else if(z == 3 && y < 9) { // Can swap EAST check
			temp = table[x][y];
			table[x][y] = table[x][y+1];
			table[x][y+1] = temp; 
		}
		
		else {
			cerr << "Invalid Z Co-ordinate!"<<endl;
			return 1;
		}
	}
	
	else {
		cerr << "Invalid (X,Y) Co-ordinate!"<<endl;
		return 1;
	}
	return 0;
}
//************************************************** swap() - END ************************************************************