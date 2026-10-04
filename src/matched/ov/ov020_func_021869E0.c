/*
 * function: func_021869E0
 * address:  0x021869E0
 * packet:   pkt_ov020_021869E0
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0218682C  0x0218682C  thumb
 *   func_02186A2C  0x02186A2C  thumb
 *   func_02186818  0x02186818  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern char *func_0218682C(char *p);
extern int func_02186A2C(char *p, int id);
extern void func_02186818(u32 *p, u32 member);

char *func_021869E0(char *a, u32 limit, char *h, int *out)
{
    char *q;
    int i;
    u32 sum;
    int r;

    sum = 0;
    q = func_0218682C(h);
    for (i = 0; i < 30; i++) {
        r = func_02186A2C(a, i);
        func_02186818((u32 *)h, r);
        sum += *(u16 *)(q + 0x2C);
        if (sum > limit) {
            *out = r;
            return q;
        }
    }
    return q;
}
