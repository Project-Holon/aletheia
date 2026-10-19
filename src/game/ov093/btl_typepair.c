/*
 * file:     btl_typepair.c
 * unit:     yes
 * function: BTL_TYPEPAIR_Make, BTL_TYPEPAIR_MakeSingle, BTL_TYPEPAIR_GetHigh, BTL_TYPEPAIR_GetLow, BTL_TYPEPAIR_Split, BTL_TYPEPAIR_HasType, BTL_TYPEPAIR_ShareType, BTL_TYPEPAIR_IsSingleType
 * address:  0x021E8CE0
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from hand_common.c, btlv_core.c by tools/splitfile.py.
 *
 * symbols:
 */
#include "btlv_core_types.h"

u16 BTL_TYPEPAIR_Make(u32 high, u32 low);

int BTL_TYPEPAIR_MakeSingle(int byte);

u8 BTL_TYPEPAIR_GetHigh(s32 word);

int BTL_TYPEPAIR_GetLow(int word);

void BTL_TYPEPAIR_Split(int word, unsigned char *high, unsigned char *low);

int BTL_TYPEPAIR_HasType(int word, int byte);

int BTL_TYPEPAIR_ShareType(int wordA, int wordB);

int BTL_TYPEPAIR_IsSingleType(int word);

/* 021E8CE0  ((high & 0xff) << 8) | (low & 0xff) as u16 */
/*
 * Leaf with no calls and no pool; 8 instructions, 16 bytes: lsls r0, r0, #0x18; lsrs r2, r0, #0x10; lsls r0, r1, #0x18; lsrs r0, r0, #0x18; orrs r0, r2; lsls r0, r0, #0x10; lsrs r0, r0, #0x10; bx lr.
 */
u16 BTL_TYPEPAIR_Make(u32 high, u32 low) { return (u16)(((high & 0xff) << 8) | (low & 0xff)); }

int BTL_TYPEPAIR_MakeSingle(int byte)
{
    return BTL_TYPEPAIR_Make(byte, byte);
}

/* 021E8CFC  asrs r0,r0,#8; lsls #0x18; lsrs #0x18 */
/*
 * Leaf with no calls and no pool; 4 instructions, 8 bytes: asrs r0, r0, #8; lsls r0, r0, #0x18; lsrs r0, r0, #0x18; bx lr.
 */
u8 BTL_TYPEPAIR_GetHigh(s32 word) { return (u8)(word >> 8); }

int BTL_TYPEPAIR_GetLow(int word)
{
    return (unsigned char)word;
}

void BTL_TYPEPAIR_Split(int word, unsigned char *high, unsigned char *low)
{
    *high = BTL_TYPEPAIR_GetHigh(word);
    *low = BTL_TYPEPAIR_GetLow(word);
}

int BTL_TYPEPAIR_HasType(int word, int byte)
{
    if (byte == BTL_TYPEPAIR_GetHigh(word)) {
        return 1;
    }
    if (byte == BTL_TYPEPAIR_GetLow(word)) {
        return 1;
    }
    return 0;
}

int BTL_TYPEPAIR_ShareType(int wordA, int wordB)
{
    if (BTL_TYPEPAIR_GetHigh(wordA) == BTL_TYPEPAIR_GetHigh(wordB)) return 1;
    if (BTL_TYPEPAIR_GetHigh(wordA) == BTL_TYPEPAIR_GetLow(wordB)) return 1;
    if (BTL_TYPEPAIR_GetLow(wordA) == BTL_TYPEPAIR_GetHigh(wordB)) return 1;
    if (BTL_TYPEPAIR_GetLow(wordA) == BTL_TYPEPAIR_GetLow(wordB)) return 1;
    return 0;
}

int BTL_TYPEPAIR_IsSingleType(int word)
{
    if (BTL_TYPEPAIR_GetHigh(word) == BTL_TYPEPAIR_GetLow(word)) {
        return 1;
    }
    return 0;
}
