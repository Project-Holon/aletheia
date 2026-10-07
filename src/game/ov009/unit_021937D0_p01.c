/*
 * file:     unit_021937D0_p01.c
 * unit:     yes
 * function: func_021937D0, func_02193848, func_02193874, func_02193908, func_0219398C, func_02193A0C, func_02193A90
 * address:  0x021937D0
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   goastrdup   0x0217F1E0  arm
 *   DoSet       0x02193C3C  arm  ov009
 *   TableEnter  0x0218474C  arm  ov009
 *   DoFind      0x02193CD0  arm  ov009
 *   DoGet       0x02193CB0  arm  ov009
 *   g_buckets   0x021ADFD0  data
 *   func_02193CD0  0x02193CD0  arm  ov009
 *   func_02193CB0  0x02193CB0  arm  ov009
 *   func_02193BD8  0x02193BD8  arm  ov009
 *   func_02193C3C  0x02193C3C  arm  ov009
 *   func_02193BF0  0x02193BF0  arm  ov009
 *   _dadd  0x0209AC04  arm
 *   _dsub  0x0209AF34  arm
 *   _dmul  0x0209B2E8  arm
 *   _s32_div_f  0x0209C0A4  arm
 *   _ddiv  0x0209D1E0  arm
 *   func_0209477C  0x0209477C  arm
 *   func_0217EAB0  0x0217EAB0  arm  ov009
 *   func_02094798  0x02094798  arm
 *   func_020948B0  0x020948B0  arm
 *   func_0217EAE0  0x0217EAE0  arm  ov009
 */
struct HashImplementation;
struct bucketset_s;
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

struct bucketset_s {
    struct HashImplementation *buckets;
};

typedef unsigned char  u8;

extern char *goastrdup(char *src);
extern void *DoSet(struct bucket_s *pbucket, void *value);
extern void TableEnter(struct HashImplementation *table, void *newElem);
extern struct bucket_s *DoFind(struct bucketset_s *set, char *name);
extern void *DoGet(struct bucket_s *pbucket);
extern struct bucket_s *func_02193CD0(struct bucketset_s *set, char *name);
extern char *func_02193CB0(char *p);
extern char *func_02193BD8(int v);
extern void *func_02193C3C(struct bucket_s *pbucket, void *value);
extern void *func_02193BF0(double f);
extern int func_0209477C(const u8 *s);
extern void *func_0217EAB0(unsigned long size);
extern char *func_02094798(char *dst, const char *src);
extern u8 *func_020948B0(u8 *dest, const u8 *src);
extern void func_0217EAE0(void *ptr);
void *BucketNew(struct bucketset_s *set, char *name, int type, void *initialvalue);
void *BucketSet(struct bucketset_s *set, char *name, void *value);
void *func_02193874(struct bucketset_s *set, char *name, void *value);
void *func_02193908(struct bucketset_s *set, char *name, void *value);
void *func_0219398C(struct bucketset_s *set, char *name, void *value);
void *func_02193A0C(struct bucketset_s *set, char *name, void *value);
void *func_02193A90(struct bucketset_s *set, char *name, void *value);
extern struct bucketset_s *g_buckets;


void *BucketNew(struct bucketset_s *set, char *name, int type, void *initialvalue)
{
    struct bucket_s bucket;

    if (set == 0)
        set = g_buckets;
    bucket.name = goastrdup(name);
    bucket.type = type;
    bucket.vals.p = 0;
    bucket.nvals = 1;
    DoSet(&bucket, initialvalue);
    TableEnter(set->buckets, &bucket);

    return DoGet(DoFind(set, name));
}


void *BucketSet(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;

    pbucket = DoFind(set, name);
    if (pbucket == 0)
        return 0;
    pbucket->nvals = 0;

    return DoSet(pbucket, value);
}


/*
 * sdk:      BucketAdd (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 */
void *func_02193874(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    if (pbucket->type == 0)
        return func_02193C3C(pbucket, func_02193BD8(*(int *)value + *(int *)func_02193CB0((char *)pbucket)));
    if (pbucket->type == 1)
        return func_02193C3C(pbucket, func_02193BF0(*(double *)value + *(double *)func_02193CB0((char *)pbucket)));
    return func_02193A90(set, name, value);
}


/*
 * sdk:      BucketSub (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 */
void *func_02193908(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    if (pbucket->type == 0)
        return func_02193C3C(pbucket, func_02193BD8(*(int *)func_02193CB0((char *)pbucket) - *(int *)value));
    if (pbucket->type == 1)
        return func_02193C3C(pbucket, func_02193BF0(*(double *)func_02193CB0((char *)pbucket) - *(double *)value));
    return func_02193CB0((char *)pbucket);
}


/*
 * sdk:      BucketMult (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 */
void *func_0219398C(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    if (pbucket->type == 0)
        return func_02193C3C(pbucket, func_02193BD8(*(int *)value * *(int *)func_02193CB0((char *)pbucket)));
    if (pbucket->type == 1)
        return func_02193C3C(pbucket, func_02193BF0(*(double *)value * *(double *)func_02193CB0((char *)pbucket)));
    return func_02193CB0((char *)pbucket);
}


/*
 * sdk:      BucketDiv (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 */
void *func_02193A0C(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    if (pbucket->type == 0)
        return func_02193C3C(pbucket, func_02193BD8(*(int *)func_02193CB0((char *)pbucket) / *(int *)value));
    if (pbucket->type == 1)
        return func_02193C3C(pbucket, func_02193BF0(*(double *)func_02193CB0((char *)pbucket) / *(double *)value));
    return func_02193CB0((char *)pbucket);
}


/*
 * strcat (func_020948B0, arm9) attests as matched through unit_02094860, whose
 * functions list names func_020948B0 since 2026-09-29 (w4_nm).
 *
 * sdk:      BucketConcat (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 */
void *func_02193A90(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;
    char *s;
    char *temp;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    s = (char *)func_02193CB0((char *)pbucket);
    temp = (char *)func_0217EAB0(func_0209477C((const u8 *)s) + func_0209477C(value) + 1);
    func_02094798(temp, s);
    func_020948B0((u8 *)temp, value);
    func_02193C3C(pbucket, temp);
    func_0217EAE0(temp);

    return func_02193CB0((char *)pbucket);
}
