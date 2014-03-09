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
}