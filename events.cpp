#include "func.h"
#include "propobility.cpp"

Event::Event(int c_id, Action act, int ord, int point){
    courier_id = c_id;
    action = act;
    order_id = ord;
    point_id = point;
}

Event GetNextEvent(){

}

set<Event> possible_events(vector<courier> cour, vector<order> ord, vector<depot> dep){
    set<Event> result;
    for(auto item: cour){
        for(auto thing1: ord){
            result.insert({item.courier_id, Action::pickup, thing1.order_id, thing1.pickup_point_id});
            result.insert({item.courier_id, Action::pickup, thing1.order_id, thing1.dropoff_point_id});
            result.insert({item.courier_id, Action::dropoff, thing1.order_id, thing1.pickup_point_id});
            result.insert({item.courier_id, Action::dropoff, thing1.order_id, thing1.dropoff_point_id});
            for(auto thing2: dep){
                result.insert({item.courier_id, Action::pickup, thing2.point_id, thing1.pickup_point_id});
                result.insert({item.courier_id, Action::pickup, thing2.point_id, thing1.dropoff_point_id});
                result.insert({item.courier_id, Action::dropoff, thing2.point_id, thing1.pickup_point_id});
                result.insert({item.courier_id, Action::dropoff, thing2.point_id, thing1.dropoff_point_id});
            }
        }
    }
    return result;
}

void Way::new_event(int n, set<Event> ev){
    //функцию нужно дописать - для этого нужна функция GetNextEvent
    Event event = GetNextEvent();
    while(event.action != Action::finish){
        ways.push_back(event);
        event = GetNextEvent();
    }
    ways.push_back(event);

}
