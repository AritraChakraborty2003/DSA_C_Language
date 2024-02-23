import java.util.*;
public class reverseQueue{
    public static void main(String[] args){

        Queue<Integer> q=new LinkedList<>();
        q.add(2);
        q.add(3);
        q.add(4);
        System.out.println(q);
        Queue q1=revQueue(q);
        System.out.println(q1);
    }
    static Queue revQueue(Queue<Integer> q){
        Stack<Integer> stk=new Stack<>();
        while(!q.isEmpty())
        {
            stk.push(q.remove());
        }
        while(!stk.isEmpty())
            q.add(stk.pop());
       
        return q;

    }
}