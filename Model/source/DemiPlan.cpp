#include "../header/DemiPlan.h"

DemiPlan::DemiPlan() : Figure(){

}

bool DemiPlan::dedans(float x, float y){
    return y >= 0;
}