#include <systemc.h>

// a basic 2-bit adder module in SystemC.

SC_MODULE( adder )
{
	sc_in<sc_uint<1>>	a0;
	sc_in<sc_uint<1>>	a1;
	sc_in<sc_uint<1>>	b0;
	sc_in<sc_uint<1>>	b1;

	sc_out<sc_uint<1>>	q0;
	sc_out<sc_uint<1>>	q1;
	sc_out<sc_uint<1>>	carry;	//carry

	void compute(void) {
		
		sc_uint<1> t0;		
		sc_uint<1> t1;		
		sc_uint<1> and_a0_b0;		
		sc_uint<1> and_a1_b1;		
		sc_uint<1> xor_a1_b1;		
		sc_uint<1> fa;		
	

		and_a0_b0 = ( a0.read() & b0.read() );	
		and_a1_b1 = ( a1.read() & b1.read() );	
		
		xor_a1_b1 = ( a1.read() ^ b1.read() );
	
		fa = ( and_a0_b0 & xor_a1_b1 );

		// writing output signals.	

		q0.write( a0.read() ^ b0.read() );
		q1.write( xor_a1_b1 ^ and_a0_b0);
		carry.write( fa | and_a1_b1);

	}

	SC_CTOR(adder) {
		SC_METHOD(compute);
		sensitive << a0;
		sensitive << a1;
		sensitive << b0;
		sensitive << b1;
	}
};

// tesbench
int sc_main( int argc, char *argv[]) 
{
	sc_signal<sc_uint<1>>	a0;
	sc_signal<sc_uint<1>>	a1;
	sc_signal<sc_uint<1>>	b0;
	sc_signal<sc_uint<1>>	b1;
	sc_signal<sc_uint<1>>	q0;
	sc_signal<sc_uint<1>>	q1;
	sc_signal<sc_uint<1>>	carry;

	adder gt("gt");
	gt.a0(a0);
	gt.a1(a1);
	gt.b0(b0);
	gt.b1(b1);
	gt.q0(q0);
	gt.q1(q1);
	gt.carry(carry);
	
	cout << "created 2-bit ADDER.\n";



	cout << "\n\n";
	
	a0.write(0); a1.write(0); b0.write(0); b1.write(0);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(0); a1.write(0); b0.write(0); b1.write(1);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(0); a1.write(0); b0.write(1); b1.write(0);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(0); a1.write(0); b0.write(1); b1.write(1);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(0); a1.write(1); b0.write(0); b1.write(0);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(0); a1.write(1); b0.write(0); b1.write(1);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(0); a1.write(1); b0.write(1); b1.write(0);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(0); a1.write(1); b0.write(1); b1.write(1);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	


	a0.write(1); a1.write(0); b0.write(0); b1.write(0);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(1); a1.write(0); b0.write(0); b1.write(1);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(1); a1.write(0); b0.write(1); b1.write(0);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(1); a1.write(0); b0.write(1); b1.write(1);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(1); a1.write(1); b0.write(0); b1.write(0);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(1); a1.write(1); b0.write(0); b1.write(1);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(1); a1.write(1); b0.write(1); b1.write(0);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	a0.write(1); a1.write(1); b0.write(1); b1.write(1);
	cout << sc_time_stamp() << ":\t A = " << a1 << " " << a0 << endl << "\t B= " << b1 <<" " << b0<< "\n\t Q= " << q1 << " " <<q0<< "\tcarry: "<<carry <<endl;
	cout << "--------------------------------------------------------" <<  endl;	
	sc_start(4, SC_NS);	

	sc_stop();

}
