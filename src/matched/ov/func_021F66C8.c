/*
 * function: WORLDTRADE_BOX_LoadPokeIconChar
 * address:  0x021F66C8
 * packet:   pkt_021F66C8
 * region:   ov135
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   ARC_TOOL_LoadHandleMember  0x02049250  arm  arm9
 *   NNS_G2dGetUnpackedCharacterDataEx  0x02062A4C  arm  arm9
 *

 *
 * Allocate through the pooled-block helper and hand the block to the loader.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;
struct ArcFile;
extern void *ARC_TOOL_LoadHandleMember(struct ArcFile *arc, u32 member, u32 heap);
struct NitroFileHeader;
extern s32 NNS_G2dGetUnpackedCharacterDataEx(struct NitroFileHeader *file, void **out);
extern u32 func_020307B0(void *p);

u32 WORLDTRADE_BOX_LoadPokeIconChar(u32 a, u32 b, u32 c, u32 d)
{
    u32 blk = (u32)ARC_TOOL_LoadHandleMember((struct ArcFile *)a, b, (u16)d);

    if (blk != 0 && NNS_G2dGetUnpackedCharacterDataEx((struct NitroFileHeader *)blk, (void **)c) == 0) {
        func_020307B0((void *)blk);
        return 0;
    }
    return blk;
}
