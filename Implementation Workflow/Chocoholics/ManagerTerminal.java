import java.util.Scanner;

public class ManagerTerminal {
	Manager m;
	Scanner keyboard = new Scanner(System.in);
	public ManagerTerminal(Datacenter d){
		boolean active = logIn(d);
		while(!active){
			active = logIn(d);
		}
		while(active){
			System.out.print("Please choose an action(#) to perform:\n"
					+ "1. Print Member Report\n"
					+ "2. Print Provider Report\n"
					+ "3. Print Manager Report\n"
					+ "4. Print EFT Report\n"
					+ "5. Log Out\n"
					+ "> ");
			int input = keyboard.nextInt();
			while(input!=5){
				switch(input){
				case 1:
					System.out.println("Printing member report");
					getMemberReport(d);
					break;
				case 2:
					System.out.println("Printing provider report");
					getProviderReport(d);
					break;
				case 3:
					System.out.println("Printing manager report");
					getManagerReport(d);
					break;
				case 4:
					System.out.println("Printing EFT report");
					getEFTReport(d);
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
	public boolean logIn(Datacenter d){
		Scanner keyboard = new Scanner(System.in);
		System.out.print("Please swipe card or enter manager number: ");
		int input = keyboard.nextInt();
		this.m=d.getManager(input);
		if (this.m==null){
			System.out.println("Improper value for manager number.");
			return false;
		}
		else{
			this.m=d.getManager(input);
			System.out.println("Successfully logged in.");
			System.out.println(this.m.name);
			return true;
		}
	}
	public boolean logOut(){
		System.out.println("Logging off...");
		return false;
	}
	public void getMemberReport(Datacenter d){
		System.out.print("Enter member number: ");
		int memberNumber = keyboard.nextInt();
		d.printMemberReport(memberNumber);
	};
	public void getManagerReport(Datacenter d){
		d.printManagerReport();
	};
	public void getProviderReport(Datacenter d){
		System.out.print("Enter provider number: ");
		int providerNumber = keyboard.nextInt();
		d.printProviderReport(providerNumber);
	};
	public void getEFTReport(Datacenter d){
		d.printEFTReport();
	};
}
