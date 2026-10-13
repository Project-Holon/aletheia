/*
 * unit:     no
 * function: func_0200A104
 * address:  0x0200A104
 * packet:   pkt_0200A104
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   MYSTERY_DATA_GetCardMax  0x0200A400  thumb
 *   MYSTERY_DATA_GetCardSlot  0x0200A43C  thumb
 *   MYSTERY_DATA_Encrypt  0x0200A480  thumb
 *   MYSTERY_DATA_Decrypt  0x0200A49C  thumb
 */
#include "../include/Obj15581.h"

struct Obj;
extern unsigned int MYSTERY_DATA_GetCardMax(struct Obj *obj);
extern void MYSTERY_DATA_Decrypt(struct Obj *obj);
extern void MYSTERY_DATA_Encrypt(struct Obj *obj);
extern void *MYSTERY_DATA_GetCardSlot(struct Obj *obj, unsigned int index);
int func_0200A104(char *p, unsigned int idx)
{
    int r = 0;
    unsigned int n = MYSTERY_DATA_GetCardMax((struct Obj *)p);
    MYSTERY_DATA_Decrypt((struct Obj *)p);
    if (idx < n) {
        unsigned char *e = (unsigned char *)MYSTERY_DATA_GetCardSlot((struct Obj *)p, idx);
        if (((unsigned int)(((struct Obj15581 *)e)->fB4) << 0x1e) >> 0x1f)
            r = 1;
    }
    MYSTERY_DATA_Encrypt((struct Obj *)p);
    return r;
}
