/*
 * function: BOX2_UI_SetMiniIconVisible
 * address:  0x021EE008
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_SEQ_DrawOffsetName  0x021EB85C  thumb  ov170
 *   BOX2_UI_ShowMiniIcon  0x021EDFC4  thumb  ov170
 *   BOX2_SEQ_SetActorDrawEnable  0x021EC000  thumb  ov170
 *   BMP_OAM_SetEnabled  0x02025774  thumb  arm9
 *
 * Two-way: with flag 1 run the pair update, otherwise release slot 3
 *   and post 0 to the p+0x2c+4 object.
 */
#include "../include/Obj00000.h"


extern void BOX2_SEQ_DrawOffsetName(unsigned char *p, int i);
extern void BOX2_UI_ShowMiniIcon(char *, int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void BOX2_SEQ_SetActorDrawEnable(char *p, int i, int v);
extern void BMP_OAM_SetEnabled(u8 *g, u32 a);
void BOX2_UI_SetMiniIconVisible(char *p, int a, int b)
{
    if (b == 1) {
        BOX2_SEQ_DrawOffsetName((unsigned char *)p, a);
        BOX2_UI_ShowMiniIcon(p, a);
        return;
    }
    BOX2_SEQ_SetActorDrawEnable((char *)(*(int *)&((struct Obj00000 *)p)->f2C), 3, 0);
    BMP_OAM_SetEnabled((u8 *)(*(int *)(*(int *)&((struct Obj00000 *)p)->f2C + 4)), 0);
}
