/*
 * function: TPOKE_DATA_GetGenderValue
 * address:  0x0202A3CC
 * packet:   pkt_0202A230
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * Blocked: gTpokeDataGenderValueTable is named by this function's one pool word
 * (0x0202A3D4) inside the compared range; `literal` has no outside site
 * and the target is neither a string nor a pointer table.  Every concrete
 * byte reproduces.
 *
 * symbols:
 *   gTpokeDataGenderValueTable  0x0209FF1C  data
 */

typedef unsigned char u8;
typedef unsigned int u32;

extern const u8 gTpokeDataGenderValueTable[];

u8 TPOKE_DATA_GetGenderValue(u32 idx)
{
    return gTpokeDataGenderValueTable[idx];
}
