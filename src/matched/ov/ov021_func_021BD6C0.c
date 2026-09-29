/*
 * function: func_021BD6C0
 * address:  0x021BD6C0
 * packet:   pkt_ov021_021BD6C0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD94C  0x021BD94C  thumb  ov021
 *   func_021BD988  0x021BD988  thumb  ov021
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_021BD94C(u32 *);
extern void func_021BD988(u32 *, u32);
extern void func_020061E4(u32);

u32 func_021BD6C0(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];

    switch (*st) {
    case 0:
        func_021BD94C(ctx);
        if (*(int *)(p + 0x38) != 2)
            func_020061E4(0x559);
        func_021BD988(ctx, a);
        (*st)++;
        break;
    case 1:
        return 1;
    }
    return 0;
}
