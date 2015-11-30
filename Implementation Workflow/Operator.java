import java.util.Scanner;

public class Operator {
	Scanner keyboard = new Scanner(System.in);
	public Operator(Datacenter d){
		System.out.print("Please choose an action(#) to perform:\n"
				+ "1. Add member\n"
				+ "2. Update member\n"
				+ "3. Remove member\n"
				+ "4. Add provider\n"
				+ "5. Update provider\n"
				+ "6. Remove provider\n"
				+ "> ");
		int input = keyboard.nextInt();
		while(input!=7){
			switch(input){
			case 1:
				System.out.println("Add member");
				addMember(d);
				break;
			case 2:
				System.out.println("Update member");
				updateMember(d);
				break;
			case 3:
				System.out.println("Remove member");
				removeMember(d);
				break;
			case 4:
				System.out.println("Add provider");
				addProvider(d);
				break;
			case 5:
				System.out.println("Update provider");
				updateProvider(d);
				break;
			case 6:
				System.out.println("Remove provider");
				removeProvider(d);
				break;
			default:
				System.out.println("Invalid input. Please enter a valid choice.");
			}
			System.out.print("> ");
			input = keyboard.nextInt();
		}
	}
	public void addMember(Datacenter d){
		String name;
		int number;
		String streetAddress;
		String city;
		String state;
		int zip;
		int status;
		System.out.print("Enter member name: ");
		name = keyboard.next();
		System.out.print("Enter member number: ");
		number = keyboard.nextInt();
		System.out.print("Enter member street address: ");
		streetAddress = keyboard.next();
		System.out.print("Enter member city: ");
		city = keyboard.next();
		System.out.print("Enter member state: ");
		state = keyboard.next();
		System.out.print("Enter member zip code: ");
		zip = keyboard.nextInt();
		System.out.print("Enter member status: ");
		status = keyboard.nextInt();
		Member m = new Member(name,number,streetAddress,city,state,zip,status);
		d.addMember(m);
		
	}
	public void removeMember(Datacenter d){
		System.out.print("Enter member number: ");
		int memberNumber = keyboard.nextInt();
		d.removeMember(memberNumber);
		
	}
	public void updateMember(Datacenter d){
		System.out.print("Enter member number: ");
		int memberNumber = keyboard.nextInt();
		d.updateMember(memberNumber);
	}
	public void addProvider(Datacenter d){
		String name;
		int number;
		String streetAddress;
		String city;
		String state;
		int zip;
		System.out.print("Enter member name: ");
		name = keyboard.next();
		System.out.print("Enter member number: ");
		number = keyboard.nextInt();
		System.out.print("Enter member street address: ");
		streetAddress = keyboard.next();
		System.out.print("Enter member city: ");
		city = keyboard.next();
		System.out.print("Enter member state: ");
		state = keyboard.next();
		System.out.print("Enter member zip code: ");
		zip = keyboard.nextInt();
		Provider p = new Provider(name,number,streetAddress,city,state,zip);
		d.addProvider(p);
	}
	public void removeProvider(Datacenter d){
		System.out.print("Enter member number: ");
		int providerNumber = keyboard.nextInt();
		d.removeProvider(providerNumber);
	}
	public void updateProvider(Datacenter d){
		System.out.print("Enter member number: ");
		int providerNumber = keyboard.nextInt();
		d.updateProvider(providerNumber);
	}

}
