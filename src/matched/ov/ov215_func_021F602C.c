/*
 * function: EGG_DEMO_MAIN_StopBgm, EGG_DEMO_MAIN_IsBgmStopped
 * address: 0x021F602C
 * packet: pkt_ov215_021F602C
 * region: ov215
 * unit: yes
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 */
#include "../include/Obj25745.h"
#include "../include/Obj25746.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int   u32;
extern void GFL_USE_FadeOutBgm(u32 a);
void EGG_DEMO_MAIN_StopBgm(void *unused, char *p)
{
    GFL_USE_FadeOutBgm(0x3c);
    ((struct Obj25745 *)p)->f18 = 7;
}

int EGG_DEMO_MAIN_IsBgmStopped(void *unused, char *p)
{
    if (((struct Obj25746 *)p)->f18 == 7) return 1;
    return 0;
}
