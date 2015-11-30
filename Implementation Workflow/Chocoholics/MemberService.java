//TODO: Add error checking.
public class MemberService {
	public int month;
	public int day;
	public int year;
	public String providerName;
	public String serviceName;
	public MemberService(int month,int day,int year,String name,String serviceName){
		this.month=month;
		this.day=day;
		this.year=year;
		this.providerName=providerName;
		this.serviceName=serviceName;
	}
}
