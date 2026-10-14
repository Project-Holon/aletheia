/*
 * function: GURU2_MAIN_StateRoundEnd
 * address: 0x021DF1C4
 * packet: pkt_ov137_021DF1C4
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GURU2_MAIN_StartBlendFade 0x021E1584 thumb ov137
 *   GURU2_MAIN_FindNearestPlayerRecord 0x021E0A44 thumb ov137
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb  arm9
 */
#include "../include/Obj02209.h"
#include "../include/Obj23756.h"
typedef unsigned char u8;
extern void GURU2_MAIN_StartBlendFade(char *p, int flag);
extern u8 *GURU2_MAIN_FindNearestPlayerRecord(void *);
typedef unsigned short u16;
typedef unsigned int   u32;
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
int GURU2_MAIN_StateRoundEnd(u8 *p)
{
    GURU2_MAIN_StartBlendFade((char *)p, 0);
    *(u8 * *)&((struct Obj02209 *)p)->f28 = GURU2_MAIN_FindNearestPlayerRecord(p);
    if (GFL_NET_SYSTEM_GetCurrentAid() == 0) {
        if (((struct Obj23756 *)(*(u8 * *)&((struct Obj02209 *)p)->f28))->fC == GFL_NET_SYSTEM_GetCurrentAid())
            ((struct Obj02209 *)p)->f0 = 29;
        else
            ((struct Obj02209 *)p)->f0 = 30;
    } else {
        ((struct Obj02209 *)p)->f0 = 31;
    }
    GFL_USE_PlaySeDefaultVolume(1833);
    return 1;
}
