    #pragma once
    #include <iostream>
    #include <map>
    #include <set>
    #include <string>
    #include <vector>

    using namespace std;

    enum class Action{
        start,
        pickup,
        dropoff,
        finish
    };

    class Event{
        public:
        int courier_id;
        Action action;
        int order_id;
        int point_id;
        Event(int c_id, Action act, int ord, int point);
    };

    class Data{
        public:
        Event event;
        int ferment;
    };

    class segments{
        public:
        map<Event, vector<Data>> segm;
    };

    class Way{
        public:
        vector<Event> ways;
        //new_event должен генерировать путь, новый Event класть в вектор(с учетом вероятностой функции)
        void new_event(int n, set<Event> );
    };

    class courier{
        public:
        int courier_id;
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

    class depot{
        public:
        int point_id;
        int location_x;
        int location_y;
    };

    set<Event> possible_events(vector<courier> cour, vector<order> ord, vector<depot> dep);

    //нужно переписать функцию с питона
    void cheсker();

    Event GetNextEvent();

   
