import java.sql.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Scanner;

public class ProviderTerminal {
	Provider p=null;
	public ProviderTerminal(Datacenter d){
		Scanner keyboard = new Scanner(System.in);
		boolean active = logIn(d);
		while(!active){
			active = logIn(d);
		}
		while(active){
			System.out.print("Please choose an action(#) to perform:\n"
					+ "1. Submit Claim\n"
					+ "2. Retrieve Provider Directory\n"
					+ "3. Validate Member for Service\n"
					+ "4. Log Out\n"
					+ "> ");
			int input = keyboard.nextInt();
			while(input!=4){
				switch(input){
				case 1:
					System.out.println("Submiting Claim...");
					System.out.print("Enter member number: ");
					int memberNumber = keyboard.nextInt();
					System.out.print("Enter month: ");
					int month = keyboard.nextInt();
					System.out.print("Enter day: ");
					int day = keyboard.nextInt();
					System.out.print("Enter year: ");
					int year = keyboard.nextInt();
					System.out.print("Enter service code: ");
					int serviceCode = keyboard.nextInt();
					keyboard.nextLine();
					System.out.print("Enter comment: ");
					String comment = keyboard.nextLine();
					Claim c = new Claim(month,day,year,p.number,memberNumber,serviceCode,comment);
					d.addClaim(c);
					break;
				case 2:
					System.out.println("Retrieving provider directory");
					getProviderDirectory(d);
					break;
				case 3:
					System.out.print("Validating member for service. Please enter member number: ");
					int number = keyboard.nextInt();
					if (d.validateMember(number)){
						System.out.println(d.getMember(number).name);
						System.out.println("Provided service.");
					}
					else{
						System.out.println("Member does not exist.");
					}
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
		System.out.print("Please swipe card or enter provider number: ");
		int input = keyboard.nextInt();
		this.p=d.getProvider(input);
		if (this.p==null){
			System.out.println("Improper value for provider number.");
			return false;
		}
		else{
			this.p=d.getProvider(input);
			System.out.println("Successfully logged in.");
			System.out.println(this.p.name);
			return true;
		}
	}
	public boolean logOut(){
		System.out.println("Logging off...");
		return false;
	}
	public void getProviderDirectory(Datacenter d){
		d.printProviderDirectory();
	}
}
