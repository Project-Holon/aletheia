/*
 * function: func_02193B04
 * address:  0x02193B04
 * packet:   pkt_ov009_02193B04
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      BucketAvg (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 *
 * symbols:
 *   func_02193CD0  0x02193CD0  arm  ov009
 *   func_02193CB0  0x02193CB0  arm  ov009
 *   func_02193BD8  0x02193BD8  arm  ov009
 *   func_02193C3C  0x02193C3C  arm  ov009
 *   func_02193BF0  0x02193BF0  arm  ov009
 *   _s32_div_f  0x0209C0A4  arm
 *   _dflt  0x0209B750  arm
 *   _dmul  0x0209B2E8  arm
 *   _dadd  0x0209AC04  arm
 *   _ddiv  0x0209D1E0  arm
 */

struct bucket_s {
    char *name;
    int type;
    int nvals;
    union {
        int i;
        double d;
        char *s;
        void *p;
    } vals;
};

struct bucketset_s;

extern struct bucket_s *func_02193CD0(struct bucketset_s *set, char *name);
extern void *func_02193CB0(struct bucket_s *pbucket);
extern char *func_02193BD8(int v);
extern void *func_02193C3C(struct bucket_s *pbucket, void *value);
extern void *func_02193BF0(double f);

void *func_02193B04(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;
    int n;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    if (pbucket->type == 0) {
        int *cur = (int *)func_02193CB0(pbucket);

        n = ++pbucket->nvals;
        return func_02193C3C(pbucket, func_02193BD8((n * *cur + *(int *)value) / n));
    }
    if (pbucket->type == 1) {
        double *cur = (double *)func_02193CB0(pbucket);

        n = ++pbucket->nvals;
        return func_02193C3C(pbucket, func_02193BF0((*(double *)value + (double)n * *cur) / (double)n));
    }
    return func_02193CB0(pbucket);
}
