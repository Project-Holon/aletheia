/*
 * function: ISS_CITY_SYS_FindUnitIndex
 * address:  0x0202ADD8
 * packet:   pkt_0202ADD8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_0202AF30  0x0202AF30  thumb
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Container {
    u8 pad[0x14];
    void **items;
    u8 count;
};

extern u32 sub_0202AF30(void *obj);

u8 ISS_CITY_SYS_FindUnitIndex(struct Container *p, u32 key)
{
    int i;
    u8 count = p->count;

    for (i = 0; i < count; i++) {
        if (key == sub_0202AF30(p->items[i])) {
            return (u8)i;
        }
    }

    return 0xff;
}
