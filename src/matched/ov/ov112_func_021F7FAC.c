/*
 * function: STA_ACT_LIGHT_AnimH
 * address: 0x021F7FAC
 * packet: pkt_ov112_021F7FAC
 * region: ov112
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MUSICAL_MCSS_SetElemRotZ 0x021F4EB4 thumb ov112
 *   table 0x020A1B38 data a2
 *   GFL_USE_StopSeSlot  0x020061F8  thumb  arm9
 */
#include "../include/Obj10324.h"
#include "../include/Obj22566.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef struct { u16 count, pad; int index; } Tail;
extern s16 table[];
extern void GFL_USE_StopSeSlot(int);
typedef unsigned int   u32;
extern void MUSICAL_MCSS_SetElemRotZ(u32 unused, u32 p, s16 a, s16 b);
void STA_ACT_LIGHT_AnimH(char *p, char *q) {
    Tail *t = (Tail *)(q + 0xf0);
    u16 angle = ((int)t->count << 11) % 65536;
    t->count++;
    if (t->count >= 0xb4) {
        ((struct Obj22566 *)q)->f104 = 0;
        ((struct Obj10324 *)p)->f43C -= 1;
        if (((struct Obj10324 *)p)->f43C == 0) GFL_USE_StopSeSlot(2);
        return;
    }
    MUSICAL_MCSS_SetElemRotZ(((struct Obj10324 *)p)->f10, *(int *)(q + 0x84 + t->index * 4),
                  table[(angle >> 4) * 2] / 8 + 1024,
                  table[(angle >> 4) * 2 + 1] / 8 + 1024);
}
