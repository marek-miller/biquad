#ifndef BIQUAD_H
#define BIQUAD_H

#include <stdlib.h>

struct bq_cfs {
	double a1, a2;
	double b0, b1, b2;
};

struct bq_mono {
	double	       x1, x2;
	double	       y1, y2;
	struct bq_cfs *cfs;
};

struct bq_stereo {
	struct bq_mono l, r;
};

int bq_cfs_init(struct bq_cfs *cfs);

int bq_mono_init(struct bq_mono *flt, struct bq_cfs *cfs);

int bq_mono_proc(struct bq_mono *flt, double *smpl, size_t n);

int bq_stereo_init(struct bq_stereo *flt, struct bq_cfs **cfs);

int bq_stereo_proc(struct bq_stereo *flt, double *smpl, size_t n);

#endif // BIQUAD_H
