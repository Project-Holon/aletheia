/*
 * function: func_021E11B4
 * address: 0x021E11B4
 * packet: pkt_ov137_021E11B4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02030DA8 0x02030DA8 arm
 *   func_021E11A0 0x021E11A0 thumb ov137
 */
#include "../include/Obj14246.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_02082BCC(void *, int, unsigned);
extern void *func_02030DA8(void *, void (*)(void *, u8 *), void *, int);
extern void func_021E11A0(void *, u8 *);
void func_021E11B4(char *p)
{
    func_02082BCC(p + 0xc74, 0, 20);
    ((struct Obj14246 *)p)->fD88 = func_02030DA8(((struct Obj14246 *)p)->fD98, func_021E11A0, p, 255);
}
