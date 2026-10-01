/*
 * function: func_02194354
 * address:  0x02194354
 * packet:   pkt_ov021_02194354
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02194418  0x02194418  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u32 key; u32 x4; u32 x8; } Item;
typedef struct { u16 n; u16 pad; u32 x4; Item *items; } List;
extern void func_02194418(Item *);

void func_02194354(List *p, u32 key)
{
    Item *it;
    u16 i;

    it = p->items;
    for (i = 0; i < p->n; i++) {
        if (it->x8 != 0 && it->key == key) {
            func_02194418(it);
            return;
        }
        it++;
    }
}
