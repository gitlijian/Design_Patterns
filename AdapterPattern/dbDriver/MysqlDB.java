package DesignPattern.AdapterPattern.dbDriver;

public class MysqlDB {
    public void mysqlSelect(){
        System.out.println("使用mysql查询数据");
    }

    public void mysqlAdd(){
        System.out.println("向mysql中插入了一条数据");
    }

    public void mysqlDel(){
        System.out.println("从mysql数据库中删除一条数据");
    }
}
