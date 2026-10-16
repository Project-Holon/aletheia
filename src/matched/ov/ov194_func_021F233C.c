/*
 * function: NAMEIN_GRAPHIC_ClearSecondary
 * address:  0x021F233C
 * packet:   pkt_021F233C
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_GetEosChar 0x02045A98 arm
 */
#include "../include/Obj03897.h"

extern unsigned int STRBUF_GetEosChar(void);

void NAMEIN_GRAPHIC_ClearSecondary(char *p)
{
    if (((struct Obj03897 *)p)->f20 != 0)
    {
        unsigned int v;
        ((struct Obj03897 *)p)->f20 = 0;
        v = STRBUF_GetEosChar();
        *(unsigned short *)(p + 0x16 + (((struct Obj03897 *)p)->f20 << 1)) = v;
        ((struct Obj03897 *)p)->f28 = 1;
    }
}
