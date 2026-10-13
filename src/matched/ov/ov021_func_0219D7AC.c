/*
 * function: FLDMMDL_RAIL_MOVE_UpdateAttrBeforeMove
 * address:  0x0219D7AC
 * packet:   pkt_ov021_0219D7AC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_UpdateCurrentAttr  0x0219D85C  thumb  ov021
 *   FLDMMDL_OnMoveBitMoveStart  0x0216DA70  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern u32 FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(u32 a);
extern void FLDMMDL_OnMoveBitMoveStart(void *a0);

void FLDMMDL_RAIL_MOVE_UpdateAttrBeforeMove(u32 a)
{
    if (FLDMMDL_CheckMoveBit((void *)a, 0x800) != 0 && FLDMMDL_RAIL_MOVE_UpdateCurrentAttr(a) == 1) {
        FLDMMDL_OnMoveBitMoveStart((void *)a);
    }
}
