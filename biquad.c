#include <stdlib.h>
#include "biquad.h"


int bq_coeffs_init(struct bq_coeffs *cfs) {

	cfs->a1 = 0.0;
	cfs->a2 = 0.0;

	cfs->b0 = 1.0;
	cfs->b1 = 0.0;
	cfs->b2 = 0.0;

	return 0;
}

int bq_mono_init(struct bq_mono *flt, struct bq_coeffs *cfs) {

	flt->x1 = 0.0;
	flt->x2 = 0.0;
	flt->y1 = 0.0;
	flt->y2 = 0.0;
	flt->cfs = cfs;
	
	return 0;
}

int bq_mono_proc(struct bq_mono *flt, double *smpl, size_t n) {

	double x, y;

	for (size_t i = 0; i < n; i++) {
		x	= flt->x1;
		flt->x1	= flt->x2;
		flt->x2	= *(smpl + i);

		y = flt->cfs->b0 * x 
			+ flt->cfs->b1 * flt->x1 
			+ flt->cfs->b2 * flt->x2
			- flt->cfs->a1 * flt->y1 
			- flt->cfs->a2 * flt->y2;
		
		
		flt->y2	= flt->y1;
		flt->y1	= y;
		*(smpl + i) = y;
	}

	return 0;
}
