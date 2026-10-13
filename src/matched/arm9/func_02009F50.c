/*
 * unit:     no
 * function: MYSTERY_DATA_CheckCardExist
 * address:  0x02009F50
 * packet:   pkt_02009F1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MYSTERY_DATA_IsValidGiftType  0x02009F0C  thumb
 *   MYSTERY_DATA_GetCardMax  0x0200A400  thumb
 *   MYSTERY_DATA_GetCardSlot  0x0200A43C  thumb
 */
#include "../include/Obj15577.h"

struct Obj;
extern unsigned int MYSTERY_DATA_GetCardMax(struct Obj *obj);
extern void *MYSTERY_DATA_GetCardSlot(struct Obj *obj, unsigned int index);
typedef unsigned int   u32;
extern u32 MYSTERY_DATA_IsValidGiftType(u32 a);
int MYSTERY_DATA_CheckCardExist(char *p, unsigned int idx)
{
    unsigned char *e = (unsigned char *)MYSTERY_DATA_GetCardSlot((struct Obj *)p, idx);
    MYSTERY_DATA_GetCardMax((struct Obj *)p);
    if (idx < 0xc && MYSTERY_DATA_IsValidGiftType(((struct Obj15577 *)e)->fB3) != 0)
        return 1;
    return 0;
}

