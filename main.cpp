 
#include "func.h"
#include "json.hpp"

int main()
{
	std::ifstream inp("input.json");
	json input = json::parse(inp);

	vector<courier> couriers;
	int couriers_num = input.at("couriers").size();
	for(int i = 0; i < couriers_num; i++)
	{
		courier helpocourier;
		input.at("couriers")[i].at("courier_id").get_to(helpocourier.courier_id);
		input.at("couriers")[i].at("location_x").get_to(helpocourier.location_x);
		input.at("couriers")[i].at("location_y").get_to(helpocourier.location_y);
		couriers.push_back(helpocourier);
		std::cout << couriers[i].courier_id << "\t" << couriers[i].location_x << "\t" << couriers[i].location_y <<endl;
	}

	vector<depot> depots;
	int depots_num = input.at("depots").size();
	for(int i = 0; i < depots_num; i++)
	{
		depot helpodepot;
		input.at("depots")[i].at("point_id").get_to(helpodepot.point_id);
		input.at("depots")[i].at("location_x").get_to(helpodepot.location_x);
		input.at("depots")[i].at("location_y").get_to(helpodepot.location_y);
		depots.push_back(helpodepot);
		std::cout << depots[i].point_id << "\t" << depots[i].location_x << "\t" << depots[i].location_y <<endl;
	}

	vector<order> orders;
	int orders_num = input.at("orders").size();
	for(int i = 0; i < orders_num; i++)
	{
		order helpoorder;
		input.at("orders")[i].at("order_id").get_to(helpoorder.order_id);
		input.at("orders")[i].at("pickup_point_id").get_to(helpoorder.pickup_point_id);
		input.at("orders")[i].at("pickup_from").get_to(helpoorder.pickup_from);
		input.at("orders")[i].at("pickup_to").get_to(helpoorder.pickup_to);
		input.at("orders")[i].at("pickup_location_x").get_to(helpoorder.pickup_location_x);
		input.at("orders")[i].at("pickup_location_y").get_to(helpoorder.pickup_location_y);
		input.at("orders")[i].at("dropoff_point_id").get_to(helpoorder.dropoff_point_id);
		input.at("orders")[i].at("dropoff_from").get_to(helpoorder.dropoff_from);
		input.at("orders")[i].at("dropoff_to").get_to(helpoorder.dropoff_to);
		input.at("orders")[i].at("dropoff_location_x").get_to(helpoorder.dropoff_location_x);
		input.at("orders")[i].at("dropoff_location_y").get_to(helpoorder.dropoff_location_y);
		input.at("orders")[i].at("payment").get_to(helpoorder.payment);
		orders.push_back(helpoorder);
		std::cout << orders[i].order_id << "\t" << orders[i].pickup_point_id << "\t" << orders[i].payment <<endl;
	}

    return 0;
}
