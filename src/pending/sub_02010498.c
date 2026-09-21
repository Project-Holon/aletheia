/*
 * function: sub_02010498
 * address:  0x02010498
 * packet:   pkt_0201045C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * note:     re-verified 2026-09-21 in a fresh process: MATCH; see verify output.
 *           function_starts.txt line 337 seeds this leaf at 0x0201049C (4 bytes
 *           too high); the real prologue and byte-exact fit are at 0x02010498,
 *           per docs/notes/unit_0201045C.c.txt.
 * blocked:  +005C ABS32 g_021461E0 : unresolved: no address for 'g_021461E0':
 *           not in the symbols: block, not an address-bearing name, not in
 *           layout/symbols_sdk.json
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021461E0;
extern void func_02082D44(u8 *p, u8 *rec);

void sub_02010498(void)
{
    u8 *o = g_021461E0;

    if (o != 0 && *(u16 *)(o + 0x30C) != 0)
        return;
    if (o == 0)
        return;
    if (*(int *)(o + 0x318) > 0)
        *(int *)(o + 0x318) = *(int *)(o + 0x318) - 1;
    o = g_021461E0;
    if (*(int *)(o + 0x31C) > 0)
        *(int *)(o + 0x31C) = *(int *)(o + 0x31C) - 1;
    o = g_021461E0;
    if (*(int *)(o + 0x320) > 0)
        *(int *)(o + 0x320) = *(int *)(o + 0x320) - 1;
    o = g_021461E0;
    if (*(int *)(o + 0x324) > 0)
        *(int *)(o + 0x324) = *(int *)(o + 0x324) - 1;
}
