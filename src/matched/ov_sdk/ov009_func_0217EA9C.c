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
 *   gGsMemoryFuncs                   0x021A3730  data
*/

extern void *gGsMemoryFuncs[4];

void gsiMemoryCallbacksSet(void *(*p_malloc)(unsigned long), void (*p_free)(void *), void *(*p_realloc)(void *, unsigned long), void *(*p_memalign)(unsigned long, unsigned long))
{
    gGsMemoryFuncs[0] = p_malloc;
    gGsMemoryFuncs[1] = p_free;
    gGsMemoryFuncs[2] = p_realloc;
    gGsMemoryFuncs[3] = p_memalign;
}
