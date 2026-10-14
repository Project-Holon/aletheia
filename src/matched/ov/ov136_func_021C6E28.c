/*
 * function: MB_SEQ_StateRedrawPage
 * address:  0x021C6E28
 * packet:   pkt_ov136_021C6E28
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MB_SEQ_DrawPage 0x021C5C00 thumb
 *   MB_SEQ_SetActorVisible 0x021C66B8 thumb
 */
#include "../include/Obj03302.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MB_SEQ_SetActorVisible(u8 *, int, u32);
extern void MB_SEQ_DrawPage(u8 *);
int MB_SEQ_StateRedrawPage(u8 *p)
{
    if (((struct Obj03302 *)p)->f1C == 0) {
        MB_SEQ_SetActorVisible(*(u8 * *)&((struct Obj03302 *)p)->f8, 0, 0);
        MB_SEQ_SetActorVisible(*(u8 * *)&((struct Obj03302 *)p)->f8, 1, 1);
    } else {
        MB_SEQ_SetActorVisible(*(u8 * *)&((struct Obj03302 *)p)->f8, 0, 1);
        MB_SEQ_SetActorVisible(*(u8 * *)&((struct Obj03302 *)p)->f8, 1, 0);
    }
    MB_SEQ_DrawPage(p);
    return 9;
}
