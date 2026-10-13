/*
 * function: FLDMMDL_MOVE_UpdateGridPosDir
 * address:  0x02163E7C
 * packet:   pkt_ov010_02163E7C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb
 *   FLDMMDL_SetGridOldX  0x0216D80C  thumb
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb
 *   FLDMMDL_SetGridOldY  0x0216D818  thumb
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb
 *   FLDMMDL_SetGridOldZ  0x0216D824  thumb
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb
 *   FLDMMDL_AddGridNowX  0x0216D848  thumb
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb
 *   FLDMMDL_AddGridNowZ  0x0216D87C  thumb
 *   FLDMMDL_MOVE_GridToVectorPos  0x02164280  thumb
 *   FLDMMDL_GetPosY  0x0216D8AC  thumb
 *   FLDMMDL_MOVE_GetMapHeight  0x02163E58  thumb
 *   FLDMMDL_SetGridNowY  0x0216D85C  thumb
 */

typedef short s16;

typedef unsigned int   u32;
extern int FLDMMDL_GetGridNowX(void *p);
extern void FLDMMDL_SetGridOldX(int a, int b);
extern int FLDMMDL_GetGridNowY(void *p);
extern void FLDMMDL_SetGridOldY(int a, int b);
extern int FLDMMDL_GetGridNowZ(void *p);
extern void FLDMMDL_SetGridOldZ(int a, int b);
extern int FLDMMDL_MOVE_GetDirAddGridX(int a);
extern void FLDMMDL_AddGridNowX(int a, int b);
extern int FLDMMDL_MOVE_GetDirAddGridZ(int a);
extern void FLDMMDL_AddGridNowZ(int a, int b);
extern void FLDMMDL_MOVE_GridToVectorPos(int x, int y, int *p);
extern u32 FLDMMDL_GetPosY(void *p);
extern void FLDMMDL_MOVE_GetMapHeight(int a, int *p, int *out);
extern void FLDMMDL_SetGridNowY(void *p, int v);

void FLDMMDL_MOVE_UpdateGridPosDir(int a, int b)
{
    int v;
    int buf[3];

    FLDMMDL_SetGridOldX(a, FLDMMDL_GetGridNowX((void *)a));
    FLDMMDL_SetGridOldY(a, FLDMMDL_GetGridNowY((void *)a));
    FLDMMDL_SetGridOldZ(a, FLDMMDL_GetGridNowZ((void *)a));
    FLDMMDL_AddGridNowX(a, FLDMMDL_MOVE_GetDirAddGridX(b));
    FLDMMDL_AddGridNowZ(a, FLDMMDL_MOVE_GetDirAddGridZ(b));
    v = 0;
    FLDMMDL_MOVE_GridToVectorPos(FLDMMDL_GetGridNowX((void *)a), FLDMMDL_GetGridNowZ((void *)a), buf);
    buf[1] = FLDMMDL_GetPosY((void *)a);
    FLDMMDL_MOVE_GetMapHeight(a, buf, &v);
    FLDMMDL_SetGridNowY((void *)a, (s16)((v >> 4) / 4096));
}
