/*
 * function: BOX2_MAIN_LoadBgTiles
 * address:  0x021DEC64
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   BOX2_MAIN_LoadBgCharTile  0x021DEB40  thumb  ov170
 *   BOX2_MAIN_LoadBgPaletteTile  0x021DEB70  thumb  ov170
 *   BOX2_MAIN_LoadBgTileSet  0x021DEB90  thumb  ov170
 *
 * Fan the 5 arguments out to the 0x74/0x26, shifted and 6-argument
 *   stages, then release the 3-handle.
 */


extern void BOX2_MAIN_LoadBgCharTile(unsigned int a, int b, void *c);
extern void BOX2_MAIN_LoadBgPaletteTile(int, int, int);
extern void BOX2_MAIN_LoadBgTileSet(void *unused, void *unused2, int x, unsigned int base, unsigned int pal);
typedef unsigned int   u32;
extern void func_02041B6C(u32 bit);
void BOX2_MAIN_LoadBgTiles(void *a, void *b, int c, void *d, int e)
{
    BOX2_MAIN_LoadBgCharTile((int)a, (int)b, d);
    BOX2_MAIN_LoadBgPaletteTile((int)a, (int)b, e);
    BOX2_MAIN_LoadBgTileSet(a, b, c, (unsigned int)d, e);
    func_02041B6C(3);
}
