/*
 * function: func_021BCA78
 * address:  0x021BCA78
 * packet:   pkt_ov210_021BCA78
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0202CA0C  0x0202CA0C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
struct WinMgr;
extern void func_0202CA0C(struct WinMgr *mgr);

void func_021BCA78(u8 *p)
{
    func_0202CA0C(*(struct WinMgr **)(p + 0x20));
}
