//Provider Directory Item
public class PDI {
	public String serviceName;
	public int serviceCode;
	public double fee;
	public PDI(int serviceCode,String serviceName, double fee){
		this.serviceName = serviceName;
		this.serviceCode = serviceCode;
		this.fee = fee;
	}
}
