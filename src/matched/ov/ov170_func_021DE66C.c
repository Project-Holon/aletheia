/*
 * function: BOX2_MAIN_SetMoverEntry
 * address:  0x021DE66C
 * packet:   pkt_ov170_021DE66C
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_SEQ_SwapSlotActorsB 0x021ECBD8 thumb
 *   BOX2_SEQ_SetSlotDrawPriority 0x021EC768 thumb
 */
#include "../include/Obj00000.h"
#include "../include/Obj23848.h"

typedef struct {
    unsigned short id;
    unsigned short slot;
    unsigned short src;
    unsigned short used;
    int vx;
    int vy;
    short dx;
    short dy;
    short x;
    short y;
} Entry;

extern void BOX2_SEQ_SwapSlotActorsB(unsigned char *p, int i);
extern void BOX2_SEQ_SetSlotDrawPriority(char *p, unsigned i, int flag);

void BOX2_MAIN_SetMoverEntry(char *p, Entry *e)
{
    unsigned char buf[7];
    unsigned short i;
    unsigned short save = 0xFFFF;
    for (i = 0; i < 7; i++) {
        if (e[i].used != 0)
            buf[i] = *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e[i].src + 0x3DD2);
    }
    for (i = 0; i < 7; i++) {
        if (e[i].used == 0)
            continue;
        if (e[i].slot <= 0x24) {
            *(unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C + e[i].slot + 0x3DD2) = buf[i];
            if (e[i].id == 0x24)
                save = e[i].slot;
        } else {
            ((struct Obj23848 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f3DF6 = buf[i];
            if (e[i].id == 0x24)
                save = 0x24;
        }
    }
    if (save != 0xFFFF)
        BOX2_SEQ_SwapSlotActorsB((unsigned char *)(*(char * *)&((struct Obj00000 *)p)->f2C), save);
    for (i = 0; i < 0x24; i++)
        BOX2_SEQ_SetSlotDrawPriority(*(char * *)&((struct Obj00000 *)p)->f2C, i, 1);
}
