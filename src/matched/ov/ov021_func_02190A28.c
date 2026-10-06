/*
 * function: func_02190A28
 * address:  0x02190A28
 * packet:   pkt_ov021_02190A28
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F878  0x0201F878  thumb  arm9
 *   func_02190A20  0x02190A20  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef short          s16;

typedef struct Pair {
    u32 a;
    u32 b;
} Pair;

extern u32 func_02190A20(int n, u32 d);
struct Slot;
extern void func_0201F878(struct Slot *table, u32 a, u32 b, u32 tag, u32 heap);

u32 func_02190A28(const Pair *arr, int n, u32 c, u16 d)
{
    u32 obj;
    int i;

    obj = func_02190A20(n, d);
    for (i = 0; i < n; i++)
        func_0201F878((struct Slot *)obj, c, arr[i].a, arr[i].b, d);
    return obj;
}
