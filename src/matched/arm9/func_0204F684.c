/*
 * function: BILLBOARD_SetElemScale
 * address:  0x0204F684
 * packet:   pkt_0204F684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 */

typedef short s16;

struct Item0204F684 {
    char pad[0x12];
    s16 field_12;
    s16 field_14;
    char pad2[6];
};

struct Manager0204F684 {
    char pad[8];
    struct Item0204F684 *items;
};

void BILLBOARD_SetElemScale(struct Manager0204F684 *mgr, int idx, const s16 *p12, const s16 *p14)
{
    mgr->items[idx].field_12 = *p12;
    mgr->items[idx].field_14 = *p14;
}
