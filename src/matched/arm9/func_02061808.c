/*
 * function: func_02061808
 * address:  0x02061808
 * packet:   pkt_0206123C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_02146B74       0x02146B74  data
 */

#include "../include/G_Arena02146B74.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Pair02061808 {
    u32 a;
    u32 b;
};

extern struct Arena02146B74 g_02146B74;

void func_02061808(struct Pair02061808 *dst)
{
    dst->a = g_02146B74.a;
    dst->b = g_02146B74.b;
}
