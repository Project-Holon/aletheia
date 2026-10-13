/*
 * function: FLDMMDL_MOVE_HitCheckMoveDir
 * address:  0x021639C0
 * packet:   pkt_ov010_021639C0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FLDMMDL_MOVE_HitCheckMoveCurrent  0x02163994  thumb  ov010
 */

typedef short s16;

extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_MOVE_GetDirAddGridX(int a);
extern int FLDMMDL_GetGridNowY(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern int FLDMMDL_MOVE_GetDirAddGridZ(int a);
extern void FLDMMDL_MOVE_HitCheckMoveCurrent();

void FLDMMDL_MOVE_HitCheckMoveDir(int a, int b)
{
    s16 x, z;
    int y;

    x = FLDMMDL_GetGridNowX((void *)a) + FLDMMDL_MOVE_GetDirAddGridX(b);
    y = FLDMMDL_GetGridNowY((void *)a);
    z = FLDMMDL_GetGridNowZ((void *)a) + FLDMMDL_MOVE_GetDirAddGridZ(b);
    FLDMMDL_MOVE_HitCheckMoveCurrent(a, x, y, z, b);
}
