/*
 * function: func_021BF0E4
 * address:  0x021BF0E4
 * packet:   pkt_ov021_021BF0E4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021877A8  0x021877A8  thumb  ov020
 *   func_02012374  0x02012374  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Evt;
extern void *func_021877A8(int a, int b, u8 c, u8 d, int e, int f);
extern void func_02012374(struct Evt *evt, struct Evt **out);

int func_021BF0E4(u32 p0, int *st, u8 *q)
{
    u32 a = *(u32 *)q;
    u32 b = *(u32 *)(q + 4);

    switch (*st) {
    case 0: {
        u32 r = (u32)func_021877A8(a, b, q[0x20], q[0x21], *(u32 *)(q + 0x24), *(u32 *)(q + 0x28));
        func_02012374((struct Evt *)p0, (struct Evt **)r);
        *st = *st + 1;
        break;
    }
    case 1:
        return 1;
    }
    return 0;
}
