/*
 * unit:     no
 * function: MYSTERY_DATA_GetCardPtr
 * address:  0x02009FD4
 * packet:   pkt_02009F1C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTERY_DATA_IsValidGiftType  0x02009F0C  thumb
 *   MYSTERY_DATA_GetCardMax  0x0200A400  thumb
 *   MYSTERY_DATA_GetCardSlot  0x0200A43C  thumb
 */
#include "../include/Obj15578.h"

struct Obj;
extern unsigned int MYSTERY_DATA_GetCardMax(struct Obj *p);
extern void *MYSTERY_DATA_GetCardSlot(struct Obj *p, unsigned int i);
typedef unsigned int   u32;
extern u32 MYSTERY_DATA_IsValidGiftType(u32 a);
void *MYSTERY_DATA_GetCardPtr(char *p, unsigned int idx)
{
    unsigned char *e = (unsigned char *)MYSTERY_DATA_GetCardSlot((struct Obj *)p, idx);
    unsigned int n = MYSTERY_DATA_GetCardMax((struct Obj *)p);
    if (idx < n && MYSTERY_DATA_IsValidGiftType(((struct Obj15578 *)e)->fB3) != 0)
        return e;
    return 0;
}

