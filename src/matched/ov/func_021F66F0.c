/*
 * function: func_021F66F0
 * address:  0x021F66F0
 * packet:   pkt_021F66F0
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb
 *   func_021F66C8  0x021F66C8  thumb
 *   MIi_CpuCopyFast  0x02082B0C  arm
 *   POKE_TOOL_CalcIconPalette  0x0201BB5C  thumb
 *   func_020307B0  0x020307B0  arm
 *
 * Load the icon graphics of a Pokemon (species, form, gender/half, egg)
 * from the archive handle and copy its 0x200 bytes into the sprite
 * record: +0 gets the VRAM offset of slot `slot`, +4 the icon palette
 * (POKE_TOOL_CalcIconPalette + 5), +8 `pal`, the pixels go to +0xC.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
    u8 pad0[0x14];
    void *pixels;
} CharData;

typedef struct {
    u32 vram;
    u32 pal;
    u32 f8;
    u8 pixels[0x200];
} IconRec;

extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern u32 func_021F66C8(u32 a, u32 b, u32 c, u32 d);
extern void MIi_CpuCopyFast(const void *src, void *dst, u32 n);
extern u32 POKE_TOOL_CalcIconPalette(u32 species, u32 form, u32 half, u32 isEgg);
extern u32 func_020307B0(void *p);

void func_021F66F0(u32 species, u32 form, u32 gender, u32 isEgg, u32 slot, u32 f8, u32 arc, IconRec *rec)
{
    CharData *cd;
    void *buf = (void *)func_021F66C8(arc, POKE_TOOL_CalcGraphicIndex(species, form, gender, isEgg), (u32)(&cd), 0x48);

    MIi_CpuCopyFast(cd->pixels, rec->pixels, 0x200);
    rec->vram = (slot * 16 + 0x1c) * 32;
    rec->f8 = f8;
    rec->pal = POKE_TOOL_CalcIconPalette(species, form, gender, isEgg) + 5;
    func_020307B0(buf);
}
