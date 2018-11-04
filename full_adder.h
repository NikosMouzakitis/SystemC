#include "half_adder.h"

SC_MODULE(full_adder) {

	sc_in<bool>	a, b, carry_in;
	sc_out<bool>	sum, carry_out;

	sc_signal<bool> c1, s1, c2;

	void prc_full_adder(void);

	half_adder *ha1, *ha2;
	
	SC_CTOR(full_adder) {

		// initializing the half-adders.
		ha1 = new half_adder("ha1");
		ha1->a(a);	
		ha1->b(b);	
		ha1->sum(s1);	
		ha1->carry(c1);

		ha2 = new half_adder("ha2");	
		(*ha2) (s1, carry_in, sum, c2);	
	
		SC_METHOD(prc_full_adder);
		sensitive << c1 << c2;
	}
	~full_adder() {
		delete ha1;
		delete ha2;
	}
};
