/*
 * function: func_021BB3AC
 * address:  0x021BB3AC
 * packet:   pkt_ov223_021BB3AC
 * region:   ov223
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * This address is also matched as func_021BB3AC in ov021; the ov223 copy is a
 * distinct function and gets its own shard.
 *
 * symbols:
 *   func_02027FD8  0x02027FD8  thumb
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int   u32;
struct TaskMenuState;
extern u32 func_02027FD8(struct TaskMenuState *s);

int func_021BB3AC(int *p)
{
    return func_02027FD8((struct TaskMenuState *)p[0x97]);
}
