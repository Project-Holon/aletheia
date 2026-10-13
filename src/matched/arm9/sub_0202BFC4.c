/*
 * function: ISS_ZONE_SYS_FindRecord
 * address:  0x0202BFC4
 * packet:   pkt_0202BEBC
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

struct Item {
    u16 key;
    u16 pad[3];
};

struct Container {
    u8 pad[4];
    u8 count;
    u8 pad2[3];
    const struct Item *items;
};

u32 ISS_ZONE_SYS_FindRecord(const struct Container *c, u32 key)
{
    u8 i;

    for (i = 0; i < c->count; i++) {
        if (c->items[i].key == key) {
            return i;
        }
    }

    return 0xff;
}
