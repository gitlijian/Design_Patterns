package DesignPattern.FactoryPattern.AbstractFactory;

public class SampleFactory {
    private String money;

    public String getMoney() {
        return money;
    }

    public void setMoney(String money) {
        this.money = money;
    }

    public Car createCar(){
        Car car = null;
        switch (money){
            case "500":
            case "700":
                car = new AoDi();
               break;
            case "1000":
                car = new BaoMa();
        }
        return car;
        //return new AoDi();
    }

    public Ship createShip(){
        Ship ship = null;
        switch (money){
            case "500":
                ship = new KuaiTing();
                break;
            case "700":
            case "1000":
                ship = new YouLun();
        }
        return ship;
    }

    public Air createAir(){
        Air air = null;
        switch (money){
            case "500":
            case "700":
                air = new GuoHang();
                break;

            case "1000":
                air = new DongFang();
        }
        return air;
    }
}
