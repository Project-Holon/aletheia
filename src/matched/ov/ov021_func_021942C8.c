/*
 * function: func_021942C8
 * address:  0x021942C8
 * packet:   pkt_ov021_021942C8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02194418  0x02194418  thumb  ov021
 *   func_020307B0  0x020307B0  arm
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

typedef struct { u32 key; u32 x4; u32 x8; } Item;
typedef struct { u16 n; u16 pad; u32 x4; Item *items; } List;
extern int func_02194418(u32 a);
extern void func_020307B0(void *);

void func_021942C8(List *p)
{
    u16 i;
    Item *it;

    i = 0;
    it = p->items;
    if (i < p->n) {
        for (; i < p->n; i++) {
            if (it->x8 != 0) {
                func_02194418((u32)it);
            }
            it++;
        }
    }
    func_020307B0(p->items);
    func_020307B0(p);
}
