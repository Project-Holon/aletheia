/*
 * function: func_021C72AC
 * address:  0x021C72AC
 * packet:   pkt_ov021_021C72AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02188C84  0x02188C84  thumb  ov021
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_021C6C70  0x021C6C70  thumb  ov021
 *   func_021C6CCC  0x021C6CCC  thumb  ov021
 *   func_021C7500  0x021C7500  thumb  ov021
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 func_02188C84(u32 a);
extern void *func_02188CB4(unsigned char *p);
extern void *func_021A3074(unsigned char *p);
extern void *func_021C6C70(u32 h, int size, void *fn);
extern u8 *func_021C6CCC(void *o);
extern void func_021C7500(void);

void *func_021C72AC(u32 a, u16 b, int c, int d)
{
    void *o;
    u8 *p;
    u32 h;
    void *q;

    h = func_02188C84(a);
    q = func_02188CB4((void *)a);
    o = func_021C6C70(h, 0x10, (void *)func_021C7500);
    p = func_021C6CCC(o);
    *(u32 *)(p + 0) = a;
    *(u32 *)(p + 4) = func_021A3074((void *)q);
    *(u16 *)(p + 8) = 0;
    *(u16 *)(p + 0xa) = b;
    p[0xc] = c;
    *(u16 *)(p + 0xe) = d;
    return o;
}
