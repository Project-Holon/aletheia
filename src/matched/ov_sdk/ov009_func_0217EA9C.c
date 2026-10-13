/*
 * function: gsiMemoryCallbacksSet
 * address:  0x0217EA9C
 * packet:   pkt_ov009_0217EA9C
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_021A3730                   0x021A3730  data
*/

extern void *d_021A3730[4];

void gsiMemoryCallbacksSet(void *(*p_malloc)(unsigned long), void (*p_free)(void *), void *(*p_realloc)(void *, unsigned long), void *(*p_memalign)(unsigned long, unsigned long))
{
    d_021A3730[0] = p_malloc;
    d_021A3730[1] = p_free;
    d_021A3730[2] = p_realloc;
    d_021A3730[3] = p_memalign;
}
