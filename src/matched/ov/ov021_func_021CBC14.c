/*
 * function: func_021CBC14
 * address:  0x021CBC14
 * packet:   pkt_ov021_021CBC14
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Shows the kind's message (20/21/22) with the +0x10 number capped at 9999 and reports whether it ended with 2 or 3.
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012ED8  0x02012ED8  thumb
 *   func_0200B6E0  0x0200B6E0  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern void *func_02158F54(void *a);
struct Big;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012ED8(struct Big *p);
extern int func_0200B6E0(void *t, int a, int id, int v, int z, u8 *b, u8 *c);

int func_021CBC14(u32 unused, u32 a)
{
    void *t;
    u8 *p;
    int id;
    int v;
    int r;

    t = func_020120F4(func_02158F54(func_0215A5F4((void *)a)));
    p = func_02012ED8(t);
    id = 20;
    v = *(u16 *)(p + 0x10);
    switch (p[9]) {
    case 0:
    case 4:
    case 5:
        break;
    case 1:
    case 6:
        id = 21;
        break;
    case 2:
    case 3:
    case 7:
    case 8:
        id = 22;
        break;
    }
    if (v > 9999)
        v = 9999;
    r = func_0200B6E0(t, 4, id, v, 0, p + 0x7e8, p + 0x7ea);
    if (r == 2 || r == 3)
        return 1;
    return 0;
}
