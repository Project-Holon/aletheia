/*
 * file:     unit_021937D0.c
 * unit:     yes
 * function: func_021937D0, func_02193848, func_02193874, func_02193908, func_0219398C, func_02193A0C, func_02193A90, func_02193B04, func_02193BD8, func_02193BF0, func_02193C0C, func_02193C3C, func_02193CB0, func_02193CD0
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
 *   TableEnter  0x0218474C  arm  ov009
 *   DoGet       0x02193CB0  arm  ov009
 *   g_buckets   0x021ADFD0  data
 *   func_02193CD0  0x02193CD0  arm  ov009
 *   func_02193C3C  0x02193C3C  arm  ov009
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
 *   _dflt  0x0209B750  arm
 *   g_021ADFD0  0x021ADFD0  data
 *   g_021ADFD4  0x021ADFD4  data
 *   g_021ADFD8  0x021ADFD8  data
 *   gsifree     0x0217EAE0  arm
 *   TableLookup  0x0218482C  arm  ov009
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
extern void TableEnter(struct HashImplementation *table, void *newElem);
extern void *DoGet(struct bucket_s *pbucket);
extern struct bucket_s *func_02193CD0(struct bucketset_s *set, char *name);
extern void *func_02193C3C(struct bucket_s *pbucket, void *value);
extern int func_0209477C(const u8 *s);
extern void *func_0217EAB0(unsigned long size);
extern char *func_02094798(char *dst, const char *src);
extern u8 *func_020948B0(u8 *dest, const u8 *src);
extern void func_0217EAE0(void *ptr);
extern void gsifree(void *ptr);
extern void *TableLookup(struct HashImplementation *table, void *elemKey);
void *BucketNew(struct bucketset_s *set, char *name, int type, void *initialvalue);
void *BucketSet(struct bucketset_s *set, char *name, void *value);
void *func_02193874(struct bucketset_s *set, char *name, void *value);
void *func_02193908(struct bucketset_s *set, char *name, void *value);
void *func_0219398C(struct bucketset_s *set, char *name, void *value);
void *func_02193A0C(struct bucketset_s *set, char *name, void *value);
void *func_02193A90(struct bucketset_s *set, char *name, void *value);
void *func_02193B04(struct bucketset_s *set, char *name, void *value);
char *func_02193BD8(int v);
void *func_02193BF0(double d);
char *stripchars(char *s);
void *DoSet(struct bucket_s *pbucket, void *value);
char *func_02193CB0(char *p);
struct bucket_s *DoFind(struct bucketset_s *set, char *name);
extern struct bucketset_s *g_buckets;
extern char g_021ADFD0[];
extern char g_021ADFD4[];
extern char g_021ADFD8[];




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



void *func_02193B04(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;
    int n;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    if (pbucket->type == 0) {
        int *cur = (int *)func_02193CB0((char *)pbucket);

        n = ++pbucket->nvals;
        return func_02193C3C(pbucket, func_02193BD8((n * *cur + *(int *)value) / n));
    }
    if (pbucket->type == 1) {
        double *cur = (double *)func_02193CB0((char *)pbucket);

        n = ++pbucket->nvals;
        return func_02193C3C(pbucket, func_02193BF0((*(double *)value + (double)n * *cur) / (double)n));
    }
    return func_02193CB0((char *)pbucket);
}




/*
 * Stores a word at +4 of the state object and returns the address of the next.
 */
char *func_02193BD8(int v)
{
    *(int *)(g_021ADFD0 + 4) = v;

    return g_021ADFD4;
}




/*
 * Stores a double at +8 of the state object and returns its address.
 */
/*
 * Stores two words at +8 and +0xc of the state object and returns +8 of it.
 */
void *func_02193BF0(double d)
{
    *(double *)(g_021ADFD0 + 8) = d;

    return g_021ADFD8;
}



char *stripchars(char *s)
{
    char *p = s;

    while (*s != 0)
    {
        if (*s == '\\')
            *s = '/';
        s++;
    }

    return p;
}




void *DoSet(struct bucket_s *pbucket, void *value)
{
    if (pbucket->type == 0)
    {
        pbucket->vals.i = *(int *)value;
    }
    else if (pbucket->type == 1)
    {
        pbucket->vals.d = *(double *)value;
    }
    else if (pbucket->type == 2)
    {
        if (pbucket->vals.s != 0)
            gsifree(pbucket->vals.s);
        pbucket->vals.s = (value != 0) ? stripchars(goastrdup(value)) : 0;
    }

    return DoGet(pbucket);
}



/*
 * Pointer at +0xc when the word at +4 is 2, otherwise +0xc itself; null in, null out.
 */
char *func_02193CB0(char *p)
{
    if (p == 0)
        return 0;
    if (*(int *)(p + 4) == 2)
        return *(char **)(p + 0xc);
    return p + 0xc;
}




struct bucket_s *DoFind(struct bucketset_s *set, char *name)
{
    struct bucket_s tbucket;

    if (set == 0)
        set = g_buckets;
    tbucket.name = name;

    return (struct bucket_s *)TableLookup(set->buckets, &tbucket);
}
