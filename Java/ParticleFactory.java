import java.awt.Color;
import java.util.ArrayList;

public class ParticleFactory {
	
	public static ArrayList<Particles> particles;
	
	public static final int MAX_PARTICLES = 64;
	
	public static void init(ArrayList<Particle> p) {
		particles = p;
	}
	
	public static void createExplosion(double x, double y) {
		createExplosion(x, y, Color.WHITE);
	}
	
}
