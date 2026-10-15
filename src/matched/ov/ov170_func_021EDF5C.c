/*
 * function: BOX2_UI_DeleteSlotIcon
 * address:  0x021EDF5C
 * packet:   pkt_ov170_021EDF5C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_MAIN_WrapOffset 0x021DEB14 thumb
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb
 */
#include "../include/Obj00000.h"

extern unsigned char BOX2_MAIN_WrapOffset(unsigned char *p, int a);
extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);

void BOX2_UI_DeleteSlotIcon(unsigned char *p)
{
    unsigned i;
    short xy[2];
    for (i = 0; i < 6; i++) {
        if (p[0x14] == BOX2_MAIN_WrapOffset(p, (signed char)(i - 1))) {
            BOX2_SEQ_GetActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, 2, &xy[1], &xy[0], 0);
            BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, 2, (short)xy[1], (short)(i * 0x22), (short)0);
            BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 2, 1);
            return;
        }
    }
    BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 2, 0);
}
