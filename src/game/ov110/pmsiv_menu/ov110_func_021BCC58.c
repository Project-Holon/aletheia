/*
 * function: func_021BCC58
 * address: 0x021BCC58
 * packet: pkt_ov110_021BCC58
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BCAD8 0x021BCAD8 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   func_021BF6DC 0x021BF6DC thumb ov110
 *   func_021BD248 0x021BD248 thumb ov110
 *   func_021BD264 0x021BD264 thumb ov110
 */
#include "../../../matched/include/Obj00295.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021BCAD8(void *);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern u8 func_021BF6DC(u8 *);
extern void func_021BD248(u8 *);
extern void func_021BD264(void *);
void func_021BCC58(u8 *p)
{
    func_021BCAD8(p);
    func_0204B3DC(((struct Obj00295 *)p)->f8C, 1);
    if (func_021BF6DC(*(u8 * *)&((struct Obj00295 *)p)->f4) == 0) func_021BD248(p);
    else func_021BD264(p);
}
