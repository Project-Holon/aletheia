/*
 * unit:     yes
 * address:  0x02010848
 * packet:   pkt_020107FC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_02010848, func_02010864, func_02010884
 * symbols:
 *   g_021461E0     0x021461E0  data
 *
 * wih_dwc.c: three unlabelled leaves after sub_020107FC (whose listing extent
 * runs to 0x02010888 because none of them saves lr): a getter of the halfword
 * at +0x312 of the object behind 0x021461E0 (0 when there is none), a raising
 * setter of the halfword at +0x314 (only upward, and only below 4; the first
 * compare is signed, the bound unsigned, so the parameter is u32 and the
 * field is compared as int), and an empty function.  func_02010888
 * (src/matched/func_02010888.c) follows.
 *
 * SEED REQUEST for the integrator: arm9 0x02010848 thumb, 0x02010864 thumb,
 * 0x02010884 thumb (witness: this unit).
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py tu --src src/matched/unit_02010848.c \
 *       --addr 0x02010848 --thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8 *g_021461E0;

u16 func_02010848(void)
{
    if (g_021461E0 != 0)
        return *(u16 *)(g_021461E0 + 0x312);
    return 0;
}

void func_02010864(u32 v)
{
    u8 *o = g_021461E0;

    if (o != 0 && (int)*(u16 *)(o + 0x314) < (int)v && v < 4)
        *(u16 *)(o + 0x314) = v;
}

void func_02010884(void)
{
}
