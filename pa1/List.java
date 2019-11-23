/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


    //-----------------------------------------------------------------------------
//Programmer: Abbas Engineer
//CruzID  :   afengine
//Project :   PA1
//Version :   1.0
//Class   : CMPS 101 Prof. Tantalo
//-----------------------------------------------------------------------------
public class List {
       
    private class Node{
      // Fields
      int data;
      Node next;
      Node prev;
      
      // Constructor
      Node(int data) { this.data = data; next = null; prev = null; }
      
      // toString():  overrides Object's toString() method
      public String toString() { 
         return String.valueOf(data); 
      }
      
      // equals(): overrides Object's equals() method
      public boolean equals(Object x){
         boolean eq = false;
         Node that;
         if(x instanceof Node){
            that = (Node) x;
            eq = (this.data==that.data);
         }
         return eq;
      }
    
}
// Fields
   private Node front;
   private Node back;
   private int  length;
   private int  index;
   private Node cursor;

   // Constructor
   List() { 
      front = back = cursor = null; 
      length = 0; 
      index = -1;
   }
   
   
   //------------------------------ Access Functions -------------------------//

// isEmpty()     Returns true if this List is empty, false otherwise.
   boolean isEmpty() { 
      return length<=0; 
   }
   
// when the cursor is between the bounds of 0 and length -1 returns true
   boolean indexIs(){
       return index <= length - 1 && index >= 0;
   }

// getLength()   Returns length of this List.
   int length() { 
      return length; 
   }
 
// If cursor is defined, returns the index of the cursor element,
// otherwise returns -1.
   int index(){
   
       if (cursor == null )
            return -1;
        else 
            return index;
   }

// Front()       Returns front element.   // Pre: !this.isEmpty()
   int front(){
      if( this.isEmpty() ){
         throw new RuntimeException
        ("List Error: getFront() called on empty List");
      }
      return front.data;
   }

// int Back()    Returns back element.   // Pre: !this.isEmpty()
   int back(){
      if( this.isEmpty() ){
         throw new RuntimeException(
            "List Error: getBack() called on empty List");
      }
      return back.data;
   }
   
// int get()     Returns cursor element. // Pre: length()>0, index()>=0
   int get(){
   if(this.isEmpty() ){
       throw new RuntimeException(
       "List Error: get() called on empty List");
   }
   if(cursor == null){
       throw new RuntimeException(
       "Index Error: get() called an undefined cursor");
   }
   return cursor.data;
   }

// Returns true if and only if this List and L are the same
// integer sequence. The states of the cursors in the two Lists
// are not used in determining equality.
   public boolean equals(Object x){
      boolean eq  = false;
      List L;
      Node N, M;

      if(x instanceof List){
         L = (List)x;
         N = this.front;
         M = L.front;
         eq = (this.length==L.length);
         while( eq && N!=null ){
            eq = N.equals(M);
            N = N.next;
            M = M.next;
         }
      }
      return eq;
   }
   
//----------------------- Manipulation Functions-----------------------------//
// Resets this List to its original empty state.  
    void clear() {
length = 0;
index  = -1;
front = back = null ;
}

// If List is non-empty, places the cursor under the front element,
// otherwise does nothing.
    void moveFront() {
    if (! this.isEmpty() ){
    cursor = front ;
    index = 0;
    }
    else 
        ;
    }

// If List is non-empty, places the cursor under the back element,
// otherwise does nothing.
    void moveBack() {
    if (! this.isEmpty() ){
    cursor = back ;
    index = length - 1 ;
    }
    else
        ;
    }
        
// If cursor is defined and not at front, moves cursor one step toward
// front of this List, if cursor is defined and at front, cursor becomes
// undefined, if cursor is undefined does nothing.        
    void movePrev(){
        if (this.indexIs() ){
            cursor = cursor.prev;
            index--;
        }
        else{
            
            cursor = null ;
            index = -1;
        }
        
    }

// If cursor is defined and not at back, moves cursor one step toward
// back of this List, if cursor is defined and at back, cursor becomes
// undefined, if cursor is undefined does nothing.
    void moveNext(){
    if (this.indexIs() ){
            cursor = cursor.next;
            index++;
        }
    else {
        index = -1 ;
        }  

    } 

// Insert new element into this List. If List is non-empty,
    void prepend(int data) {
        Node N = new Node(data);
        if (this.isEmpty() ){
            front = back = N;
        }

        else if(front != null){

               N.next = front;
               N.prev = null;
               front.prev = N;
               front = N;
           
               index++;
        }
        length++;
        
    }

// insertion takes place before front element.
// Insert new element into this List. If List is non-empty,
    void append(int data) {
      Node N = new Node(data);
      if( this.isEmpty() ) { 
         front = back = N;
      }else{ 
         
         back.next = N; 
         N.prev = back;
         back = N; 
         N.next = null;
         
      }
      length++;
   }

