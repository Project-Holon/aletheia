/*
 * function: FLDMMDL_MOVECODE_CheckByEventType
 * address:  0x0219B45C
 * packet:   pkt_ov021_0219B45C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 *   gMmdlEventTypeCheckProcs  0x021D52CC  data  a4
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
typedef void (*Handler)(u32);
extern u16 FLDMMDL_GetEventType(u8 *p);
extern Handler gMmdlEventTypeCheckProcs[];

void FLDMMDL_MOVECODE_CheckByEventType(u32 a)
{
    gMmdlEventTypeCheckProcs[FLDMMDL_GetEventType((u8 *)a)](a);
}
