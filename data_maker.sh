
g++ -o data_maker data_maker.cpp `pkg-config --libs --cflags gtkmm-3.0`

./data_maker

rm -r ./data_maker