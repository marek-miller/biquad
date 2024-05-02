#include "biquad.h"
#include <stdlib.h>

int bq_cfs_init(struct bq_cfs *cfs)
{
	cfs->a1 = 0.0;
	cfs->a2 = 0.0;

	cfs->b0 = 1.0;
	cfs->b1 = 0.0;
	cfs->b2 = 0.0;

	return 0;
}

int bq_mo_init(struct bq_mo *flt, struct bq_cfs *cfs)
{
	flt->x1 = 0.0;
	flt->x2 = 0.0;
	flt->y1 = 0.0;
	flt->y2 = 0.0;

	flt->cfs = cfs;

	return 0;
}

static int bq_mo_proc_step(
	struct bq_mo *flt, double *smpl, size_t n, size_t step)
{
	double x, y;

	for (size_t i = 0; i < n; i++) {
		x	= flt->x1;
		flt->x1 = flt->x2;
		flt->x2 = *(smpl + i * step);

		y = flt->cfs->b0 * x + flt->cfs->b1 * flt->x1 +
		    flt->cfs->b2 * flt->x2 - flt->cfs->a1 * flt->y1 -
		    flt->cfs->a2 * flt->y2;

		flt->y2		   = flt->y1;
		flt->y1		   = y;
		*(smpl + i * step) = y;
	}

	return 0;
}

int bq_mo_proc(struct bq_mo *flt, double *smpl, size_t n)
{
	return bq_mo_proc_step(flt, smpl, n, 1);
}

int bq_st_init(struct bq_st *flt, struct bq_cfs **cfs)
{
	bq_mo_init(&flt->l, cfs[0]);
	bq_mo_init(&flt->r, cfs[1]);

	return 0;
}

int bq_st_proc(struct bq_st *flt, double *smpl, size_t n)
{
	bq_mo_proc_step(&flt->l, smpl, n, 2);
	bq_mo_proc_step(&flt->r, smpl + 1, n, 2);

	return 0;
}
