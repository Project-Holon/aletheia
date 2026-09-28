/*
 * function: DoSet
 * address:  0x02193C3C
 * packet:   pkt_ov009_02193C3C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      DoSet (gbucket.o)
 *
 * symbols:
 *   gsifree     0x0217EAE0  arm
 *   goastrdup   0x0217F1E0  arm
 *   stripchars  0x02193C0C  arm  ov009
 *   DoGet       0x02193CB0  arm  ov009
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

extern void gsifree(void *ptr);
extern char *goastrdup(char *src);
extern char *stripchars(char *s);
extern void *DoGet(struct bucket_s *pbucket);

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
