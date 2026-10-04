/*
 * function: func_02194384
 * address:  0x02194384
 * packet:   pkt_ov021_02194384
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D854  0x0216D854  thumb  ov010
 *   func_02163C04  0x02163C04  thumb  ov010
 */

typedef unsigned short u16;
typedef short s16;

extern int func_0216D854(void *p);
extern int func_02163C04(int a, int x, int y, int flag);

int func_02194384(u16 *a, s16 b, int c, s16 d, int *e, unsigned *f)
{
    unsigned n = *a;
    unsigned char *q;
    short dlt;

    if (*f < n) {
        q = *(unsigned char **)(a + 4) + *f * 0xc;
        do {
            (*f)++;
            if (*(void **)(q + 8) != 0) {
                dlt = func_0216D854(*(void **)(q + 8)) - c;
                if (dlt < 0)
                    dlt = -dlt;
                if (dlt < 1) {
                    if (func_02163C04((int)(*(void **)(q + 8)), b, d, 1)) {
                        *e = *(int *)q;
                        return 1;
                    }
                }
                q += 0xc;
            }
        } while (*f < n);
    }
    return 0;
}
