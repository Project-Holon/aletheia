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

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct Item {
    u16 id;
    u8 pad[0x1a];
} Item;

typedef struct Container {
    u8 count;
    u8 pad[3];
    Item *items;
} Container;

Item *func_0202B374(Container *c, u16 id)
{
    int i;
    for (i = 0; i < c->count; i++) {
        if (c->items[i].id == id) {
            return (Item *)((char *)c->items + i * 0x1c);
        }
    }
    return 0;
}
