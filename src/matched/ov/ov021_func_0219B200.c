/*
 * function: FLDMMDL_MOVECODE_GetDirTowardPlayerInSet
 * address:  0x0219B200
 * packet:   pkt_ov021_0219B200
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_MOVECODE_GetDirSet  0x0219B120  thumb  ov021
 *   FLDMMDL_MOVECODE_FindTableEnd  0x0219B0D8  thumb  ov021
 *   FLDMMDL_MOVECODE_GetSightDirToPlayer  0x0219B13C  thumb  ov021
 *   FLDMMDL_GetMmdlSys  0x0216D67C  thumb  ov010
 *   FLDMMDL_SysSearchPlayer  0x0216DEE0  thumb  ov010
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 */

extern unsigned int *FLDMMDL_MOVECODE_GetDirSet(unsigned int id);
extern int FLDMMDL_MOVECODE_FindTableEnd(unsigned int *t, unsigned int v);
typedef unsigned int   u32;
extern int FLDMMDL_MOVECODE_GetSightDirToPlayer(u32 a);
extern void *FLDMMDL_GetMmdlSys(void *a0);
extern void *FLDMMDL_SysSearchPlayer(void *a0);
extern int FLDMMDL_GetGridNowX(void *p);
extern int FLDMMDL_GetGridNowZ(void *p);

int FLDMMDL_MOVECODE_GetDirTowardPlayerInSet(int a, int id, int end)
{
    int *tbl;
    int n;
    int t;
    int i;
    int o;
    int ax;
    int ay;
    int ox;
    int oy;
    int dx;
    int dy;

    tbl = (int *)FLDMMDL_MOVECODE_GetDirSet(id);
    n = FLDMMDL_MOVECODE_FindTableEnd((unsigned int *)tbl, end);
    if (n == 1) {
        return 9;
    }
    t = FLDMMDL_MOVECODE_GetSightDirToPlayer(a);
    if (t != 9) {
        i = 0;
        do {
            if (t == tbl[i]) {
                return t;
            }
            i++;
        } while (i < n);
        o = (int)FLDMMDL_SysSearchPlayer(FLDMMDL_GetMmdlSys((void *)a));
        dx = 9;
        dy = 9;
        ax = FLDMMDL_GetGridNowX((void *)a);
        ay = FLDMMDL_GetGridNowZ((void *)a);
        ox = FLDMMDL_GetGridNowX((void *)o);
        oy = FLDMMDL_GetGridNowZ((void *)o);
        if (ax > ox) {
            dx = 2;
        } else if (ax < ox) {
            dx = 3;
        }
        if (ay > oy) {
            dy = 0;
        } else if (ay < oy) {
            dy = 1;
        }
        i = 0;
        if (dx == 9) {
            do {
                if (dy == tbl[i]) {
                    return dy;
                }
                i++;
            } while (i < n);
        } else if (dy == 9) {
            do {
                if (dx == tbl[i]) {
                    return dx;
                }
                i++;
            } while (i < n);
        } else {
            do {
                if (dx == tbl[i]) {
                    return dx;
                }
                if (dy == tbl[i]) {
                    return dy;
                }
                i++;
            } while (i < n);
        }
        return 9;
    }
    return t;
}
