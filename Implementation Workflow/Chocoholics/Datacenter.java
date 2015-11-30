import java.util.HashMap;
import java.util.Vector;

//Do error checking in here...

public class Datacenter {
	private HashMap<Integer,Provider> listOfProviders = new HashMap<Integer,Provider>();
	private HashMap<Integer,Manager> listOfManagers = new HashMap<Integer,Manager>();
	private HashMap<Integer,Member> listOfMembers = new HashMap<Integer,Member>();
	private HashMap<Integer,PDI> providerDirectory = new HashMap<Integer,PDI>();
	private Vector<Service> services = new Vector<Service>();
	//Add new physical service to total list
	public void addService(int code, string name, double price){
		services.addElement(code,name,price);
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
