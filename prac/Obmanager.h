#pragma once
#include "Item.h"
#include "Gate.h"
#include <vector>

using namespace std;
class Obm{
private:
    vector<Item*> item;
    vector<Gate*> gate;
    int gate_size,item_size;
public:
    Obm();
    ~Obm(){}
    void push_item(Item* item);
    void push_gate(Gate* gate);
    void pop_item();
    void pop_gate();
    int get_gate_size();
    int get_item_size();
    void up_gate_size();
    void up_item_size();
    void down_gate_size();
    void down_item_size();
};