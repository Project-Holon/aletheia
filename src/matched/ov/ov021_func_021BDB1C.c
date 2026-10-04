/*
 * function: func_021BDB1C
 * address:  0x021BDB1C
 * packet:   pkt_ov021_021BDB1C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_021BF644  0x021BF644  thumb  ov021
 *   func_021BDC80  0x021BDC80  thumb  ov021
 *   func_02012374  0x02012374  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_021BF644(int a, int b, int c);
extern void func_021BDC80(u32 *);
struct Evt;
extern void func_02012374(struct Evt *evt, struct Evt **out);

u32 func_021BDB1C(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[0];
    u32 x = *(u32 *)(p + 4);
    u32 y = *(u32 *)(p + 0xc);

    switch (*st) {
    case 0:
        func_02012374((struct Evt *)a, (struct Evt **)func_021BF644(0, x, y));
        (*st)++;
        break;
    case 1:
        func_021BDC80(ctx);
        return 1;
    }
    return 0;
}
