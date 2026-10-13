/*
 * function: FLDMMDL_InitPosition
 * address:  0x0216E014
 * packet:   pkt_ov010_0216E014
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SetGridNowX  0x0216D844  thumb  ov010
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb  ov010
 *   FLDMMDL_SetGridNowZ  0x0216D874  thumb  ov010
 *   FLDMMDL_SetPos  0x0216D89C  thumb  ov010
 *   FLDMMDL_MOVE_UpdateOldGridPos  0x02163F10  thumb  ov010
 *   FLDMMDL_SetDirDisp  0x0216D5D8  thumb  ov010
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int u32;
typedef short s16;

extern void FLDMMDL_SetGridNowX(void *p, s16 v);
extern void FLDMMDL_SetGridNowY(void *p, int v);
extern void FLDMMDL_SetGridNowZ(int a0, int a1);
extern void FLDMMDL_SetPos(void *p, const void *q);
extern int FLDMMDL_MOVE_UpdateOldGridPos(int a0);
extern int FLDMMDL_SetDirDisp(int a0, int a1);
extern void *FLDMMDL_FreeAcmd(char *p);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);

void FLDMMDL_InitPosition(void *a, int *p, int b)
{
    FLDMMDL_SetGridNowX(a, (s16)((p[0] >> 4) / 4096));
    FLDMMDL_SetGridNowY(a, (s16)((p[1] >> 4) / 4096));
    FLDMMDL_SetGridNowZ((int)a, (s16)((p[2] >> 4) / 4096));
    FLDMMDL_SetPos(a, p);
    FLDMMDL_MOVE_UpdateOldGridPos((int)a);
    FLDMMDL_SetDirDisp((int)a, b);
    FLDMMDL_FreeAcmd(a);
    FLDMMDL_SetMoveBit(a, 0x20);
    FLDMMDL_ClearMoveBit(a, 0x50);
}
