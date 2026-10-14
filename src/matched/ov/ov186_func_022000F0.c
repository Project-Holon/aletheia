/*
 * packet: pkt_ov186_022000F0
 * function: BR_POKESEARCH_PollGroupTouch
 * address: 0x022000F0
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov186
 * isa: thumb
 * status: EXACT
 * symbols:
 *   TOUCHPANEL_HitTrg 0x02035C08 arm
 *   TOUCHPANEL_GetPointTrg 0x02035D20 arm
 *   func_021FD860 0x021FD860 thumb ov186
 *   GFL_USE_PlaySeDefaultVolume 0x020061E4 thumb
 *   gBrPokeSearchHitTable 0x02200CD0 data a1
 */
#include "../include/Obj24879.h"
extern int TOUCHPANEL_HitTrg(const void *);
extern unsigned int TOUCHPANEL_GetPointTrg(unsigned int *outA, unsigned int *outB);
extern void func_021FD860(int, int, int *);
typedef unsigned int   u32;
extern void GFL_USE_PlaySeDefaultVolume(u32 a);
extern const char gBrPokeSearchHitTable[];
int BR_POKESEARCH_PollGroupTouch(char *p)
{
    int x, y, args[2];
    int index = TOUCHPANEL_HitTrg(gBrPokeSearchHitTable);
    if (index != -1) {
        if (*(unsigned char *)(p + index + 0x14)) {
            TOUCHPANEL_GetPointTrg((unsigned int *)(&x), (unsigned int *)(&y));
            args[0] = x;
            args[1] = y;
            func_021FD860(((struct Obj24879 *)p)->f78, 1, args);
            GFL_USE_PlaySeDefaultVolume(0x703);
            return index;
        }
        GFL_USE_PlaySeDefaultVolume(0x704);
    }
    return 9;
}
