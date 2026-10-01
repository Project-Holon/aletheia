/*
 * function: func_021A31D0
 * address:  0x021A31D0
 * packet:   pkt_ov021_021A31D0
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   data_021D890C  0x021D890C  data  a2
 */

typedef unsigned short u16;

typedef struct {
    u16 id;
    u16 val;
} Ent021A31D0;

extern const Ent021A31D0 data_021D890C[2][10];

int func_021A31D0(u16 id)
{
    int j;
    int i;
    const Ent021A31D0 *e;

    for (j = 0; j < 2; j++) {
        e = data_021D890C[j];
        for (i = 0; i < 10; i++) {
            if (e->id == id)
                return i;
            e++;
        }
    }
    return 10;
}
