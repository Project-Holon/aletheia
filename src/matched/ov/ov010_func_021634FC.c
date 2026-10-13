/*
 * function: FLDMMDL_MOVE_AttrEffectFootMarkIfFlag
 * address: 0x021634FC
 * packet: pkt_ov010_021634FC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * trailing: two-byte zero alignment at 0x0216352A before FLDMMDL_MOVE_AttrEffectFootMarkIfNoFlag.
 * symbols:
 *   FLDMMDL_GetDirMove 0x0216D608 thumb ov010
 *   FLDMMDL_MOVE_GetFootMarkKind 0x02163464 thumb ov010
 *   FLDEFF_GRASS_Start 0x021AC760 thumb ov021
 */
#include "../include/Obj00110.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u16 FLDMMDL_GetDirMove(void *p);
extern int FLDMMDL_MOVE_GetFootMarkKind(int a0, int a1);
extern void FLDEFF_GRASS_Start(u32 a, u32 b, u32 c, int d);
void FLDMMDL_MOVE_AttrEffectFootMarkIfFlag(void *p, u8 *q)
{
    int flag;
    int kind;
    if (((struct Obj00110 *)q)->fE & 0x20) {
        flag = FLDMMDL_GetDirMove(p);
        kind = FLDMMDL_MOVE_GetFootMarkKind(((struct Obj00110 *)q)->fA, q[24]);
        if (flag != 0)
            FLDEFF_GRASS_Start(*(u32 *)&((struct Obj00110 *)q)->f14, (u32)p, 1, kind);
    }
}
