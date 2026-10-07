/*
 * function: func_021F8668
 * address: 0x021F8668
 * packet: pkt_ov135_021F8668
 * region: ov135
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021F8554 0x021F8554 thumb ov135
 */
#include "../../../matched/include/Obj06510.h"
#include "../../../matched/include/Obj06511.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_021F8554(u8 *dst, void *p);
void func_021F8668(u8 *dst, u8 *p)
{
    func_021F8554(dst, p);
    ((struct Obj06510 *)dst)->fEC = ((struct Obj06511 *)p)->fB4C;
    ((struct Obj06510 *)dst)->fEE = ((struct Obj06511 *)p)->fB4E;
    ((struct Obj06510 *)dst)->fF0 = ((struct Obj06511 *)p)->fB50;
    ((struct Obj06510 *)dst)->fF2 = ((struct Obj06511 *)p)->fB52;
    ((struct Obj06510 *)dst)->fF4 = ((struct Obj06511 *)p)->fB54;
}
