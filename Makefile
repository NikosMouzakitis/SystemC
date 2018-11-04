	# a basic systemc Makefile.
all:
	g++ -I/usr/local/systemc-2.3.2/include main.cpp monitor.cpp driver.cpp full_adder.cpp half_adder.cpp -L/usr/local/systemc-2.3.2/lib-linux64  -lsystemc  -fpermissive
#./a.out
