#include <stdio.h>

#include "biquad.h"

int main(void)
{
	struct bq_cfs cfs;
	bq_cfs_init(&cfs);

	struct bq_stereo flt;
	bq_stereo_init(&flt, (struct bq_cfs *[]){ &cfs, &cfs });

	return 0;
}
