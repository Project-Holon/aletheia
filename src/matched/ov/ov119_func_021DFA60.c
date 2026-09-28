/*
 * function: func_021DFA60
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
 *   func_020061E4   0x020061E4  thumb
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

extern void func_020061E4(u32);
extern const Table g_021E7844;

void func_021DFA60(u32 key)
{
    Table local;
    unsigned int i;

    local = g_021E7844;
    for (i = 0; i < 25; i++)
        if (key == local.t[i].b)
            func_020061E4(local.t[i].a);
}
