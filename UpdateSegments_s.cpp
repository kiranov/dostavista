#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "func.h"

#define EVARATE 0.2 // скорость испарения феромона





using namespace std;



void UpdateSegments(segments segm, vector<Event> way) {
    for (map<Event, vector<Data> >::iterator it = segm.segm.begin(); it != segm.segm.end(); it++) {  // выводим их
        for (int j = 0; j < it->second.size(); j++ ){
            it->second[j].ferment-= it->second[j].ferment * EVARATE;
        }
    }

    vector<Event>::iterator it = way.begin();
    auto nz = next(it, 0);
    for(; it != next(way.end(), -1); it++) {  // выводим их
        auto nz = next(it, 0);
        bool flag = true;
        int L_ev = 2;

        //cout << segm.segm[*it]://.size();
         for(int i = 0; i < segm.segm[*it].size(); i++){
            if (*nz == segm.segm[*it][i].event){
                segm.segm[*it][i].ferment += L_ev; //нужно будет подумать как размазываем феромон по ребрам, какой вклад они привносят
                flag = false;
                break;
            }
        }
        if(flag) {
            segm.segm[*it].push_back(Data {*nz, L_ev});
        }
    }
    
}