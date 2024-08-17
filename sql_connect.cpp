#include<iostream>
#include<mysql/mysql.h>

using namespace std;
int main(){

    MYSQL mysql;
    MYSQL_ROW row;
    mysql_init(&mysql);
    mysql_real_connect(&mysql, "127.0.0.1","root","Xjf030904","webserver",3306,NULL,0);
    mysql_query(&mysql,"select * from user");
    MYSQL_RES* res = mysql_store_result(&mysql);
    unsigned int num = mysql_num_fields(res);
    cout<<"num_fields="<<num<<endl;
    MYSQL_FIELD* fields = mysql_fetch_fields(res);
    for(int i =0;i<num;i++){
        cout<<fields[i].name;
        cout<<"\t";
    }
    cout<<endl;
    while(row=mysql_fetch_row(res)){
        for(int i=0;i<num;i++){
            cout<<row[i]<<"\t";
        }
    }
    cout<<endl;




    return 0;
}