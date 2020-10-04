
#include "cairo_picker/src/cairo_picker.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <string>

Capr::C_picker picker;

const int range_w = 800;
const int range_h = 800;
const int rect_w = 20;
const int rect_h = 20;

struct point{
    int x, y;
};

std::vector<point> data;

void func(Capr::Cairo_cont cr){
    cr->set_source_rgba(1.0, 0.0, 0.0, 0.5);
    for(auto it: data){
        cr->rectangle(it.x-rect_w/2, it.y-rect_h/2, rect_w/2, rect_h/2);
        cr->fill();
    }
}

void button_press(unsigned int _button, unsigned int _x, unsigned int _y){
    data.push_back(point{int(_x), int(_y)});
}

void key_press(unsigned int _key){

    if(_key != 115) return;

    std::time_t now = time(0);
    std::string date = std::ctime(&now);

    for(int i=0; i<date.length(); i++){
        if(date[i]==' ')date[i]='_';
    }

    std::string filename = "./data_container/data__" + date + ".txt";

    std::ofstream ofs(filename);

    for(auto it: data){
        ofs<<it.x<<":"<<it.y<<std::endl;
    }

    ofs.close();

    std::cout<<"Wrote to file : "<<date<<std::endl;

}

int main(){

    data.clear();

    picker.set_default_size(range_w,range_h);
    picker.set_loop(10);

    picker.set_button_input(button_press, nullptr);
    picker.set_key_input(key_press, nullptr);

    picker.run(func);
}