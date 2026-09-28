/*
 * function: DoFind
 * address:  0x02193CD0
 * packet:   pkt_ov009_02193CD0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DoFind (gbucket.o)
 *
 * symbols:
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

extern void *TableLookup(struct HashImplementation *table, void *elemKey);
extern struct bucketset_s *g_buckets;

struct bucket_s *DoFind(struct bucketset_s *set, char *name)
{
    struct bucket_s tbucket;

    if (set == 0)
        set = g_buckets;
    tbucket.name = name;

    return (struct bucket_s *)TableLookup(set->buckets, &tbucket);
}
