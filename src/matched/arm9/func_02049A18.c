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
 *   func_02062B30  0x02062B30  arm
 *   func_0204169C  0x0204169C  arm
 *   func_0204162C  0x0204162C  arm
 *   func_02040AF0  0x02040AF0  arm
 *   func_020409E0  0x020409E0  arm
 *   func_020409B4  0x020409B4  arm
 *   func_02041B6C  0x02041B6C  arm
 *   func_020307B0  0x020307B0  arm
 *
 * arc_tool.c (wave 13): the palette-upload worker the sound/palette front
 * ends of unit_0204994C.c, ARC_UTIL_UploadBgPaletteFromArchive.c and ARC_UTIL_UploadBgPaletteFromHandle.c forward to.
 * Look up the resource's palette block; default the size to the block's own
 * (+0x08); when `add` is non-zero, add it to every entry of the data at +0x0C
 * -- as halfwords (size / 2 of them) when func_0204169C says the channel is
 * not 8-bit, else as bytes; then upload through func_02040AF0 plus the
 * flag-selected commit (func_02041B6C / func_020409B4) or func_020409E0, and
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

extern int func_02062B30(void *file, void **out);
extern u8 func_0204169C(int channel);
extern u32 func_0204162C(int channel);
extern void func_02040AF0(u32 index, const void *src, u32 mode, u32 offset);
extern void func_020409E0(u32 index, const void *src, u32 mode, u32 offset);
extern void func_020409B4(u8 channel);
extern void func_02041B6C(u8 channel);
extern u32 func_020307B0(void *p);

u32 ARC_UTIL_UploadBgPalette(void *file, u32 channel, u32 a2, u32 add, u32 size, u32 flag)
{
    struct Pal *pal;

    if (func_02062B30(file, (void **)(&pal)) != 0) {
        if (size == 0)
            size = pal->size;
        if (add != 0) {
            if (func_0204169C((u8)channel) == 0) {
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
        if ((int)func_0204162C((u8)channel) != 0) {
            func_02040AF0((u8)channel, pal->data, size, a2);
            if (flag != 0)
                func_02041B6C(channel);
            else
                func_020409B4(channel);
        } else {
            func_020409E0((u8)channel, pal->data, size, a2);
        }
    }
    return func_020307B0(file);
}
