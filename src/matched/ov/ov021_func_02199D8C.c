/*
 * function: FLDMMDL_ACMD_FlyUpInit
 * address:  0x02199D8C
 * packet:   pkt_ov021_02199D8C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   FLDMMDL_InitMoveCmdWork  0x0216D6BC  thumb  ov010
 *   FLDMMDL_SetDrawStatus  0x0216D674  thumb  ov010
 *   FLDMMDL_IncAcmdSeq  0x0216D7CC  thumb
 */
#include "../include/Obj09499.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u8 *FLDMMDL_InitMoveCmdWork(u32, u32);
extern void FLDMMDL_SetDrawStatus(void *p, u16 v);
extern void FLDMMDL_IncAcmdSeq(u32);

int FLDMMDL_ACMD_FlyUpInit(u32 a)
{
    u8 *p = FLDMMDL_InitMoveCmdWork(a, 16);
    ((struct Obj09499 *)p)->f4 = 0x2000;
    ((struct Obj09499 *)p)->f8 = 0;
    p[10] = 0;
    FLDMMDL_SetDrawStatus((void *)a, 11);
    FLDMMDL_IncAcmdSeq(a);
    return 1;
}
