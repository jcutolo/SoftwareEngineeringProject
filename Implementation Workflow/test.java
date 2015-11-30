import java.util.Scanner;

public class test {
	public static void main(String[]args){
		
		//Create testing objects
		Datacenter d = new Datacenter();
		Manager m1 = new Manager("Fred",000000);
		Manager m2 = new Manager("Apathy",000001);
		Provider p1 = new Provider("Doctor one",000000,"address1","city1","state1",28306);
		Provider p2 = new Provider("Doctor two",000001,"address2","city2","state2",27514);
		Member n1 = new Member("Member one",000000,"addresses1","cities1","states1",28306,0);
		Member n2 = new Member("Member two",000001,"addresses2","cities2","states2",27514,0);
		d.addManager(m1);
		d.addManager(m2);
		d.addProvider(p1);
		d.addProvider(p2);
		d.addMember(n1);
		d.addMember(n2);
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Testing simulation for Chocoholics Anonymous program.");
		System.out.print("Please choose an option to test:\n"
				+ "1. Provider\n"
				+ "2. Manager\n"
				+ "3. Operator\n"
				+ "4. Exit\n"
				+ "> ");
		int input = keyboard.nextInt();
		while(input!=4){
			switch(input){
			case 1:
				System.out.println("Starting provider simulation");
				ProviderTerminal p = new ProviderTerminal(d);
				break;
			case 2:
				System.out.println("Starting manager simulation");
				ManagerTerminal m = new ManagerTerminal(d);
				break;
			case 3:
				System.out.println("Starting operator simulation");
				Operator o = new Operator(d);
				break;
			default:
				System.out.println("Invalid input. Please enter a valid choice.");
			}
			System.out.print("Returned to testing simulation...\n"
					+ "> ");
			input = keyboard.nextInt();
		}
		System.out.println("Ending test simulation...");
	}
}
