/*
 * function: func_0219398C
 * address:  0x0219398C
 * packet:   pkt_ov009_0219398C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      BucketMult (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 *
 * symbols:
 *   func_02193CD0  0x02193CD0  arm  ov009
 *   func_02193CB0  0x02193CB0  arm  ov009
 *   func_02193BD8  0x02193BD8  arm  ov009
 *   func_02193C3C  0x02193C3C  arm  ov009
 *   func_02193BF0  0x02193BF0  arm  ov009
 *   _dmul  0x0209B2E8  arm
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
extern void *func_02193BD8(int i);
extern void *func_02193C3C(struct bucket_s *pbucket, void *value);
extern void *func_02193BF0(double f);

void *func_0219398C(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    if (pbucket->type == 0)
        return func_02193C3C(pbucket, func_02193BD8(*(int *)value * *(int *)func_02193CB0(pbucket)));
    if (pbucket->type == 1)
        return func_02193C3C(pbucket, func_02193BF0(*(double *)value * *(double *)func_02193CB0(pbucket)));
    return func_02193CB0(pbucket);
}
