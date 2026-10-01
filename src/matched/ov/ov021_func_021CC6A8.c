/*
 * function: func_021CC6A8
 * address:  0x021CC6A8
 * packet:   pkt_ov021_021CC6A8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Script command: stores the current value of func_02010F18 in one variable and whether it changes away from 0x30 after a func_02010F40 round trip in another.
 *
 * symbols:
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_02010F18  0x02010F18  thumb
 *   func_02010F7C  0x02010F7C  thumb
 *   func_02010F40  0x02010F40  thumb
 *   func_02010F8C  0x02010F8C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *func_02159AE8(void *vm, void *ctx);
extern u16 func_02010F18(void);
extern void *func_02010F7C(u32 heap);
extern void func_02010F40(u16 v, void *p);
extern void func_02010F8C(void *p);

int func_021CC6A8(void *vm, void *ctx)
{
    u16 *a = func_02159AE8(vm, ctx);
    u16 *b = func_02159AE8(vm, ctx);
    void *p;

    *a = func_02010F18();
    if (*a != 0x30) {
        p = func_02010F7C(0x8015);
        func_02010F40(*a, p);
        func_02010F8C(p);
        *b = (func_02010F18() != 0x30) ? 1 : 0;
    } else {
        *b = 0;
    }
    return 0;
}
