/*
 * function: BSUBWAY_RECORD_LIST_HandleAction
 * address:  0x021BA2D8
 * packet:   pkt_ov069_021BA2D8
 * region:   ov069
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BSUBWAY_RECORD_LIST_ChangePage  0x021BA400  thumb  ov069
 *   BSUBWAY_RECORD_LIST_ShowPage  0x021BA438  thumb  ov069
 *   func_020061E4  0x020061E4  thumb
 *   CLACT_SetActorAnimSeq  0x0204B878  arm
 */
#include "../include/Obj00432.h"

typedef unsigned int   u32;
extern int BSUBWAY_RECORD_LIST_ChangePage(char *p, int k);
extern void BSUBWAY_RECORD_LIST_ShowPage(char *p, int i);
extern void func_020061E4(u32 a);
typedef unsigned short u16;
struct Obj;
extern void CLACT_SetActorAnimSeq(struct Obj *p, u16 value);

void BSUBWAY_RECORD_LIST_HandleAction(char *o, int k)
{
    switch (k) {
    case 0:
        if (BSUBWAY_RECORD_LIST_ChangePage(o, k) != 0) {
            func_020061E4(0x548);
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00432 *)o)->f12C), 12);
            BSUBWAY_RECORD_LIST_ShowPage(o, ((struct Obj00432 *)o)->f160);
        }
        break;
    case 1:
        if (BSUBWAY_RECORD_LIST_ChangePage(o, k) != 0) {
            func_020061E4(0x548);
            CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00432 *)o)->f130), 13);
            BSUBWAY_RECORD_LIST_ShowPage(o, ((struct Obj00432 *)o)->f160);
        }
        break;
    case 2:
        ((struct Obj00432 *)o)->f158 = 2;
        CLACT_SetActorAnimSeq((struct Obj *)(((struct Obj00432 *)o)->f128), 9);
        break;
    }
}
