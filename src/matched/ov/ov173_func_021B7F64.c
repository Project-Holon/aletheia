/*
 * function: POKE_SUMMARY_ACTOR_UpdateScrollArrows
 * address: 0x021B7F64
 * packet: pkt_ov173_021B7F64
 * region: ov173
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   CURSOR_MOVE_ClearSkipBit 0x02026124 thumb
 *   CURSOR_MOVE_SetSkipBit 0x0202614C thumb
 */
#include "../include/Obj00180.h"
#include "../include/Obj24190.h"
#include "../include/Obj24191.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
struct Sound;
extern void CURSOR_MOVE_ClearSkipBit(struct Sound *obj, u32 idx);
extern void CURSOR_MOVE_SetSkipBit(struct Sound *obj, u32 idx);
void POKE_SUMMARY_ACTOR_UpdateScrollArrows(char *p)
{
    if (((struct Obj00180 *)p)->f1B8 < 4) {
        CURSOR_MOVE_ClearSkipBit(((struct Obj00180 *)p)->f1C8, 4);
        CURSOR_MOVE_ClearSkipBit(((struct Obj00180 *)p)->f1C8, 5);
        return;
    }
    if (((struct Obj24190 *)(*(char * *)&((struct Obj00180 *)p)->f0))->f16 == 0)
        CURSOR_MOVE_ClearSkipBit(((struct Obj00180 *)p)->f1C8, 5);
    else
        CURSOR_MOVE_SetSkipBit(((struct Obj00180 *)p)->f1C8, 5);
    if (((struct Obj24191 *)(*(char * *)&((struct Obj00180 *)p)->f0))->f16 + 4 >= ((struct Obj00180 *)p)->f1B8) {
        CURSOR_MOVE_ClearSkipBit(((struct Obj00180 *)p)->f1C8, 4);
        return;
    } else {
        CURSOR_MOVE_SetSkipBit(((struct Obj00180 *)p)->f1C8, 4);
        return;
    }
}
