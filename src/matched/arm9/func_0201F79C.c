/*
 * function: BMP_MENUWORK_DrawWindowEx
 * address:  0x0201F79C
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A width-narrowing wrapper on BMP_MENUWORK_DrawWindow, and the only evidence in the
 * image that BMP_MENUWORK_DrawWindow's third parameter is u16: the single
 * `lsls #16 / lsrs #16` pair here is the argument conversion, so the wrapper
 * takes the tile base as a full word and the worker takes it as a halfword.
 *
 * symbols:
 *   BMP_MENUWORK_DrawWindow  0x0201F73C  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/BMP_MENUWORK_DrawWindowEx.c \
 *       --func BMP_MENUWORK_DrawWindowEx --addr 0x0201F79C --cc 1.1p1 --thumb
 */
typedef unsigned short u16;
typedef unsigned int   u32;

extern void BMP_MENUWORK_DrawWindow(void *a0, int a1, int a2, int a3);

void BMP_MENUWORK_DrawWindowEx(void *desc, u32 kind, u32 base, u32 pal)
{
    BMP_MENUWORK_DrawWindow(desc, kind, (u16)base, pal);
}
