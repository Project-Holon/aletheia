/*
 * function: func_021C32FC
 * address: 0x021C32FC
 * packet: pkt_ov208_021C32FC
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 */
#include "../include/Obj00146.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct PrintSys; struct Descriptor; struct CharBuf;
extern void func_0201C6EC(struct PrintSys *print);
extern void *func_02045770(struct Descriptor *p);
extern void BMP_Clear(struct CharBuf *p, u8 v);
void func_021C32FC(u16 *heap, u8 *p, int key)
{
    ((struct Obj00146 *)p)->f10 = 0;
    func_0201C6EC(*(struct PrintSys * *)&((struct Obj00146 *)p)->f8);
    BMP_Clear(func_02045770(*(struct Descriptor * *)&((struct Obj00146 *)p)->fC), 0);
}
