/*
 * function: FLDMMDL_MOVE_HitCheckMoveLimit
 * address:  0x02163C9C
 * packet:   pkt_ov010_02163C9C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetGridInitX  0x0216D7E8  thumb
 *   FLDMMDL_GetMoveLimitX  0x0216D660  thumb
 *   FLDMMDL_GetGridInitZ  0x0216D7F8  thumb
 *   FLDMMDL_GetMoveLimitZ  0x0216D66C  thumb
 */

typedef short s16;

extern int FLDMMDL_GetGridInitX(void *p);
extern int FLDMMDL_GetMoveLimitX(void *p);
extern int FLDMMDL_GetGridInitZ(void *p);
extern int FLDMMDL_GetMoveLimitZ(void *p);

int FLDMMDL_MOVE_HitCheckMoveLimit(int a, int b, int c)
{
    int base;
    int d;
    int hi;
    int lo;

    base = FLDMMDL_GetGridInitX((void *)a);
    d = FLDMMDL_GetMoveLimitX((void *)a);
    if (d != -1) {
        hi = (s16)(base + d);
        lo = (s16)(base - d);
        if (lo > b || hi < b)
            return 1;
    }
    base = FLDMMDL_GetGridInitZ((void *)a);
    d = FLDMMDL_GetMoveLimitZ((void *)a);
    if (d != -1) {
        hi = (s16)(base + d);
        lo = (s16)(base - d);
        if (lo > c || hi < c)
            return 1;
    }
    return 0;
}
