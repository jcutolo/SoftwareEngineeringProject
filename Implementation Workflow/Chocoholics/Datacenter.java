import java.util.HashMap;
import java.util.Map;
import java.util.Vector;

//Do error checking in here...

public class Datacenter {
	public HashMap<Integer,Provider> listOfProviders = new HashMap<Integer,Provider>();
	public HashMap<Integer,Manager> listOfManagers = new HashMap<Integer,Manager>();
	public HashMap<Integer,Member> listOfMembers = new HashMap<Integer,Member>();
	public HashMap<Integer,PDI> providerDirectory = new HashMap<Integer,PDI>();
	public Vector<Claim> claim = new Vector<Claim>();
	//Add new physical service to total list
	public void addClaim(Claim c){
		claim.addElement(c);
		ProviderService p = new ProviderService(c.month,c.day,c.year,c.date,getMember(c.memberNumber).name,c.memberNumber,c.serviceCode,providerDirectory.get(c.serviceCode).fee);
		MemberService m = new MemberService(c.month,c.day,c.year,getProvider(c.providerNumber).name,providerDirectory.get(c.serviceCode).serviceName);
		getMember(c.memberNumber).services.addElement(m);
		getProvider(c.providerNumber).services.addElement(p);
	}
	public void addPDI(PDI p){
		providerDirectory.put(p.serviceCode, p);
	}
	public void removePDI(int serviceCode){
		listOfProviders.remove(serviceCode);
	}
	public void updatePDI(PDI p){
		removePDI(p.serviceCode);
		addPDI(p);
	}
	public void addManager(Manager m){
		listOfManagers.put(m.number, m);
	}
	public void addProvider(Provider p){
		listOfProviders.put(p.number, p);
	}
	public void removeProvider(int providerNumber){
		listOfProviders.remove(providerNumber);
	}
	public void updateProvider(Provider p){
		listOfProviders.get(p.number).name = p.name;
		listOfProviders.get(p.number).streetAddress = p.streetAddress;
		listOfProviders.get(p.number).city = p.city;
		listOfProviders.get(p.number).state = p.state;
		listOfProviders.get(p.number).zip = p.zip;
	}
	public void addMember(Member m){
		listOfMembers.put(m.number, m);
	}
	public void removeMember(int memberNumber){
		listOfProviders.remove(memberNumber);
	}
	public void updateMember(Member m){
		listOfMembers.get(m.number).name = m.name;
		listOfMembers.get(m.number).streetAddress = m.streetAddress;
		listOfMembers.get(m.number).city = m.city;
		listOfMembers.get(m.number).state = m.state;
		listOfMembers.get(m.number).zip = m.zip;
		listOfMembers.get(m.number).status = m.status;
	}
	public boolean validateMember(int memberNumber){
		Member m = listOfMembers.get(memberNumber);
		if(m==null){
			return false;
		}
		else{
			return true;
		}
	}
	public Provider getProvider(int number){
		return listOfProviders.get(number);
	}
	public Member getMember(int number){
		return listOfMembers.get(number);
	}
	public Manager getManager(int number){
		return listOfManagers.get(number);
	}
	public boolean validateManager(int managerNumber){
		Manager m = listOfManagers.get(managerNumber);
		if(m==null){
			return false;
		}
		else{
			return true;
		}
	}
	public boolean validateProvider(int providerNumber){
		Provider p = listOfProviders.get(providerNumber);
		if(p==null){
			return false;
		}
		else{
			return true;
		}
	}
	public void printMemberReport(int memberNumber){
		System.out.println("\t\t\tChocoholics Anonymous\n");
                System.out.println("\t\t\tServices Received\n");
                System.out.println("Week Ending: 12-4-2015");
                System.out.println("Member Number: "+Integer.toString(getMember(memberNumber).number));
                System.out.println("Member Name: "+ getMember(memberNumber).name);
                System.out.println("Member Address: "+ getMember(memberNumber).streetAddress + ", "+getMember(memberNumber).city +", " +Integer.toString(getMember(memberNumber).zip) + "\n");
                System.out.println("Service Date    Service\t\tProvider");
                System.out.println("------------    -------\t\t--------");
                //Begin printing out the services now
                Vector<MemberService> tmp = getMember(memberNumber).services;
                for(int i =0;i<tmp.size();i++){
                	System.out.println(Integer.toString(tmp.get(i).month)+ Integer.toString(tmp.get(i).day) +Integer.toString(tmp.get(i).year)+tmp.get(i).serviceName +" "+ tmp.get(i).providerName);
                }
                //End printing
	}
	public void printProviderReport(int providerNumber){
                int numConsultations = 0;
                double totalFee = 0.0;
                System.out.println("\t\tChocoholics Anonymous\n");
                System.out.println("\t\tClaim Submissions\n");
                System.out.println("Week Ending: 12-4-2015");
                System.out.println("Provider Number: "+ Integer.toString(getProvider(providerNumber).number));
                System.out.println("Provider Name: "+ getProvider(providerNumber).name);
                System.out.println("Address: "+getProvider(providerNumber).streetAddress+", "+getMember(providerNumber).city+", "+Integer.toString(getMember(providerNumber).zip)+"\n");
                System.out.println("Submission Date-Time  Service Date  Code  Fee  Member No.  Member Name");
                System.out.println("--------------------  ------------  ----  ---  ----------  -----------");
                //Begin printing the claims the provider had for the week
                Vector<ProviderService> tmp = getProvider(providerNumber).services;
                for(int i =0;i<tmp.size();i++){
                	System.out.println(tmp.get(i).date + Integer.toString(tmp.get(i).month) + Integer.toString(tmp.get(i).day) + Integer.toString(tmp.get(i).year) + Integer.toString(tmp.get(i).serviceCode) + Double.toString(tmp.get(i).fee) + Integer.toString(tmp.get(i).memberNumber) + tmp.get(i).memberName);
                }
                //End printing 
                
                System.out.println("Number of Consultations: " + numConsultations);
                System.out.format("Total Fee:%.2f%n", totalFee);
	}
        
