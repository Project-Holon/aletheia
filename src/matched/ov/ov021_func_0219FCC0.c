/*
 * function: func_0219FCC0
 * address:  0x0219FCC0
 * packet:   pkt_ov021_0219FCC0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Blocked at MATCH: func_02050848 (0x02050848), func_02050880 (0x02050880) is an unlabelled arm9 leaf
 * (the integrator's, inside a labelled arm9 function) with no witness outside this range.
 * Leaf C for the arm9 owner:
 *   u16 func_02050848(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0xe); }  (EXACT, verified)
 *   u16 func_02050880(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x10); }  (EXACT, verified)
 *
 * symbols:
 *   func_02050848  0x02050848  arm
 *   func_02050880  0x02050880  arm
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern u16 func_0216D598(void *p);
extern void *func_0216D6F0(void *p);
extern int func_0216D910(int a0);
extern u32 func_0219C9DC(u8 *p);
extern u16 func_02050848(u8 *p, int i);
extern u16 func_02050880(u8 *p, int i);

int func_0219FCC0(u32 a, u16 *o1, u16 *o2)
{
    u16 *p;
    u32 h;

    if ((u16)(func_0216D598((void *)a) + 0xFF23) <= 1) {
        p = func_0216D6F0((void *)a);
        if (*p != 0xFFFF) {
            h = func_0219C9DC((u8 *)func_0216D910(a));
            *o1 = func_02050848((u8 *)h, *p);
            *o2 = func_02050880((u8 *)h, *p);
            return 1;
        }
        return 0;
    }
    *o1 = 0;
    *o2 = 0;
    return 1;
}
