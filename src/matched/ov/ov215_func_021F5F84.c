/*
 * function: EGG_DEMO_MAIN_PlayBgm, EGG_DEMO_MAIN_IsBgmPlaying
 * address: 0x021F5F84
 * packet: pkt_ov215_021F5F84
 * region: ov215
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_CancelChangeAndPlayBgm 0x02005D90 thumb
 */
#include "../include/Obj25741.h"
#include "../include/Obj25742.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void GFL_USE_CancelChangeAndPlayBgm(unsigned, unsigned);
void EGG_DEMO_MAIN_PlayBgm(void *unused, char *p)
{
    GFL_USE_CancelChangeAndPlayBgm(0x3f2, 0xffff);
    ((struct Obj25741 *)p)->f18 = 2;
}

int EGG_DEMO_MAIN_IsBgmPlaying(void *unused, char *p)
{
    if (((struct Obj25742 *)p)->f18 == 2) return 1;
    return 0;
}
