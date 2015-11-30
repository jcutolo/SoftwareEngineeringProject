import java.util.Vector;

public class Provider {
	public String name;
	public int number;
	public String streetAddress;
	public String city;
	public String state;
	public int zip;
	public Vector<ProviderService> services = new Vector<ProviderService>();
	public Provider(String name,int number,String streetAddress,String city,String state,int zip){
		this.name = name;
		this.number = number;
		this.streetAddress = streetAddress;
		this.city = city;
		this.state = state;
		this.zip = zip;
	}
	
}
