/*
 * function: func_0219F7CC
 * address:  0x0219F7CC
 * packet:   pkt_ov021_0219F7CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked at MATCH: func_02050880 (0x02050880) is an unlabelled arm9 leaf
 * (Ilias's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u16 func_02050880(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x10); }  (EXACT, verified)
 *
 * symbols:
 *   func_0205085C  0x0205085C  arm
 *   func_02050880  0x02050880  arm
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u16 *func_0216D6F0(u32);
extern int func_0216D910(int a0);
extern u32 func_0219C9DC(u32);
extern u32 func_02050880(u32, u32);
extern void func_0205085C(u32, u32, u32);

int func_0219F7CC(u32 a, u32 b)
{
    u32 idx;
    u16 *p;
    u32 h;
    u32 t;

    p =func_0216D6F0(a);
    if (*p == 0xFFFF) {
        return 0;
    }
    if (b < 0x18) {
        if (b < 6) idx = 0;
        else if (b < 0xC) idx = 1;
        else if (b < 0x12) idx = 2;
        else idx = 3;
    } else if (b < 0x28) {
        if (b < 0x1C) idx = 4;
        else if (b < 0x20) idx = 5;
        else if (b < 0x24) idx = 6;
        else idx = 7;
    } else if (b < 0x30) {
        if (b < 0x2A) idx = 8;
        else if (b < 0x2C) idx = 9;
        else if (b < 0x2E) idx = 10;
        else idx = 11;
    } else {
        idx = 12;
    }
    h = func_0219C9DC(func_0216D910(a));
    t = func_02050880(h, *p);
    if (t != idx) {
        func_0205085C(h, *p, 0);
    }
    return 1;
}
