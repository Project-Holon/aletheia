/*
 * function: FLDMMDL_MOVECODE_RoutePatrolSwapStepSwapMoveCode
 * address:  0x0219AE68
 * packet:   pkt_ov021_0219AE68
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_ACMD_Update  0x02197EDC  thumb  ov021
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 *   FLDMMDL_ChangeMoveCode  0x0216E0E8  thumb  ov010
 *   FLDMMDL_OffMoveBitMove  0x0216DA50  thumb  ov010
 *   gMmdlSwapMoveCodePairs     0x021D4F90  data    a2
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed char    s8;

extern u32 FLDMMDL_ACMD_Update(u8 *p);
extern u16 FLDMMDL_GetMoveCode(void *p);
extern int FLDMMDL_ChangeMoveCode(int a0, int a1);
extern void FLDMMDL_OffMoveBitMove(u8 *p);
extern u16 gMmdlSwapMoveCodePairs[];

int FLDMMDL_MOVECODE_RoutePatrolSwapStepSwapMoveCode(int a, s8 *b)
{
    u16 *p;
    u32 id;
    u32 r4;
    u32 v;
    int t;

    if (FLDMMDL_ACMD_Update((u8 *)a) == 1) {
        r4 = 0xff;
        v = FLDMMDL_GetMoveCode((void *)a);
        p = gMmdlSwapMoveCodePairs;
        id = 0x25;
        do {
            if (id == v) {
                r4 = p[1];
            } else if (p[1] == v) {
                r4 = id;
            }
            if (r4 != 0xff) {
                t = 4 - (b[1] + 1);
                FLDMMDL_ChangeMoveCode(a, r4);
                b[1] = t;
                break;
            }
            p += 2;
            id = p[0];
        } while (id != 0xff);
        FLDMMDL_OffMoveBitMove((u8 *)a);
        b[0] = 2;
    }
    return 0;
}
