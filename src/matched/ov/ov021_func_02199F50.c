/*
 * function: FLDMMDL_ACMD_FlyReadyInit
 * address:  0x02199F50
 * packet:   pkt_ov021_02199F50
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_SetDrawOffset  0x0216D8C0  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 *   d_021D4ACC     0x021D4ACC  data  a4
 */
#include "../include/Obj12643.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef struct { int x, y, z; } Vec;
extern const Vec d_021D4ACC;
extern u16 *FLDMMDL_InitMoveCmdWork(u32, u32);
extern void FLDMMDL_SetDrawOffset(u32, const Vec *);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_FlyReadyInit(u32 a)
{
    u16 *p;
    Vec t = d_021D4ACC;
    p = FLDMMDL_InitMoveCmdWork(a, 6);
    *p = 0;
    ((struct Obj12643 *)p)->f2 = 0;
    FLDMMDL_SetDrawOffset(a, &t);
    FLDMMDL_SetDrawStatus((void *)a, 10);
    FLDMMDL_IncAcmdSeq(a);
    return 1;
}
