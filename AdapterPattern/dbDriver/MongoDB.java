package DesignPattern.AdapterPattern.dbDriver;

public class MongoDB {
    public void mongoSelect(){
        System.out.println("使用mongo查询数据");
    }

    public void mongoAdd(){
        System.out.println("向mongo中插入了一条数据");
    }

    public void mongoDel(){
        System.out.println("从mongo数据库中删除一条数据");
    }
}
