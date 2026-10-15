/*
 * function: SHINKA_DEMO_GRAPHIC_VBlank
 * address:  0x02205AAC
 * packet:   pkt_02205AAC
 * region:   ov195
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   SHINKA_DEMO_GRAPHIC_UpdateSubBg 0x02205B64 thumb
 *   SHINKA_DEMO_GRAPHIC_VBlankClact 0x02205BD0 thumb
 */

extern void SHINKA_DEMO_GRAPHIC_UpdateSubBg(void *);
extern void SHINKA_DEMO_GRAPHIC_VBlankClact(void *);

void SHINKA_DEMO_GRAPHIC_VBlank(int a, char *b)
{
    SHINKA_DEMO_GRAPHIC_UpdateSubBg(b);
    SHINKA_DEMO_GRAPHIC_VBlankClact(b + 4);
}