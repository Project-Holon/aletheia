/*
 * function: NAMEIN_GRAPHIC_AppendChar
 * address:  0x021F2190
 * packet:   pkt_021F2190
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
#include "../include/Obj02909.h"

extern unsigned int STRBUF_GetEosChar(void);

int NAMEIN_GRAPHIC_AppendChar(char *p, unsigned short v)
{
    if (((struct Obj02909 *)p)->f1E < ((struct Obj02909 *)p)->f22)
    {
        *(unsigned short *)(p + (((struct Obj02909 *)p)->f1E << 1)) = v;
        ((struct Obj02909 *)p)->f1E += 1;
        *(unsigned short *)(p + (((struct Obj02909 *)p)->f1E << 1)) = STRBUF_GetEosChar();
        ((struct Obj02909 *)p)->f28 = 1;
        return 1;
    }
    return 0;
}
