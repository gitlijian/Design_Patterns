package DesignPattern.AdapterPattern.adapter;

import DesignPattern.AdapterPattern.MyJdbc;
import DesignPattern.AdapterPattern.dbDriver.OracleDB;

public class OracleAdapter implements MyJdbc {

    private OracleDB oracleDB;

    public OracleDB getOracleDB() {
        return oracleDB;
    }

    public  OracleAdapter(OracleDB oracleDB) {
        this.oracleDB = oracleDB;
    }

    @Override
    public void select() {
       oracleDB.oracleSelect();
    }

    @Override
    public void add() {
       oracleDB.oracleAdd();
    }

    @Override
    public void del() {
        oracleDB.oracleDel();
    }
}
