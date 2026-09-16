/*
 * unit:     no
 * function: func_02021640
 * address:  0x02021640
 * packet:   pkt_02021444
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020215EC  0x020215EC  thumb
 *
 * Forward to func_020215EC with a source offset of zero, i.e. copy from the
 * start of the loaded palette.  The four register arguments are never
 * touched, only the three stack arguments are re-pushed and the eighth is
 * appended; the seventh is re-read with `ldrh`, which is what pins it as a
 * `u16` in both prototypes.
 *
 * EXACT*: the extent runs long because the next function has no label.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02021640.c \
 *       --func func_02021640 --addr 0x02021640 --cc 1.1p1 --thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

struct PalAnmSlot;

extern void func_020215EC(struct PalAnmSlot *slots, u32 arcId, u32 fileId,
                          u32 tag, u32 idx, u32 count, u16 off, u16 srcOff);

void func_02021640(struct PalAnmSlot *slots, u32 arcId, u32 fileId, u32 tag,
                   u32 idx, u32 count, u16 off)
{
    func_020215EC(slots, arcId, fileId, tag, idx, count, off, 0);
}
