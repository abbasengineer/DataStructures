//
// To change this license header, choose License Headers in Project Properties.
// To change this template file, choose Tools | Templates
// and open the template in the editor.

//Updated
//Programmer: Abbas Engineer
//Project :   PA1
//Version :   1.0
//Class   : CMPS 101 Prof. Tantalo

//-----------------------------------------------------------------------------
// FileIO.java
// Illustrates file IO and tokenization using String.split()
//-----------------------------------------------------------------------------
//
import java.io.*;
import java.util.Scanner;

public class Lex {


   public static void main(String[] args) throws IOException{
      Scanner in = null;
      PrintWriter out = null;
      String line = null;
      String[] token = null;
      int lineNumber = 0;

      if(args.length < 2){
         System.err.println("Usage: FileIO infile outfile");
         System.exit(1);
      }
      
      in = new Scanner(new File(args[0]));
      out = new PrintWriter(new FileWriter(args[1]));
      
      
      while( in.hasNextLine() ){
         lineNumber++;
         line = in.nextLine()+" ";    // add extra space so split works right
         
         }


     in.close();

     
     in = new Scanner(new File(args[0]));
     
     String[] array = new String[lineNumber];
     
     int n = 0;
     while (in.hasNextLine() ){
         array[n]=in.nextLine();
         n++;
     }
   
    List list = new List();
    if( list.isEmpty() ){
        list.append(0);
    }
int i;
int j ;
    for(i = 1 ; i <= lineNumber - 1 ; i++ ){

        list.moveFront();      //Insert A[i] into the sorted sequence A[1 ...j-1]
        String S = array[i];   //set key = A[j]
        j = i - 1 ;
        j++;

        while( j > 0  &&  0 <= S.compareTo(array[list.get()]) ){ //while i>0 and A[i] > key
            list.moveNext();     
            j--;                 // j = j - 1
        }
        if (list.indexIs() ) {
                list.insertBefore(i);
            } 
        else if(list.index() == -1){
                list.append(i);
        }
    }

    list.moveFront();
    
    while(list.index() > -1 ){
        out.println(array[list.get()]);
        list.moveNext();
    }
    
    in.close();
    out.close();
    
  }
   
}
