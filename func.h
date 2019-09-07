    #pragma once
    #include <iostream>
    #include <map>
    #include <string>
    #include <vector>
    #include <fstream>
    #include "json.hpp"

    using namespace std;
    using json = nlohmann::json;

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

	class AllEvents{
        public:
        vector<vector<Event>> evs;
    };

	struct segments{
        map<Event, vector<Data> > segm;
    };

    class Events{
        public:
        vector<Event> ev;
        //new_event должен генерировать путь, новый Event класть в вектор(с учетом вероятностой функции)
        void new_event();
    };

    class courier{
    	public:
        int courier_id;
        int location_x;
        int location_y;
    };

    class depot{
    	public:
        int point_id;
        int location_x;
        int location_y;
    };

    class order{
    	public:
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
