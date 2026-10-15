/*
 * function: NNS_G2dGetUnpackedCharacterData
 * address:  0x02062A00
 * packet:   pkt_0206296C
 * region:   arm9
 * compiler: ../2.0/sp2
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dFindBinaryBlock  0x02062B64  arm
 *   NNSi_G2dFixupCharacterData  0x02062A3C  arm
 *
 * Finds the 'RAHC' (NCGR character data) block in a loaded NITRO file, runs its
 * offset-to-pointer fixup and hands back the block body (block header + 8).
 * Returns 1 on success, 0 (and a NULL out-pointer) when the block is absent.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/NNS_G2dGetUnpackedCharacterData.c  *       --func NNS_G2dGetUnpackedCharacterData --addr 0x02062A00 --cc 1.1p1
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;


struct NitroFileHeader;

extern void *NNS_G2dFindBinaryBlock(struct NitroFileHeader *file, u32 signature);
extern void NNSi_G2dFixupCharacterData(u8 *block);

s32 NNS_G2dGetUnpackedCharacterData(struct NitroFileHeader *file, void **out)
{
    void *block = NNS_G2dFindBinaryBlock(file, 0x43484152);

    if (block == 0) {
        *out = 0;
        return 0;
    }

    NNSi_G2dFixupCharacterData((u8 *)block + 8);
    *out = (u8 *)block + 8;
    return 1;
}
