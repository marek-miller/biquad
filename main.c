#include <stdio.h>

#include "biquad.h"


int main(void) {

	struct bq_coeffs cfs;
	bq_coeffs_init(&cfs);

	struct bq_mono flt;
	bq_mono_init(&flt, &cfs);

	return 0;
}
