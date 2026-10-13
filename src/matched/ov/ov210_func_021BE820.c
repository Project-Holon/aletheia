/*
 * function: func_021BE820
 * address:  0x021BE820
 * packet:   pkt_021BE820
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BMP_Clear  0x02043B5C  arm  arm9
 *   BMP_WIN_TransferChars  0x02045334  arm  arm9
 * Addresses are Black-image addresses.
 */
#include "../include/Obj14681.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *);

void func_021BE820(u8 *p)
{
    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj14681 *)p)->f154)), 0);
    BMP_WIN_TransferChars((struct Descriptor *)((struct Obj14681 *)p)->f154);
}

