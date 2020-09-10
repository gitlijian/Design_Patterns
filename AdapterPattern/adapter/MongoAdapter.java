package DesignPattern.AdapterPattern.adapter;

import DesignPattern.AdapterPattern.MyJdbc;
import DesignPattern.AdapterPattern.dbDriver.MongoDB;
import DesignPattern.AdapterPattern.dbDriver.OracleDB;

public class MongoAdapter implements MyJdbc {

    private MongoDB mongoDB;

    public MongoDB getMongoDB() {
        return mongoDB;
    }

    public MongoAdapter(MongoDB mongoDB){
        this.mongoDB = mongoDB;
    }

    @Override
    public void select() {
        mongoDB.mongoSelect();
    }

    @Override
    public void add() {
       mongoDB.mongoAdd();
    }

    @Override
    public void del() {
       mongoDB.mongoDel();
    }
}
