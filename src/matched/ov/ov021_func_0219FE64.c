/*
 * function: func_0219FE64
 * address:  0x0219FE64
 * packet:   pkt_ov021_0219FE64
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216D598  0x0216D598  thumb  ov010
 *   func_0216D7A8  0x0216D7A8  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0205085C  0x0205085C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern int func_0216D598(u32);
extern u32 func_0216D7A8(u32, u32);
extern int func_0216D910(int a0);
extern u32 func_0219C9DC(u32);
extern void func_0205085C(u32, u32, u16);

void func_0219FE64(u32 a)
{
    u16 v;
    u16 z;
    if (func_0216D598(a) == 0x7B) {
        z = 0;
        v = func_0216D7A8(a, 0);
        if (v != 0xFFFF) {
            func_0205085C(func_0219C9DC(func_0216D910(a)), v, z);
        }
    }
}
