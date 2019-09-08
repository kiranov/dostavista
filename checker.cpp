#include "func.h"

int main()
{
	std::ifstream inp("input.json");
	json input = json::parse(inp);
	std::ifstream outp("output.json");
	json output = json::parse(outp);

	int couriers_num = input.at("couriers").size();
	for(int i = 0; i < couriers_num; i++)
	{
		int helpocourier;
		input.at("couriers")[i].at("courier_id").get_to(helpocourier);
		couriers[helpocourier].location_id = helpocourier;
		couriers[helpocourier].time = 360;
		input.at("couriers")[i].at("location_x").get_to(locations[helpocourier].first);
		input.at("couriers")[i].at("location_y").get_to(locations[helpocourier].second);
		std::cout << "Courier #" << helpocourier << " is located at (";
		std::cout << locations[helpocourier].first << ", " << locations[helpocourier].second << ")" <<endl;
	} std::cout<<endl;

	int depots_num = input.at("depots").size();
	for(int i = 0; i < depots_num; i++)
	{
		int helpodepot;
		input.at("depots")[i].at("point_id").get_to(helpodepot);
		input.at("depots")[i].at("location_x").get_to(locations[helpodepot].first);
		input.at("depots")[i].at("location_y").get_to(locations[helpodepot].second);
		std::cout << "Depot #" << helpodepot << " is located at (";
		std::cout << locations[helpodepot].first << ", " << locations[helpodepot].second << ")" <<endl;
	} std::cout<<endl;

	int orders_num = input.at("orders").size();
	for(int i = 0; i < orders_num; i++)
	{
		int helpoorder;
		input.at("orders")[i].at("order_id").get_to(helpoorder);
		input.at("orders")[i].at("pickup_point_id").get_to(orders[helpoorder].pickup_point_id);
		input.at("orders")[i].at("pickup_from").get_to(orders[helpoorder].pickup_from);
		input.at("orders")[i].at("pickup_to").get_to(orders[helpoorder].pickup_to);
		input.at("orders")[i].at("pickup_location_x").get_to(locations[orders[helpoorder].pickup_point_id].first);
		input.at("orders")[i].at("pickup_location_y").get_to(locations[orders[helpoorder].pickup_point_id].second);
		input.at("orders")[i].at("dropoff_point_id").get_to(orders[helpoorder].dropoff_point_id);
		input.at("orders")[i].at("dropoff_from").get_to(orders[helpoorder].dropoff_from);
		input.at("orders")[i].at("dropoff_to").get_to(orders[helpoorder].dropoff_to);
		input.at("orders")[i].at("dropoff_location_x").get_to(locations[orders[helpoorder].dropoff_point_id].first);
		input.at("orders")[i].at("dropoff_location_y").get_to(locations[orders[helpoorder].dropoff_point_id].second);
		input.at("orders")[i].at("payment").get_to(orders[helpoorder].payment);
		points[orders[helpoorder].pickup_point_id][orders[helpoorder]]=orders[helpoorder].pickup_from;
		std::cout << "Order #" << helpoorder << " would be move from (";
		std::cout << locations[orders[helpoorder].pickup_point_id].first << ", ";
		std::cout << locations[orders[helpoorder].pickup_point_id].second << ") [";
		std::cout << orders[helpoorder].pickup_from << "-";
		std::cout << orders[helpoorder].pickup_to << "] to (";
		std::cout << locations[orders[helpoorder].dropoff_point_id].first << ", ";
		std::cout << locations[orders[helpoorder].dropoff_point_id].second << ") [";
		std::cout << orders[helpoorder].dropoff_from << "-";
		std::cout << orders[helpoorder].dropoff_to << "] and costs ";
		std::cout << orders[helpoorder].payment <<endl;
	} std::cout<<endl;

	vector<Event> events;
	int events_num = output.at("events").size();
	for(int i = 0; i < events_num; i++)
	{
		Event helpoevent;
		output.at("events")[i].at("courier_id").get_to(helpoevent.courier_id);
		output.at("events")[i].at("action").get_to(helpoevent.action);
		output.at("events")[i].at("order_id").get_to(helpoevent.order_id);
		output.at("events")[i].at("point_id").get_to(helpoevent.point_id);
		events.push_back(helpoevent);
		std::cout << "Courier #" << events[i].courier_id << " " << events[i].action;
		std::cout << " order #" << events[i].order_id << " at (";
		std::cout << locations[helpoevent.point_id].first << ", ";
		std::cout << locations[helpoevent.point_id].second << ")" <<endl;
	} std::cout<<endl;

	for(int event_counter = 0; event_counter < events_num; event_counter++)
	{
		// Последнее местоположение курьера
		pair<int,int> courier_location = locations[couriers[events[event_counter].courier_id].location_id];
		std::cout<<"Courier #"<<events[event_counter].courier_id<<" goes from (";
		std::cout<<courier_location.first<<", "<<courier_location.second<<") to (";
		// Местоположение точки назначения, куда направляется курьер
		pair<int,int> destination_location = locations[events[event_counter].point_id];
		std::cout<<destination_location.first<<", "<<destination_location.second<<") ";
		// Время перемещения до точки назначения
		int duration_minutes = 10 + abs(courier_location.first - destination_location.first)
									+ abs(courier_location.second - destination_location.second);
		std::cout<<"during "<<duration_minutes<<" minutes"<<endl;
		// Самое раннее время, в которое курьер может оказаться на точке назначения
		int visit_time = couriers[events[event_counter].courier_id].time + duration_minutes;


		if (events[event_counter].point_id <= 60000)
		{
			if (visit_time < orders[events[event_counter].order_id].pickup_from)
				// Если курьер прибывает раньше левой границы временного интервала на точке, то он ждет начала интервала
				visit_time =  orders[events[event_counter].order_id].pickup_from;
			else if (visit_time > orders[events[event_counter].order_id].pickup_to)
				// Если курьер прибывает позже правой границы временного интервала на точке, то это опоздание
				{std::cout<<endl<<"Courier will be late!"<<endl;return 0;}
		}
		else
		{
			if (visit_time < orders[events[event_counter].order_id].dropoff_from)
				// Если курьер прибывает раньше левой границы временного интервала на точке, то он ждет начала интервала
				visit_time =  orders[events[event_counter].order_id].dropoff_from;
			else if (visit_time > orders[events[event_counter].order_id].dropoff_to)
				// Если курьер прибывает позже правой границы временного интервала на точке, то это опоздание
				{std::cout<<endl<<"Courier will be late!"<<endl;return 0;}
		}

		if (events[event_counter].action == "pickup")
		{
			// Если order_id сейчас не в точке point_id, то ошибка
			if (orders[events[event_counter].order_id].pickup_point_id != events[event_counter].point_id)
				{std::cout<<endl<<"Can't pick up! (event #"<<event_counter<<")"<<endl;return 0;}
			// Если курьер едет за заказом на склад, то, мб, ему нужно будет подождать появления этого заказа на складе
			if ((30001 <= events[event_counter].point_id and events[event_counter].point_id <= 40000)
				and visit_time < point['order_time'][order_id])
                visit_time = point['order_time'][order_id]
		}


		// Обновляем время и местоположение курьера
        couriers[events[event_counter].courier_id].time = visit_time;
        locations[couriers[events[event_counter].courier_id].location_id] = destination_location;
	}

    return 0;
}
