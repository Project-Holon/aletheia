/*
 * function: BMP_WIN_Init
 * address:  0x02045088
 * packet:   pkt_020445F4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   g_02146A50     0x02146A50  data
 *   str_020A7E70   0x020A7E70  data
 *   func_02030734  0x02030734  arm
 *
 * The one-time init of the BG subsystem's heap record.  Four bytes are
 * allocated on the heap the caller names, the pointer is published in the
 * global at 0x02146A50, and the heap id itself is written back into the
 * first halfword of the block.  Every later allocation in this family reads
 * that halfword back out (see src/matched/BMP_WIN_MakeScreen.c, which spells it
 * (*g_02146A50 & 0x7fff) | 0x8000), so the block is the subsystem's record
 * of which heap it owns.
 *
 * The allocator's fourth and fifth arguments are the same debug site string
 * and tag pair used everywhere else in this file; here the tag is 0x4f.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_WIN_Init.c \
 *       --func BMP_WIN_Init --addr 0x02045088 --cc 1.1p1 --arm
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern u16 *g_02146A50;
extern const char str_020A7E70[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);

void BMP_WIN_Init(u16 heapId)
{
    u16 *p = func_02030734(heapId, 4, 0, str_020A7E70, 0x4f);

    g_02146A50 = p;
    *p = heapId;
}
