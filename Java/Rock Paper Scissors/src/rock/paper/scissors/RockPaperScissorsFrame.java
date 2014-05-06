/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package rock.paper.scissors;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.Random;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author zolphinus
 */
public class RockPaperScissorsFrame extends JFrame{
    
    JButton rock, paper, scissors;
    JPanel panel;
    JLabel message;
    ActionListener listener;
    Random rng = new Random();
    public int myHand, opponentHand;
    
    public static final int FRAME_WIDTH = 300;
    public static final int FRAME_HEIGHT = 300;
    
    public RockPaperScissorsFrame(){
        createComponents();
        setSize(FRAME_WIDTH, FRAME_HEIGHT);   
    }
    
    private void createComponents(){
        listener = new ClickListener();
        rock = new JButton("Rock");
        paper = new JButton("Paper");
        scissors = new JButton("Scissors");
        message = new JLabel("Let's Roshambo!!");
        panel = new JPanel();
        
        rock.addActionListener(listener);
        paper.addActionListener(listener);
        scissors.addActionListener(listener);
        
        panel.add(rock);
        panel.add(paper);
        panel.add(scissors);
        panel.add(message);
        
        add(panel);
        
        
        
    }
    
    public class ClickListener implements ActionListener{
    
        /**
         *Button Clicks will represent hand symbols
         * @param event
         */
        @Override
    public void actionPerformed(ActionEvent event){
        opponentHand = rng.nextInt(2);
        
        if(event.getSource() == rock){
            myHand = 0;
        }
        
        if(event.getSource() == paper){
            myHand = 1;
        }
        
        if(event.getSource() == scissors){
            myHand = 2;
        }
        
        if(myHand == 0){
            if(opponentHand == 0){
                message.setText("Rock vs. Rock results in a draw.");
            }
            
            if(opponentHand == 1){
                message.setText("Rock vs. Paper results in a loss...");
            }
            
            if(opponentHand == 2){
                message.setText("Rock vs. Scissors results in a win!");
            }
        }
        
        if(myHand == 1){
            if(opponentHand == 0){
                message.setText("Paper vs. Rock results in a win!");
            }
            
            if(opponentHand == 1){
                message.setText("Paper vs. Paper results in a draw.");
            }
            
            if(opponentHand == 2){
                message.setText("Paper vs. Scissors results in a loss...");
            }
        }
        
        if(myHand == 2){
            if(opponentHand == 0){
                message.setText("Scissors vs. Rock results in a loss...");
            }
            
            if(opponentHand == 1){
                message.setText("Scissors vs. Paper results in a win!!");
            }
            
            if(opponentHand == 2){
                message.setText("Scissors vs. Scissors results in a draw.");
            }
        }
    }
    
}
}
