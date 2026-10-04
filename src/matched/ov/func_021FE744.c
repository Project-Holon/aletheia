/*
 * function: func_021FE744
 * address:  0x021FE744
 * packet:   pkt_021FE744
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F513C  0x021F513C  thumb  ov135
 *   func_02006210  0x02006210  thumb
 *   func_0200FBB0  0x0200FBB0  thumb
 *   func_0200FBA0  0x0200FBA0  thumb
 *   func_0203CA04  0x0203CA04  arm
 *   func_0203C968  0x0203C968  arm
 *   func_021C866C  0x021C866C  arm
 *   func_021C86A8  0x021C86A8  arm
 *
 * 23-slot switch on the 0x021C86A8 index (case value = index + 15, so the
 * bound is 22): the +0xd0 archive with state 0x13 for indexes 15..22, the
 * state-0x1e group with the four redraw calls for 1 and 13, the shared redraw
 * for 2 and the state-0x16 pair for 0 and 3; 4..12 and 14 are table holes.
 * The counter in the else arm compares against 0x1c20, not 0xe10.
 * Concrete bytes are identical to the image; the only wildcards are the two
 * BLX sites to 0x021C866C and 0x021C86A8, which carry no func_ label in any
 * overlay listing (match.py's `label` class needs exactly one listing to
 * carry the label, so no region hint can witness them).  One-line fix:
 * trace 0x021C866C / 0x021C86A8 in layout/function_starts.txt and this
 * promotes automatically.
 
 *
 * UNBLOCKED: func_021C866C (0x021C866C) and func_021C86A8
 * (0x021C86A8) are now EXACT entries in layout/matched/ov114
 * (pkt_ov114_021C866C, pkt_ov114_021C86A8); both BLX sites
 * resolve as `matched`.  Verdict promoted to EXACT.
*/
#include "../include/Obj04907.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;

extern u32 func_021C866C(u8 *p);
extern s32 func_021C86A8(void);
extern void func_021F513C(u8 *p);
extern void func_02006210(void);
extern u32 func_0200FBB0(void);
extern void func_0200FBA0(void);
extern void func_0203CA04(void);
extern void func_0203C968(void);

int func_021FE744(u8 *p)
{
    s32 n;

    if (func_021C866C(p) != 0) {
        n = func_021C86A8();
        ((struct Obj04907 *)p)->fF8C = 0;
        switch (n + 15) {
        case 15:
        case 16:
        case 17:
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
            ((struct Obj04907 *)p)->fD0 = n;
            ((struct Obj04907 *)p)->f28 = 0x13;
            break;
        case 1:
        case 13:
            func_02006210();
            ((struct Obj04907 *)p)->f28 = 0x1e;
            func_0200FBB0();
            func_0203CA04();
            func_0200FBA0();
            func_0203C968();
            break;
        case 2:
            func_02006210();
            func_021F513C(p);
            break;
        case 0:
        case 3:
            func_02006210();
            ((struct Obj04907 *)p)->f28 = 0x16;
            break;
        }
    } else {
        if (++((struct Obj04907 *)p)->fF8C == 0x1c20) {
            func_02006210();
            func_021F513C(p);
        }
    }
    return 2;
}
