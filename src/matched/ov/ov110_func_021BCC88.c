/*
 * function: func_021BCC88
 * address: 0x021BCC88
 * packet: pkt_ov110_021BCC88
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021BCAD8 0x021BCAD8 thumb ov110
 *   func_0204B3DC 0x0204B3DC arm
 *   CLACT_SetActorAnimSeq 0x0204B878 arm
 */
#include "../include/Obj00295.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef unsigned int u32;
extern void func_021BCAD8(void *);
struct Obj;
extern void func_0204B3DC(struct Obj *p, u32 v);
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);
void func_021BCC88(u8 *p)
{
    func_021BCAD8(p);
    func_0204B3DC(((struct Obj00295 *)p)->f28, 1);
    CLACT_SetActorAnimSeq(((struct Obj00295 *)p)->f28, 1);
    ((struct Obj00295 *)p)->f2C = 0;
}
