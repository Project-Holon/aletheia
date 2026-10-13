/*
 * function: BTL_SIDE_GetPokeAtPos
 * address:  0x021B98AC
 * packet:   pkt_ov093_021B98AC
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   BTL_MAIN_GetSlotClientId  0x021B8CFC  thumb  ov093
 *   BTL_SLOT_GetCount  0x021B9B94  thumb  ov093
 *   BTL_SLOT_GetPokeParam  0x021B9C00  thumb  ov093
 */

typedef unsigned char u8; typedef unsigned short u16; typedef unsigned int u32;

extern u8 BTL_MAIN_GetSlotClientId(char *p, int i);
struct Q1;
extern u8 BTL_SLOT_GetCount(struct Q1 *p);
struct S2;
extern u8 *BTL_SLOT_GetPokeParam(struct S2 *p, u32 i);

u8 *BTL_SIDE_GetPokeAtPos(char *const *q, u8 b)
{
    u8 i = b;
    char *p = *q;
    u8 a;
    u8 cnt;
    char *g;

    a = BTL_MAIN_GetSlotClientId(p, b);
    cnt = 0;
    while (i-- != 0) {
        if (a == *(u8 *)(p + i + 0x428))
            cnt++;
    }
    g = (char *)q + 4 + a * 0x1c;
    if (cnt < BTL_SLOT_GetCount((struct Q1 *)g))
        return BTL_SLOT_GetPokeParam((struct S2 *)g, cnt);
    return 0;
}
