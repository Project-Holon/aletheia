/*
 * function: FLDMMDL_MOVECODE_InitByEventType
 * address:  0x0219B440
 * packet:   pkt_ov021_0219B440
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH dependency: target of the Thumb tail-call thunk
 * FLDMMDL_MOVECODE_InitEventTypeProcThunk (ov021).  Indexes the function-pointer table at 0x021D5278 by
 * the word read at p+0x10 and tail-dispatches through it.
 *
 * symbols:
 *   FLDMMDL_GetEventType  0x0216D5A8  thumb  ov010
 *   gMmdlEventTypeInitProcs  0x021D5278  data   ov021  a4
 */

typedef unsigned int   u32;
typedef unsigned char  u8;
typedef unsigned short u16;
extern u16 FLDMMDL_GetEventType(u8 *p);
extern int (*const gMmdlEventTypeInitProcs[])(char *);

int FLDMMDL_MOVECODE_InitByEventType(char *a)
{
    int i = FLDMMDL_GetEventType((u8 *)a);

    return gMmdlEventTypeInitProcs[i](a);
}
