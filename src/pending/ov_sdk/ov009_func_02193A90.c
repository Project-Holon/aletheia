/*
 * function: BucketConcat
 * address:  0x02193A90
 * packet:   pkt_ov009_02193A90
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 *
 * sdk:      BucketConcat (gbucket.o)
 *
 * Byte-correct (116/116); one relocation site stays wildcarded.
 * Blocker: strcat @ 0x020948B0 is an unlabelled ARM9 leaf (a .word run in
 * asm/arm9/src/029_0208CB10.s), so `label` and `sole-ref/code` both refuse
 * it; it is arm9 / game, not the same region, so it is out of this lane.
 * --suggest-split reports the range is NOT viable and drops BucketConcat
 * entirely (no partition of a single function can help).
 *
 * symbols:
 *   DoFind     0x02193CD0  arm  ov009
 *   DoGet      0x02193CB0  arm  ov009
 *   strlen     0x0209477C  arm
 *   gsimalloc  0x0217EAB0  arm
 *   strcpy     0x02094798  arm
 *   strcat     0x020948B0  arm
 *   DoSet      0x02193C3C  arm  ov009
 *   gsifree    0x0217EAE0  arm
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
extern void *DoGet(struct bucket_s *pbucket);
extern int strlen(char *s);
extern void *gsimalloc(unsigned long size);
extern char *strcpy(char *dst, char *src);
extern char *strcat(char *dst, char *src);
extern void *DoSet(struct bucket_s *pbucket, void *value);
extern void gsifree(void *ptr);

void *BucketConcat(struct bucketset_s *set, char *name, void *value)
{
    struct bucket_s *pbucket;
    char *s;
    char *temp;

    pbucket = DoFind(set, name);
    if (pbucket == 0)
        return 0;
    s = (char *)DoGet(pbucket);
    temp = (char *)gsimalloc(strlen(s) + strlen(value) + 1);
    strcpy(temp, s);
    strcat(temp, value);
    DoSet(pbucket, temp);
    gsifree(temp);

    return DoGet(pbucket);
}
