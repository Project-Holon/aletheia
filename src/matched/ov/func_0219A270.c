/*
 * function: FLDMMDL_MOVECODE_InitWalkRandomSet13
 * address:  0x0219A270
 * packet:   pkt_0219A270
 * region:   ov021
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Calls FLDMMDL_MOVECODE_InitWalkRandom(its own argument 1, 0xc, 0xd, 0x0) and returns nothing.
 *
 * symbols:
 *   FLDMMDL_MOVECODE_InitWalkRandom  0x0219A290  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef int BOOL;

extern void FLDMMDL_MOVECODE_InitWalkRandom(u32 a1, u32 a2, u32 a3, u32 a4);

void FLDMMDL_MOVECODE_InitWalkRandomSet13(u32 a1)
{
    FLDMMDL_MOVECODE_InitWalkRandom(a1, 0xc, 0xd, 0x0);
}

