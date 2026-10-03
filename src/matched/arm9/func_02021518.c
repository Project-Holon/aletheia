/*
 * unit:     no
 * function: func_02021518
 * address:  0x02021518
 * packet:   pkt_02021444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02030734      0x02030734  arm
 *   MI_CpuFill8        0x02082BCC  arm
 *   func_02021518_File 0x020A73BC  data
 *
 * Allocate and zero the 0x120-byte palette-animation context.  0x120 is out
 * of Thumb immediate range, so the compiler materialises the tag 88 first
 * and derives the size from it with `adds r4, #0xc8`, the
 * docs/idioms/consecutive-line-numbers-are-one-pool-word-and-adds.md shape
 * applied to two unrelated constants that happen to be close.
 *
 * The heap id is truncated to 16 bits before the call (`lsls #16 / lsrs
 * #16`), so the value reaching the allocator is narrower than the parameter
 * this function receives.  A plain `u16` parameter forwarded unchanged does
 * not produce the pair, since mwcc assumes an incoming narrow parameter is
 * already truncated; the equally byte-exact reading is a `u16` heap-id
 * slot on the allocator prototype itself, which every other call site in
 * src/matched/ spells `u32`.
 *
 * EXACT*: the extent runs to 48 bytes because the next function at
 * 0x02021548 saves no lr and carries no label.
 *
 * 0x020A73BC is this translation unit's allocation-site pointer, the
 * palanm.c anchor in layout/file_anchors.txt.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021518.c \
 *       --func func_02021518 --addr 0x02021518 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern const char func_02021518_File[];

extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void MI_CpuFill8(void *dest, u32 data, u32 size);

void *func_02021518(u32 heap)
{
    void *p = func_02030734((u16)heap, 0x120, 0, func_02021518_File, 88);
    MI_CpuFill8(p, 0, 0x120);
    return p;
}
