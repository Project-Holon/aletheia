/*
 * function: FLDMMDL_RAIL_MOVE_ProcMoveEnd
 * address:  0x0219D824
 * packet:   pkt_ov021_0219D824
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_MapAttrProcMoveEndJump  0x0219DA20  thumb  ov021
 *   FLDMMDL_RAIL_MOVE_MapAttrProcMoveEnd  0x0219D9D8  thumb  ov021
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern void FLDMMDL_RAIL_MOVE_MapAttrProcMoveEndJump(u32);
extern void FLDMMDL_RAIL_MOVE_MapAttrProcMoveEnd(u32);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);

void FLDMMDL_RAIL_MOVE_ProcMoveEnd(u32 a)
{
    if (FLDMMDL_CheckMoveBit((void *)a, 0x100) != 0) {
        FLDMMDL_RAIL_MOVE_MapAttrProcMoveEndJump(a);
    } else if (FLDMMDL_CheckMoveBit((void *)a, 0x40) != 0) {
        FLDMMDL_RAIL_MOVE_MapAttrProcMoveEnd(a);
    }
    FLDMMDL_ClearMoveBit((char *)a, 0x140);
}
