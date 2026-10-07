/*
 * file:     unit_021937D0_p03.c
 * unit:     yes
 * function: func_02193C0C, func_02193C3C, func_02193CB0, func_02193CD0
 * address:  0x02193C0C
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
 *   gsifree     0x0217EAE0  arm
 *   goastrdup   0x0217F1E0  arm
 *   DoGet       0x02193CB0  arm  ov009
 *   TableLookup  0x0218482C  arm  ov009
 *   g_buckets    0x021ADFD0  data
 */
struct HashImplementation;
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

extern void gsifree(void *ptr);
extern char *goastrdup(char *src);
extern void *DoGet(struct bucket_s *pbucket);
extern void *TableLookup(struct HashImplementation *table, void *elemKey);
char *stripchars(char *s);
void *DoSet(struct bucket_s *pbucket, void *value);
char *func_02193CB0(char *p);
struct bucket_s *DoFind(struct bucketset_s *set, char *name);
extern struct bucketset_s *g_buckets;

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
