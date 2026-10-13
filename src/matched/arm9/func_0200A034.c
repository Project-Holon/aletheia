/*
 * function: MYSTERY_DATA_AddCard
 * address:  0x0200A034
 * packet:   pkt_0200A034
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTERY_DATA_IsValidGiftType  0x02009F0C  thumb
 *   MYSTERY_DATA_CheckCardSpace  0x02009F1C  thumb
 *   MYSTERY_DATA_GetCardMax  0x0200A400  thumb
 *   MYSTERY_DATA_GetCardSlot  0x0200A43C  thumb
 *   MYSTERY_DATA_Encrypt  0x0200A480  thumb
 *   MYSTERY_DATA_Decrypt  0x0200A49C  thumb
 *   MI_CpuCopy8  0x02082D44  arm
 */
#include "../include/Obj15579.h"

typedef unsigned char u8;
typedef unsigned int   u32;
struct Obj;
extern u32 MYSTERY_DATA_GetCardMax(struct Obj *obj);
extern void MYSTERY_DATA_Decrypt(struct Obj *obj);
extern int MYSTERY_DATA_CheckCardSpace(void *p);
extern void *MYSTERY_DATA_GetCardSlot(struct Obj *obj, u32 index);
extern u32 MYSTERY_DATA_IsValidGiftType(u32 a);
extern void MYSTERY_DATA_Encrypt(struct Obj *obj);
extern void MI_CpuCopy8(void *dst, void *src, int n);
int MYSTERY_DATA_AddCard(void *p, void *arg)
{
    unsigned int i;
    int found = 0;
    unsigned int n = (unsigned int)MYSTERY_DATA_GetCardMax(p);
    MYSTERY_DATA_Decrypt(p);
    if (MYSTERY_DATA_CheckCardSpace(p) == 1) {
        for (i = 0; i < n; i++) {
            void *slot = MYSTERY_DATA_GetCardSlot(p, i);
            if (MYSTERY_DATA_IsValidGiftType(((struct Obj15579 *)slot)->fB3) == 0) {
                MI_CpuCopy8(arg, slot, 0xcc);
                found = 1;
                break;
            }
        }
    }
    MYSTERY_DATA_Encrypt(p);
    return found;
}
