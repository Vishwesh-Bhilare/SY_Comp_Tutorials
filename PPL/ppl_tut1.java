import java.util.*;

class Student {
    private String name;
    private int mark1, mark2, mark3;
    private int avg = 0;
    private int ID = 0;

    /*
     private int mark[3] = {0, 0, 0}
    */


    public boolean showResult(){
         if (avg < 45 || mark1 < 40 || mark2 < 40 || mark3 < 40){
             return false;
         }
         else{
             return true;
         }
    }

    public int getAvg(){
        avg = (mark1 + mark2 + mark3) / 3;

        return avg;
    }

    public void setMarks(int a, int b, int c){
        mark1 = a;
    mark2 = b;
    mark3 = c;
    }

    public void setName(String n){
        name = n;
    }

    public String getName(){
        return name;
    }

    public void setID(int n){
        ID = n;
    }

    public int getID(){
        return ID;
    }

    /*
    public setMarks(int mrk[3]){
        for (int i = 0; i < 3; i++){
        marks[i] = mrk[i];
    }
    }
    */
}

class Main{
    public static void main(String[] args){
        Student s1 = new Student();
        
        /*
        Scanner sc = new Scanner (System.in);
        System.out.println("Enter your name: ");
        String name = sc.next();

        int mark[3] = {0, 0, 0};
        
        System.out.println("Enter marks for 3 subjects: ");
        for(int i = 0; i < 3; i++){
            mark[i] = sc.nextInt();
        }

        s1.setMarks(mark);
        s1.setName(name);

        */

        s1.setName("Tushar");
        s1.setID(1001);

        System.out.println("Student name: " + s1.getName());
        System.out.println("ID : " + s1.getID());

        s1.setMarks(100, 100, 75);
        
        System.out.println("Average marks: " + s1.getAvg());

        if (s1.showResult()){
            System.out.println(s1.getName() + " has passed the exam!!");
        }
        else {
            System.out.println(s1.getName() + " has failed the exam!!");
        }

    }
}
