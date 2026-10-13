/*
 * function: FLDMMDL_RAIL_SetMoveRequest
 * address:  0x0219E370
 * packet:   pkt_ov021_0219E370
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_GetMoveProcWork  0x0216D69C  thumb  ov010
 *   FLDMMDL_RAIL_DirToRailKey  0x0219E938  thumb  ov021
 *   FLDMMDL_RAIL_RailKeyToDir  0x0219E940  thumb  ov021
 *   FIELD_RAIL_WORK_StartStep  0x021B80E0  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef signed short   s16;
typedef unsigned int   u32;

extern void *FLDMMDL_GetMoveProcWork(void *p);
extern u32 FLDMMDL_RAIL_DirToRailKey(int a0);
extern u32 FLDMMDL_RAIL_RailKeyToDir(int x);
extern void FIELD_RAIL_WORK_StartStep(void *p, u32 a, u32 b);

void FLDMMDL_RAIL_SetMoveRequest(u32 a, u32 b, u32 c)
{
    u32 *p = FLDMMDL_GetMoveProcWork((void *)a);
    u32 x = FLDMMDL_RAIL_DirToRailKey(b);
    FIELD_RAIL_WORK_StartStep((void *)*p, FLDMMDL_RAIL_RailKeyToDir(c), x);
}
