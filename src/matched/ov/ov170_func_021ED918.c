/*
 * function: BOX2_UI_MoveSlotIcon
 * address: 0x021ED918
 * packet: pkt_ov170_021ED918
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: Two trailing zero bytes at 0x021ED9B2 are alignment padding.
 * symbols:
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb ov170
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb ov170
 *   BMP_OAM_GetPos 0x020258E8 thumb
 *   BMP_OAM_SetPos 0x0202590C thumb
 */
#include "../include/Obj03849.h"
extern void BOX2_SEQ_GetActorSurfacePos(char *, int, short *, short *, unsigned short);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
typedef signed short   s16;
struct Grid;
struct Obj02025774;
extern void BMP_OAM_GetPos(struct Obj02025774 *p, s16 *out_x, s16 *out_y);
extern void BMP_OAM_SetPos(struct Grid *g, s16 x, s16 y);
void BOX2_UI_MoveSlotIcon(char *p, int d)
{
    short t[2];
    int i = 0;
    BOX2_SEQ_GetActorSurfacePos(*(char * *)&((struct Obj03849 *)p)->f2C, 2, &t[1], &t[0], 0);
    BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj03849 *)p)->f2C, 2, (short)(t[1] - d), (short)t[0], (short)0);
    for (; i < 6u; i++) {
        BOX2_SEQ_GetActorSurfacePos(*(char * *)&((struct Obj03849 *)p)->f2C, i + 0x2d, &t[1], &t[0], 0);
        BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj03849 *)p)->f2C, i + 0x2d, (short)(t[1] - d), (short)t[0], (short)0);
        BMP_OAM_GetPos(*(void **)(*(char * *)&((struct Obj03849 *)p)->f2C + i * 8 + 0xc), &t[1], &t[0]);
        BMP_OAM_SetPos(*(void **)(*(char * *)&((struct Obj03849 *)p)->f2C + i * 8 + 0xc), t[1] - d, t[0]);
    }
}
