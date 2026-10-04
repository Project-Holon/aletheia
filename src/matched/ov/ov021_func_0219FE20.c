/*
 * function: func_0219FE20
 * address:  0x0219FE20
 * packet:   pkt_ov021_0219FE20
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked at MATCH: func_020508EC (0x020508EC) is an unlabelled arm9 leaf
 * (Ilias's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u32 func_020508EC(u8 *p, int i, u16 *out) reads a u16 at record+0x1C, stores it, returns a range test; see the pending ov021 files that already name it
 *
 * symbols:
 *   func_020508EC  0x020508EC  arm
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u16 func_0216D598(void *p);
extern int func_0216D7A8(void *p, unsigned int v);
extern int func_0216D910(int a0);
extern u32 func_0219C9DC(u8 *p);
extern u32 func_020508EC(u8 *p, int i, u16 *out);

int func_0219FE20(u32 a)
{
    u32 t;
    u16 out;

    if (func_0216D598((void *)a) != 0x7B) {
        return 1;
    }
    t = (u16)func_0216D7A8((void *)a, 0);
    if (t != 0xFFFF) {
        if (func_020508EC((u8 *)func_0219C9DC((u8 *)func_0216D910(a)), t, &out) == 1) {
            return 1;
        }
    }
    return 0;
}
