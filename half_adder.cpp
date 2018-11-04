#include "half_adder.h"

void half_adder::prc_half_adder(void) {
	sum = a ^ b;
	carry = a & b;
}
