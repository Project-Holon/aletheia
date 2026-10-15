/*
 * function: BOX2_UI_ShowMiniIcon
 * address: 0x021EDFC4
 * packet: pkt_ov170_021EDFC4
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   d_021EFCD8 0x021EFCD8 data a2
 *   BOX2_SEQ_AddActorSurfacePos 0x021EC08C thumb ov170
 *   BOX2_SEQ_SetActorDrawEnable 0x021EC000 thumb ov170
 *   BMP_OAM_SetPos 0x0202590C thumb
 *   BMP_OAM_SetEnabled 0x02025774 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj24025.h"
#include "../include/Obj24026.h"
extern const short d_021EFCD8[];
extern void BOX2_SEQ_AddActorSurfacePos(char *p, int i, int a, int b, unsigned short c);
extern void BOX2_SEQ_SetActorDrawEnable(char *, int, int);
typedef signed short   s16;
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Grid;
extern void BMP_OAM_SetPos(struct Grid *g, s16 x, s16 y);
extern void BMP_OAM_SetEnabled(u8 *g, u32 a);
void BOX2_UI_ShowMiniIcon(char *p, int i)
{
    short y = d_021EFCD8[i];
    BOX2_SEQ_AddActorSurfacePos(*(char * *)&((struct Obj00000 *)p)->f2C, 3, 0xce, y, 0);
    BOX2_SEQ_SetActorDrawEnable(*(char * *)&((struct Obj00000 *)p)->f2C, 3, 1);
    BMP_OAM_SetPos(((struct Obj24025 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f4, 0x9e, y - 8);
    BMP_OAM_SetEnabled(((struct Obj24026 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f4, 1);
}
