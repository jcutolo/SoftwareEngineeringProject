package csc470;

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
                                        + "3. Print Manager Report\n"
                                        + "4. Print EFT Report\n"
					+ "5. Log Out\n"
					+ "> ");
			int input = keyboard.nextInt();
			while(input!=3){
				switch(input){
				case 1:
					System.out.println("Printing Member Report");
                                        //printMemberReport();
					break;
				case 2:
					System.out.println("Printing Provider Report");
                                        //printProviderReport();
					break;
                                case 3:
                                        System.out.println("Printing Manager Report");
                                        //printManagerReport();
                                        break;
                                case 4:
                                        System.out.println("Printing EFT report");
                                        //printEFTData();
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
	public static boolean logIn(){
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
	public static boolean logOut(){
		System.out.println("Logging off...");
		return false;
	}
	
	public void printMemberReport(Member m){
		System.out.println("\t\t\tChocoholics Anonymous\n");
                System.out.println("\t\t\tServices Received\n");
                System.out.println("Week Ending: ");
                System.out.println("Member Number: ");
                System.out.println("Member Name: ");
                System.out.println("Member Address: \n");
                System.out.println("Service Date    Service\t\tProvider");
                System.out.println("------------    -------\t\t--------");
                //Begin printing out the services now
	}
	public void printProviderReport(Provider p){
                int numConsultations = 0;
                double totalFee = 0.0;
                System.out.println("\t\tChocoholics Anonymous\n");
                System.out.println("\t\tClaim Submissions\n");
                System.out.println("Week Ending: ");
                System.out.println("Provider Number: ");
                System.out.println("Provider Name: ");
                System.out.println("Address: \n");
                System.out.println("Submission Date-Time  Service Date  Code  Fee  Member No.  Member Name");
                System.out.println("--------------------  ------------  ----  ---  ----------  -----------");
                //Begin printing the claims the provider had for the week
                System.out.println("Number of Consultations: " + numConsultations);
                System.out.format("Total Fee:%.2f%n", totalFee);
	}
        
        public void printManagerReport() {
                System.out.println("\t\tChocoholics Anonymous\n");
                System.out.println("\t\tAccounts Payable\n");
                System.out.println("Week Ending: \n");
                System.out.println("Provider Number   Consultations\t\tFee Provider Name");
                System.out.println("---------------   -------------\t\t--- -------------");
                //Begin printing the accounts payable report
                System.out.println("---------------   -------------\t\t--- -------------");
                System.out.println("Totals:                       ");
        }
        
        public void printEFTReport() {
                System.out.println("\t\t\tChocoholics Anonymous\n");
                //Print out the providers number of consultations with total fee and provider name
        }
}
