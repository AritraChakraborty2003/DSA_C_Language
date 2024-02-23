package stacks_queues;

import java.util.Stack;

public class postfix_evaluation {
	public static void main(String[] args) {
		 int val =evaluatePostFix("231*+9-");
		 System.out.println(val);
	}
	 static int evaluatePostFix(String S)
    {
        // Your code here
        Stack<Integer> stk=new Stack<>();
        for(int i=0;i<S.length();i++){
            if(((int)(S.charAt(i))>=48) && ((int)(S.charAt(i))<=57)){
                String str=String.valueOf(S.charAt(i));
                int res=Integer.valueOf(str);
                stk.push(res);
            }
            else{
        
                int op1=stk.pop();
                int op2=stk.pop();
                if(S.charAt(i)=='+') stk.add(op1+op2);
                else if(S.charAt(i)=='-') stk.add(op2-op1);
                else if(S.charAt(i)=='/') stk.add(op2/op1);
                else  stk.add(op1*op2);
                
            }
        }
        return stk.peek();
    }
}
