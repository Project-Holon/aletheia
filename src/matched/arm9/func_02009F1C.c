/*
 * function: MYSTERY_DATA_CheckCardSpace
 * address:  0x02009F1C
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

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj;
extern u32 MYSTERY_DATA_GetCardMax(struct Obj *obj);
extern void *MYSTERY_DATA_GetCardSlot(struct Obj *obj, u32 index);
extern u32 MYSTERY_DATA_IsValidGiftType(u32 a);

int MYSTERY_DATA_CheckCardSpace(void *a0)
{
    u32 i;
    u32 n = MYSTERY_DATA_GetCardMax(a0);

    for (i = 0; i < n; i++) {
        if (MYSTERY_DATA_IsValidGiftType(((u8 *)MYSTERY_DATA_GetCardSlot(a0, i))[0xb3]) == 0)
            return 1;
    }
    return 0;
}
