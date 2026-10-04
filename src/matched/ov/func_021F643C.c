/*
 * function: func_021F643C
 * address:  0x021F643C
 * packet:   pkt_021F643C
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F4D14  0x021F4D14  thumb  ov135
 *   func_021F4CE4  0x021F4CE4  thumb  ov135
 *   func_021F6474  0x021F6474  thumb  ov135

 * Two-way mode dispatch: mode 1 clears and runs the sub-step, mode 2 clears, releases the +0xdd0 word and latches state 1.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
extern u32 func_021F4D14(u8 *p);
extern void func_021F4CE4(u8 *p);
extern void func_021F6474(u8 *p);
extern void func_0201F7A8(void *desc, u32 kind);

int func_021F643C(u8 *p)
{
    u32 k = func_021F4D14(p);

    if (k == 1) {
        func_021F4CE4(p);
        func_021F6474(p);
    } else if (k == 2) {
        func_021F4CE4(p);
        func_0201F7A8((void *)(*(u32 *)(p + 0xdd0)), 0);
        *(u32 *)(p + 0x28) = 1;
    }
    return 2;
}
