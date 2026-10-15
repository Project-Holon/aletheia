/*
 * function: STA_ACT_LIGHT_StopSe
 * address: 0x021F7A98
 * packet: pkt_ov112_021F7A98
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 *
 * symbols:
 *   GFL_USE_StopSeSlot  0x020061F8  thumb  arm9
 */
#include "../include/Obj13842.h"
#include "../include/Obj22559.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
extern void GFL_USE_StopSeSlot(int);
typedef struct { u16 count, pad; int index; } Tail;
void STA_ACT_LIGHT_StopSe(char *p, char *q) {
    Tail *tail = (Tail *)(q + 0xf0);
    s16 *v = *(s16 **)(q + 0xa8 + tail->index * 4);
    v[1] += 0x1000;
    tail->count += 1;
    if (tail->count >= 0xc0) {
        ((struct Obj22559 *)q)->f104 = 0;
        ((struct Obj13842 *)p)->f43C -= 1;
        if (((struct Obj13842 *)p)->f43C == 0) GFL_USE_StopSeSlot(2);
    }
}
