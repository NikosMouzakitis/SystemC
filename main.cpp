#include "driver.h"
#include "monitor.h"
#include "full_adder.h"

int sc_main(int argc, char * argv[]) {

	sc_signal<bool> t_a, t_b, t_cin, t_sum, t_cout;

	full_adder f1("FullAdder");
	
	// connected with positional association.
	f1.a(t_a);
	f1.b(t_b);
	f1.carry_in(t_cin);
	f1.sum(t_sum);
	f1.carry_out(t_cout);	

	driver d1("GenerateWaveforms");
	//connect using named association.	
	d1.d_a(t_a);
	d1.d_b(t_b);
	d1.d_cin(t_cin);

	monitor mo1("MonitorWaveforms");

	mo1.m_a(t_a);
	mo1.m_b(t_b);
	mo1.m_cin(t_cin);
	mo1.m_sum(t_sum);
	mo1.m_cout(t_cout);

	sc_start(40, SC_NS);

	return(0);
}
