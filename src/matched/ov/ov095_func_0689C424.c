/*
 * function: func_0689C424
 * address:  0x0689C424
 * packet:   pkt_ov095_0689C424
 * region:   ov095
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_0689E21C   0x0689E21C  data  ov095  a4
 */

typedef unsigned int u32;
typedef short s16;

typedef struct Ent {
    u32 key;
    s16 a;
    s16 b;
} Ent;

extern Ent d_0689E21C[17];

int func_0689C424(u32 key, int flag)
{
    u32 i;
    int v;

    for (i = 0; i < 17; i++) {
        if (key == d_0689E21C[i].key) {
            if (flag != 0)
                v = d_0689E21C[i].b;
            else
                v = d_0689E21C[i].a;
            if (v < 0)
                return d_0689E21C[i].a;
            return v;
        }
    }
    return -1;
}
