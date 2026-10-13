/*
 * function: FLDMMDL_MOVE_IsGridInObjectRect
 * address:  0x02163C04
 * packet:   pkt_ov010_02163C04
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb
 *   FLDMMDL_MOVE_GetGridRect  0x02163A08  thumb
 */

typedef short s16;

extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern int FLDMMDL_GetGridOldX(void *p);
extern int FLDMMDL_GetGridOldZ(void *p);
extern void FLDMMDL_MOVE_GetGridRect(int a, int b, int c, s16 *r);

int FLDMMDL_MOVE_IsGridInObjectRect(int a, int x, int y, int flag)
{
    s16 r[4];
    int t;

    t = FLDMMDL_GetGridNowX((void *)a);
    FLDMMDL_MOVE_GetGridRect(a, t, FLDMMDL_GetGridNowZ((void *)a), r);
    if (r[0] <= x && r[2] >= x && r[1] <= y && r[3] >= y)
        return 1;
    if (flag == 1) {
        t = FLDMMDL_GetGridOldX((void *)a);
        FLDMMDL_MOVE_GetGridRect(a, t, FLDMMDL_GetGridOldZ((void *)a), r);
        if (r[0] <= x && r[2] >= x && r[1] <= y && r[3] >= y)
            return 1;
    }
    return 0;
}
