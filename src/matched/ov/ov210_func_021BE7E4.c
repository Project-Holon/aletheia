/*
 * function: func_021BE7E4
 * address:  0x021BE7E4
 * packet:   pkt_ov210_021BE7E4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02045770  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_021BE44C  0x021BE44C  thumb  ov210
 *   func_021BE49C  0x021BE49C  thumb  ov210
 * Addresses are Black-image addresses.
 */
#include "../include/Obj00222.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef signed int     s32;
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_021BE44C(u8 *p, int slot, u32 message, int x, int y, u16 color, u32 mode);
extern void func_021BE49C(u8 *p);

void func_021BE7E4(u8 *p)
{
    u32 z = 0;

    BMP_Clear((struct CharBuf *)((u32)func_02045770((struct Descriptor *)*(u32 *)&((struct Obj00222 *)p)->f154)), 0);
    func_021BE44C(p, 1, 1, 0, 4, 0x440, z);
    func_021BE49C(p + 0x154);
}
