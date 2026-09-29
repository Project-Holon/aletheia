/*
 * function: func_0219C880
 * address:  0x0219C880
 * packet:   pkt_ov021_0219C880
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Blocker: the only unresolved site is the call to func_020508D8
 * (0x020508D8, arm, arm9), an unlabelled arm9 leaf with no witness (Ilias's).
 * Verified C for the leaf (EXACT, dsi/1.1p1 -O4,p --arm --region arm9):
 *     u32 func_020508D8(u8 *o, u32 i)
 *     {
 *         return *(u16 *)(*(u8 **)(o + 0x18) + i * 0x28 + 4);
 *     }
 *
 * symbols:
 *   func_0219CBD4  0x0219CBD4  thumb  ov021
 *   func_020508D8  0x020508D8  arm
 *   func_02050278  0x02050278  arm
 *   func_0216DFC4  0x0216DFC4  thumb  ov010
 *   func_0219CB98  0x0219CB98  thumb  ov021

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_0219CBD4(u8 *, u32, u16 *, u16 *);
extern u32 func_020508D8();
extern void func_02050278();
extern int func_0216DFC4(u32, u32);
extern void func_0219CB98(u8 *, u32);

void func_0219C880(u8 *o, u32 a, u32 b, u32 c)
{
    u16 v[2];
    if (func_0219CBD4(o, c, &v[1], &v[0]) == 1) {
        if (v[0] & 2) {
            u32 t = func_020508D8(*(u32 *)(o + 4), b);
            func_02050278(*(u32 *)(o + 4), t, 1);
        }
        if (v[0] & 1) {
            if (func_0216DFC4(a, c) == 0)
                func_0219CB98(o, c);
        }
    }
}
