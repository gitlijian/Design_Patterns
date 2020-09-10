package DesignPattern.AdapterPattern;

import DesignPattern.AdapterPattern.adapter.MongoAdapter;
import DesignPattern.AdapterPattern.adapter.MysqlAdapter;
import DesignPattern.AdapterPattern.adapter.OracleAdapter;
import DesignPattern.AdapterPattern.dbDriver.MongoDB;
import DesignPattern.AdapterPattern.dbDriver.MysqlDB;
import DesignPattern.AdapterPattern.dbDriver.OracleDB;

public class DriverManager {
    //使用工厂模式，根据url不同，创建不同的数据库driver连接对象
    MyJdbc myJdbc = null;
    public MyJdbc getConn(String url){
        switch (url) {
            case "oracle":
                System.out.println("创建oracle连接");
                myJdbc = new OracleAdapter(new OracleDB());
                break;
            case "mysql":
                System.out.println("创建mysql连接");
                myJdbc = new MysqlAdapter(new MysqlDB());
                break;
            case "mongoDB":
                System.out.println("创建mongo连接");
                myJdbc = new MongoAdapter(new MongoDB());
                break;
            default:
                System.out.println("错误");
                break;
        }
        return myJdbc;
    }
}
