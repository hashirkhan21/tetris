/* PROGRAMMING FUNDAMENTAL'S PROJECT FOR FALL 2022 BS(CS)
 * You need to define the required function in the part instructed here below.
 * Avoid making any unnecessary changes, particularly the ones you don't understand.
 * The different pieces should be defined using an array - uncomment the following code once you are done creating the array.
 * TIP: Understand thoroughly before getting started with coding.
 * */

//---Piece Starts to Fall When Game Starts---//
	void shadow();
void bombs(float& timer ,float& delay, bool& bomb);
void fallingPiece(float& timer, float& delay,int& colorNum,int& c1,int& c2,int& c3,int& n1,int& n2,int& n3,bool& bomb, int& c4,int& mov, int& n, float& q){
    if (timer>delay){
    if(bomb==0)
    	mov=1;
    	else 
    	mov=0;
    
        for (int i=0;i<4;i++){
            point_2[i][0]=point_1[i][0];
            point_2[i][1]=point_1[i][1];
            point_1[i][1]+=mov;
            }
             
        if (!anamoly() && bomb==false){
       for(int i=0;i<4;i++)
	{gameGrid[point_2[i][1]][point_2[i][0]] = colorNum;}	
        for (int i=0;i<4;i++){
            point_4[i][0]=point_2[i][0];
            point_4[i][1]=point_2[i][1];
            }
        
            if(rand()%10 == 5 && bomb==false)
            {bomb=true;
            point_8[0][0]=rand()%10;
            point_8[0][1]=0;
            for (int i=0;i<4;i++){
            point_1[i][0]=70;
            point_1[i][1]=70;
            point_3[i][1]=70;
            point_3[i][0]=70;
            }
            
            c4=1+rand()%7;
            mov=1;
            }
            
            if(bomb==false){
            n=n1; 
      	     colorNum=c1;
      	     n1=n2;
      	     c1=c2;
      	     n2=n3;
      	     c2=c3;
      	     c3=1+rand()%7;
      	     n3=rand()%7;}
      	     
            //--- Un-Comment this Part When You Make BLOCKS array---//
            
                for (int i=0;i<4 && bomb==false;i++){
                    point_1[i][0] = (BLOCKS[n][i] % 2) + 4 ;
                    point_1[i][1] = BLOCKS[n][i] / 2;
                    point_5[i][0] = BLOCKS[n1][i] % 2;
                    point_5[i][1] = BLOCKS[n1][i] / 2;
                    point_6[i][0] = BLOCKS[n2][i] % 2;
                    point_6[i][1] = BLOCKS[n2][i] / 2;
                    point_7[i][0] = BLOCKS[n3][i] % 2;
                    point_7[i][1] = BLOCKS[n3][i] / 2;

                }
        }
        timer=0;
        delay = q;
    }
}

