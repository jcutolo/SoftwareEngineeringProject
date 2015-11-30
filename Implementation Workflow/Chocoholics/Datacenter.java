import java.util.HashMap;
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
		ProviderService p = new ProviderService(c.month,c.day,c.year,c.date,getMember(c.memberNumber).name,c.memberNumber,11111);
		MemberService m = new MemberService(c.month,c.day,c.year,getProvider(c.providerNumber).name,"TEST SERVICE NAME");
		getMember(c.memberNumber).services.addElement(m);
		getProvider(c.providerNumber).services.addElement(p);
	}
	public void addPDI(PDI p){
		providerDirectory.put(p.serviceCode, p);
	}
	public void removePDI(int serviceCode){
		listOfProviders.remove(serviceCode);
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
	public void updateProvider(int providerNumber){
		//klshakshakkjshkahdsajkd
	}
	public void addMember(Member m){
		listOfMembers.put(m.number, m);
	}
	public void removeMember(int memberNumber){
		listOfProviders.remove(memberNumber);
	}
	public void updateMember(int memberNumber){
		//ndsfkdsjfsk
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
}
