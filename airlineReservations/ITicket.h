#pragma once
#include "IPassenger.h"

class ITicket {
private: 
IPassenger *Ihead, *Itail; 
public: 
 ITicket();
~ITicket(); 
// Function Prototypes 
void reverselTicket(); 
void cancellTicket(); 
void checklTicket();
void display(); }; 