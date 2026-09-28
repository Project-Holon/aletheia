/*
 * function: goastrdup
 * address:  0x0217F1E0
 * packet:   pkt_ov009_0217F1E0
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      goastrdup (gsplatformutil.o)
 *
 * symbols:
 *   strlen     0x0209477C  arm
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   memcpy     0x02092344  arm
 */

extern int strlen(char *s);
extern void *gsimalloc(unsigned long size);
extern void *memcpy(void *dst, void *src, unsigned long n);

char *goastrdup(char *src)
{
    unsigned long len;
    char *res;

    if (src == 0)
        return 0;
    len = strlen(src);
    res = (char *)gsimalloc(len + 1);
    if (res != 0)
        memcpy(res, src, len + 1);

    return res;
}
