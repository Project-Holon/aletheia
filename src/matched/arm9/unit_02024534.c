/*
 * unit:     yes
 * function: PMSI_PARAM_Compare
 * address:  0x02024534
 * packet:   pkt_02024534
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned short u16;

struct Data {
    u16 a;
    u16 b;
    u16 c[2];
};

int PMSI_PARAM_Compare(const struct Data *p1, const struct Data *p2)
{
    int i;

    if (p1->a != p2->a || p1->b != p2->b) {
        return 0;
    }

    for (i = 0; i < 2; i++) {
        if (p1->c[i] != p2->c[i]) {
            return 0;
        }
    }

    return 1;
}
