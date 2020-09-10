package DesignPattern.AdapterPattern.dbDriver;

public class OracleDB {
    public void oracleSelect(){
        System.out.println("使用oracle查询数据");
    }

    public void oracleAdd(){
        System.out.println("向oracle中插入了一条数据");
    }

    public void oracleDel(){
        System.out.println("从oracle数据库中删除一条数据");
    }
}
