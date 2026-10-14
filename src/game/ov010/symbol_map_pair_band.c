/*
 * file:     symbol_map_pair_band.c
 * unit:     yes
 * function: SYMBOL_MAP_MoveRecordToPairedBand
 * address:  0x0216628C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from unit_02165FC0.c by tools/splitfile.py.
 *
 * symbols:
 *   func_0200E184  0x0200E184  thumb
 *   func_0200E164  0x0200E164  thumb
 *   func_0200E06C  0x0200E06C  thumb
 *   func_0200E27C  0x0200E27C  thumb
 *   func_0200E024  0x0200E024  thumb
 *   func_0200E18C  0x0200E18C  thumb
 */
#include "../arm9/game_beacon_types.h"

/* One-word struct: the record move in SYMBOL_MAP_MoveRecordToPairedBand needs a word copy. */
typedef struct {
    u32 word;
} RecordWord;

extern u32 func_0200E184(u32 recordIndex);

extern u32 func_0200E164(u32 *save, u32 band);

extern void func_0200E06C(char *save);

extern void func_0200E27C(u8 *save, int recordIndex);

extern void func_0200E024(void *save);

extern void func_0200E18C(u32 *save, u32 recordIndex);

int SYMBOL_MAP_MoveRecordToPairedBand(u32 *save, u32 recordIndex);

/*
 * closed 2026-10-05: the unlabelled leaves it calls are now matched files, so every relocation resolves.
 *
 * Moves a record of the symbol save to the paired band: maps the band of
 * the record (0..3, via the 0x0200E184 thunk) to the paired band (0 and 2,
 * 1 and 3), asks func_0200E164 for a free index in that band, and moves
 * the word at save[recordIndex] there; band 3 also runs func_0200E27C on
 * it. Returns 0 on failure.
 *
 * 2026-10-05 (P25L5): all 128 bytes match. The word move is a one-word
 * struct copy (RecordWord, lever "one-word structs for word copies"); the
 * plain u32 copy gave 8 bytes off (cmp r5,#3 after the str, dst*4 in r0).
 * Only blocker: func_0200E184 is a Thumb veneer (ldr r3,[pc]; bx r3) to
 * the real function at 0x0200E0BC (44 bytes, maps a value to 0..3 by a
 * 4-entry threshold table). It has no witness outside this function, so
 * the relocation stays unresolved. No C can express the veneer; the
 * integrator should seed a label or witness for 0x0200E184.
 * Tried and inert (8 bytes off): raw byte offsets, u16 dst (31 off),
 * const callee proto, u8 obj, u8 kind, inline copy helper, byte offset
 * locals, per-arm store (45 off), each pragma (scheduling, peephole,
 * opt_propagation, opt_common_subs, opt_lifetimes, opt_dead_assignments).
 */
int SYMBOL_MAP_MoveRecordToPairedBand(u32 *save, u32 recordIndex)
{
    u32 targetBand;
    u32 newIndex;

    switch (func_0200E184(recordIndex)) {
    case 0:
        targetBand = 2;
        break;
    case 1:
        targetBand = 3;
        break;
    case 2:
        targetBand = 0;
        break;
    case 3:
        targetBand = 1;
        break;
    default:
        return 0;
    }
    newIndex = func_0200E164(save, targetBand);
    if (newIndex == 0xFFFF)
        return 0;
    func_0200E06C((char *)save);
    ((RecordWord *)save)[newIndex] = ((RecordWord *)save)[recordIndex];
    if (targetBand == 3)
        func_0200E27C((u8 *)save, (u16)newIndex);
    func_0200E024(save);
    func_0200E18C(save, recordIndex);
    return 1;
}
