#include"offlinemessage.hpp"
#include"db.h"

//存储用户离线消息
    void OfflineMsgModel::insert(int userid, string msg)
    {
        char sql[1024]={0};
        sprintf(sql,"insert into OfflineMessage values(%d,'%s')",userid, msg.c_str());

        MySQL mysql;
        if (mysql.connect())
        {
            mysql.update(sql);
        }
    }

    //删除用户的离线消息
    void OfflineMsgModel::remove(int userid)
    {
        char sql[1024]={0};
        sprintf(sql,"delete from OfflineMessage where userid=%d",userid);

        MySQL mysql;
        if (mysql.connect())
        {
            mysql.update(sql);
        }
    }

    //查询用户离线消息
    vector<string> OfflineMsgModel::query(int userid)
    {
        char sql[1024]={0};
        sprintf(sql,"select message from OfflineMessage where userid = %d",userid);

        vector<string> vec;
        MySQL mysql;
        if(mysql.connect())
        {
            MYSQL_RES *res = mysql.query(sql);
            if (res!=nullptr)
            {
                MYSQL_ROW row ;
                //把userid用户所有的离线消息存入vec中
                while((row = mysql_fetch_row(res))!=nullptr)
                {
                    vec.push_back(row[0]);
                }
                mysql_free_result(res);
                return vec;
            }
        }
        return vec;
    }