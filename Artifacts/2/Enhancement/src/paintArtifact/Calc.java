package paintArtifact;

public class Calc {
	public double x;
	public double y;
	public double area;
	public double squareFeetPerGallon;
	public double gallons;
	
	Calc(double xx, double yy, double sfpg) {
		x = xx;
		y = yy;
		area = (x * y);
		squareFeetPerGallon = sfpg;
		gallons = (area / squareFeetPerGallon);
	}
	
	
	
	
	
	void print() {
		System.out.println(x + " * " + y + " = " + area);
		System.out.println("Paint Needed = " + gallons);
	}
}
