/*
 * function: ov208_func_021BC758
 * address:  0x021BC758
 * packet:   pkt_ov208_021BC758
 * region:   ov208
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   PALANM_CopyHwPaletteToSlot  0x020216D4  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct Ov208PalFade {
    u32 f0;
    u32 f4;
    void *slots;
    u16 mask;
};

struct PalAnmSlot;
extern void PALANM_CopyHwPaletteToSlot(struct PalAnmSlot *slots, u32 bank, u32 off, u32 size);

void ov208_func_021BC758(struct Ov208PalFade *p)
{
    if (p->mask & 1)
        PALANM_CopyHwPaletteToSlot(p->slots, 0, 0, 0x1a0);
    if (p->mask & 4)
        PALANM_CopyHwPaletteToSlot(p->slots, 2, 0, 0x100);
    if (p->mask & 2)
        PALANM_CopyHwPaletteToSlot(p->slots, 1, 0, 0x1a0);
    if (p->mask & 8)
        PALANM_CopyHwPaletteToSlot(p->slots, 3, 0, 0x1c0);
}
