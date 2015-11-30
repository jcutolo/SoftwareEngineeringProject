
public class Service {
	public int month;
	public int day;
	public int year;
	public int m;
	public int d;
	public int y;
	public int providerNumber;
	public int memberNumber;
	public int serviceCode;
	public String comment;
	public Service(int month,int day,int year,int m,int d,int y,int providerNumber,int memberNumber,int serviceCode,String comment){
		this.month = month;
		this.day = day;
		this.year = year;
		this.m = m;
		this.d = d;
		this.y = y;
		this.providerNumber = providerNumber;
		this.memberNumber = memberNumber;
		this.serviceCode = serviceCode;
		this.comment = comment;
	}
}
