package metawork;
import java.awt.BorderLayout;
import java.awt.Button;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.LayoutManager;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.*;
import javax.swing.text.JTextComponent;
public class calculate extends JFrame
{
	long a,b,c,result;
	
	
	
	public static  void main(String args[])
	{
		calculate frame = new calculate();
		frame.setVisible(true);
	}
	
	JTextField textField = new JTextField ();//设置显示

public  calculate() 
{
	super();
	setTitle("计算器");	
	setResizable(false);
	setBounds(100,100,300,280);
	setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	final JPanel viewpanel = new JPanel();//设置显示面板     面板是text  显示器是textField;
	getContentPane().add(viewpanel, BorderLayout.NORTH);
	
	
	
	textField.setEditable(false);
	textField.setHorizontalAlignment(SwingConstants.RIGHT);
	textField.setColumns(18);
	textField.getText();
	
	
	viewpanel.add(textField);//合并起来
	final JPanel buttonpanel = new JPanel();
	
    final GridLayout gridLayout=new GridLayout(4,0);
    
    
	gridLayout.setVgap(10);//设置组件的水平间距
	gridLayout.setHgap(10);//设置组件的垂直间距
	buttonpanel.setLayout(gridLayout);//组件容器采用流布局管理器
 	getContentPane().add(buttonpanel,BorderLayout.CENTER);
//		Container container_1 = new Container ();
//		container_1.setLayout(gridLayout);
//		
		String pre;
		
		String[][] names={{"1","2","3","+"},{"4","5","6","-"},{"7","8","9","*"},{".","0","=","/"}};
		JButton[][] buttons=new JButton[4][4];
		for(int row=0;row<names.length;row++){
			for(int col=0;col<names.length;col++){
				buttons[row][col]=new JButton(names[row][col]);
				String button=buttons[row][col].getActionCommand();
				if(button=="="||button=="+"||button=="-"||button=="*"||button=="/")
					buttons[row][col].addActionListener(new result());
				else 
					buttons[row][col].addActionListener(new formula());
				buttonpanel.add(buttons[row][col]);
			}
		}		
				
				final JLabel leftlabel = new JLabel();
				leftlabel.setPreferredSize(new Dimension(10,0));
				getContentPane().add(leftlabel,BorderLayout.WEST);
				
				final JLabel rightlabel = new JLabel();
				rightlabel.setPreferredSize(new Dimension(10,0));
				getContentPane().add(rightlabel,BorderLayout.EAST);

	}
				
				
//				final JLabel uplabel = new JLabel();
//				leftlabel.setPreferredSize(new Dimension(10,0));
//				getContentPane().add(uplabel,BorderLayout.NORTH);
//				final JLabel downlabel = new JLabel();
//				leftlabel.setPreferredSize(new Dimension(10,0));
//				getContentPane().add(downlabel,BorderLayout.SOUTH);
				
				//pre=buttons[row][col].getActionCommand();
//				
//				if(pre=="+"||pre=="-"||pre=="*"||pre=="/")
//					buttons[row][col].addActionListener(new ActionListener(r));//为加减乘除添加动作触发事件
//				else if(pre=="=")
//					buttons[row][col].addActionListener(new ActionListener());//等号按钮触发动作事件
//				else
//					buttons[row][col].addActionListener(new ActionListener());
//				text.add(buttons[row][col]);
		
		
//		JTextField text = new JTextField("0");
//		JButton one = new JButton("1");
//		JButton two = new JButton("2");
//		JButton three= new JButton("3");
//		JButton plus = new JButton("+");
//		JButton four = new JButton("4");
//		JButton five = new JButton("5");
//		JButton six= new JButton("6");
//		JButton minus= new JButton("-");
//		JButton seven= new JButton("7");
//		JButton eight= new JButton("8");
//		JButton nine= new JButton("9");
//		JButton by= new JButton("*");
//		JButton zero= new JButton("0");
//		JButton equal= new JButton("=");
//		JButton point= new JButton(".");
//		JButton devide= new JButton("/");
//		
//		
		double a1,b1;
		char sign;
		
//		buttons[1][1]=new JBottons(names[row][col]);
		class result implements ActionListener{//等于号的事件
		
			@Override
			public void actionPerformed(ActionEvent a) {
				a1=Double.parseDouble(textField.getText());
				String pre=a.getActionCommand();
				switch(pre){
					case "+":{
						sign='+';
						textField.setText(null);
					}break;
					case "-":{
						sign='-';
						textField.setText(null);
					}break;
					case "*":{
						sign='*';
						textField.setText(null);
					}break;
					case "/":{
						sign='/';
						textField.setText(null);
					}break;
					case "=":{
						b1=Double.parseDouble(textField.getText());
						textField.setText(null);
						switch(sign){//..........................
						case'+':{
							double result=a1+b1;
							textField.setText(String.valueOf(result));
						}break;
						case'-':{
							double result=a1-b1;
							textField.setText(String.valueOf(result));
						}break;
						case'*':{
							double result=a1*b1;
							textField.setText(String.valueOf(result));
						}break;
						case'/':{
							double result=a1/b1;
							textField.setText(String.valueOf(result));}
						break;
							}
						}break;
					}
					
				}
	
				//}//for.....
				
			//}
		}
	int p=0;
		class formula implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent arg0) {
			// TODO Auto-generated method stub
			String e=arg0.getActionCommand();		
			textField.setText(textField.getText()+e);
			
		}
		
	}
				

}     
   

