/*
 * function: FLDMMDL_RAIL_MOVE_CheckMoveStart
 * address:  0x0219D780
 * packet:   pkt_ov021_0219D780
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_CheckMoveBitMove  0x0216DA5C  thumb  ov010
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_GetMoveCode  0x0216D5A0  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern int FLDMMDL_CheckMoveBitMove(void *a0);
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern u16 FLDMMDL_GetMoveCode(void *p);

int FLDMMDL_RAIL_MOVE_CheckMoveStart(u32 a)
{
    if (FLDMMDL_CheckMoveBitMove((void *)a) == 1) {
        return 1;
    }
    if (FLDMMDL_CheckMoveBit((void *)a, 0x800) == 0) {
        return 1;
    }
    FLDMMDL_GetMoveCode((void *)a);
    return 1;
}
