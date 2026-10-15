/*
 * function: WIFICLUB_SetFriendNameWord
 * address:  0x021C2370
 * packet:   pkt_ov099_021BF2C4
 * region:   ov099
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02009864  0x02009864  thumb
 *   func_020099E4  0x020099E4  thumb
 *   WORDSET_SetSlotTag  0x0201EE0C  thumb
 */
typedef struct {
    int pad00;
    void *f4;               /* 0x04 */
    char pad08[0xd4];
    int fdc;                /* 0xdc */
    char pade0[0x10];
    int ff0;                /* 0xf0 */
    char padf4[0x8b0 - 0xf4];
    int f8b0;               /* 0x8b0 */
} Work;

typedef unsigned int   u32;
struct Sub020097BCObj;
extern u32 func_02009864(const struct Sub020097BCObj *obj, u32 i, u32 field);
extern void func_020099E4(struct Sub020097BCObj *obj, int i, void *dest);
struct WordSet;
extern void WORDSET_SetSlotTag(struct WordSet *p, u32 i, const void *src, u32 n, u32 f, u32 c);

void WIFICLUB_SetFriendNameWord(Work *w, int id)
{
    int r;

    if (id != -1) {
        r = func_02009864(w->f4, id, 9);
        func_020099E4(w->f4, id, (void *)w->ff0);
        WORDSET_SetSlotTag((struct WordSet *)w->f8b0, 0, (const void *)w->ff0, r, 1, 2);
    }
}
