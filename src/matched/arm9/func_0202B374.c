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
 *
 * iss_dungeon_sys.c: find the 0x1C-byte item whose id matches, or NULL.
 * Three shape facts close it (docs/notes/pkt_0202B374.c.txt had 6, later
 * 31, bytes out):
 *   - the loop is written as its own guard plus do/while, with the items
 *     base loaded inside the guard (the image loads it after `cmp; ble`);
 *   - the items pointer member is volatile, so the hit path re-reads it
 *     (`ldr r0, [r0, #4]`) instead of reusing the loop's base;
 *   - the count goes through a copy local before the bound (found by
 *     tools/permuter.py, temp(tmp=c->count)): it swaps the bound and the
 *     base between r7 and r6 to the image's choice.
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
    Item * volatile items;
} Container;

Item *func_0202B374(Container *c, u16 id)
{
    int i;
    int n;
    Item *it;
    int count = c->count;

    n = count;
    i = 0;
    if (i < n) {
        it = c->items;
        do {
            if (id == it[i].id)
                return &c->items[i];
            i++;
        } while (i < n);
    }
    return 0;
}
