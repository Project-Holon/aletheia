/*
 * function: BG_SYS_BlitTileMap
 * address:  0x02042D2C
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_020422D4  0x020422D4  arm
 *   BG_SYS_GetTileMapEntry  0x02040EE0  arm
 *
 * The third of the three tilemap blitters BG_SYS_SetTileEntry dispatches to on the
 * bit-depth byte at +0x1c of the 0x2c-byte slot.  Its two siblings are
 * src/matched/BG_SYS_BlitPixelsEx.c (8bpp pixel fill, tiled addressing, u8 buffer)
 * and src/matched/BG_SYS_BlitTileMapEx.c (text fill, linear addressing, u16 buffer);
 * this one is BG_SYS_BlitTileMapEx's three write modes over BG_SYS_BlitPixelsEx's tiled
 * addressing, into a u16 buffer.  Like both of those it is handed the slot's
 * sub-object (slot + 8), so the buffer pointer is at +0x00 and the
 * screen-size code at +0x15, i.e. slot +0x08 and slot +0x1d.
 *
 * The three write modes, on the seventh argument:
 *     0x11     entry = value
 *     0x10     entry = value + (entry & 0xf000)      keep the palette nibble
 *     other    entry = (u16)(value + (mode << 12))   fold the mode in
 * The third form is loop-invariant and is materialised once in the preheader.
 * BG_SYS_GetTileMapEntry is called once per cell, before the dispatch, so its result
 * has to be bound to a local; writing the call out in each arm emits it three
 * times.
 *
 * WHAT CLOSED IT (wave 2 of this family).  docs/notes/BG_SYS_BlitTileMap.c.txt
 * recorded an 11-byte plateau at +0x10..+0x18, three mutually independent
 * prologue instructions issued in a different order:
 *     +0010  orig mov sb, r1          got ldr r7, [sp, #0x38]
 *     +0014  orig str r2, [sp]        got mov sb, r1
 *     +0018  orig ldr r7, [sp, #0x38] got str r2, [sp]
 * and concluded it was the instruction scheduler, hence unreachable from C.
 * That conclusion was wrong, and so was the premise it rested on: the note
 * argued the seventh parameter must be u32 because it arrives by `ldr` and
 * not `ldrb`.  A u8 stack argument also occupies a full word of the argument
 * area and is also loaded with `ldr`, so the load width says nothing about
 * the declared type.  Declaring
 *     u8 mode
 * instead of u32 is the whole fix, and it closes all 11 bytes at once: the
 * narrower type gives the value a different spill cost, which moves its home
 * load behind the other two prologue instructions.  Nothing else in the body
 * changed.  tools/permuter.py found it with --types (mutation
 * `type:p(mode:u32->u8)`); the earlier permute.py pass recorded in the note
 * had no type mutation and so could not reach it.
 *
 * All seven parameter types are pinned by the diff: `s` pointer, `u16 value`,
 * `u8 x0`, `u8 y0`, `u8 w`, `u8 h`, `u8 mode`.  Every other choice blows the
 * function up: value as u32 costs 157 bytes, x0 as u32 170, y0 as u32 190,
 * the helper result as u16 107.
 *
 * This unblocks src/pending/BG_SYS_SetTileEntry.c (fan-in 224), which needed all
 * three blitters as `matched` witnesses and now has them.
 *
 * Verified with:
 *   python3 tools/match.py one --src src/matched/BG_SYS_BlitTileMap.c \
 *       --func BG_SYS_BlitTileMap --addr 0x02042D2C --arm --cc 1.1p1
 */


typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Screen {
    u16 *entries;
    u8   pad_04[0x11];
    u8   size_code;
};

extern void func_020422D4(u32 mode, u8 *a, u8 *b);
extern u16 BG_SYS_GetTileMapEntry(int x, int y, u32 code);

void BG_SYS_BlitTileMap(struct Screen *s, u16 value, u8 x0, u8 y0, u8 w, u8 h,
                   u8 mode)
{
    u8   width;
    u8   height;
    u16 *entries;
    u8   x;
    u8   y;

    entries = s->entries;
    if (entries == 0) {
        return;
    }

    func_020422D4(s->size_code, &width, &height);

    for (y = y0; y < y0 + h; y++) {
        if (y >= height) {
            return;
        }

        for (x = x0; x < x0 + w; x++) {
            u32 i;

            if (x >= width) {
                break;
            }

            i = BG_SYS_GetTileMapEntry(x, y, s->size_code);

            if (mode == 0x11) {
                entries[i] = value;
            } else if (mode == 0x10) {
                entries[i] = value + (entries[i] & 0xf000);
            } else {
                entries[i] = (u16)(value + (mode << 12));
            }
        }
    }
}
