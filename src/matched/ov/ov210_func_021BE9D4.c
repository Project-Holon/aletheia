/*
 * function: func_021BE9D4
 * address:  0x021BE9D4
 * packet:   pkt_021BE9D4
 * region:   ov210
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_Clear  0x02043B5C  arm
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   func_021BE44C  0x021BE44C  thumb ov210
 *   func_021BE49C  0x021BE49C  thumb ov210
 *   func_021BEA54  0x021BEA54  thumb ov210
 */
#include "../include/Obj00222.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *);
typedef unsigned short u16;
extern void func_021BE44C(u8 *p, int slot, u32 message, int x, int y, u16 color, u32 mode);
extern void func_021BE49C(u8 *p);
extern void func_021BEA54(u8 *p);

void func_021BE9D4(u8 *p)
{
    func_021BE49C(p + 0x14C);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj00222 *)p)->f154)), 0);
    func_021BE44C(p, 1, 6, 0, 4, 0x440, 0);
    func_021BE49C(p + 0x154);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)*(u32 *)&((struct Obj00222 *)p)->f1AC)), 0);
    func_021BE44C(p, 0xC, 0xE, 0x28, 0, 0x3C40, 2);
    func_021BE49C(p + 0x1AC);
    func_021BEA54(p);
}
