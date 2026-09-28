/*
 * function: func_0215CE7C
 * address:  0x0215CE7C
 * packet:   pkt_0215CE7C
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021AA484 0x021AA484 data ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern void func_02085DBC(void *heap, void *ptr, u32 flags);
extern void *g_021AA484;

void func_0215CE7C(void *ptr)
{
    if (ptr != 0) {
        func_02085DBC(&g_021AA484, ptr, 0);
    }
}
