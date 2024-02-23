package stacks_queues;
import java.util.*;

public class infix_postfix {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		String s="a+b*(c^d-e)^(f+g*h)-i";
		String res=infixToPostfix(s);
		System.out.println(res);

	}
	static String infixToPostfix(String exp) {
        // Your code here
         Stack<Character> stk = new Stack<Character>();
        HashMap<Character,Integer> weightMap=new HashMap<>();
        weightMap.put('^',5);
        weightMap.put('*',4);
        weightMap.put('/',4);
        weightMap.put('+',3);
        weightMap.put('-',3);
        weightMap.put('(',0);
        String modExp=exp;
        String res="";
        for(int i=0;i<modExp.length();i++){
            if(((int) (modExp.charAt(i))>= 49 && 
            (int) (modExp.charAt(i))<= 57)||((int) (modExp.charAt(i))>= 97 && 
            (int) (modExp.charAt(i))<= 122) ||
            ((int) (modExp.charAt(i))>= 65 && 
            (int) (modExp.charAt(i))<= 90) ){
                res+=modExp.charAt(i);
            }
            
            else if(modExp.charAt(i)=='(')
                stk.push(modExp.charAt(i));
            
            else if(modExp.charAt(i)==')'){
            
                while(stk.peek()!='(')
                {
                    res+=stk.pop();
                    
                }
                stk.pop();
            }
            
            
            else{
              
              if(stk.isEmpty()) stk.push(modExp.charAt(i));
              else if(weightMap.get(modExp.charAt(i))>
               weightMap.get(modExp.charAt(i))){
                   stk.push(modExp.charAt(i));
               }
               else{
                    while((!stk.isEmpty()) && (weightMap.get(stk.peek())>= weightMap.get(modExp.charAt(i)))){
                        res+=stk.pop();
                   }
                   stk.push(modExp.charAt(i));
               }
            }
        }
        
        while(!stk.isEmpty())
            res+=stk.pop();

       return res;
        
    }

}
