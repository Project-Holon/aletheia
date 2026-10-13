/*
 * function: FLDMMDL_MOVECODE_UpdateByEventType
 * address:  0x0219B478
 * packet:   pkt_ov021_0219B478
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 *   gMmdlEventTypeUpdateProcs  0x021D5320  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef void (*Handler)(u32);
extern u16 FLDMMDL_GetEventType(u8 *p);
extern Handler gMmdlEventTypeUpdateProcs[];

void FLDMMDL_MOVECODE_UpdateByEventType(u32 a)
{
    gMmdlEventTypeUpdateProcs[FLDMMDL_GetEventType((u8 *)a)](a);
}
