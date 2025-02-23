import java.util.Scanner;

public class Paint1 {

    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        double wallHeight = 0.0;
        double wallWidth = 0.0;
        double wallArea = 0.0;
        double gallonsPaintNeeded = 0.0;
        boolean condition = true;
        
        final double squareFeetPerGallons = 350.0;
        
        // Implement a do-while loop to ensure input is valid
        // Prompt user to input wall's height
        do {
        	
        	try {
            	System.out.println("Enter wall height (feet): ");
            	wallHeight = scnr.nextDouble();
            	
            	if(wallHeight <= 0) {
            		throw new Exception("Zero or negative");
            	}
            	
            	
            	condition = false;
        	}
        	catch(Exception e) {
        		
        		if (e.getMessage() == null) {
        		scnr.next();
        		}
        		System.out.println("Input not Valid! \nPlease enter a valid number!" + e.getMessage());
        	}
        	
        } while(condition);

        // Implement a do-while loop to ensure input is valid
        // Prompt user to input wall's width
        condition = true;
        do {
        	
        	try {
                System.out.println("Enter wall width (feet): ");
                wallWidth = scnr.nextDouble();
                
                if(wallWidth <= 0) {
                	throw new Exception("Zero or negative");
                }
                
            	condition = false;
        	}
        	catch(Exception e) {
        		
        		if (e.getMessage() == null) {
        		scnr.next();
        		}
        		System.out.println("Input not valid! \nPlease enter a valid number!");
        	}
        	
        } while(condition);

        // Calculate and output wall area
        wallArea = wallHeight * wallWidth;
        System.out.println("Wall area: " + wallArea + " square feet");

        // Calculate and output the amount of paint (in gallons) needed to paint the wall
        gallonsPaintNeeded = wallArea/squareFeetPerGallons;
        System.out.println("Paint needed: " + gallonsPaintNeeded + " gallons");

    }
}
