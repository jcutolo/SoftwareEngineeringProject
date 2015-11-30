import java.util.Scanner;

public class ProviderTerminal {
	public ProviderTerminal(Datacenter d){
		Scanner keyboard = new Scanner(System.in);
		boolean active = logIn();
		while(!active){
			active = logIn();
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
					System.out.println("Submiting Claim");
					break;
				case 2:
					System.out.println("Retrieving provider directory");
					break;
				case 3:
					System.out.print("Validating member for service. Please enter member number: ");
					if (d.validateMember(keyboard.nextInt())){
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
}
