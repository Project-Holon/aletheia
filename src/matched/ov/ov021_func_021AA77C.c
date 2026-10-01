/*
 * function: func_021AA77C
 * address:  0x021AA77C
 * packet:   pkt_ov021_021AA77C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030734  0x02030734  arm
 *   d_021DDFB4  0x021DDFB4  data  a4
 */

extern void *func_02030734(int heap, int size, int clear, const char *file, int line);
extern char d_021DDFB4[];

void *func_021AA77C(int heap)
{
    return func_02030734(heap, 0x5c0, 1, d_021DDFB4, 0x6e);
}
