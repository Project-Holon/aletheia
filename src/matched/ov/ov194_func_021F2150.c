/*
 * function: NAMEIN_GRAPHIC_Backspace
 * address:  0x021F2150
 * packet:   pkt_021F2150
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   STRBUF_GetEosChar 0x02045A98 arm
 */
#include "../include/Obj03896.h"

extern unsigned short STRBUF_GetEosChar(void);

int NAMEIN_GRAPHIC_Backspace(unsigned char *p)
{
    if (((struct Obj03896 *)p)->f20 != 0) {
        ((struct Obj03896 *)p)->f20 -= 1;
        *(unsigned short *)(p + 0x16 + ((struct Obj03896 *)p)->f20 * 2) =
            STRBUF_GetEosChar();
        ((struct Obj03896 *)p)->f28 = 1;
        return 1;
    }
    if (((struct Obj03896 *)p)->f1E != 0) {
        ((struct Obj03896 *)p)->f1E -= 1;
        *(unsigned short *)(p + ((struct Obj03896 *)p)->f1E * 2) =
            STRBUF_GetEosChar();
        ((struct Obj03896 *)p)->f28 = 1;
        return 1;
    }
    return 0;
}
