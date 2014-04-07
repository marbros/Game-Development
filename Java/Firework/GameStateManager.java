package firework.handlers;

import firework.GamePanel;
import firework.gamestates.GameState;

/**
 *
 * @author usuario
 */
public class GameStateManager {
    
    private GameState gameState;
    private int currentState;
    
    public static final int INTRO_STATE = -1;
    public static final int MENU_STATE = 0;
    public static final int LEVEL_INFO_STATE = 1;
    public static final int PLAYING_STATE = 2;
    public static final int LEVEL_SELECT_STATE = 3;    
    
    public GameStateManager() {
        currentState = INTRO_STATE;
        loadState(currentState);	
    }
    
    private void loadState(int state) {
        if(state == MENU_STATE)
            gameState = new MenuState(this);
	}
	
	public void setState(int state) {
		currentState = state;
		loadState(currentState);
	}    
    
    public void update() {
        if(gameState != null) gameState.update();
    }
	
    public void draw(java.awt.Graphics2D g) {
        if(gameState != null) gameState.draw(g);
        else {
            g.setColor(java.awt.Color.BLACK);
            g.fillRect(0, 0, GamePanel.WIDTH, GamePanel.HEIGHT);
        }
    }    
}
