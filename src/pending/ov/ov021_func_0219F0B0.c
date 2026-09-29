/*
 * function: func_0219F0B0
 * address:  0x0219F0B0
 * packet:   pkt_ov021_0219F0B0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; blocked only by unlabelled arm9 leaf(s) (Ilias's), each verified EXACT from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
 *   func_0205082C:
 *   void func_0205082C(u8 *p, int i, u16 v)
 *   {
 *       u8 *e = *(u8 **)(p + 0x18) + i * 40;
 *       *(u16 *)(e + 0xe) = v;
 *       func_020500A0(e);   // 0x020500A0: extern void (u8 *), arm
 *   }
 *
 * symbols:
 *   func_0216E3C4  0x0216E3C4  thumb  ov010
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_0205082C  0x0205082C  arm
 *   func_0205085C  0x0205085C  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u8 *func_0216E3C4(u32);
extern u16 *func_0216D6F0(u32);
extern void func_0216D910(u32);
extern u32 func_0219C9DC(void);
extern void func_0205082C(u32, u32, u32);
extern void func_0205085C(u32, u32, u32);

void func_0219F0B0(u32 a, u32 b, u32 c)
{
    u16 *q;
    u32 r;
    if (func_0216E3C4(a)[2] == 1) {
        q = func_0216D6F0(a);
        if (*q != 0xFFFF) {
            func_0216D910(a);
            r = func_0219C9DC();
            func_0205082C(r, *q, b);
            func_0205085C(r, *q, c);
        }
    }
}
