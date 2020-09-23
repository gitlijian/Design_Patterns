package DesignPattern.constructPattern.BridgePattern.impl1;


public class IPhone {
    private Phone phone;

    public IPhone(Phone phone){
        this.phone = phone;
    }

    public void call(){
        System.out.println("苹果手机");
        phone.call();
    }

    public void online(){
        System.out.println("苹果手机");
        phone.online();
    }
}
