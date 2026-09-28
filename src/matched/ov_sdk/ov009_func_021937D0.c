/*
 * function: BucketNew
 * address:  0x021937D0
 * packet:   pkt_ov009_021937D0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      BucketNew (gbucket.o)
 *
 * symbols:
 *   goastrdup   0x0217F1E0  arm
 *   DoSet       0x02193C3C  arm  ov009
 *   TableEnter  0x0218474C  arm  ov009
 *   DoFind      0x02193CD0  arm  ov009
 *   DoGet       0x02193CB0  arm  ov009
 *   g_buckets   0x021ADFD0  data
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

extern char *goastrdup(char *src);
extern void *DoSet(struct bucket_s *pbucket, void *value);
extern void TableEnter(struct HashImplementation *table, void *newElem);
extern struct bucket_s *DoFind(struct bucketset_s *set, char *name);
extern void *DoGet(struct bucket_s *pbucket);
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
