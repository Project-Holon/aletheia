/*
 * function: func_021E9634
 * address:  0x021E9634
 * packet:   pkt_ov093_021E9634
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BTL_MAIN_GetSlotFromViewPos  0x021B8ED8  thumb  ov093
 *   BTL_SIDE_GetPokeAtPos  0x021B98AC  thumb  ov093
 */
typedef unsigned char u8;
typedef unsigned int u32;

extern u8 BTL_MAIN_GetSlotFromViewPos(u8 *p, u8 k);
extern u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b);

struct Pair {
    u8 *a;
    u32 pad;
    char *const *q;
};

u8 *func_021E9634(struct Pair *s, u32 k)
{
    return BTL_SIDE_GetPokeAtPos(s->q, BTL_MAIN_GetSlotFromViewPos(s->a, k));
}
