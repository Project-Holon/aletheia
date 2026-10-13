/*
 * function: FLDMMDL_MOVECODE_IsDirInsideMoveRect
 * address:  0x0219A4CC
 * packet:   pkt_ov021_0219A4CC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_MOVECODE_GetMoveRect  0x0219A3D8  thumb  ov021
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void FLDMMDL_MOVECODE_GetMoveRect(u32, int *);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_MOVE_GetDirAddGridX(int a);
extern int FLDMMDL_GetGridNowZ(void *p);
extern int FLDMMDL_MOVE_GetDirAddGridZ(u16);

int FLDMMDL_MOVECODE_IsDirInsideMoveRect(u32 a, u32 b)
{
    int r[4];
    int x;
    int y;
    FLDMMDL_MOVECODE_GetMoveRect(a, r);
    x = FLDMMDL_GetGridNowX((void *)a) + FLDMMDL_MOVE_GetDirAddGridX((u16)b);
    y = FLDMMDL_GetGridNowZ((void *)a) + FLDMMDL_MOVE_GetDirAddGridZ(b);
    if (r[0] > x || r[2] < x)
        return 0;
    if (r[1] > y || r[3] < y)
        return 0;
    return 1;
}
