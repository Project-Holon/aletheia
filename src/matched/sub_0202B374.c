/*
 * function: func_0202B374
 * address:  0x0202B374
 * packet:   pkt_0202B374
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Element {
    u16 id;
    u8  pad[26];
};

struct Container {
    u8 count;
    u8 pad[3];
    struct Element * volatile items;
};

struct Element *func_0202B374(struct Container *p, u16 key)
{
    int i;

    if ((int)p->count <= 0) {
        return 0;
    }

    for (i = 0; i < (int)p->count; i++) {
        if (p->items[i].id == key) {
            return &p->items[i];
        }
    }

    return 0;
}
