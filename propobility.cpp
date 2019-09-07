#include "func.h"

#define GREED 1 // жадность
#define HERD 1 // стадность
#define RANDSS 1 // вероятность для непройденных путей
#define NUMFIND 100 // если будет очень долго искать следующий event


using namespace std;



Event GetNextEvent(Event evt, set<Event> events) {
    int myCourier = evt.courier_id;
    vector<Event> allEv = AllEvents.evs[myCourier];
    if(segm[evt].is_empty()){
        return allEv[rand() % allEv.size()];
    }
    vector<Data> was = segments.segm[evt];

    vector<int> p;

    sum = 0;
    for (i = 0; i < was.size(); i++) {
        a = pow(was[i].ferment, GREED) * pow(distance(), HERD);
        sum+=a;
        p.pushback(a);
    }

    sum = sum(1 + RANDSS);
    int ind = rand() % int(sum);
    int MyInd = 0;

    for (i = 0; i < was.size(); i++) {
        if (MyInd > ind){
            return was[MyInd].ev;
            break;
        } else {
            MyInd+= p[i];
        }
    }

    bool flag = true
    if(i == was.size()) {
        for (i = 0; i < NUMFIND, i++) {
            outEv = allEv[rand() % allEv.size()];
            flag = true;
            for (auto dat : was) {
                if (dat.ev == outEv) {
                    flag = false;
                    break;
                }
            }
            if (flag){
                return outEv;
            }
        }
    }
    return allEv[rand() % allEv.size()];
}

