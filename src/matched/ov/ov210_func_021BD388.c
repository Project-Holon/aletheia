/*
 * function: func_021BD388
 * address:  0x021BD388
 * packet:   pkt_ov210_021BD388
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   ZUKAN_InitQuery  0x021C9380  thumb  ov212
 *   func_021BE564  0x021BE564  thumb  ov210
 *   func_021BEDF0  0x021BEDF0  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00222.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
struct Blk37;
extern void ZUKAN_InitQuery(struct Blk37 *p, u8 *out);
extern void func_021BE564(u8 *p);
extern void func_021BEDF0(int p, int i, int v);

u32 func_021BD388(u8 *p)
{
    u32 *ctx = *(u32 * *)&((struct Obj00222 *)p)->f0;

    ZUKAN_InitQuery((struct Blk37 *)ctx[1], (u8 *)ctx[2]);
    func_021BE564(p);
    func_021BEDF0((int)p, 7, 0);
    return 4;
}
