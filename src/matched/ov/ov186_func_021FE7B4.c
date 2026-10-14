/*
 * function: BR_FADE_CaptureHwPalettes
 * address: 0x021FE7B4
 * packet: pkt_ov186_021FE7B4
 * region: ov186
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * lever: plain literals 512 and 448; mwcc derives 448 from the held 512 itself. Twin shape: matched ov197 0220C980 call to PALANM_CopyHwPaletteToSlot.
 * symbols:
 *   PALANM_CopyHwPaletteToSlot 0x020216D4 thumb
 */
typedef unsigned int u32;
struct PalAnmSlot;
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);
void BR_FADE_CaptureHwPalettes(char *p)
{
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot **)(p + 0x20), 0, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot **)(p + 0x20), 2, 0, 448);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot **)(p + 0x20), 1, 0, 512);
    PALANM_CopyHwPaletteToSlot(*(struct PalAnmSlot **)(p + 0x20), 3, 0, 448);
}
