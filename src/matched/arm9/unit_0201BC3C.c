/*
 * unit:     yes
 * function: func_0201BC3C, func_0201BC40, func_0201BC78, func_0201BCB4,
 *           func_0201BCEC
 * address:  0x0201BC3C
 * packet:   pkt_0201BC3C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Five leaves after POKE_TOOL_GetIconPalette.  The first returns 0.  The other four read
 * the OBJ character mapping bits of DISPCNT (bit 4, 1D mapping, and bits
 * 20..21, the 1D boundary) for the main engine (0x04000000) or the sub engine
 * (0x04001000) and turn the 32/64/128 KB boundary into a shift: 2/4/6 and
 * 1/3/5, with the unlisted 256 KB case falling into a separate default that
 * repeats the last value.  Seeded from ov208 0x021C5304, 0x021C531E,
 * 0x021C5324 (func_021C52F0) and ov021 0x021CC8EA, 0x021CC906, 0x021CC90C.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

#define REG_DISPCNT      (*(volatile u32 *)0x04000000)
#define REG_DB_DISPCNT   (*(volatile u32 *)0x04001000)
#define OBJ_MAPPING_MASK 0x300010

int func_0201BC3C(void)
{
    return 0;
}

int func_0201BC40(void)
{
    switch (REG_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 2;
    case 0x100010: return 4;
    case 0x200010: return 6;
    default:       return 6;
    }
}

int func_0201BC78(void)
{
    switch (REG_DB_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 2;
    case 0x100010: return 4;
    case 0x200010: return 6;
    default:       return 6;
    }
}

int func_0201BCB4(void)
{
    switch (REG_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 1;
    case 0x100010: return 3;
    case 0x200010: return 5;
    default:       return 5;
    }
}

int func_0201BCEC(void)
{
    switch (REG_DB_DISPCNT & OBJ_MAPPING_MASK) {
    case 0x10:     return 1;
    case 0x100010: return 3;
    case 0x200010: return 5;
    default:       return 5;
    }
}
