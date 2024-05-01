#ifndef BIQUAD_H
#define BIQUAD_H

#include <stdlib.h>

struct bq_coeffs {
	double a1, a2;
	double b0, b1, b2;
};


struct bq_mono {
	double x1, x2;
	double y1, y2;
	struct bq_coeffs *cfs;
};


int bq_coeffs_init(struct bq_coeffs *cfs);
int bq_mono_init(struct bq_mono *flt, struct bq_coeffs *cfs);
int bq_mono_proc(struct bq_mono *flt, double *smpl, size_t n);

#endif // BIQUAD_H
