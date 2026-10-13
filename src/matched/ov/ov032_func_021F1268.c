/*
 * function: func_021F1268
 * address:  0x021F1268
 * packet:   pkt_ov032_021F1268
 * region:   ov032
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021F1268 0x021F1268 thumb
 *   GAME_BEACON_ACCESSOR_TableGetRingIndex 0x021659F0 thumb ov010
 *   func_021F0F44 0x021F0F44 thumb
 *   func_021F1080 0x021F1080 thumb
 */
#include "../include/Obj09797.h"
#include "../include/Obj13063.h"

typedef unsigned char u8;

extern int GAME_BEACON_ACCESSOR_TableGetRingIndex(u8 *q, int delta);
extern char *func_021F0F44(char *this, u8 id);
extern void func_021F1080(char *this, char *e, int i, int j);

void func_021F1268(char *this)
{
    int i;
    char *e;

    for (i = 0; i < ((struct Obj09797 *)this)->f7D; i++) {
        e = func_021F0F44(this, GAME_BEACON_ACCESSOR_TableGetRingIndex(*(u8 * *)&((struct Obj09797 *)this)->f3C, ((struct Obj09797 *)this)->f7C + i));
        if (((struct Obj13063 *)e)->f30 == 0 || ((struct Obj13063 *)e)->f2C != 0)
            func_021F1080(this, e, 0, 0);
    }
}
