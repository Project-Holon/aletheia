/*
 * function: sub_02042FB0
 * address:  0x02042FB0
 * packet:   pkt_02042B24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 *
 * status:   EXACT
 *
 * symbols:
 *   g_02146A44     0x02146A44  data
 *   func_02040EE0  0x02040EE0  arm
 *
 * Poke one tile entry into the screen buffer of table slot `idx`.  The
 * table is the 0x2c-byte-per-slot array hanging off the singleton pointer
 * at 0x02146A44 (the same one sub_020403F4 tears down): +8 is the screen
 * buffer and +0x1d the screen-size code that tells func_02040EE0 how to
 * fold (x, y) into a linear index.  A slot with no buffer is skipped.
 *
 * The three `and rN, rM, #0xff` are the truncations at the call, not casts
 * in this function's own arithmetic; func_02040EE0 takes three u8.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Slot {
    u8   pad_00[8];
    u16 *screen;
    u8   pad_0c[0x11];
    u8   size_code;
    u8   pad_1e[0x0e];
};

extern struct Slot *g_02146A44;

extern u16 func_02040EE0(int x, int y, u32 code);

void sub_02042FB0(u32 idx, u32 x, u32 y, u16 value)
{
    struct Slot *slot = &g_02146A44[idx];
    u16 *screen = slot->screen;
    u32 code = slot->size_code;

    if (screen == 0) {
        return;
    }

    screen[(u32)func_02040EE0((u8)x, (u8)y, (u8)code)] = value;
}
