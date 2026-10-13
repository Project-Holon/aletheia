/*
 * function: FLDMMDL_InitWork
 * address:  0x0216D1C8
 * packet:   pkt_ov010_0216D1C8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_SetZoneId  0x0216D58C  thumb  ov010
 *   FLDMMDL_SetStatusBit  0x0216D548  thumb  ov010
 *   FLDMMDL_SetMoveBit  0x0216D568  thumb  ov010
 *   FLDMMDL_IsAliasEventId  0x0216D5BC  thumb  ov010
 *   FLDMMDL_SetStatusBitAlias  0x0216DB98  thumb  ov010
 *   FLDMMDL_FreeAcmd  0x0216D4B4  thumb  ov010
 */
#include "../include/Obj19119.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void FLDMMDL_SetZoneId(void *p, u16 v);
extern u32 *FLDMMDL_SetStatusBit(u32 *p, u32 v);
extern void *FLDMMDL_SetMoveBit(void *p, u32 v);
extern int FLDMMDL_IsAliasEventId(void *p);
extern int FLDMMDL_SetStatusBitAlias(void *a0, int a1);
extern void *FLDMMDL_FreeAcmd(char *p);

void FLDMMDL_InitWork(u8 *p, u32 a, u32 b)
{
    ((struct Obj19119 *)p)->f88 = a;
    FLDMMDL_SetZoneId(p, (u16)b);
    FLDMMDL_SetStatusBit((u32 *)p, 1);
    FLDMMDL_SetMoveBit(p, 0x1800);
    if (FLDMMDL_IsAliasEventId(p) == 1)
        FLDMMDL_SetStatusBitAlias(p, 1);
    FLDMMDL_FreeAcmd((char *)p);
}
