/*
 * function: FLDMMDL_MOVE_IsNearPlayer
 * address:  0x02164168
 * packet:   pkt_ov010_02164168
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb
 */

typedef short s16;

extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysSearchPlayer(void *a0);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);

int FLDMMDL_MOVE_IsNearPlayer(int a)
{
    int t;
    int tx;
    int ty;
    int x;
    int y;
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;

    t = (int)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)a));
    if (t != 0) {
        tx = FLDMMDL_GetGridNowX((void *)t);
        ty = FLDMMDL_GetGridNowZ((void *)t);
        x = FLDMMDL_GetGridNowX((void *)a);
        y = FLDMMDL_GetGridNowZ((void *)a);
        x0 = x - 18;
        y0 = y - 18;
        x1 = x + 17;
        y1 = y + 17;
        if (y0 <= ty && y1 >= ty && x0 <= tx && x1 >= tx)
            return 1;
    }
    return 0;
}
