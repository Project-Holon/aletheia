/*
 * function: EFFECT_ENCOUNT_Create
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
 *   sEffectEncountFileName  0x021DDFB4  data  a4
 */

typedef unsigned short u16;
typedef unsigned int   u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern char sEffectEncountFileName[];

void *EFFECT_ENCOUNT_Create(int heap)
{
    return func_02030734(heap, 0x5c0, 1, sEffectEncountFileName, 0x6e);
}
