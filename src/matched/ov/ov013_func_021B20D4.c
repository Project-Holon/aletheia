/*
 * function: func_021B20D4
 * address:  0x021B20D4
 * packet:   pkt_ov013_021B20D4
 * region:   ov013
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021B60D8  0x021B60D8  data  a4
 *   func_021B2848  0x021B2848  arm  ov013
 *   func_021B29A4  0x021B29A4  arm  ov013
 *   func_021B2958  0x021B2958  arm  ov013
 */

#include "../include/G_Sess.h"

struct Chan {
    unsigned char pad[4];
    unsigned char f4;
    unsigned char pad5[3];
    unsigned int f8;
    int fc;
};

extern struct Sess g_021B60D8;
typedef unsigned char  u8;
struct Msg;
extern int func_021B2848(u8 *o, struct Msg *p, int n);
struct N;
extern int func_021B29A4(int *obj, const u8 *q);
extern int func_021B2958(struct N *p);

int func_021B20D4(struct Chan *a, unsigned int b, unsigned char *buf, unsigned int c)
{
    int z = 0;

    if (a == 0)
        return -1;
    if (c < 0x10)
        return -1;
    if (b >= 6)
        return -3;
    buf[4] = z;
    func_021B2848((u8 *)a, (struct Msg *)buf, b & 0xff);
    if (b == 0) {
        if (g_021B60D8.f10 == 1 && a->fc == 4) {
            if (func_021B2958((struct N *)a) == 0)
                return z - 3;
        }
        a->f8 = a->f4 ? 1 << a->f4 : 1;
    }
    if (func_021B29A4((int *)a, buf) == 0)
        return -3;
    return 0;
}
