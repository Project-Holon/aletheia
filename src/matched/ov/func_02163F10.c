/*
 * function: FLDMMDL_MOVE_UpdateOldGridPos
 * address:  0x02163F10
 * packet:   pkt_02163F10
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_SetGridOldX  0x0216D80C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_SetGridOldY  0x0216D818  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_SetGridOldZ  0x0216D824  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_SetGridOldX();
extern int FLDMMDL_GetGridNowY(void *p);
extern int FLDMMDL_SetGridOldY();
extern int FLDMMDL_GetGridNowZ(void *p);
extern int FLDMMDL_SetGridOldZ();

int FLDMMDL_MOVE_UpdateOldGridPos(int a0)
{
    int a1;
    int t4;

t4 = a0 + 0;
    a0 = FLDMMDL_GetGridNowX((void *)a0);
loc_02163F18:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = FLDMMDL_SetGridOldX(a0, a1);
loc_02163F20:
a0 = t4 + 0;
    a0 = FLDMMDL_GetGridNowY((void *)a0);
loc_02163F26:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = FLDMMDL_SetGridOldY(a0, a1);
loc_02163F2E:
a0 = t4 + 0;
    a0 = FLDMMDL_GetGridNowZ((void *)a0);
loc_02163F34:
a1 = a0 + 0;
a0 = t4 + 0;
    a0 = FLDMMDL_SetGridOldZ(a0, a1);
loc_02163F3C:
    return a0;}
