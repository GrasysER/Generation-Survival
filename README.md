# Generation-Survival

Project ran with makefile
    
    User can enter the boards dimensions (<= 100x100)    
    Number of generations    
    Coordinates of species by input or from file
        
    Displays the initial state for the board and the locations of each species
    Runs for the # of generations entered, and displays result
    
    
Enter board dimensions. Keep the size 100x100 or less.   
Width: 10    
Height: 15     
Enter number of generations: 3     
     
Enter cell data from user or file input?    
    
0 - User   
1 - File   
1   
    
coordinate (4,8) selected   
coordinate (4,10) selected   
coordinate (5,8) selected   
coordinate (5,10) selected    
coordinate (6,8) selected   
coordinate (6,9) selected    
coordinate (6,10) selected   
   
   
======initial state======   
14----------    
13----------    
12----------   
11----------   
10----***---        
09------*---   
08----***---    
07----------   
06----------   
05----------   
04----------    
03----------       
02----------   
01----------   
00----------    
  0000000000   
  0123456789   
   
 /======generation 1======\   
              |  born = 3     died = 3   |   
 \\========================/    
   
14----------    
13----------   
12----------    
11-----*----    
10-----**---    
09-------*--      
08-----**---    
07-----*----   
06----------    
05----------    
04----------    
03----------   
02----------   
01----------   
00----------   
  0000000000   
  0123456789   
    
 /======generation 2======\    
|  born = 2     died = 0   |   
 \\========================/   
   
14----------   
13----------    
12----------    
11-----**---   
10-----**---   
09-------*--   
08-----**---   
07-----**---   
06----------   
05----------   
04----------   
03----------   
02----------    
01----------    
00----------      
  0000000000   
  0123456789   
    
 /======generation 3======\   
|  born = 2     died = 2   |   
 \\========================/   
   
14----------   
13----------   
12----------   
11-----**---    
10-----*-*--   
09-------*--    
08-----*-*--    
07-----**---   
06----------       
05----------    
04----------   
03----------    
02----------     
01----------     
00----------   
  0000000000    
  0123456789   
   
   
