/*
 * function: func_02175004
 * address:  0x02175004
 * packet:   pkt_ov011_02175004
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02026478  0x02026478  thumb
 *   func_02012E40  0x02012E40  thumb
 *   INTRUDE_COMM_UpdatePlayerObject  0x02175060  thumb ov011
 */
#include "../include/Obj01838.h"

typedef unsigned char u8;

typedef struct Fl {
    u8 b0 : 1;
    u8 b1 : 1;
    u8 rest : 6;
} Fl;

typedef unsigned int   u32;
u32 func_02026478(void *obj);
u8 func_02012E40(const u8 *o);
void INTRUDE_COMM_UpdatePlayerObject(u8 *p, int i);

void func_02175004(u8 *p)
{
    u8 i;

    if (func_02012E40((const u8 *)func_02026478((void *)(((struct Obj01838 *)p)->f4))) == 1) {
        return;
    }
    if (((Fl *)(p + 0x904))->b1 == 1) {
        return;
    }
    for (i = 0; i < 3; i++) {
        if (p[0x927] & (1 << i)) {
            INTRUDE_COMM_UpdatePlayerObject(p, i);
            p[0x927] ^= (u8)(1 << i);
        }
    }
}
