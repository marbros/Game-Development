 class ParticleManager {
    private Node guiNode;
    private Spatial standardParticle, glowParticle;
 
    private Node particleNode;
    private Random rand;
 
    public ParticleManager(Node guiNode, Spatial standardParticle, Spatial glowParticle) {
        this.guiNode = guiNode;
        this.standardParticle = standardParticle;
        this.glowParticle = glowParticle;
 
        particleNode = new Node("particles");
        guiNode.attachChild(particleNode);
 
        rand = new Random();
    }

    public void Gravity(Vector3f gravity, float distance) {
        Vector3f additionalVelocity = gravity.mult(1000f / (distance*distance + 10000f));
        velocity.addLocal(additionalVelocity);
        
        if (distance < 400) {
            additionalVelocity = new Vector3f(gravity.y, -gravity.x, 0).mult(3f / (distance + 100));
            velocity.addLocal(additionalVelocity);
        }
    }

    public void sprayParticle(Vector3f position, Vector3f sprayVel) {
        Spatial particle = standardParticle.clone();
        particle.setLocalTranslation(position);
        ColorRGBA color = new ColorRGBA(0.8f,0.4f,0.8f,1f);
        particle.addControl(new ParticleControl(sprayVel, 3500, color, screenWidth, screenHeight));
        particle.setUserData("affectedByGravity", true);
        ((Node) guiNode.getChild("particles")).attachChild(particle);
    }

    public ColorRGBA hsvToColor(float h, float s, float v) {
        if (h == 0 && s == 0) {
            return new ColorRGBA(v, v, v,1);
        }
     
        float c = s * v;
        float x = c * (1 - Math.abs(h % 2 - 1));
        float m = v - c;
     
        if (h < 1) {return new ColorRGBA(c + m, x + m, m, 1);
        } else if (h < 2) {return new ColorRGBA(x + m, c + m, m, 1);
        } else if (h < 3) {return new ColorRGBA(m, c + m, x + m, 1);
        } else if (h < 4) {return new ColorRGBA(m, x + m, c + m, 1);
        } else if (h < 5) {return new ColorRGBA(x + m, m, c + m, 1);
        } else {return new ColorRGBA(c + m, m, x + m, 1);}
    }    
}