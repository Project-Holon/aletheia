/*
 * function: func_021BD874
 * address:  0x021BD874
 * packet:   pkt_ov021_021BD874
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD94C  0x021BD94C  thumb  ov021
 *   func_021BE8D4  0x021BE8D4  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 *   func_02012374  0x02012374  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BD94C(u32 *);
struct Evt;
extern int func_021BE8D4(void *a, int b, int sel, int d);
extern void func_020061E4(u32);
extern void func_02012374(struct Evt *evt, struct Evt **out);

u32 func_021BD874(u32 a, int *st, u32 *ctx)
{
    u32 *p = (u32 *)ctx[2];
    u32 x = p[1];
    u32 y = p[3];

    switch (*st) {
    case 0:
        func_021BD94C(ctx);
        func_020061E4(0x737);
        func_02012374((struct Evt *)a, (struct Evt **)func_021BE8D4((void *)x, y, 2, 0));
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
