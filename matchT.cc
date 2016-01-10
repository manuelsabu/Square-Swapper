//************************************************* matchT() - START *********************************************************

// Purpose: Looks for the 4 variations of the T shape in the grid.
// Arguments: A Table
// Return: Total number of T matches

int matchT(int (&table)[10][10]){
	int total = 0, c1, c2, c3, c4, c5, c6, c7;
	
	//Test for upright T
	for(int i = 0; i <= 7 ; ++i){
		for(int j = 2; j <= 7; ++j){
			if(table[i][j] != -1){
				c1 = table[i][j];
				c2 = table[i][j-1];
				c3 = table[i][j-2];
				c4 = table[i][j+1];
				c5 = table[i][j+2];
				c6 = table[i+1][j];
				c7 = table[i+2][j];
				if(((c1%10) == (c2%10)) && ((c1%10) == (c3%10)) && ((c1%10) == (c4%10)) && 
				   ((c1%10) == (c5%10)) && ((c1%10) == (c6%10)) && ((c1%10) == (c7%10))){
					table[i][j-1] = table[i][j-2] = table[i][j+1] = table[i][j+2] = table[i+1][j] = table[i+2][j] = -1; //Void square
					table[i][j] = ((c1/100)*100) + 60 + (c1%10);	//Set special square
					++total;
				}}}}
	
	//Test for left T
	for(int i = 2; i <= 7; ++i){
		for(int j = 0; j <= 7; ++j){
			if(table[i][j] != -1){
				c1 = table[i][j];
				c2 = table[i-1][j];
				c3 = table[i-2][j];
				c4 = table[i+1][j];
				c5 = table[i+2][j];
				c6 = table[i][j+1];
				c7 = table[i][j+2];
				if(((c1%10) == (c2%10)) && ((c1%10) == (c3%10)) && ((c1%10) == (c4%10)) && 
				   ((c1%10) == (c5%10)) && ((c1%10) == (c6%10)) && ((c1%10) == (c7%10))){
					table[i-1][j] = table[i-2][j] = table[i+1][j] = table[i+2][j] = table[i][j+1] = table[i][j+2] = -1; //Void square
					table[i][j] = ((c1/100)*100) + 60 + (c1%10);	//Set special square
					++total;
				}}}}
	
	//Test for right T
	for(int i = 2; i <= 7; ++i){
		for(int j = 2; j <= 9; ++j){
			if(table[i][j] != -1){
				c1 = table[i][j];
				c2 = table[i][j-1];
				c3 = table[i][j-2];
				c4 = table[i-1][j];
				c5 = table[i-2][j];
				c6 = table[i+1][j];
				c7 = table[i+2][j];
				if(((c1%10) == (c2%10)) && ((c1%10) == (c3%10)) && ((c1%10) == (c4%10)) && 
				   ((c1%10) == (c5%10)) && ((c1%10) == (c6%10)) && ((c1%10) == (c7%10))){
					table[i][j-1] = table[i][j-2] = table[i-1][j] = table[i-2][j] = table[i+1][j] = table[i+2][j] = -1; //Void square
					table[i][j] = ((c1/100)*100) + 60 + (c1%10);	//Set special square
					++total;
				}}}}
	
	//Test for upside down T
	for(int i = 2; i <= 9; ++i){
		for(int j = 2; j <= 7; ++j){
			if(table[i][j] != -1){
				c1 = table[i][j];
				c2 = table[i-1][j];
				c3 = table[i-2][j];
				c4 = table[i][j-1];
				c5 = table[i][j-2];
				c6 = table[i][j+1];
				c7 = table[i][j+2];
				if(((c1%10) == (c2%10)) && ((c1%10) == (c3%10)) && ((c1%10) == (c4%10)) && 
				   ((c1%10) == (c5%10)) && ((c1%10) == (c6%10)) && ((c1%10) == (c7%10))){
					table[i-1][j] = table[i-2][j] = table[i][j-1] = table[i][j-2] = table[i][j+1] = table[i][j+2] = -1; //Void square
					table[i][j] = ((c1/100)*100) + 60 + (c1%10);	//Set special square
					++total;
				}}}}
	return total;
}
//************************************************* matchT() - END ***********************************************************