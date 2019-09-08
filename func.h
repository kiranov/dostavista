    #pragma once
    #include <iostream>
    #include <map>
    #include <string>
    #include <vector>
    #include <fstream>
    #include "json.hpp"

    using json = nlohmann::json;
    using namespace std;

<<<<<<< HEAD
    struct Event{
	public:
		int courier_id;
        string action;
        int order_id;
        int point_id;
=======
    class Event{
        public:
        int courier_id;
        Action action;
        int order_id;
        int point_id;
    
>>>>>>> 4989f64ec083d90eb01b645f5e6db0442e51a318
        bool operator<(const Event& right) const {
            return courier_id < right.courier_id;
        }

        bool operator==(const Event& right) const {
            return courier_id == right.courier_id;
        }
    };

    struct Data{
        Event event;
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
		int location_id;
		int time;
    };

    class order{
	public:
        int pickup_point_id;//location_id
        int pickup_from;
        int pickup_to;
        int dropoff_point_id;//location_id
        int dropoff_from;
        int dropoff_to;
        int payment;

    };

    map < int, pair < int, int > >  locations;// here pair is (x, y)
    map < int, courier > couriers;
    map < int, order > orders;

