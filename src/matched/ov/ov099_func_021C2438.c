/*
 * function: WIFICLUB_UpdateBgmFade
 * address: 0x021C2438
 * packet: pkt_ov099_021C2438
 * region: ov099
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_USE_SetBgmTrackVolume 0x02005F24 thumb
 */
#include "../include/Obj00825.h"
typedef unsigned char u8;
typedef unsigned int   u32;
extern void GFL_USE_SetBgmTrackVolume(u32 a0, u32 a1);
int WIFICLUB_UpdateBgmFade(char *p)
{
    int remaining;
    int start;
    int delta;
    if (((struct Obj00825 *)p)->f1343 != 0) {
        --((struct Obj00825 *)p)->f1343;
        remaining = ((struct Obj00825 *)p)->f1343;
        if (remaining != 0) {
            start = ((struct Obj00825 *)p)->f1342;
            delta = start - ((struct Obj00825 *)p)->f1341;
            if (delta < 0) ((struct Obj00825 *)p)->f1340 = start + (-delta / 6) * remaining;
            else ((struct Obj00825 *)p)->f1340 = start - (delta / 6) * remaining;
            GFL_USE_SetBgmTrackVolume(0xffff, ((struct Obj00825 *)p)->f1340);
            return 0;
        }
        ((struct Obj00825 *)p)->f1340 = ((struct Obj00825 *)p)->f1342;
        GFL_USE_SetBgmTrackVolume(0xffff, ((struct Obj00825 *)p)->f1342);
    }
    return 1;
}
