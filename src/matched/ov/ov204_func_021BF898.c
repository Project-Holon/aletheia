/*
 * function: func_021BF898
 * address: 0x021BF898
 * packet: pkt_ov204_021BF898
 * region: ov204
 * compiler: 1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Trailing two bytes are zero alignment padding.
 * symbols:
 *   GF_STANDARD_Rand 0x0203F0A8 arm
 *   MCSS_SetAnmStopFlag 0x02015E04 thumb
 *   func_021BF744 0x021BF744 thumb ov204
 *   _ull_mul 0x0209C054 arm
 */
#include "../include/Obj06674.h"

extern unsigned int GF_STANDARD_Rand(void);
extern void MCSS_SetAnmStopFlag(void *);
extern void func_021BF744(char *, unsigned int, unsigned int, unsigned int);

void func_021BF898(char *p)
{
    if (((struct Obj06674 *)p)->f18 != 0)
    {
        if (((struct Obj06674 *)p)->f68 == 0)
        {
            ((struct Obj06674 *)p)->f68 = 20 * (unsigned int)(((unsigned long long)GF_STANDARD_Rand() * 5) >> 32) + 200;
            func_021BF744(p, 1, 0, 1);
            return;
        }
        MCSS_SetAnmStopFlag(((struct Obj06674 *)p)->f14);
        --((struct Obj06674 *)p)->f68;
    }
}
