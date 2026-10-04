/*
 * function: func_021BD734
 * address:  0x021BD734
 * packet:   pkt_ov021_021BD734
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021BD8C0  0x021BD8C0  thumb  ov021
 *   func_021BD96C  0x021BD96C  thumb  ov021
 *   func_021BD94C  0x021BD94C  thumb  ov021
 *   func_021BD988  0x021BD988  thumb  ov021
 *   func_02161B1C  0x02161B1C  thumb  ov010
 *   func_02161B74  0x02161B74  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 func_021BD8C0(u32 *ctx);
extern void func_021BD96C(u32 *, u32);
extern void func_021BD94C(u32 *);
extern void func_021BD988(u32 *, u32);
extern int func_02161B1C(void *a);
extern int func_02161B74(int a0);
extern void func_020061E4(u32);

u32 func_021BD734(u32 a, int *st, u32 *ctx)
{
    u8 *p = (u8 *)ctx[2];
    u32 x = *(u32 *)(p + 0xc);

    switch (*st) {
    case 0:
        if (func_021BD8C0(ctx))
            func_021BD96C(ctx, a);
        else
            func_021BD94C(ctx);
        ctx[1] = func_02161B1C((void *)x);
        (*st)++;
        break;
    case 1:
        if (func_02161B74(ctx[1])) {
            if (*(int *)(p + 0x38) != 2)
                func_020061E4(0x559);
            func_021BD988(ctx, a);
            (*st)++;
        }
        break;
    case 2:
        return 1;
    }
    return 0;
}
