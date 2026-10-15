/*
 * function: BOX2_UI_AddSlotIcon
 * address:  0x021EDD38
 * packet:   pkt_ov170_021EDD38
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_GetActorSurfacePos 0x021EC0B0 thumb
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb
 *   BMP_OAM_GetPos 0x020258E8 thumb
 *   BMP_OAM_SetPos 0x0202590C thumb
 *   BOX2_MAIN_WrapOffset 0x021DEB14 thumb
 *   BOX2_UI_UploadSlotChar 0x021EDB64 thumb
 *   BOX2_SEQ_DrawMonName 0x021EB874 thumb
 *   BOX2_SEQ_GetActorDrawEnable 0x021EC01C thumb
 */
#include "../include/Obj00000.h"

extern void BOX2_SEQ_GetActorSurfacePos(char *p, int i, short *a, short *b, unsigned short space);
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
typedef signed short   s16;
struct Grid;
struct Obj02025774;
extern void BMP_OAM_GetPos(struct Obj02025774 *p, s16 *out_x, s16 *out_y);
extern void BMP_OAM_SetPos(struct Grid *g, s16 x, s16 y);
extern unsigned char BOX2_MAIN_WrapOffset(unsigned char *p, int a);
extern void BOX2_UI_UploadSlotChar(char *p, int a, int i);
extern void BOX2_SEQ_DrawMonName(char **p, unsigned a, int i);
typedef unsigned int   u32;
extern u32 BOX2_SEQ_GetActorDrawEnable(char *p, int i);

void BOX2_UI_AddSlotIcon(char *p, int d)
{
    short t[4];
    int step;
    int i;
    short x, y;
    int k;
    step = ((d < 0 ? -d : d) == 5) ? 2 : 8;
    if (d < 0)
        step *= -1;
    for (i = 0; i < 6u; i++) {
        BOX2_SEQ_GetActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2D, &t[3], &t[2], 0);
        x = t[2] + step;
        BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2D, (short)t[3], (short)x, (short)0);
        BMP_OAM_GetPos(*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C + i * 8 + 0xC), &t[1], &t[0]);
        y = t[0] + step;
        BMP_OAM_SetPos(*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C + i * 8 + 0xC), t[1], y);
        if (x < -0x10) {
            k = BOX2_MAIN_WrapOffset((unsigned char *)p, 4);
            BOX2_UI_UploadSlotChar(p, k, i + 0x2D);
            BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2D, (short)t[3], (short)(x + 0xCC), (short)0);
            BOX2_SEQ_DrawMonName((char **)p, k, i + 1);
            BMP_OAM_SetPos(*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C + i * 8 + 0xC), t[1], y + 0xCC);
        } else if (x >= 0xBA) {
            k = BOX2_MAIN_WrapOffset((unsigned char *)p, -1);
            BOX2_UI_UploadSlotChar(p, k, i + 0x2D);
            BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, i + 0x2D, (short)t[3], (short)(x - 0xCC), (short)0);
            BOX2_SEQ_DrawMonName((char **)p, k, i + 1);
            BMP_OAM_SetPos(*(void **)(*(char * *)&((struct Obj00000 *)p)->f2C + i * 8 + 0xC), t[1], y - 0xCC);
        }
    }
    if (BOX2_SEQ_GetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 2) == 1) {
        BOX2_SEQ_GetActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, 2, &t[3], &t[2], 0);
        BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, 2, (short)t[3], (short)(t[2] + step), (short)0);
    }
}
