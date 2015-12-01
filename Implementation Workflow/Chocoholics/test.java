import java.util.Scanner;

public class test {
	public static void main(String[]args){
		
		//Create testing objects
		Datacenter d = new Datacenter();
		
		PDI q1 = new PDI(883948,"Aerobics exercises",10.20);
		PDI q2 = new PDI(11,"Aversion Therapy",30.00);
		PDI q3 = new PDI(555,"Chocolates in excess",100.00);
		PDI q4 = new PDI(598470,"Dietition session",20.50);
		//PDI q5 = new PDI(22,"Yoga",$12.50);
		d.addPDI(q1);
		d.addPDI(q2);
		d.addPDI(q3);
		d.addPDI(q4);
		//d.addPDI(q5);
		Manager m1 = new Manager("Fred",000000);
		Manager m2 = new Manager("Apathy",000010);
		Provider p1 = new Provider("Alexander",000002,"123 Owen Street","Fayetteville","NC",28303);
		Provider p2 = new Provider("Berry",000004,"xxxxxx","yyyyy","SC",23456);
		Provider p3 = new Provider("Carrel",000006,"1200 Murchison","Fayetteville","NC",28301);
		Member n1 = new Member("Adam Blerk",000001,"2932 Circle Drive","Port Shepstone","NY",12345,0); // zero is payment status
		Member n2 = new Member("Brian Macbeth",000003,"100 Macbeth's Castle","Inverness","SL",52561,0);
		Member n3 = new Member("Cathy Montague",000005,"101 Montague Place","Verona","IT",10002,0);
		Member n4 = new Member("Debbie Capulet",000007,"212 Capulet Drive","Verona","IL",20101,0);
		d.addManager(m1);
		d.addManager(m2);
		d.addProvider(p1);
		d.addProvider(p2);
		d.addProvider(p3);
		d.addMember(n1);
		d.addMember(n2);
		d.addMember(n3);
		d.addMember(n4);
		
		d.addClaim(new Claim(11,10,2015,2,1,11,null));
		d.addClaim(new Claim(11,10,2015,2,1,11,null));
		d.addClaim(new Claim(11,10,2015,2,1,883948,null));
		d.addClaim(new Claim(11,3,2015,2,5,11,"Hopeless case"));
		d.addClaim(new Claim(11,15,2015,2,3,555,null));
		d.addClaim(new Claim(11,3,2015,4,1,598470,""));
		//d.addClaim(new Claim(11,03,2015,4,7,883948));
		//d.addClaim(new Claim(1234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890));
		//d.addClaim(new Claim(11,9,2015,6,5,22,"Control your mind!"));
		d.addClaim(new Claim(11,8,2015,6,7,555,"Death by chocolate"));
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
		d.runAccountingProceedure();
		System.out.println("Ending test simulation...");
	}
}
