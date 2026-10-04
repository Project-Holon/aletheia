/*
 * function: func_021BF594
 * address: 0x021BF594
 * packet: pkt_ov204_021BF594
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: 0x02016024 Thumb, Ilias-owned ARM9 leaf; scratch one EXACT, 4 bytes.
 *   void func_02016024(char *p, unsigned int v)
 *   {
 *       *(unsigned int *)(p + 52) = v;
 *   }
 * note 2026-10-04 (D2): the arm9 leaf 02016024 is now filed EXACT in src/matched/arm9/func_02016024.c (D2 lane 11).
 *   Only that relocation is unresolved; after shards are regenerated this should read EXACT. Header compiler fixed.
 * symbols:
 *   site 0x021C0AF0 data ov204
 *   func_02030734 0x02030734 arm
 *   func_02016024 0x02016024 thumb
 *   func_02015BF0 0x02015BF0 thumb
 */

extern const char site[];
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
extern void *func_02014B08(int, unsigned int);
extern void func_02016020(void *, unsigned int);
extern void func_02016024(void *, unsigned int);
extern void func_02015BF0(void *);

void *func_021BF594(unsigned int heap, int kind)
{
    char *p = func_02030734(heap, 108, 1, site, 98);
    *(void **)(p + 4) = func_02014B08(8, heap);
    *(unsigned short *)p = heap;
    if (kind != 7)
        func_02016020(*(void **)(p + 4), 7 << 16);
    func_02016024(*(void **)(p + 4), 1 << 14);
    func_02015BF0(*(void **)(p + 4));
    return p;
}
