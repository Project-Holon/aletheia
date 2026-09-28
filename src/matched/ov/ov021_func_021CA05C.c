/*
 * function: func_021CA05C
 * address:  0x021CA05C
 * packet:   pkt_ov021_021CA05C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Draws the current page of the +0x32 list through 0x021CBED8; kinds 2, 3, 7, 8 draw two pages with the slot tags.
 *
 * symbols:
 *   func_0200DA54  0x0200DA54  thumb
 *   func_0200DEA8  0x0200DEA8  thumb
 *   func_021CBED8  0x021CBED8  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u16 tag : 11;
    u16 hi  : 5;
    u16 val;
    u8  pad4[0x38];
} Slot;

extern u32 func_0200DA54(u32 h);
extern void func_0200DEA8(u32 h, u8 *list, u8 n, u16 id);
extern u8 func_021CBED8(u8 *p, u8 *list, u16 v, u8 n, u16 *tags, u16 *vals, u32 z, u16 id);

void func_021CA05C(u8 *p)
{
    u32 n = func_0200DA54(*(u32 *)(p + 0x70));
    int i;
    u32 j;
    u16 tags[2];
    u16 vals[2];

    switch (p[9]) {
    case 4:
        func_0200DEA8(*(u32 *)(p + 0x78), p + 0x88, n, *(u32 *)(p + 4));
        return;
    case 2:
    case 3:
    case 7:
    case 8:
        i = 0;
        j = n * 2;
        func_021CBED8(p, p + 0x88, ((u16 *)(p + 0x32))[j], p[8], 0, 0, 0, *(u32 *)(p + 4));
        for (; i < p[8]; i++) {
            tags[i] = ((Slot *)(p + 0xb8))[i].tag;
            vals[i] = ((Slot *)(p + 0xb8))[i].val;
        }
        func_021CBED8(p, p + 0x1a8, ((u16 *)(p + 0x32))[j + 1], p[8], tags, vals, 0, *(u32 *)(p + 4));
        return;
    }
    func_021CBED8(p, p + 0x88, ((u16 *)(p + 0x32))[n], p[8], 0, 0, 0, *(u32 *)(p + 4));
}
