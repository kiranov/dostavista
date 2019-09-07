#include <iostream>
#include <map>
#include <string>
#include <vector>


using namespace std;

enum struct Action{
    pickup,
    dropoff
};

struct Event{
    int courier_id;
    Action action;
    int order_id;
    int point_id;
};

struct Data{
    struct Event;
    int ferment;
};

struct segments{
    map<Event, Data> segm;
};

class Events{
    vector<Event> ev;
    //new_event должен генерировать путь, новый Event класть в вектор(с учетом вероятностой функции)
    void new_event(){

    }
};

class courier{
    int courier_id;
    int location_x;
    int location_y;
};

class order{
    int order_id;
    int pickup_point_id;
    int pickup_location_x;
    int pickup_location_y;
    int pickup_from;
    int pickup_to;
    int dropoff_point_id;
    int dropoff_location_x;
    int dropoff_location_y;
    int dropoff_from;
    int dropoff_to;
    int payment;

};

//нужно переписать функцию с питона
void cheсker(){


};
