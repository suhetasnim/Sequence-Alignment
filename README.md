# Sequence-Alignment
  The Sequence Alignment is a process where two or more strings’ some part or the whole part are aligned with each other.
  In this algorithm,
The whole process is analysed through finding out the best alignment between the sequence. If the two process are such X = x1 x2....xm, and Y = y1 y2....ym
There are 3 ways to align them,
 1. Xi aligned to Yi
 2. Xi aligned to gap
 3. Yi aligned to gap

Here, 
  Two types of penalties are count:
     Gap penalty: For every gap in sequence a penalty is counted     TREE_
 								                                                     _REED
     Mismatch penalty: For every mismatch in sequence is counted  TREE
   									                                              REED

According , to this the sequence alignment is counted doing back tracking and the best one is selected.
