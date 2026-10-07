/*
 * file:     unit_0217F130_p02.c
 * unit:     yes
 * function: func_0217F1CC, func_0217F1E0, func_0217F21C
 * address:  0x0217F1CC
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
 *   strlen     0x0209477C  arm
 *   gsimalloc  0x0217EAB0  arm  ov009
 *   memcpy     0x02092344  arm
 *   g_020A60DC     0x020A60DC  data
 */
extern void func_0217EAE0(void *p);
extern int strlen(char *s);
extern void *gsimalloc(unsigned long size);
extern void *memcpy(void *dst, void *src, unsigned long n);
int func_0217F1CC(int *p);
char *goastrdup(char *src);
char *func_0217F21C(char *s);
extern unsigned char g_020A60DC[];


/*
 * Saves the word at +4, calls the helper and returns it.
 */
int func_0217F1CC(int *p)
{
    int v = p[1];

    func_0217EAE0(p);

    return v;
}


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


/*
 * In-place character remap: for every byte of the NUL-terminated string at
 * s that is a non-negative value below 0x80, replace it with the byte at
 * the same index in the 128-entry table at 0x020A60DC; leave negative and
 * high bytes alone.  Returns s.
 */
char *func_0217F21C(char *s)
{
    char *ret = s;
    int c = *s;

    if (c != 0) {
        do {
            if (c >= 0 && c < 0x80) {
                c = g_020A60DC[c];
            }
            *s = c;
            c = *++s;
        } while (c != 0);
    }
    return ret;
}
