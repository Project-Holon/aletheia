/*
 * function: FLDMMDL_MOVE_TurnToPlayer
 * address:  0x0219BA6C
 * packet:   pkt_ov021_0219BA6C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   FLDMMDL_MOVE_GetTurnAcmdBase  0x0219BA2C  thumb  ov021
 *   FLDMMDL_MOVE_GetDirFromPoints  0x021642B4  thumb  ov010
 *   FLDMMDL_ACMD_ConvertCodeByDir  0x02197E7C  thumb  ov021
 *   FLDMMDL_SetLocalAcmd  0x0216D438  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysSearchPlayer(void *a0);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern int FLDMMDL_GetGridOldX(void *p);
extern int FLDMMDL_GetGridOldZ(void *p);
extern int FLDMMDL_MOVE_GetTurnAcmdBase(int a);
extern u16 FLDMMDL_MOVE_GetDirFromPoints(int x0, int y0, int x1, int y1);
extern int FLDMMDL_ACMD_ConvertCodeByDir(int a, int b);
extern void FLDMMDL_SetLocalAcmd(char *a0, int a1);

int FLDMMDL_MOVE_TurnToPlayer(char *a)
{
    int o;
    int x;
    int y;
    int tx;
    int ty;
    int k;

    o = (int)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)a));
    x = FLDMMDL_GetGridNowX((void *)a);
    y = FLDMMDL_GetGridNowZ((void *)a);
    tx = FLDMMDL_GetGridOldX((void *)o);
    ty = FLDMMDL_GetGridOldZ((void *)o);
    if (x != tx || y != ty) {
        k = FLDMMDL_MOVE_GetTurnAcmdBase((int)a);
        FLDMMDL_SetLocalAcmd(a, (u16)((u32)FLDMMDL_ACMD_ConvertCodeByDir((u16)((int)FLDMMDL_MOVE_GetDirFromPoints(x, y, tx, ty)), (u16)k)));
        return 1;
    }
    return 0;
}
