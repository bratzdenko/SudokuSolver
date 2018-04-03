#include<stdio.h>
    int	sudoku[9][9]=
    		{
    0,0,0,0,0,4,0,0,0,
0,6,8,0,0,0,5,0,0,
0,2,0,0,0,0,0,7,6,
6,0,0,0,0,0,8,9,0,
0,0,5,2,6,0,0,0,0,
0,0,0,9,0,0,1,0,0,
0,0,0,0,0,7,0,5,0,
0,4,0,0,0,0,0,0,1,
0,0,0,0,5,1,4,0,0
    		};
    		int a[9][9]=
    		{
    0,0,0,0,0,4,0,0,0,
0,6,8,0,0,0,5,0,0,
0,2,0,0,0,0,0,7,6,
6,0,0,0,0,0,8,9,0,
0,0,5,2,6,0,0,0,0,
0,0,0,9,0,0,1,0,0,
0,0,0,0,0,7,0,5,0,
0,4,0,0,0,0,0,0,1,
0,0,0,0,5,1,4,0,0
    		};
    //PRINT SUDOKU
    void printSudoku()
    {
    	int i,j;
    	for(i = 0; i < 9; i++) { if(i==3 || i==6 || i==6) printf("\n");
    		for(j = 0; j < 9; j++)	{
    			printf("%d",sudoku[i][j]);
    printf(" ");
    			if(j>7) printf("\n");
    			if(j==2 || j==5 || j==5) printf("  ");

    		}
    	}
    printf("\n");
    }
    //CHECK ROW
    int checkRow(int num, int i)	{
    int j,x=1;
    	for(j = 0; j < 9; j++)
    			if(sudoku[i][j] == num)	x=0;

    return x;
    }
    //CHECK COLUMN
    int checkCol(int num, int j) {
    int i,x=1;
    	for(i = 0; i < 9; i++)
    			if(sudoku[i][j]==num)	x=0;

    return x;
    }

    //CHECK SQUARE
    int checkSquare(int num, int xj, int yi)
    {
    	int x=1;
    	int i,j;
    	for(i = yi; i < yi+3; i++)
    		for(j = xj; j < xj+3; j++)
    			if(sudoku[i][j]==num)	x=0;

    return x;
    }
    //MAIN PROGRAM
    main()
    {
    	int i,j,num,row,col;
    	int pi,pj,xj,yi,square;

    	printSudoku();

    		for(i = 0; i < 9; i++)
    			for(j = 0; j < 9; j++) {
    				if(sudoku[i][j]==0)	{
    					num=1;

    					do	{
    							if(num>9)	{
    								pi=i;
    								if(j == 0)  {
    										if(i!=0)	{
    											pj=8;
    											pi=i-1;
    										}
    								}
    								else	{
    									pj=j-1;
    								}
    								for(i = pi; i >= 0; i--)
    									for(j = pj; j >= 0; j--)	{
                                            pj=8;

    									    if(a[i][j]==0 && sudoku[i][j]==9)	{
    											sudoku[i][j]=0;
    										}
    										else if(a[i][j]==0 && sudoku[i][j]<9)	{

    											num=sudoku[i][j]+1;
    											sudoku[i][j]=0;
    											goto check;
    										}
    									}
    							}
    						check:row=checkRow(num,i);
    						col=checkCol(num,j);
    						if(j<3)	xj=0;
    						if(j>2 && j<6) xj=3;
    						if(j>5) xj=6;
    						if(i<3)	yi=0;
    						if(i>2 && i<6) yi=3;
    						if(i>5) yi=6;
    						square=checkSquare(num,xj,yi);
    								if(row==1 && col==1 && square==1)
    										sudoku[i][j]=num;
    								else
    										num++;

    					}
    					while(row==0 || col==0 || square==0);
    				}
    			}

    	printf("\n");
    	printSudoku();

    }
