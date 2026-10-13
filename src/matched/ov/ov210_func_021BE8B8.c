/*
 * function: func_021BE8B8
 * address: 0x021BE8B8
 * packet: pkt_ov210_021BE8B8
 * region: ov210
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: raw 0x1B4 accesses retain the offset in r6; a named enum swaps
 *        the offset with the implicit zero in r4.
 * symbols:
 *   BMP_WIN_GetBmp 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   func_021BE44C 0x021BE44C thumb ov210
 *   func_021BE49C 0x021BE49C thumb ov210
 */
#include "../include/Obj00222.h"
typedef unsigned char u8;
struct Descriptor;
struct CharBuf;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
extern void BMP_Clear(struct CharBuf *, u8);
extern void func_021BE44C(u8 *, int, unsigned, int, int, unsigned short, unsigned);
extern void func_021BE49C(u8 *);
void func_021BE8B8(u8 *p)
{
    BMP_Clear(BMP_WIN_GetBmp(*(struct Descriptor * *)&((struct Obj00222 *)p)->f1B4), 0);
    func_021BE44C(p, 13, (*(u8 **)(*(u8 * *)&((struct Obj00222 *)p)->f0 + 8))[1] + 25, 48, 0, 0x3c40, 2);
    func_021BE49C(p + 0x1b4);
}
