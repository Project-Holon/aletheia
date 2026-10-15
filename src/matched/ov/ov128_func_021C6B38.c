/*
 * function: Wf2dmapFriend_ClearWindow
 * address:  0x021C6B38
 * packet:   pkt_021C6B38
 * region:   ov128
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_ClearScreen  0x020456F8  arm
 *   BMP_WIN_GetBgLayer  0x02045730  arm
 *   func_02041B6C  0x02041B6C  arm
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14046.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

struct Descriptor;
extern void BMP_WIN_ClearScreen(struct Descriptor *d);
extern u8 BMP_WIN_GetBgLayer(struct Descriptor *p);
extern void func_02041B6C(u32);

void Wf2dmapFriend_ClearWindow(u8 *p)
{
    void *q = ((struct Obj14046 *)p)->fC;
    BMP_WIN_ClearScreen(q);
    func_02041B6C(BMP_WIN_GetBgLayer(q));
}
