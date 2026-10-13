/*
 * function: MYSTERY_DATA_DeleteCard
 * address:  0x0200A094
 * packet:   pkt_0200A034
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTERY_DATA_CloseCardGap  0x02009F7C  thumb
 *   MYSTERY_DATA_GetCardMax  0x0200A400  thumb
 *   MYSTERY_DATA_GetCardSlot  0x0200A43C  thumb
 *   MYSTERY_DATA_Encrypt  0x0200A480  thumb
 *   MYSTERY_DATA_Decrypt  0x0200A49C  thumb
 */
#include "../include/Obj15580.h"

typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern u32 MYSTERY_DATA_GetCardMax(struct Obj *obj);
extern void MYSTERY_DATA_Decrypt(struct Obj *obj);
extern void *MYSTERY_DATA_GetCardSlot(struct Obj *obj, u32 index);
extern void MYSTERY_DATA_CloseCardGap(void *p, unsigned int i);
extern void MYSTERY_DATA_Encrypt(struct Obj *obj);
void MYSTERY_DATA_DeleteCard(void *p, unsigned int idx)
{
    unsigned int n = (unsigned int)MYSTERY_DATA_GetCardMax(p);
    MYSTERY_DATA_Decrypt(p);
    if (idx < n) {
        void *slot = MYSTERY_DATA_GetCardSlot(p, idx);
        ((struct Obj15580 *)slot)->fB3 = 0;
        MYSTERY_DATA_CloseCardGap(p, idx);
    }
    MYSTERY_DATA_Encrypt(p);
}