/////////////////////////////////////////////
///*** START CODING YOUR FUNTIONS HERE ***///

	void bombDel(int c4, int& score);
	void bombs(float& timer ,float& delay , bool& bomb, int c4, int& score)
	{
	
	if(bomb==true){
	 if (timer>0.5){
	 
          point_9[0][1] = point_8[0][1]; 
          point_8[0][1]+= 1; 
          
        if (!anamoly3()){
     	point_8[0][1] = point_9[0][1];
     	bombDel(c4,score);
     	bomb=0;
     	point_8[0][1]=30;
     	point_8[0][0]=-20;
    	}}}}
	
	void bombDel(int c4, int& score)
	{
	int l=0;
	if(point_8[0][1]!=20)
	if(gameGrid[point_8[0][1]+1][point_8[0][0]] == c4){
	int line = M-1;
	for(int i=line ; i>0 ; i--)
	{
	for(int j=0 ; j<N ; j++)
	{if(gameGrid[i][j]==0)
	l++;}
	}
	for(int m=M-1 ; m>=0 ; m--){
	for(int n=N-1 ; n>=0 ; n--)
	{gameGrid[m][n]={0};}}
	score += l;
	}
	else
	{
	if(gameGrid[point_8[0][1]+2][point_8[0][0]])
	{l++;gameGrid[point_8[0][1]+2][point_8[0][0]]=0;}
	if(gameGrid[point_8[0][1]+1][point_8[0][0]+1])
	{l++;gameGrid[point_8[0][1]+1][point_8[0][0]+1]=0;}
	if(gameGrid[point_8[0][1]+1][point_8[0][0]-1])
	{l++;gameGrid[point_8[0][1]+1][point_8[0][0]-1]=0;}
	
	gameGrid[point_8[0][1]+1][point_8[0][0]]=0;
	gameGrid[point_8[0][1]+1][point_8[0][0]-1]=0;
	gameGrid[point_8[0][1]+1][point_8[0][0]+1]=0;
	gameGrid[point_8[0][1]+2][point_8[0][0]]=0;
	
	score += l+1;
	}

	}
	
	
	//Movement
	void move(int& delta_x)
	{
	if(delta_x != 0 )
	for (int i=0;i<4;i++)
	{point_2[i][0]=point_1[i][0];
	 point_1[i][0]+=delta_x;
	 }
	 if(!anamoly())
	 for(int i=0 ; i<4 ; i++){
	 point_1[i][0]=point_2[i][0];
	 }
	 
	 for(int i=0 ; i<4 ; i++)
	{point_3[i][0]=point_1[i][0];
        }
	delta_x=0;
	}
	
        //Deletes Line             *    	
	void deleteline()
	{int line = M-1;
	for(int i=line ; i>0 ; i--)
	{int l=0;
	for(int j=0 ; j<N ; j++)
	{if(gameGrid[i][j]!=0)
	l++;
	}
	if(l==10){
	for(int k=0 ; k<N ; k++)
	{gameGrid[i][k] = 0;}
	}
	}}
	
	
	//Moves Line Down After Deletion *
	void lineDown()
	{int line = M-1;
	for(int i=line ; i>0 ; i--)
	{
	int l=0;
	for(int j=0 ; j<N ; j++)
	{if(gameGrid[i][j]==0)
	l++;}
	
	if(l==10)
	for(int h=i ; h>1 ; h--)
	 for (int k = 0; k < N; k++)
        {gameGrid[h][k] = gameGrid[h-1][k];}}}
	
	//Calls the deleteline and lineDown Function ***
	void line()
	{deleteline();
	lineDown();}
	
	//For Calculation of Score
	void Score(int& score)
	{
	int line = M-1; int c=0;
	for(int i=line ; i>0 ; i-- )
	{int l=0;
	for(int j=0 ; j<N ; j++){
	{if(gameGrid[i][j]!=0)
	l++;}}
	if(l==10)
	{c++;}
	}
	if(c==4)
	score += 100;
	else if(c==3)
	score += 60;
	else if(c==2)
	score +=30;
	else if(c==1)
	score += 10;
	c=0;
	}
	
	
	//Rotation
	void shadow(bool bomb);
	void rotation(bool& rotate , bool bomb)
	{
	for (int i=0;i<4;i++)
	{
	point_2[i][0]=point_1[i][0]; 
	point_2[i][1]=point_1[i][1];
	}  
	
	if(point_1[0][0]==point_1[2][0] && point_1[1][0]==point_1[3][0])  
	if(point_1[2][1]==point_1[3][1])
	rotate=false;
	
         if(rotate==true)
        {
	for (int i=0;i<4; i++)
	{
	int ax = point_1[i][1]-point_1[1][1];
	int ay = point_1[i][0]-point_1[1][0];  //X and Y cords being swapped 
	point_1[i][0] = point_1[1][0] - ax ;
	point_1[i][1] = point_1[1][1] + ay ;
	}
	rotate=0; }
	
	if(!anamoly())
	for (int i=0;i<4;i++)
	{point_1[i][0]=point_2[i][0]; point_1[i][1]=point_2[i][1];}
	shadow(bomb);
	}
	
	
	
	//Shadow function
	void shadow(bool bomb)
	{
	if(bomb==false){
	for (int i=0;i<4;i++){
	point_3[i][0]=point_1[i][0];
        point_3[i][1]=point_1[i][1];}
	while(anamoly2()){
	for (int i=0;i<4;i++){
            point_4[i][0]=point_3[i][0];
            point_4[i][1]=point_3[i][1];
            point_3[i][1]+=1;}}
            
        if(!anamoly2())
        for (int i=0;i<4;i++){
            point_3[i][0]=point_4[i][0];
            point_3[i][1]=point_4[i][1];}}
	}
	
	void Space()
	{
	for(int i=0; i<4 ; i++)
	{
	point_1[i][0]=point_3[i][0];
        point_1[i][1]=point_3[i][1];
	}}
	

	


///*** YOUR FUNCTIONS END HERE ***///
/////////////////////////////////////
