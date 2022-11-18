#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "Cities.h"
using namespace std;

struct _date {
    int day, month, year;
};
//struct _time {
//    int hour, min;
//};
//struct _cities {
//    string up_city;
//    string down_city;
//};

struct _flights {
        //Номер рейса
        //Пункт выбытия
        //Пункт назначения
        //Дата рейса
        //Время вылета
        //Время прибытия
        //Тип самолета
        //Стоимость билета
        //Количество мест
    string number_flight;
    string up_city;
    string down_city;
    //_date date_flight;
    //_time time_up;
    //_time time_down;
    //string type_airoplane;
    //string ticket_price;
    //string number_of_seats;
};

class Flights 
{
    map<string, _flights> flights;
public:
    Flights();
    ~Flights();
    void add_flight(Cities& _cities);
    void delete_flight();
    void edit_flight();
    void print_flight();
    void print_flight_up_cities();
    void print_flight_down_cities();
    void print_flight_up_down_cities();
};
