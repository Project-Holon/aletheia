/*
 * function: func_021D9D50
 * address:  0x021D9D50
 * packet:   pkt_021D9D50
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * symbols:
 *   func_0200DFD8  0x0200DFD8  thumb
 *   func_0200DFE4  0x0200DFE4  thumb
 *
 * Syncs three words of a record (+0x10, +0x8, +0xc) into slots 0..2 of table 10 of the save block at +0x104; returns 1 when any of them differed from what was stored.
 *
 * Blocker: byte-correct (MATCH*); both callees 0x0200DFD8 and 0x0200DFE4 are
 *     unlabelled arm9 Thumb leaves (12 and 0x30 bytes) with no witness. Seed and
 *     match them and this file is EXACT.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned long u32;

extern u32 func_0200DFD8(u32 save, u32 table, u32 slot);
extern void func_0200DFE4(u32 save, u32 table, u32 slot, u32 value);

int func_021D9D50(char *obj, u32 *rec)
{
    int changed = 0;

    if (rec[4] != func_0200DFD8(*(u32 *)(*(char **)(obj + 0x104) + 0x10), 10, 0)
        || rec[2] != func_0200DFD8(*(u32 *)(*(char **)(obj + 0x104) + 0x10), 10, 1)
        || rec[3] != func_0200DFD8(*(u32 *)(*(char **)(obj + 0x104) + 0x10), 10, 2))
        changed = 1;
    func_0200DFE4(*(u32 *)(*(char **)(obj + 0x104) + 0x10), 10, 0, rec[4]);
    func_0200DFE4(*(u32 *)(*(char **)(obj + 0x104) + 0x10), 10, 1, rec[2]);
    func_0200DFE4(*(u32 *)(*(char **)(obj + 0x104) + 0x10), 10, 2, rec[3]);
    return changed;
}
