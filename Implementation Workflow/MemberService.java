//TODO: Add error checking.
public class MemberService {
	private int month;
	private int day;
	private int year;
	private String name;
	private String serviceName;
	public MemberService(int month,int day,int year,String name,String serviceName){
		this.month=month;
		this.day=day;
		this.year=year;
		this.name=name;
		this.serviceName=serviceName;
	}
}
