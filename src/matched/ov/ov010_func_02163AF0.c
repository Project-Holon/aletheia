/*
 * function: FLDMMDL_MOVE_HitCheckObjectRect
 * address:  0x02163AF0
 * packet:   pkt_ov010_02163AF0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_MOVE_GetGridRect  0x02163A08  thumb  ov010
 *   FLDMMDL_MOVE_IsRectOverlap  0x02163A40  thumb  ov010
 *   FLDMMDL_CheckStatusBit  0x0216D55C  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_GetGridNowY  0x0216D854  thumb  ov010
 *   FLDMMDL_GetGridOldX  0x0216D804  thumb  ov010
 *   FLDMMDL_GetGridOldZ  0x0216D81C  thumb  ov010
 *   FLDMMDL_GetGridOldY  0x0216D810  thumb  ov010
 */

typedef short s16;

extern void FLDMMDL_MOVE_GetGridRect();
extern int FLDMMDL_MOVE_IsRectOverlap(s16 *a, s16 *b);
extern int FLDMMDL_CheckStatusBit(int a0, int a1);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);
extern int FLDMMDL_GetGridNowY(void *p);
extern int FLDMMDL_GetGridOldX(void *p);
extern int FLDMMDL_GetGridOldZ(void *p);
extern int FLDMMDL_GetGridOldY(void *p);

int FLDMMDL_MOVE_HitCheckObjectRect(int a, int b, int c, int d, s16 e, int g)
{
    int v1[2];
    int v0[2];
    s16 t;

    FLDMMDL_MOVE_GetGridRect(a, c, e, v1);
    if (FLDMMDL_CheckStatusBit(b, 0x80) == 0) {
        FLDMMDL_MOVE_GetGridRect(b, FLDMMDL_GetGridNowX((void *)b), FLDMMDL_GetGridNowZ((void *)b), v0);
        if (FLDMMDL_MOVE_IsRectOverlap((s16 *)v1, (s16 *)v0) != 0) {
            t = d - FLDMMDL_GetGridNowY((void *)b);
            if (t < 0) {
                t = -t;
            }
            if (t < 1) {
                return 1;
            }
        }
        if (g == 1) {
            FLDMMDL_MOVE_GetGridRect(b, FLDMMDL_GetGridOldX((void *)b), FLDMMDL_GetGridOldZ((void *)b), v0);
            if (FLDMMDL_MOVE_IsRectOverlap((s16 *)v1, (s16 *)v0) != 0) {
                t = d - FLDMMDL_GetGridOldY((void *)b);
                if (t < 0) {
                    t = -t;
                }
                if (t < 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}
