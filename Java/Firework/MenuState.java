/**
 * The main menu.
 */

package firework.gamestates;

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics2D;
import java.awt.image.BufferedImage;
import java.util.ArrayList;


public class MenuState extends GameState {
	
	// bg image
	private BufferedImage bg;
	
	// buttons
	private int currentChoice = 0;
	private GameButton[] options;
	
	// fonts and colors
	private Color titleColor;
	private Font titleFont;
	private Font font;
	private Font font2;
	
	// fading
	private int fadeInTimer;
	private int fadeInDelay;
	private int fadeOutTimer;
	private int fadeOutDelay;
	private int alpha;
	private int nextState;
	
	public MenuState(GameStateManager gsm) {
		super(gsm);
		init();
	}
	
	public void init() {
		
		// load bg image
		bg = ImageLoader.BG;
		
		// load fonts
		try {
			Font scFont = Font.createFont(
					Font.TRUETYPE_FONT,
					getClass().getResourceAsStream("/fonts/SECRCODE.TTF"));
			titleColor = Color.WHITE;
			titleFont = scFont.deriveFont(64f);
			font = scFont.deriveFont(26f);
			font2 = scFont.deriveFont(14f);
		}
		catch(Exception e) {
			e.printStackTrace();
		}
		
		// show mouse cursor
		Game.setCursor(Game.VISIBLE);
		
		// set up buttons
		options = new GameButton[2];
		options[0] = new GameButton(320, 300, 100, 50);
		options[0].setText("s t a r t", font);
		options[1] = new GameButton(320, 350, 100, 50);
		options[1].setText("q u i t", font);
		
		// fade timer
		fadeInTimer = 0;
		fadeInDelay = 60;
		fadeOutTimer = -1;
		fadeOutDelay = 60;
		
		// music
		if(!JukeBox.isPlaying("menumusic")) {
			JukeBox.loop("menumusic", 3000, JukeBox.getFrames("menumusic") - 3000);
		}
		JukeBox.stop("bgmusic1");
		
		
	}
	
	
	public void handleInput() {
		
		// see if button is clicked
		if(Mouse.isPressed()) {
			select();
		}
		
		// check if mouse is hovering over buttons
		boolean hit = false;
		for(int i = 0; i < options.length; i++) {
			if(options[i].isHovering(Mouse.x, Mouse.y)) {
				currentChoice = i;
				hit = true;
				break;
			}
		}
		if(!hit) currentChoice = -1;
		
	}
	
}