    void insertBefore(int data){
        Node N = new Node(data);
        if(this.isEmpty() || cursor == front){
            prepend(data);
          
        }
        else if(!this.indexIs() ){
            throw new RuntimeException(
            "Index Error: insertBefore() called on undefined cursor");
        }
        else{
           Node prev = cursor.prev;
            //System.out.println("in else 1");
           
           N.next = cursor;
           N.prev = prev;
           prev.next = N;
           cursor.prev = N;
           //System.out.println("out of else ");
        length++;
        index++;
           //System.out.println("in else last");
            } 
         
      
    }

// Pre: length()>0, index()>=0
// Inserts new element after cursor.
    void insertAfter(int data){
        Node N = new Node(data);
        if (this.isEmpty() ){
            prepend(data);
        }
        else if( ! this.indexIs() ){
            throw new RuntimeException(
            "Index Error: insertAfter() called on undefined cursor");
        }
        else if(cursor == back){
            append(data);
        }
        else{
            Node next = cursor.next;
            
            N.next = cursor.next;
            N.prev = next;
            next.prev = N;
            cursor.next = N;
            length++;
        }
        
        
    } 
 
// Pre: length()>0, index()>=0
// Deletes the front element. Pre: length()>0            
    void deleteFront(){
        if(this.isEmpty() ){
         throw new RuntimeException(
            "List Error: deleteFront() called on empty List");
      }
       
      if(! this.isEmpty() ){
         front = front.next;
         if(front != null )
         front.prev = null;
         if (index != -1){
             index--; 
         }
	
         
      }else if (this.length() == 1){
         front = back = null;
         index = -1;
      }
      length--;
    }

// Deletes the back element. Pre: length()>0
    void deleteBack() {
        if(this.isEmpty() ){
         throw new RuntimeException(
            "List Error: deleteBack() called on empty List");
      }
      if(! this.isEmpty() ){
         if(cursor == back){
             index = -1;
         }
         back = back.prev;
         if(back != null){
         back.next = null;
         }

         
         length--;
         
      }else if (this.length() == 1){
         front = back = null;
         index =-1;
         
      }
      
    }
    
 // Deletes cursor element, making cursor undefined.
 // Pre: length()>0, index()>=0
    void delete() {
        if(this.isEmpty() || ! this.indexIs() ){
         throw new RuntimeException(
            "List Error: delete() called on empty List or cursor out of index");
      }
        else{
        if (cursor.next != null) { 
            cursor.next.prev = cursor.prev; 
        } 
        if (cursor.prev != null) { 
            cursor.prev.next = cursor.next; 
        } 
           cursor = null;
        }
        index = -1;
        length --;
    }

//------------------------------ Other Functions -----------------------------//
 
 // Overrides Object's toString method. Returns a String
 // representation of this List consisting of a space
 // separated sequence of integers, with front on left.
    public String toString() {
        StringBuffer sb = new StringBuffer();
      Node N = front;
      while(N!=null){
         // System.out.println("tostring1");
         sb.append(N.toString());
         sb.append(" ");
         N = N.next;
         // System.out.println("tostring2");
      }
      return new String(sb);
    }
  


 // copy()
 // Returns a new List identical to this List.
    List copy(){
      List L = new List();
      Node N = this.front;

      while( N!=null ){
         L.append(N.data);
         N = N.next;
      }
      return L;
    }
}
