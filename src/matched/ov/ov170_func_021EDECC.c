/*
 * function: BOX2_UI_HideSlotIcon
 * address: 0x021EDECC
 * packet: pkt_ov170_021EDECC
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_WrapOffset 0x021DEB14 thumb ov170
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb ov170
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb ov170
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 */
#include "../include/Obj00000.h"
extern unsigned char BOX2_MAIN_WrapOffset(unsigned char *p, int a);
extern void BOX2_SEQ_GetActorSurfacePos(char *, int, short *, short *, unsigned short);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
void BOX2_UI_HideSlotIcon(unsigned char *p, int d)
{
    short t[2];
    if (d < 0 && p[0x14] == BOX2_MAIN_WrapOffset(p, -1)) {
        BOX2_SEQ_GetActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, 2, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, 2, t[1], -0x22, 0);
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 2, 1);
        return;
    }
    if (d > 0 && p[0x14] == BOX2_MAIN_WrapOffset(p, 4)) {
        BOX2_SEQ_GetActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, 2, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, 2, t[1], 0xcc, 0);
        BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 2, 1);
    }
}
