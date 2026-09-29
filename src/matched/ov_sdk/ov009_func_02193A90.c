/*
 * function: func_02193A90
 * address:  0x02193A90
 * packet:   pkt_ov009_02193A90
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * strcat (func_020948B0, arm9) attests as matched through unit_02094860, whose
 * functions list names func_020948B0 since 2026-09-29 (w4_nm).
 *
 * sdk:      BucketConcat (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 *
 * symbols:
 *   func_02193CD0  0x02193CD0  arm  ov009
 *   func_02193CB0  0x02193CB0  arm  ov009
 *   func_0209477C  0x0209477C  arm
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02094798  0x02094798  arm
 *   func_020948B0  0x020948B0  arm
 *   func_02193C3C  0x02193C3C  arm  ov009
 *   func_0217EAE0  0x0217EAE0  arm  ov009
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
extern int func_0209477C(char *s);
extern void *func_0217EAB0(unsigned long size);
extern char *func_02094798(char *dst, char *src);
extern char *func_020948B0(char *dst, char *src);
extern void *func_02193C3C(struct bucket_s *pbucket, void *value);
extern void func_0217EAE0(void *ptr);

void *func_02193A90(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;
    char *s;
    char *temp;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    s = (char *)func_02193CB0(pbucket);
    temp = (char *)func_0217EAB0(func_0209477C(s) + func_0209477C(value) + 1);
    func_02094798(temp, s);
    func_020948B0(temp, value);
    func_02193C3C(pbucket, temp);
    func_0217EAE0(temp);

    return func_02193CB0(pbucket);
}
