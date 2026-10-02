/*
 * function: func_0216EF84
 * address:  0x0216EF84
 * packet:   pkt_0216EF84
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012F2C  0x02012F2C  thumb
 *   func_02008DF0  0x02008DF0  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;

extern void *func_020120F4(const struct Ctx *p);
extern int func_02012F2C();
extern int func_02008DF0();

int func_0216EF84(int a0, int a1)
{
    int t4;
    void *p;

t4 = *(int *)((char *)a0 + 8);
a0 = *(int *)((char *)a0);
    p = func_020120F4((const struct Ctx *)a0);
loc_0216EF8E:
    a0 = func_02012F2C(p);
loc_0216EF92:
a1 = *(int *)((char *)t4);
    if (a1 != 0) goto loc_0216EFA6;
loc_0216EF98:
t4 = t4 + 0x8c;
a1 = *(int *)((char *)t4);
    if (a1 != 4) goto loc_0216EFA6;
loc_0216EFA0:
a1 = 0x4f;
    a0 = func_02008DF0(a0, a1);
loc_0216EFA6:
    return a0;}
