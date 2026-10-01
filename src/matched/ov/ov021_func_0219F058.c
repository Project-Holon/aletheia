/*
 * function: func_0219F058
 * address:  0x0219F058
 * packet:   pkt_ov021_0219F058
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Leaf callees now filed; formerly MATCH. Leaf sources verified from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
 *   func_02050848:
 *   u16 func_02050848(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0xe); }
 *   func_02050880:
 *   u16 func_02050880(u8 *p, int i) { return *(u16 *)(*(u8 **)(p + 0x18) + i * 40 + 0x10); }
 *
 * symbols:
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_02050848  0x02050848  arm
 *   func_02050880  0x02050880  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u8 *func_0216E3C4(u32);
extern u16 *func_0216D6F0(u32);
extern void func_0216D910(u32);
extern u32 func_0219C9DC(void);
extern u16 func_02050848(u32, u32);
extern u16 func_02050880(u32, u32);

void func_0219F058(u32 a, u16 *o1, u16 *o2)
{
    u16 *q;
    u32 r;
    if (func_0216E3C4(a)[2] == 1) {
        q = func_0216D6F0(a);
        if (*q != 0xFFFF) {
            func_0216D910(a);
            r = func_0219C9DC();
            *o1 = func_02050848(r, *q);
            *o2 = func_02050880(r, *q);
        } else {
            *o1 = 0;
            *o2 = 0;
        }
    } else {
        *o1 = 0;
        *o2 = 0;
    }
}
