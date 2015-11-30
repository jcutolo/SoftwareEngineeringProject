import java.util.Scanner;

public class ManagerTerminal {
	public ManagerTerminal(Datacenter d){
		Scanner keyboard = new Scanner(System.in);
		boolean active = logIn();
		while(!active){
			active = logIn();
		}
		while(active){
			System.out.print("Please choose an action(#) to perform:\n"
					+ "1. Print Member Report\n"
					+ "2. Print Provider Report\n"
					+ "3. Log Out\n"
					+ "> ");
			int input = keyboard.nextInt();
			while(input!=3){
				switch(input){
				case 1:
					System.out.println("Printing member report");
					break;
				case 2:
					System.out.println("Printing provider report");
					break;
				default:
					System.out.println("Invalid input. Please enter a valid choice.");
				}
				System.out.print("> ");
				input = keyboard.nextInt();
			}
			active = logOut();
		}
		
	}
	public boolean logIn(){
		Scanner keyboard = new Scanner(System.in);
		System.out.print("Please swipe card or enter provider number: ");
		int input = keyboard.nextInt();
		if (((input/1000000000)>=1)||(input<0)){
			System.out.println("Invalid range for provider number.");
			return false;
		}
		else{
			System.out.println("Successfully logged in.");
			return true;
		}
	}
	public boolean logOut(){
		System.out.println("Logging off...");
		return false;
	}
	
	public void printMemberReport(Member m){
		
	}
	public void printProviderReport(Provider p){
		
	}
}
