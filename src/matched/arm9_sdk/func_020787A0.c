/*
 * function: FSi_DecrementSjisPosition
 * address:  0x020787A0
 * packet:   pkt_020787A0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      FSi_DecrementSjisPosition (libfs.TWL.HYB.a fs_file.o)
 *
 * symbols:
 */

typedef unsigned char u8;
typedef unsigned int u32;

#define STD_IsSjisLeadByte(c) ((u32)((((u8)(c)) ^ 0x20) - 0xA1) < 0x3C)

int FSi_DecrementSjisPosition(const char *str, int pos)
{
    int prev = pos - 1;

    while ((prev > 0) && STD_IsSjisLeadByte(str[prev - 1]))
    {
        --prev;
    }
    return pos - 1 - ((pos - 1 - prev) & 1);
}
