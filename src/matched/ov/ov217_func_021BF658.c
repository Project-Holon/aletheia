/*
 * function: func_021BF658
 * address: 0x021BF658
 * packet: pkt_ov217_021BF658
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0202173C 0x0202173C thumb
 */
#include "../include/Obj00021.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
struct PalAnmObj;
extern int func_0202173C(struct PalAnmObj *,u16,u16,s16,u8,u8,u16,void *);
void func_021BF658(char *p)
{
    func_0202173C(*(struct PalAnmObj * *)&((struct Obj00021 *)p)->f3B8,1,0xffff,3,7,0,0xffff,((struct Obj00021 *)p)->f3BC);
    func_0202173C(*(struct PalAnmObj * *)&((struct Obj00021 *)p)->f3B8,4,0xffff,3,7,0,0xffff,((struct Obj00021 *)p)->f3BC);
}
