/*
 * function: BucketDiv
 * address:  0x02193A0C
 * packet:   pkt_ov009_02193A0C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      BucketDiv (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 *
 * symbols:
 *   func_02193CD0  0x02193CD0  arm  ov009
 *   DoGet  0x02193CB0  arm  ov009
 *   bint  0x02193BD8  arm  ov009
 *   func_02193C3C  0x02193C3C  arm  ov009
 *   bfloat  0x02193BF0  arm  ov009
 *   _s32_div_f  0x0209C0A4  arm
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
extern char *DoGet(char *p);
extern char *bint(int v);
extern void *func_02193C3C(struct bucket_s *pbucket, void *value);
extern void *bfloat(double f);

void *BucketDiv(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    if (pbucket->type == 0)
        return func_02193C3C(pbucket, bint(*(int *)DoGet((char *)pbucket) / *(int *)value));
    if (pbucket->type == 1)
        return func_02193C3C(pbucket, bfloat(*(double *)DoGet((char *)pbucket) / *(double *)value));
    return DoGet((char *)pbucket);
}
