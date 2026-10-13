/*
 * function: func_021D6524
 * address:  0x021D6524
 * packet:   pkt_021D6524
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BSUBWAY_SAVEDATA_IncStat  0x0200E008  thumb
 *
 * Thumb jump table over 0..4: modes 1 and 4 pass the constant 1, modes 0 and
 * 3 pass 2, mode 2 and everything above 4 do nothing.
 *
 * BLOCKER: the two THM_CALL sites relocate to 0x0200E008, which has no
 * func_/sub_ label in asm/arm9/main.s and no other reference anywhere in the
 * listings, so the site reports "unresolved: 0200E008 (arm, from header) has
 * no witness outside 021D6524..021D6550".  Bytes and size are correct
 * (44 bytes, 2 relocation sites, both wildcarded); it needs an entry for the
 * arm9 target to promote.
 */

typedef unsigned int u32;

typedef unsigned char  u8;
extern void BSUBWAY_SAVEDATA_IncStat(u8 *base, int a, int idx);

void func_021D6524(int a, int b, u32 c)
{
    switch (c) {
    case 1:
    case 4:
        BSUBWAY_SAVEDATA_IncStat((u8 *)a, b, 1);
        break;
    case 0:
    case 3:
        BSUBWAY_SAVEDATA_IncStat((u8 *)a, b, 2);
        break;
    }
}
