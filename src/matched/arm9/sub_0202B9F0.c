/*
 * function: ISS_3DS_SYS_FindTableIndex
 * address:  0x0202B9F0
 * packet:   pkt_0202B9F0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Item {
    u32 id;
    u32 unk;
};

struct Obj {
    u8 pad[0x264];
    const struct Item *items;
    u8 count;
};

u8 ISS_3DS_SYS_FindTableIndex(const struct Obj *p, u32 key)
{
    const struct Item *items = p->items;
    u8 count;
    u8 i;

    if (items == 0) {
        return 0xff;
    }

    count = p->count;
    for (i = 0; i < count; i++) {
        if (items[i].id == key) {
            return i;
        }
    }

    return 0xff;
}
