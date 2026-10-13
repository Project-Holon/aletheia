/*
 * function: FLDMMDL_RAIL_MOVE_ProcMoveStartFirst
 * address:  0x0219D7D0
 * packet:   pkt_ov021_0219D7D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckMoveBit  0x0216D57C  thumb  ov010
 *   FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartFirst  0x0219D8DC  thumb  ov021
 *   FLDMMDL_ClearMoveBit  0x0216D570  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_CheckMoveBit(void *p, u32 v);
extern void FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartFirst(u32);
extern char *FLDMMDL_ClearMoveBit(char *p, u32 v);

void FLDMMDL_RAIL_MOVE_ProcMoveStartFirst(u32 a)
{
    if (FLDMMDL_CheckMoveBit((void *)a, 0x20) != 0) {
        FLDMMDL_RAIL_MOVE_MapAttrProcMoveStartFirst(a);
    }
    FLDMMDL_ClearMoveBit((char *)a, 0xA0);
}
