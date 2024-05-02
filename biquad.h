#ifndef BIQUAD_H
#define BIQUAD_H

#include <stdlib.h>

#include <x86intrin.h>

struct bq_cfs {
	double a1, a2;
	double b0, b1, b2;
};

struct bq_mo {
	double	       x1, x2;
	double	       y1, y2;
	struct bq_cfs *cfs;
};

struct bq_st {
	struct bq_mo l, r;
};

struct bq_staxv_cfs {
	__m128d a1, a2;
	__m128d b0, b1, b2;
};

struct bq_stavx {
	__m128d		     x1, x2;
	__m128d		     y1, y2;
	struct bq_stavx_cfs *cfs;
};

int bq_cfs_init(struct bq_cfs *cfs);

int bq_mo_init(struct bq_mo *flt, struct bq_cfs *cfs);

int bq_mo_proc(struct bq_mo *flt, double *smpl, size_t n);

int bq_st_init(struct bq_st *flt, struct bq_cfs **cfs);

int bq_st_proc(struct bq_st *flt, double *smpl, size_t n);

#endif // BIQUAD_H
