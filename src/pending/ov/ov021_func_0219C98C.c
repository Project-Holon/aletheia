/*
 * function: func_0219C98C
 * address:  0x0219C98C
 * packet:   pkt_ov021_0219C98C
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
 *   func_0216D520  0x0216D520  thumb  ov010
 *   func_020508D8  0x020508D8  arm
 *   func_02050278  0x02050278  arm
 *   func_02050468  0x02050468  arm

 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *func_0216D520(u32);
extern u32 func_020508D8();
extern void func_02050278();
extern void func_02050468();

void func_0219C98C(u32 a, u16 *b)
{
    u8 *c = func_0216D520(a);
    if (b[1] != 0xFFFF) {
        if (b[0] & 2) {
            u32 t = func_020508D8(*(u32 *)(c + 4), b[1]);
            func_02050278(*(u32 *)(c + 4), t, 1);
        }
        func_02050468(*(u32 *)(c + 4), b[1], 1);
    }
    b[0] = 0;
    b[1] = 0xFFFF;
}
