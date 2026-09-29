/*
 * function: func_0219F128
 * address:  0x0219F128
 * packet:   pkt_ov021_0219F128
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Byte-correct; blocked only by unlabelled arm9 leaf(s) (Ilias's), each verified EXACT from a scratch
 * file (region arm9, --arm, dsi/1.1p1 -O4,p; typedefs u8/u16/u32):
 *   func_02050080:
 *   u32 func_02050080(u8 *p) { return *(u32 *)(p + 4); }
 *
 * symbols:
 *   func_0216D6F0  0x0216D6F0  thumb  ov010
 *   func_0216D910  0x0216D910  thumb  ov010
 *   func_0219C9DC  0x0219C9DC  thumb  ov021
 *   func_02197CCC  0x02197CCC  thumb  ov021
 *   func_0219FFBC  0x0219FFBC  thumb  ov021
 *   func_02050080  0x02050080  arm
 *   func_0204F638  0x0204F638  arm
 *   func_0219FEB0  0x0219FEB0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;
extern u16 *func_0216D6F0(u32);
extern void func_0216D910(u32);
extern u32 func_0219C9DC(void);
extern void func_02197CCC(u32, s32 *);
extern void func_0219FFBC(u32, s32 *);
extern u32 func_02050080(u32);
extern void func_0204F638(u32, u32, s32 *);
extern void func_0219FEB0(u16 *, u32, u32, u32);

void func_0219F128(u32 a)
{
    s32 buf[3];
    u16 *q;
    u32 r;
    q = func_0216D6F0(a);
    if (*q != 0xFFFF) {
        func_0216D910(a);
        r = func_0219C9DC();
        func_0219FEB0(q + 2, a, r, *q);
    func_02197CCC(a, buf);
    func_0219FFBC(a, buf);
    r = func_02050080(r);
    func_0204F638(r, *q, buf);
    }
}
