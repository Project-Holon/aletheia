/*
 * function: FIELD_PLAYER_CORE_SetPos
 * address:  0x021A38A4
 * packet:   pkt_ov021_021A38A4
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_SetGridOldX  0x0216D80C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_SetGridOldY  0x0216D818  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_SetGridOldZ  0x0216D824  thumb  ov010
 *   FLDMMDL_SetGridNowX  0x0216D844  thumb  ov010
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb  ov010
 *   FLDMMDL_SetGridNowZ  0x0216D874  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 */
#include "../include/Obj19775.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    int x;
    int y;
    int z;
} Vec021A38A4;

u16 FLDMMDL_GetGridNowX(u32 h);
void FLDMMDL_SetGridOldX(void *p, u16 v);
u16 FLDMMDL_GetGridNowY(u32 h);
void FLDMMDL_SetGridOldY(void *p, u16 v);
u16 FLDMMDL_GetGridNowZ(u32 h);
void FLDMMDL_SetGridOldZ(void *p, u16 v);
void FLDMMDL_SetGridNowX(void *p, short v);
void FLDMMDL_SetGridNowY(void *p, int v);
void FLDMMDL_SetGridNowZ(int a0, int a1);
void FLDMMDL_SetPos(u32 h, Vec021A38A4 *v);

void FIELD_PLAYER_CORE_SetPos(u8 *p, Vec021A38A4 *v)
{
    int x = (v->x >> 4) / 4096;
    int y = (v->y >> 4) / 4096;
    int z = (v->z >> 4) / 4096;
    u32 h = ((struct Obj19775 *)p)->f1C;

    FLDMMDL_SetGridOldX((void *)h, FLDMMDL_GetGridNowX(h));
    FLDMMDL_SetGridOldY((void *)h, FLDMMDL_GetGridNowY(h));
    FLDMMDL_SetGridOldZ((void *)h, FLDMMDL_GetGridNowZ(h));
    FLDMMDL_SetGridNowX((void *)h, (short)x);
    FLDMMDL_SetGridNowY((void *)h, (short)y);
    FLDMMDL_SetGridNowZ(h, (short)z);
    FLDMMDL_SetPos(h, v);
}
