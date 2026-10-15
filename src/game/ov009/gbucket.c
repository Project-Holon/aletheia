/*
 * file:     gbucket.c
 * unit:     yes
 * function: func_021937D0, func_02193848, BucketAdd, BucketSub, BucketMult, BucketDiv, BucketConcat, BucketAvg, bint, bfloat, func_02193C0C, func_02193C3C, DoGet, func_02193CD0
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
 *   strlen  0x0209477C  arm
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   strcpy  0x02094798  arm
 *   strcat  0x020948B0  arm
 *   gsifree  0x0217EAE0  arm  ov009
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
extern struct bucket_s *func_02193CD0(struct bucketset_s *set, char *name);
extern void *func_02193C3C(struct bucket_s *pbucket, void *value);
extern int strlen(const u8 *s);
extern void *gsimalloc(unsigned long size);
extern char *strcpy(char *dst, const char *src);
extern u8 *strcat(u8 *dest, const u8 *src);
extern void gsifree(void *ptr);
extern void gsifree(void *ptr);
extern void *TableLookup(struct HashImplementation *table, void *elemKey);
void *BucketNew(struct bucketset_s *set, char *name, int type, void *initialvalue);
void *BucketSet(struct bucketset_s *set, char *name, void *value);
void *BucketAdd(struct bucketset_s *set, char *name, void *value);
void *BucketSub(struct bucketset_s *set, char *name, void *value);
void *BucketMult(struct bucketset_s *set, char *name, void *value);
void *BucketDiv(struct bucketset_s *set, char *name, void *value);
void *BucketConcat(struct bucketset_s *set, char *name, void *value);
void *BucketAvg(struct bucketset_s *set, char *name, void *value);
char *bint(int v);
void *bfloat(double d);
char *stripchars(char *s);
void *DoSet(struct bucket_s *pbucket, void *value);
char *DoGet(char *p);
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

    return DoGet((char *)DoFind(set, name));
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
void *BucketAdd(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    if (pbucket->type == 0)
        return func_02193C3C(pbucket, bint(*(int *)value + *(int *)DoGet((char *)pbucket)));
    if (pbucket->type == 1)
        return func_02193C3C(pbucket, bfloat(*(double *)value + *(double *)DoGet((char *)pbucket)));
    return BucketConcat(set, name, value);
}




/*
 * sdk:      BucketSub (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 */
void *BucketSub(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    if (pbucket->type == 0)
        return func_02193C3C(pbucket, bint(*(int *)DoGet((char *)pbucket) - *(int *)value));
    if (pbucket->type == 1)
        return func_02193C3C(pbucket, bfloat(*(double *)DoGet((char *)pbucket) - *(double *)value));
    return DoGet((char *)pbucket);
}




/*
 * sdk:      BucketMult (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 */
void *BucketMult(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    if (pbucket->type == 0)
        return func_02193C3C(pbucket, bint(*(int *)value * *(int *)DoGet((char *)pbucket)));
    if (pbucket->type == 1)
        return func_02193C3C(pbucket, bfloat(*(double *)value * *(double *)DoGet((char *)pbucket)));
    return DoGet((char *)pbucket);
}




/*
 * sdk:      BucketDiv (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 */
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




/*
 * strcat (strcat, arm9) attests as matched through unit_02094860, whose
 * functions list names strcat since 2026-09-29 (w4_nm).
 *
 * sdk:      BucketConcat (libdwcgsgstats.TWL.HYB.a(gbucket.o))
 */
void *BucketConcat(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;
    char *s;
    char *temp;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    s = (char *)DoGet((char *)pbucket);
    temp = (char *)gsimalloc(strlen((const u8 *)s) + strlen(value) + 1);
    strcpy(temp, s);
    strcat((u8 *)temp, value);
    func_02193C3C(pbucket, temp);
    gsifree(temp);

    return DoGet((char *)pbucket);
}



void *BucketAvg(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;
    int n;

    pbucket = func_02193CD0(set, name);
    if (pbucket == 0)
        return 0;
    if (pbucket->type == 0) {
        int *cur = (int *)DoGet((char *)pbucket);

        n = ++pbucket->nvals;
        return func_02193C3C(pbucket, bint((n * *cur + *(int *)value) / n));
    }
    if (pbucket->type == 1) {
        double *cur = (double *)DoGet((char *)pbucket);

        n = ++pbucket->nvals;
        return func_02193C3C(pbucket, bfloat((*(double *)value + (double)n * *cur) / (double)n));
    }
    return DoGet((char *)pbucket);
}




/*
 * Stores a word at +4 of the state object and returns the address of the next.
 */
char *bint(int v)
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
void *bfloat(double d)
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

    return DoGet((char *)pbucket);
}



/*
 * Pointer at +0xc when the word at +4 is 2, otherwise +0xc itself; null in, null out.
 */
char *DoGet(char *p)
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
