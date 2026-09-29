/*
 * function: func_021B2620
 * address:  0x021B2620
 * packet:   pkt_ov013_021B2620
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021B60D8  0x021B60D8  data  ov013  a4
 *   d_021B4BD0  0x021B4BD0  data  ov013  a4
 *   func_021B25FC  0x021B25FC  arm  ov013
 *   func_02176E90  0x02176E90  arm  ov009
 */

typedef unsigned char u8;

typedef struct Ctx {
    u8 b0;
} Ctx;

typedef struct Stat {
    int f0;
    unsigned int mask;
} Stat;

extern Ctx d_021B60D8;
extern Stat d_021B4BD0;
extern void func_021B25FC(int *o, u8 *p);
extern int func_02176E90(int i, u8 *p, int n);

int func_021B2620(int *o, u8 *p)
{
    int cnt;
    u8 i;

    cnt = 0;
    func_021B25FC(o, p);
    for (i = 0; i < 0x20; i++) {
        unsigned int m = (i != 0) ? (1 << i) : 1;
        if ((d_021B4BD0.mask & m) != 0 && i != d_021B60D8.b0) {
            p[9] = i;
            if (func_02176E90(i, p, 0x10) != 0)
                cnt++;
        }
    }
    if (p[10] == 1)
        o[2] = d_021B4BD0.mask;
    else if (p[10] == 0)
        o[2] = 0;
    return cnt == 0 ? -4 : 0;
}
