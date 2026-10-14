/*
 * function: GURU2_MAIN_StateWaitWipeIn
 * address: 0x021DEA84
 * packet: pkt_ov137_021DEA84
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   WIPE_SYS_EndCheck  0x020221A4  thumb  arm9
 *   TIME_ICON_Create  0x0202EE30  thumb  arm9
 */
#include "../include/Obj08214.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern u32 WIPE_SYS_EndCheck(void);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern u8 *TIME_ICON_Create(void *owner, void *a1, u8 a2, u8 a3, volatile u16 heap);
int GURU2_MAIN_StateWaitWipeIn(u8 *p)
{
    if (WIPE_SYS_EndCheck()) {
        ((struct Obj08214 *)p)->f0 = GFL_NET_SYSTEM_GetCurrentAid() == 0 ? 2 : 8;
        ((struct Obj08214 *)p)->fDA8 = TIME_ICON_Create(((struct Obj08214 *)p)->fD98, ((struct Obj08214 *)p)->fCF0, 15, 16, 114);
        return 1;
    }
    return 0;
}
