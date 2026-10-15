/*
 * function: NAMEIN_GRAPHIC_CopyToStrbuf
 * address:  0x021F2328
 * packet:   pkt_021F2328
 * region:   ov194
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   STRBUF_SetStringN 0x02045994 arm
 */
#include "../include/Obj24901.h"

typedef unsigned short u16;
typedef unsigned int u32;
struct Strbuf;
extern void STRBUF_SetStringN(struct Strbuf *o, const u16 *src, u32 len);

void NAMEIN_GRAPHIC_CopyToStrbuf(char *self, struct Strbuf *dst)
{
    STRBUF_SetStringN(dst, (const u16 *)self,
                 ((struct Obj24901 *)self)->f1E + 1);
}
