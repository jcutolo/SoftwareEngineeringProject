import java.util.Date;
import java.text.DateFormat;
import java.text.SimpleDateFormat;

public class Claim{
	public int month;
	public int day;
	public int year;
	public String date;
	public int providerNumber;
	public int memberNumber;
	public int serviceCode;
	public String comment;
	public Claim(int month,int day,int year,int providerNumber,int memberNumber,int serviceCode,String comment){
		this.month = month;
		this.day = day;
		this.year = year;
		DateFormat df = new SimpleDateFormat("dd/MM/yy HH:mm:ss");
		Date dateobj = new Date();
		String date = df.format(dateobj);
		this.date=date;
		this.providerNumber = providerNumber;
		this.memberNumber = memberNumber;
		this.serviceCode = serviceCode;
		this.comment = comment;
	}
}