        public void printManagerReport() {
        		double total = 0.0;
        		int count = 0;
        		int consultations = 0;
                System.out.println("\t\tChocoholics Anonymous\n");
                System.out.println("\t\tAccounts Payable\n");
                System.out.println("Week Ending: 12-4-2015\n");
                System.out.println("Provider Number   Consultations\t\tFee Provider Name");
                System.out.println("---------------   -------------\t\t--- -------------");
                //Begin printing the accounts payable report
                for (Map.Entry me : listOfProviders.entrySet()) {
                	Provider tmp = (Provider)me.getValue();
                	double sum = 0.0;
                	for(int i=0;i<tmp.services.size();i++){
                		sum=sum+tmp.services.get(i).fee;
                		consultations = consultations+1;
                	}
                    System.out.println(Integer.toString(tmp.number)+" "+Integer.toString(tmp.services.size())+" $"+Double.toString(sum)+" "+tmp.name);
                    total = total + sum;
                    count++;
                  }
                //End printing
                System.out.println("---------------   -------------\t\t--- -------------");
                System.out.println("Totals:                       ");
                System.out.println(Integer.toString(consultations)+" "+Double.toString(total)+" "+Integer.toString(count));
        }
        
        public void printEFTReport() {
                System.out.println("\t\t\tChocoholics Anonymous\n");
                //Print out the providers number of consultations with total fee and provider name
                for (Map.Entry me : listOfProviders.entrySet()) {
                	Provider tmp = (Provider)me.getValue();
                	double sum = 0.0;
                	for(int i=0;i<tmp.services.size();i++){
                		sum=sum+tmp.services.get(i).fee;
                	}
                    System.out.println(Integer.toString(tmp.number)+" "+Double.toString(sum)+" "+tmp.name);
                  }
        }
        public void printProviderDirectory(){
        	System.out.println("ServiceName\t\tCode\tFee");
        	System.out.println("===========\t\t====\t===");
        	for (Map.Entry me : providerDirectory.entrySet()) {
            	PDI tmp = (PDI)me.getValue();
                System.out.println(tmp.serviceName+" "+Integer.toString(tmp.serviceCode)+" "+Double.toString(tmp.fee));
              }
        }
}
