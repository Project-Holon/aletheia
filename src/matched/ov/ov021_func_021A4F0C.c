/*
 * function: FIELD_PLAYER_GRID_StartHopOnFoot
 * address:  0x021A4F0C
 * packet:   pkt_ov021_021A4F0C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GRID_FindHopDir  0x021A5630  thumb  ov021
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetAcmd  0x0216D410  thumb  ov010
 *   FLDMMDL_SetStatusBitHeightGetOff  0x0216DB4C  thumb  ov010
 *   FLDMMDL_SetMoveBitShadowVanish  0x0216DCE8  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj19794.h"
#include "../include/Obj19795.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u32 FIELD_PLAYER_GRID_FindHopDir(u32);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetAcmd(u32, u32);
extern int FLDMMDL_SetStatusBitHeightGetOff(void *a0, int a1);
extern int FLDMMDL_SetMoveBitShadowVanish(void *a0, int a1);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);

void FIELD_PLAYER_GRID_StartHopOnFoot(u32 a, void *b, u32 c)
{
    u32 x = ((struct Obj19795 *)c)->f8;
    if (x == 9) {
        x = FIELD_PLAYER_GRID_FindHopDir(a);
    }
    FLDMMDL_SetAcmd((u32)b, FLDMMDL_ACMD_ConvertCodeByDir(x, 0x34));
    FLDMMDL_SetStatusBitHeightGetOff(b, 1);
    FLDMMDL_SetMoveBitShadowVanish((void *)b, 1);
    FLDMMDL_SetMoveBit((void *)b, 0x8000);
    ((struct Obj19794 *)a)->f0 = 5;
}
