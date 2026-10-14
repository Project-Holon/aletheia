/*
 * function: POKETRADE_NEGO_PlaySeByKeyA
 * address:  0x021DFA60
 * packet:   pkt_ov119_021DFA60
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   GFL_USE_PlaySeDefaultVolume   0x020061E4  thumb
 *   g_021E7844      0x021E7844  data  ov119
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

typedef struct {
    u32 a;
    u32 b;
} Pair;

typedef struct {
    Pair t[25];
} Table;

extern void GFL_USE_PlaySeDefaultVolume(u32);
extern const Table g_021E7844;

void POKETRADE_NEGO_PlaySeByKeyA(u32 key)
{
    Table local;
    unsigned int i;

    local = g_021E7844;
    for (i = 0; i < 25; i++)
        if (key == local.t[i].b)
            GFL_USE_PlaySeDefaultVolume(local.t[i].a);
}
