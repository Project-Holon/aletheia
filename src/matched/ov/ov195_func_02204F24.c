/*
 * function: SHINKA_DEMO_PushBgm
 * address:  0x02204F24
 * packet:   pkt_02204F24
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   GFL_USE_SetBgmPlayerParam 0x02005DE4 thumb
 *   GFL_USE_PushBgm 0x02005E64 thumb
 */
#include "../include/Obj08346.h"

extern void GFL_USE_SetBgmPlayerParam(void *p);
extern int GFL_USE_PushBgm(void);

void SHINKA_DEMO_PushBgm(int a, int *b)
{
    if (((struct Obj08346 *)b)->f30 == 4) {
        GFL_USE_SetBgmPlayerParam((void *)1);
        GFL_USE_PushBgm();
        ((struct Obj08346 *)b)->f30 = 5;
    }
}