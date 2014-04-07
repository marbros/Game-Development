package firework;

import java.awt.Dimension;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.awt.RenderingHints;

import javax.swing.JPanel;

import firework.handlers.GameStateManager;
import firework.handlers.Mouse;
import firework.handlers.Keys;

/**
 *
 * @author usuario
 */
public class GamePanel extends JPanel implements MouseListener, MouseMotionListener {
	// dimensions
	public static final int WIDTH = 640;
	public static final int HEIGHT = 480;
	
	// game thread
	private Thread thread;
	private boolean running;
	private int FPS = 60;
	private long targetTime = 1000 / FPS;
	
	// image
	private BufferedImage image;
	private Graphics2D g;
	
	// game state manager
	private GameStateManager gsm;
	
	// other
	private boolean screenshot;
	
	public GamePanel() {
            setPreferredSize(new Dimension(WIDTH, HEIGHT));
            setFocusable(true);
            requestFocus();
	}    
        
	public void keyPressed(KeyEvent key) {
		if(key.isControlDown()) {
			if(key.getKeyCode() == KeyEvent.VK_S) {
				screenshot = true;
				return;
			}
		}
		Keys.keySet(key.getKeyCode(), true);
	}
	public void keyReleased(KeyEvent key) {
		Keys.keySet(key.getKeyCode(), false);
	}
	
	public void mousePressed(MouseEvent me) {
		Mouse.setAction(Mouse.PRESSED);
	}
	
	public void mouseReleased(MouseEvent me) {
		Mouse.setAction(Mouse.RELEASED);
	}
	
	public void mouseMoved(MouseEvent me) {
		Mouse.setPosition(me.getX(), me.getY());
	}
	
	public void mouseDragged(MouseEvent me) {
		Mouse.setAction(Mouse.PRESSED);
		Mouse.setPosition(me.getX(), me.getY());
	}
	public void mouseEntered(MouseEvent me) {}
	public void mouseExited(MouseEvent me) {}
	public void mouseClicked(MouseEvent me) {}
	public void keyTyped(KeyEvent key) {}        
}
