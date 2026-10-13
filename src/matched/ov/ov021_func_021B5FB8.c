/*
 * function: SCRCMD_POKEMON_FLD_CheckTutorGroup
 * address:  0x021B5FB8
 * packet:   pkt_ov021_021B5FB8
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   POKE_TOOL_CheckTutorCompat  0x0201891C  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef signed int     s32;
extern u32 POKE_TOOL_CheckTutorCompat(void *p, s32 v);

int SCRCMD_POKEMON_FLD_CheckTutorGroup(u32 a, int sel)
{
    switch (sel) {
    case 1:
        if (POKE_TOOL_CheckTutorCompat((void *)a, 3))
            return 1;
        if (POKE_TOOL_CheckTutorCompat((void *)a, 4))
            return 1;
        if (POKE_TOOL_CheckTutorCompat((void *)a, 5))
            return 1;
        return 0;
    case 0:
        if (POKE_TOOL_CheckTutorCompat((void *)a, 6))
            return 1;
        return 0;
    case 2:
        if (POKE_TOOL_CheckTutorCompat((void *)a, 0))
            return 1;
        if (POKE_TOOL_CheckTutorCompat((void *)a, 1))
            return 1;
        if (POKE_TOOL_CheckTutorCompat((void *)a, 2))
            return 1;
        return 0;
    }
    return 0;
}
