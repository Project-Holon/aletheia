/*
 * function: MYSTERY_DATA_CloseCardGap
 * address:  0x02009F7C
 * packet:   pkt_02009F7C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   MYSTERY_DATA_CheckCardExist  0x02009F50  thumb
 *   MYSTERY_DATA_GetCardMax  0x0200A400  thumb
 *   MYSTERY_DATA_GetCardSlot  0x0200A43C  thumb
 */

typedef unsigned char u8;
typedef struct { int w[0x33]; } Slot;
typedef unsigned int   u32;
struct Obj;
extern u32 MYSTERY_DATA_GetCardMax(struct Obj *obj);
extern int MYSTERY_DATA_CheckCardExist(char *p, unsigned int idx);
extern void *MYSTERY_DATA_GetCardSlot(struct Obj *obj, u32 index);
extern void func_02082BCC(void *dst, int v, int n);
void MYSTERY_DATA_CloseCardGap(void *p, unsigned int idx)
{
    unsigned int i;
    unsigned int n = (unsigned int)MYSTERY_DATA_GetCardMax(p);
    if (MYSTERY_DATA_CheckCardExist(p, idx) != 0)
        return;
    for (i = idx; i < n - 1; i++) {
        void *dst = MYSTERY_DATA_GetCardSlot(p, i);
        void *src = MYSTERY_DATA_GetCardSlot(p, i + 1);
        *(Slot *)dst = *(Slot *)src;
    }
    func_02082BCC(MYSTERY_DATA_GetCardSlot(p, i), 0, 0xcc);
}
