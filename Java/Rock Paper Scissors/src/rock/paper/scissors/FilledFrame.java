/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package rock.paper.scissors;

import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

/**
 *
 * @author collinsj04
 */
public class FilledFrame extends JFrame {
    
    private JButton button;
    private JLabel label;
    private ActionListener listener;
    
    public static final int FRAME_WIDTH = 300;
    public static final int FRAME_HEIGHT = 100;
    
    public FilledFrame(){
        createComponents();
        
        setSize(FRAME_WIDTH, FRAME_HEIGHT);
    }
    
    private void createComponents(){
        button = new JButton("CLICK MEEE");
        label = new JLabel("I'm a label!!");
        listener = new ClickListener();
        JPanel panel = new JPanel();
        
        button.addActionListener(listener);
        panel.add(button);
        panel.add(label);
        add(panel);
    }
    
}
