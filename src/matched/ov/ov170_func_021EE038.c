/*
 * function: BOX2_UI_DeleteSlotObjects
 * address:  0x021EE038
 * packet:   pkt_ov170_021EE038
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 *   BOX2_SEQ_SetActorAutoAnim 0x021EBFCC thumb
 */
#include "../include/Obj00000.h"

extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern void BOX2_SEQ_SetActorAutoAnim(char *p, int i, int v);

void BOX2_UI_DeleteSlotObjects(char *p, int a, int b, int c)
{
    p[0x1F] = a;
    p[0x20] = b;
    p[0x21] = c;
    if (a == 0) {
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 1);
        BOX2_SEQ_SetActorAutoAnim(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 1);
    } else if (a == 1) {
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 0);
    } else {
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 1);
        BOX2_SEQ_SetActorAutoAnim(*(char * *)&((struct Obj00000 *)p)->f2C, 6, 0xF);
    }
    if (b == 0) {
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 1);
        BOX2_SEQ_SetActorAutoAnim(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 0);
    } else if (b == 1) {
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 0);
    } else {
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 1);
        BOX2_SEQ_SetActorAutoAnim(*(char * *)&((struct Obj00000 *)p)->f2C, 7, 0xE);
    }
    if (c == 0) {
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 1);
        BOX2_SEQ_SetActorAutoAnim(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 0);
    } else if (c == 1) {
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 0);
    } else {
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 1);
        BOX2_SEQ_SetActorAutoAnim(*(char * *)&((struct Obj00000 *)p)->f2C, 8, 2);
    }
}
