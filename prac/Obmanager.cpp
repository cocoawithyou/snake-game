#include "Obmanager.h"

using namespace std;

Obm::Obm(){
    gate_size=item_size=0;
}

void Obm::push_item(Item* item){
    this->item.push_back(item);
}
void Obm::push_gate(Gate* gate){
    this->gate.push_back(gate);
}
void Obm::pop_item(){
    item.pop_back();
}
void Obm::pop_gate(){
    gate.pop_back();
}
int Obm::get_gate_size(){
    return gate_size;
}
int Obm::get_item_size(){
    return item_size;
}

void Obm::up_gate_size(){
    gate_size++;
}

void Obm::up_item_size(){
    item_size++;
}

void Obm::down_gate_size(){
    gate_size--;
}

void Obm::down_item_size(){
    item_size--;
}