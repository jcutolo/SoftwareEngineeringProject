import java.util.Vector;

//Status 0=good 1=suspended
public class Member {
	public String name;
	public int number;
	public String streetAddress;
	public String city;
	public String state;
	public int zip;
	public int status;
	public Vector<MemberService> services = new Vector<MemberService>();
	public Member(String name, int number, String streetAddress, String city, String state, int zip, int status){
		this.name = name;
		this.number=number;
		this.streetAddress=streetAddress;
		this.city=city;
		this.state=state;
		this.zip=zip;
		this.status=status;
	}
	public void addService(){}
}
