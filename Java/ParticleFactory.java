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
	
	public static void createExplosion(double x, double y, Color c) {
		for(int i = 0; i < 10; i++) {
			double dx = Math.random() * 4 - 2;
			double dy = Math.random() * 4 - 2;
			particles.add(new Particle(x, y, dx, dy, c));
		}
		checkLimit();
	}
	
	public static void checkLimit() {
		int extra = particles.size() - MAX_PARTICLES;
		if(extra <= 0) return;
		for(int i = 0; i < extra; i++) {
			particles.remove(0);
		}
	}
	
}
