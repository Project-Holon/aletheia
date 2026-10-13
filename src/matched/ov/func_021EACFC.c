/*
 * function: func_021EACFC
 * address:  0x021EACFC
 * packet:   pkt_021EACFC
 * region:   ov170
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BMP_WIN_GetBmp  0x02045770  arm
 *   BMP_Clear  0x02043B5C  arm
 *   func_021EABD0  0x021EABD0  thumb  ov170
 */
#include "../include/Obj02053.h"
#include "../include/Obj18510.h"
typedef unsigned char u8;
typedef unsigned int u32;

struct Descriptor;
extern void *BMP_WIN_GetBmp(struct Descriptor *p);
struct CharBuf;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void func_021EABD0(unsigned char *w, int i, void *bank, unsigned idx, int x, int y, unsigned font, unsigned short color);

void func_021EACFC(u8 *p)
{
    u8 *q = *(u8 * *)&((struct Obj18510 *)p)->f2C;

    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02053 *)q)->fE4)), 0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02053 *)q)->fEC)), 0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02053 *)q)->fF4)), 0);
    BMP_Clear((struct CharBuf *)((u32)BMP_WIN_GetBmp((struct Descriptor *)((struct Obj02053 *)q)->fFC)), 0);
    func_021EABD0(q, 0xa, (void *)(((struct Obj02053 *)q)->f80), 0x6d, 0, 0, ((struct Obj02053 *)q)->f78, 0x440);
    func_021EABD0(q, 0xb, (void *)(((struct Obj02053 *)q)->f80), 0x64, 0, 0, ((struct Obj02053 *)q)->f78, 0x440);
    func_021EABD0(q, 0xc, (void *)(((struct Obj02053 *)q)->f80), 0x65, 0, 0, ((struct Obj02053 *)q)->f78, 0x440);
    func_021EABD0(q, 0xd, (void *)(((struct Obj02053 *)q)->f80), 0x66, 0, 0, ((struct Obj02053 *)q)->f78, 0x440);
}
