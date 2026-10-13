/*
 * function: FIELD_EVENT_CHECK_IsLedgePathClear
 * address:  0x0218B6F8
 * packet:   pkt_ov021_0218B6F8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FIELD_PLAYER_GetMmdl  0x021A3074  thumb
 *   FLDMMDL_GetGridNowX  0x0216D83C  thumb  ov010
 *   FLDMMDL_GetGridNowZ  0x0216D86C  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridX  0x021641E8  thumb  ov010
 *   FLDMMDL_MOVE_GetDirAddGridZ  0x021641F8  thumb  ov010
 *   FIELDMAP_GetMmdlSys  0x02188C7C  thumb
 *   FLDMMDL_SysSearchGridPos  0x0216DDC0  thumb  ov010
 * Addresses are Black-image addresses.
 */
#include "../include/Obj07410.h"

typedef unsigned short u16;
typedef signed short   s16;

typedef unsigned char  u8;
extern void *FIELD_PLAYER_GetMmdl(u8 *p);
extern int FLDMMDL_GetGridNowX(void *o);
extern int FLDMMDL_GetGridNowZ(void *o);
extern int FLDMMDL_MOVE_GetDirAddGridX(u16 d);
extern int FLDMMDL_MOVE_GetDirAddGridZ(u16 d);
extern void *FIELDMAP_GetMmdlSys(u8 *p);
typedef unsigned int   u32;
extern void *FLDMMDL_SysSearchGridPos(u32 a, u32 b, u32 c, u32 d);

int FIELD_EVENT_CHECK_IsLedgePathClear(char *p, void *q)
{
    void *o = FIELD_PLAYER_GetMmdl(((struct Obj07410 *)p)->f18);
    u16 d = ((struct Obj07410 *)p)->f30;
    int x = FLDMMDL_GetGridNowX(o);
    int z = FLDMMDL_GetGridNowZ(o);
    int i;

    for (i = 0; i < 2; i++) {
        x = (s16)(x + FLDMMDL_MOVE_GetDirAddGridX(d));
        z = (s16)(z + FLDMMDL_MOVE_GetDirAddGridZ(d));
        if (FLDMMDL_SysSearchGridPos((u32)FIELDMAP_GetMmdlSys(q), x, z, 1))
            return 0;
    }
    return 1;
}
