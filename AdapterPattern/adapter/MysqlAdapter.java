package DesignPattern.AdapterPattern.adapter;

import DesignPattern.AdapterPattern.MyJdbc;
import DesignPattern.AdapterPattern.dbDriver.MysqlDB;

public class MysqlAdapter implements MyJdbc {

    private MysqlDB mysqlDB;

    public MysqlDB getMysqlDB() {
        return mysqlDB;
    }

    public MysqlAdapter(MysqlDB mysqlDB){
        this.mysqlDB = mysqlDB;
    }

    @Override
    public void select() {
       mysqlDB.mysqlSelect();
    }

    @Override
    public void add() {
       mysqlDB.mysqlAdd();
    }

    @Override
    public void del() {
       mysqlDB.mysqlDel();
    }
}
