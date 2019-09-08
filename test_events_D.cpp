#include "func.h"

Event::Event(int c_id, string act, int ord, int point){
    courier_id = c_id;
    action = act;
    order_id = ord;
    point_id = point;
}


Event createEvent(int c_id, string act, int ord_id, int point_id){
    return {c_id, act, ord_id, point_id};
}

vector<vector<Event>> possible_events(vector<courier> cour, vector<order> ord, vector<depot> dep){
    vector<vector<Event>> result;
    vector<Event> temp;
    for(auto item: cour){
        for(auto thing1: ord){
            temp.push_back(createEvent(item.courier_id, "pickup", thing1.order_id, thing1.pickup_point_id));
            temp.push_back(createEvent(item.courier_id, "pickup", thing1.order_id, thing1.dropoff_point_id));
            temp.push_back(createEvent(item.courier_id, "dropoff", thing1.order_id, thing1.pickup_point_id));
            temp.push_back(createEvent(item.courier_id, "dropoff", thing1.order_id, thing1.dropoff_point_id));
            for(auto thing2: dep){
                temp.push_back(createEvent(item.courier_id, "pickup", thing2.point_id, thing1.pickup_point_id));
                temp.push_back(createEvent(item.courier_id, "pickup", thing2.point_id, thing1.dropoff_point_id));
                temp.push_back(createEvent(item.courier_id, "dropoff", thing2.point_id, thing1.pickup_point_id));
                temp.push_back(createEvent(item.courier_id, "dropoff", thing2.point_id, thing1.dropoff_point_id));
            }
        }
        result.push_back(temp);
    }
    return result;
}

int main(){

    return 0;
}
