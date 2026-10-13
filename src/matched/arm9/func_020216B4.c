/*
 * unit:     no
 * function: PALANM_LoadHandlePaletteToSlot
 * address:  0x020216B4
 * packet:   pkt_02021444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   PALANM_LoadHandlePaletteToSlotAt  0x02021660  thumb
 *
 * Forward to PALANM_LoadHandlePaletteToSlotAt with a source offset of zero, i.e. copy from the
 * start of the loaded palette.  The four register arguments are never
 * touched, only the three stack arguments are re-pushed and the eighth is
 * appended; the seventh is re-read with `ldrh`, which is what pins it as a
 * `u16` in both prototypes.
 *
 * EXACT*: the extent runs long because the next function has no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/PALANM_LoadHandlePaletteToSlot.c \
 *       --func PALANM_LoadHandlePaletteToSlot --addr 0x020216B4 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct PalAnmSlot;

extern void PALANM_LoadHandlePaletteToSlotAt(struct PalAnmSlot *slots, void *arc, u32 fileId,
                          u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);

void PALANM_LoadHandlePaletteToSlot(struct PalAnmSlot *slots, void *arc, u32 fileId, u32 tag,
                   u32 idx, u32 count, u16 off)
{
    PALANM_LoadHandlePaletteToSlotAt(slots, arc, fileId, tag, idx, count, off, 0);
}
