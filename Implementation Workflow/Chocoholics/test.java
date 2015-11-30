import java.util.Scanner;

public class test {
	public static void main(String[]args){
		
		//Create testing objects
		Datacenter d = new Datacenter();
		d.addService(883948,"Aerobics exercises",10.20)
		d.addService(11,"Aversion Therapy",30.00)
		d.addService(555,"Chocolates in excess",100.00)
		d.addService(598470,"Dietition session",20.50)
		d.addService(22,"Yoga",$12.50)
		Manager m1 = new Manager("Fred",000000);
		Manager m2 = new Manager("Apathy",000001);
		Provider p1 = new Provider("Alexander",000000,"123 Owen Street","Fayetteville","NC",28303);
		Provider p2 = new Provider("Berry",000001,"xxxxxx","yyyyy","SC",23456);
		Provider p3 = new Provider("Carrel",000002,"1200 Murchison","Fayetteville","NC",28301);
		Member n1 = new Member("Adam Blerk",000000,"2932 Circle Drive","Port Shepstone","NY",12345,0); // zero is payment status
		Member n2 = new Member("Brian Macbeth",000001,"100 Macbeth's Castle","Inverness","SL",52561,0);
		Member n3 = new Member("Cathy Montague",000002,"101 Montague Place","Verona","IT",10002,0);
		Member n4 = new Member("Debbie Capulet",000002,"212 Capulet Drive","Verona","IL",20101,0);
		d.addManager(m1);
		d.addManager(m2);
		d.addProvider(p1);
		d.addProvider(p2);
		d.addProvider(p3);
		d.addMember(n1);
		d.addMember(n2);
		d.addMember(n3);
		d.addMember(n4);
		
		
		
		
		ProviderService(int month,int day,int year,int m,int d,int y,String memberName,int memberNumber, double fee){
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
