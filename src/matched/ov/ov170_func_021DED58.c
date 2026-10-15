/*
 * function: BOX2_MAIN_LoadBoxPalette
 * address: 0x021DED58
 * packet: pkt_ov170_021DED58
 * region: ov170
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   BOX2_MAIN_LoadBgCharTile 0x021DEB40 thumb ov170
 *   PALANM_LoadArcPaletteToSlot 0x02021640 thumb
 *   BOX2_MAIN_LoadBgTileSet 0x021DEB90 thumb ov170
 *   func_02041B6C 0x02041B6C arm
 */
extern void BOX2_MAIN_LoadBgCharTile(unsigned int a, int b, void *c);
typedef unsigned short u16;
typedef unsigned int   u32;
struct PalAnmSlot;
extern void PALANM_LoadArcPaletteToSlot(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag, u32 idx, u32 count, u16 off);
extern void BOX2_MAIN_LoadBgTileSet(void *unused, void *unused2, int x, u32 base, u32 pal);
extern void func_02041B6C(unsigned bit);
typedef struct {
    char pad[0xA178];
    signed char box;
    unsigned char flip;
} Work;
#define WORK(p) (*(Work **)((p) + 0x2C))
void BOX2_MAIN_LoadBoxPalette(char *p, int a)
{
    int offset;
    int bank;
    if (WORK(p)->flip == 0) {
        offset = 0x25C;
        bank = 14;
    } else {
        offset = 0xB8;
        bank = 15;
    }
    WORK(p)->flip ^= 1;
    BOX2_MAIN_LoadBgCharTile((unsigned int)p, a, (void *)offset);
    PALANM_LoadArcPaletteToSlot(*(void **)((char *)WORK(p) + 0x6C), 0x74, a + 0x26, 0x4C, 0, 0x20, bank << 4);
    BOX2_MAIN_LoadBgTileSet(p, (void *)a, WORK(p)->box, offset, bank);
    func_02041B6C(3);
}
