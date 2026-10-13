/*
 * function: FLDMMDL_BLACT_Update
 * address:  0x0219C5FC
 * packet:   pkt_ov021_0219C5FC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_SysGetBlActCont  0x0216D520  thumb  ov010
 *   FLDMMDL_BLACT_AddReservedActors  0x0219D0F4  thumb  ov021
 *   FLDMMDL_BLACT_LoadReservedRes  0x0219CDAC  thumb  ov021
 *   FLDMMDL_BLACT_UpdateCodeChanges  0x0219D390  thumb  ov021
 */
#include "../include/Obj03579.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;
extern u32 FLDMMDL_SysGetBlActCont(void *p);
extern void FLDMMDL_BLACT_AddReservedActors(int *obj);
extern void FLDMMDL_BLACT_LoadReservedRes(u8 *);
extern void FLDMMDL_BLACT_UpdateCodeChanges(u8 *);

void FLDMMDL_BLACT_Update(u32 a)
{
    u8 *s = (u8 *)FLDMMDL_SysGetBlActCont((void *)a);
    if (s != 0) {
        if (*(u32 *)&((struct Obj03579 *)s)->f1C != 0) {
            FLDMMDL_BLACT_AddReservedActors((int *)s);
            FLDMMDL_BLACT_LoadReservedRes(s);
        }
        FLDMMDL_BLACT_UpdateCodeChanges(s);
        s[0] = 0;
    }
}
