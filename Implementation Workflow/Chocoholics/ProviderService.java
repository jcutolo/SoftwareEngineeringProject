public class ProviderService {
	public int month;
	public int day;
	public int year;
	public String date;
	public String memberName;
	public int memberNumber;
	public int serviceCode;
	public double fee;
	public ProviderService(int month,int day,int year,String date,String memberName,int memberNumber,int serviceCode, double fee){
		this.month=month;
		this.day=day;
		this.year=year;
		this.memberName=memberName;
		this.memberNumber=memberNumber;
		this.serviceCode = serviceCode;
		this.fee=fee;
	}
}
