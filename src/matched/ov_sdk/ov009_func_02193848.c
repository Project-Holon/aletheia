/*
 * function: BucketSet
 * address:  0x02193848
 * packet:   pkt_ov009_02193848
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      BucketSet (gbucket.o)
 *
 * symbols:
 *   DoFind  0x02193CD0  arm  ov009
 *   DoSet   0x02193C3C  arm  ov009
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

extern struct bucket_s *DoFind(struct bucketset_s *set, char *name);
extern void *DoSet(struct bucket_s *pbucket, void *value);

void *BucketSet(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;

    pbucket = DoFind(set, name);
    if (pbucket == 0)
        return 0;
    pbucket->nvals = 0;

    return DoSet(pbucket, value);
}
