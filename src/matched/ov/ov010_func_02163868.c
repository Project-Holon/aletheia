/*
 * function: FLDMMDL_MOVE_AttrEffectLongGrassEnd
 * address:  0x02163868
 * packet:   pkt_ov010_02163868
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   FLDMMDL_CheckMoveBitReflect  0x0216DC34  thumb  ov010
 *   FLDMMDL_MOVE_GetDirMapAttr  0x02163F40  thumb  ov010
 *   FLDMMDL_SetMoveBitReflect  0x0216DC18  thumb  ov010
 *   MAP_ATTR_GetFlags  0x021AB0F8  thumb  ov021
 */
#include "../include/Obj00110.h"

typedef unsigned char u8;

extern int FLDMMDL_CheckMoveBitReflect(void *a0);
typedef unsigned short u16;
typedef unsigned int   u32;
extern int FLDMMDL_MOVE_GetDirMapAttr(int a, int dir);
extern int FLDMMDL_SetMoveBitReflect(void *a0, int a1);
extern u16 MAP_ATTR_GetFlags(u32 attr);

void FLDMMDL_MOVE_AttrEffectLongGrassEnd(void *a, int q)
{
    u8 *t = *(u8 * *)&((struct Obj00110 *)q)->f10;

    if (t[6] != 0 && FLDMMDL_CheckMoveBitReflect((void *)a) != 0) {
        int r = FLDMMDL_MOVE_GetDirMapAttr((int)a, 1);

        if (r == -1) {
            FLDMMDL_SetMoveBitReflect(a, 0);
            return;
        }
        if ((MAP_ATTR_GetFlags(r) & 0x40) == 0) {
            FLDMMDL_SetMoveBitReflect(a, 0);
        }
    }
}
