package paintArtifact;

import java.util.Scanner;
import java.io.File;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;


enum state {
	MENU,
	CALCULATION,
	HISTORY
}

public class Paint1 {
	
	static String FILENAME = "calcs.txt";
	static double squareFeetPerGallons = 350.0;
	static ArrayList<Calc> calcs = new ArrayList<Calc>();
	
	
	public static void readSaveFile() {
		File f = new File(FILENAME);
		if(f.isFile()) {
			
			try(BufferedReader R = new BufferedReader(new FileReader(FILENAME))) {
				String line;
				int index;
				
				while ((line = R.readLine()) != null) {
					index = line.indexOf(',');
					
					calcs.add(new Calc(Double.parseDouble(line.substring(0, index)), Double.parseDouble(line.substring(index + 1, line.length())), squareFeetPerGallons));
				}
				
				
			} catch (IOException e) {
				e.printStackTrace();
			}
			
		} else {
			try (BufferedWriter W = new BufferedWriter(new FileWriter(FILENAME))) {

			} catch (IOException e) {
				e.printStackTrace();
			}
		}
	}
	
	public static void saveFile() {
		try (BufferedWriter W = new BufferedWriter(new FileWriter(FILENAME))){
			String writable;
			
			for (int i = 0; i < calcs.size(); i++) {
				writable = calcs.get(i).x + "," + calcs.get(i).y;
				W.write(writable);
				W.newLine();
			}

			
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void println(String str) {
		System.out.println(str);
	}
	
	public static double getDouble(Scanner scnr, String text) {

		boolean condition = true;
		
		double enteredDouble = 0.0;
		
		do {
        	
        	try {
            	println(text);
            	enteredDouble = scnr.nextDouble();
            	
            	if(enteredDouble <= 0) {
            		throw new Exception("Zero or negative");
            	}
            	
            	
            	return enteredDouble;
        	}
        	catch(Exception e) {
        		
        		if (e.getMessage() == null) {
        		scnr.next();
        		}
        		println("Input not Valid! \nPlease enter a valid number!\n" + e.getMessage());
        	}
        	
        } while(condition);
		
		return enteredDouble;
	}
	
	public static int getInt(Scanner scnr) {
		boolean condition = true;
		
		int enteredInt = 0;
		
		do {
        	
        	try {
            	enteredInt = scnr.nextInt();
            	
            	if(enteredInt <= 0) {
            		throw new Exception("Zero or negative");
            	}
            	
            	
            	return enteredInt;
        	}
        	catch(Exception e) {
        		
        		if (e.getMessage() == null) {
        		scnr.next();
        		}
        		println("Input not Valid! \nPlease enter a valid number!\n" + e.getMessage());
        	}
        	
        } while(condition);
		
		return enteredInt;
	}

	public static void screenDivider() {
		println("********************");
	}
	
	public static void menu() {
		screenDivider();
		println("1) Enter Calculation");
		println("2) Check History");
		println("3) Exit");
		screenDivider();
		
	}
	
	public static void calculation(Scanner scnr) {
		double wallHeight = 0.0;
        double wallWidth = 0.0;
        double wallArea = 0.0;
        double gallonsPaintNeeded = 0.0;
		
		// Implement a do-while loop to ensure input is valid
        // Prompt user to input wall's height
        wallHeight = getDouble(scnr, "Enter wall height: ");
        
        screenDivider();

        // Implement a do-while loop to ensure input is valid
        // Prompt user to input wall's width
        wallWidth = getDouble(scnr, "Enter wall width: ");
        
        screenDivider();

        // Calculate and output wall area
        wallArea = wallHeight * wallWidth;
        System.out.println("Wall area: " + wallArea + " square feet");

        // Calculate and output the amount of paint (in gallons) needed to paint the wall
        gallonsPaintNeeded = wallArea/squareFeetPerGallons;
        System.out.println("Paint needed: " + gallonsPaintNeeded + " gallons");
        
        
        
        calcs.add(new Calc(wallHeight, wallWidth, squareFeetPerGallons));
        
        
        
	}
	
	public static void printHistory() {
		
		screenDivider();
		for(int i = 0; i < calcs.size(); i++) {
			calcs.get(i).print();
			screenDivider();
		}
		
		
	}
	
    public static void main(String[] args) {
        Scanner scnr = new Scanner(System.in);
        
        readSaveFile();
        
        
        
        
        
        
        boolean condition = true;
        int selection = 0;
        
        state st = state.MENU;
        
        
        
        
        do {
        	
        	
        	
        	switch(st) {
        	case MENU:
        		menu();
        		break;
        	case CALCULATION:
        		calculation(scnr);
        		st = state.MENU;
        		continue;
        	case HISTORY:
        		printHistory(); 
        		st = state.MENU;
        		continue;
        	default:
        		println("DEFAULT CASE");
        	}
        	
        	
        	selection = getInt(scnr);
        	
        	switch(selection) {
        	case 1:
        		st = state.CALCULATION;
        		break;
        	case 2:
        		st = state.HISTORY;
        		break;
        	case 3:
        		condition = false;
        		break;
        	default:
        		println("DEFAULT CASE");
        	}
        	
        	
        	
        	
        	
        	
        	
        }while (condition);
        
        
        saveFile();
        
        
        
        
        

    }
}
