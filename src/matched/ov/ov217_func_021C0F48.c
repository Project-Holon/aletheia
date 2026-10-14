/*
 * function: BgTextLabel_Destroy
 * address:  0x021C0F48
 * packet:   pkt_021B9850
 * region:   ov217
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Two-call wrapper: field +0x18, then the object itself.
 *
 * symbols:
 *   BgTextLabel_Destroy  0x021C0F48  thumb  ov217
 *   BMP_WIN_Delete  0x020452E8  arm  arm9
 *
 * Addresses are Black-image addresses.
 */
#include "../include/Obj26004.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;
typedef signed short   s16;
typedef signed int     s32;

struct Descriptor;
extern u32 BMP_WIN_Delete(struct Descriptor *d);
extern u32 func_020307B0(void *p);
void BgTextLabel_Destroy(u8 *p)
{
    BMP_WIN_Delete((struct Descriptor *)(((struct Obj26004 *)p)->f18));
    func_020307B0(p);
}

