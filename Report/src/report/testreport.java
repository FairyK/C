package report;
import java.util.ArrayList;
import java.util.List;
import java.util.Random;

public class testreport {
	//��Ace,1,2,3,4,5,6,7,8,9,10,Jack,Queen,King����
		//�ƵĻ�ɫӦ����ʾΪ(Diamonds(����)��Hearts�����ģ���Spades�����ң���Clubs��÷����)			
		public static void main(String[]args)
		{ 
			String [] fourcardcolor={"Diamonds","Hearts","Spades","Clubs"};
			List<Card> cardList = new ArrayList<Card>(52);		
				for(int j=0;j<10;j++){
					for(int k=0;k<4;k++){
			Card card=new Card(""+j,fourcardcolor[k]);
			cardList.add(card);
			int count=0;			
			if(count<4) {
				Card cardJ=new Card("jack",fourcardcolor[k]);
				cardList.add(cardJ);
				Card cardQ=new Card("Queen",fourcardcolor[k]);
				cardList.add(cardQ);
				Card cardK=new Card("King",fourcardcolor[k]);
				cardList.add(cardK);	
				Card cardA=new Card("A",fourcardcolor[k]);
				cardList.add(cardA);				
			}
			count++;  //ʹ��ִֻ��4��JQKA
					}		
				}									
			 // shuffle ����˳�� 
	       // Collections.shuffle(cardList);
			Random r=new Random();	        
			System.out.println(cardList.get(r.nextInt(cardList.size())).toString());		
	   }
		
}

class Card{	
	private String cardname;
	private String cardcolor;
	public Card(String n,String c){
		cardname=n;
		cardcolor=c;		
	}
	@Override
	public String toString(){
		
		return "The Card you picked is" +" "+cardname+" " + "of"+" "+cardcolor+".";
	}	
}
	


