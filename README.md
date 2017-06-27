# Dependencies

apt-get install libboost-all-dev python-dev


#How to build with g++

g++ -I /usr/include/boost -shared -o hello_ext.so hw.cpp -fpic -lboost_python -I /usr/include/python2.7


