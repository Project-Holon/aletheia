/*
 * function: NAMEIN_GRAPHIC_AppendCandidate
 * address:  0x021F21BC
 * packet:   pkt_021F21BC
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_GetEosChar 0x02045A98 arm
 *   NAMEIN_GRAPHIC_PickCandidate 0x021F23FC thumb
 */
#include "../include/Obj01574.h"

extern unsigned short STRBUF_GetEosChar(void);
typedef unsigned char  u8;
extern int NAMEIN_GRAPHIC_PickCandidate(u8 *p, int direction);

int NAMEIN_GRAPHIC_AppendCandidate(unsigned char *p, unsigned short a, unsigned short b)
{
    if (((struct Obj01574 *)p)->f1E < ((struct Obj01574 *)p)->f22 &&
        ((struct Obj01574 *)p)->f20 < 3) {
        *(unsigned short *)(p + 0x16 + ((struct Obj01574 *)p)->f20 * 2) = a;
        ((struct Obj01574 *)p)->f20 += 1;
        *(unsigned short *)(p + 0x16 + ((struct Obj01574 *)p)->f20 * 2) =
            STRBUF_GetEosChar();
        NAMEIN_GRAPHIC_PickCandidate(p, b);
        ((struct Obj01574 *)p)->f28 = 1;
        return 1;
    }
    return 0;
}
