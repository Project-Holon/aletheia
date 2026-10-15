/*
 * function: ARC_UTIL_UploadBgPalette
 * address:  0x02049A18
 * packet:   pkt_0204994C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   NNS_G2dGetUnpackedScreenData  0x02062B30  arm
 *   BG_SYS_GetField16  0x0204169C  arm
 *   BG_SYS_GetBuf  0x0204162C  arm
 *   BG_SYS_DecodeTileSource  0x02040AF0  arm
 *   BG_SYS_PushTileSource  0x020409E0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020307B0  0x020307B0  arm
 *
 * arc_tool.c (wave 13): the palette-upload worker the sound/palette front
 * ends of unit_0204994C.c, ARC_UTIL_UploadBgPaletteFromArchive.c and ARC_UTIL_UploadBgPaletteFromHandle.c forward to.
 * Look up the resource's palette block; default the size to the block's own
 * (+0x08); when `add` is non-zero, add it to every entry of the data at +0x0C
 * -- as halfwords (size / 2 of them) when BG_SYS_GetField16 says the channel is
 * not 8-bit, else as bytes; then upload through BG_SYS_DecodeTileSource plus the
 * flag-selected commit (func_02041B6C / func_020409B4) or BG_SYS_PushTileSource, and
 * release the resource either way.  Every `and rN, r7, #0xff` is a callee's
 * u8 channel parameter, not a cast in the source.
 *
 * WHAT CLOSED IT (docs/notes/ARC_UTIL_UploadBgPalette.c.txt: 300 against 296, 122 out):
 * the callees take `u8 channel` and the caller passes the u32 unchanged; the
 * two loops each own a block-scoped counter (a shared `i` makes the compiler
 * hoist one `mov r3, #0` above the arm test, 4 bytes short); and inside each
 * block the counter is declared BEFORE the element pointer (the other order
 * swaps the two registers in both loops, 17 bytes).
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Pal {
    u8  pad00[8];
    u32 size;
    u8  data[1];
};

extern int NNS_G2dGetUnpackedScreenData(void *file, void **out);
extern u8 BG_SYS_GetField16(int channel);
extern u32 BG_SYS_GetBuf(int channel);
extern void BG_SYS_DecodeTileSource(u32 index, const void *src, u32 mode, u32 offset);
extern void BG_SYS_PushTileSource(u32 index, const void *src, u32 mode, u32 offset);
extern void func_020409B4(u8 channel);
extern void func_02041B6C(u8 channel);
extern u32 func_020307B0(void *p);

u32 ARC_UTIL_UploadBgPalette(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag)
{
    struct Pal *pal;

    if (NNS_G2dGetUnpackedScreenData(file, (void **)(&pal)) != 0) {
        if (size == 0)
            size = pal->size;
        if (add != 0) {
            if (BG_SYS_GetField16((u8)channel) == 0) {
                u32 i;
                u16 *p = (u16 *)pal->data;
                for (i = 0; i < size / 2; i++)
                    p[i] += (u16)add;
            } else {
                u32 i;
                u8 *p = pal->data;
                for (i = 0; i < size; i++)
                    p[i] += (u8)add;
            }
        }
        if ((int)BG_SYS_GetBuf((u8)channel) != 0) {
            BG_SYS_DecodeTileSource((u8)channel, pal->data, size, a2);
            if (flag != 0)
                func_02041B6C(channel);
            else
                func_020409B4(channel);
        } else {
            BG_SYS_PushTileSource((u8)channel, pal->data, size, a2);
        }
    }
    return func_020307B0(file);
}
