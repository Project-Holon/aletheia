/*
 * function: INTRO_MCSS_Create
 * address: 0x021BF594
 * packet: pkt_ov204_021BF594
 * region: ov204
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * blocker: 0x02016024 Thumb, integrator-owned ARM9 leaf; scratch one EXACT, 4 bytes.
 *   void MCSS_SetPaletteTransAdrs(char *p, unsigned int v)
 *   {
 *       *(unsigned int *)(p + 52) = v;
 *   }
 * note 2026-10-04 (D2): the arm9 leaf 02016024 is now filed EXACT in src/matched/arm9/MCSS_SetPaletteTransAdrs.c (D2 lane 11).
 *   Only that relocation is unresolved; after shards are regenerated this should read EXACT. Header compiler fixed.
 * symbols:
 *   site 0x021C0AF0 data ov204
 *   func_02030734 0x02030734 arm
 *   MCSS_SetPaletteTransAdrs 0x02016024 thumb
 *   MCSS_SetOrthoMode 0x02015BF0 thumb
 *   MCSS_Init  0x02014B08  thumb  arm9
 *   MCSS_SetTextureTransAdrs  0x02016020  thumb  arm9
 */

extern const char site[];
extern void *func_02030734(unsigned int, unsigned int, int, const char *, unsigned short);
typedef unsigned int   u32;
extern void *MCSS_Init(u32 id, void *heap);
extern void MCSS_SetTextureTransAdrs(void *, unsigned int);
extern void MCSS_SetPaletteTransAdrs(char *p, unsigned int v);
extern void MCSS_SetOrthoMode(void *);

void *INTRO_MCSS_Create(unsigned int heap, int kind)
{
    char *p = func_02030734(heap, 108, 1, site, 98);
    *(void **)(p + 4) = MCSS_Init(8, (void *)heap);
    *(unsigned short *)p = heap;
    if (kind != 7)
        MCSS_SetTextureTransAdrs(*(void **)(p + 4), 7 << 16);
    MCSS_SetPaletteTransAdrs(*(void **)(p + 4), 1 << 14);
    MCSS_SetOrthoMode(*(void **)(p + 4));
    return p;
}
