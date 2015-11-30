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
				+ "7. Add service\n"
				+ "8. Update service\n"
				+ "9. Remove service\n"
				+ "> ");
		int input = keyboard.nextInt();
		while(input!=10){
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
			case 7:
				System.out.println("Add service");
				addService(d);
				break;
			case 8:
				System.out.println("Update service");
				updateService(d);
				break;
			case 9:
				System.out.println("Remove service");
				removeService(d);
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
		String name;
		String streetAddress;
		String city;
		String state;
		int zip;
		int status;
		System.out.print("Enter member name: ");
		name = keyboard.next();
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
		Member m = new Member(name,memberNumber,streetAddress,city,state,zip,status);
		d.updateMember(m);
	}
	public void addProvider(Datacenter d){
		String name;
		int number;
		String streetAddress;
		String city;
		String state;
		int zip;
		System.out.print("Enter provider name: ");
		name = keyboard.next();
		System.out.print("Enter provider number: ");
		number = keyboard.nextInt();
		System.out.print("Enter provider street address: ");
		streetAddress = keyboard.next();
		System.out.print("Enter provider city: ");
		city = keyboard.next();
		System.out.print("Enter provider state: ");
		state = keyboard.next();
		System.out.print("Enter provider zip code: ");
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
		System.out.print("Enter provider number: ");
		int providerNumber = keyboard.nextInt();
		System.out.print("Enter provider name: ");
		String name = keyboard.next();
		System.out.print("Enter provider street address: ");
		String streetAddress = keyboard.next();
		System.out.print("Enter provider city: ");
		String city = keyboard.next();
		System.out.print("Enter provider state: ");
		String state = keyboard.next();
		System.out.print("Enter provider zip code: ");
		int zip = keyboard.nextInt();
		Provider p = new Provider(name,providerNumber,streetAddress,city,state,zip);
		d.updateProvider(p);
	}
	public void addService(Datacenter d){
		System.out.print("Enter service name: ");
		String serviceName = keyboard.next();
		System.out.print("Enter service code: ");
		int serviceCode = keyboard.nextInt();
		System.out.print("Enter service fee: ");
		double fee = keyboard.nextDouble();
		PDI p = new PDI(serviceCode,serviceName,fee);
		d.addPDI(p);
	}
	public void updateService(Datacenter d){
		System.out.print("Enter member number: ");
		int serviceNumber = keyboard.nextInt();
		System.out.print("Enter service name: ");
		String serviceName = keyboard.next();
		System.out.print("Enter service fee: ");
		double fee = keyboard.nextDouble();
		PDI p = new PDI(serviceNumber,serviceName,fee);
		d.updatePDI(p);
	}
	public void removeService(Datacenter d){
		System.out.print("Enter service code: ");
		int serviceCode = keyboard.nextInt();
		d.removePDI(serviceCode);
	}
}
