/*
 * function: BOX2_MAIN_FindMoverSlot
 * address:  0x021DE5C8
 * packet:   pkt_ov170_021DE5C8
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 */
#include "../include/Obj00000.h"
#include "../include/Obj23846.h"

typedef struct {
    unsigned short id;
    unsigned short val;
    unsigned short f4;
    unsigned short used;
    unsigned char pad[0x10];
} Entry;

int BOX2_MAIN_FindMoverSlot(char *p, unsigned id)
{
    Entry *e = *(Entry * *)&((struct Obj23846 *)(*(char * *)&((struct Obj00000 *)p)->f2C))->f60;
    unsigned i;
    for (i = 0; i < 7; i++) {
        if (e[i].used != 0 && id == e[i].id)
            return e[i].val;
    }
    return ((unsigned char *)p)[0x16];
}
