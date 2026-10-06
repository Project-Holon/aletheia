/*
 * function: func_021C03AC
 * address:  0x021C03AC
 * packet:   pkt_ov093_021C03AC
 * region:   ov093
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D62C4  0x021D62C4  thumb  ov093
 *   func_021C54FC  0x021C54FC  thumb  ov093
 *   func_021D7AF0  0x021D7AF0  thumb  ov093
 */
typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;
typedef signed char s8; typedef signed short s16; typedef signed int s32;

struct Unk021D62A8;
extern int func_021D62C4(struct Unk021D62A8 *p, int i);
extern void func_021C54FC(u8 *p, u8 *a);
extern int func_021D7AF0(u32 pct);

int func_021C03AC(u8 *p, u8 *a)
{
    if (func_021D62C4((struct Unk021D62A8 *)a, 7) != 0) {
        func_021C54FC(p, a);
        if (func_021D7AF0(50) != 0) return 1;
    }
    return 0;
}
