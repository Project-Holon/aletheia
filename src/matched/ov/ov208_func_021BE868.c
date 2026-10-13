/*
 * function: func_021BE868
 * address: 0x021BE868
 * packet: pkt_ov208_021BE868
 * region: ov208
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BMP_WIN_Create 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   BMP_Clear 0x02043B5C arm
 *   BMP_WIN_TransferChars 0x02045334 arm
 *   BMP_CreateFromArchive 0x0204384C arm
 *   BMP_GetByteSize 0x020437EC arm
 *   BMP_GetPixels 0x020437D4 arm
 *   func_02040B58 0x02040B58 arm
 *   ARC_UTIL_UploadBgPaletteAddFromArchive 0x0204994C arm
 *   func_020413B0 0x020413B0 arm
 *   func_02045B38 0x02045B38 arm
 * tail: two zero alignment bytes after the function (listing extent is 2 bytes longer).
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ov208Gfx { u16 heap; u16 pad; int f4; int f8; int fc; int f10; u32 f14; void *f18; int f1c; int f20; int f24; };
struct Bmp;
extern u32 BMP_WIN_Create(u32 layer, u32 a, u32 b, u32 tiles, u8 c, u8 d, u8 slot);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
struct CharBuf;
struct MsgBank;
extern void BMP_Clear(struct CharBuf *buf, u8 value);
extern void BMP_WIN_TransferChars(struct Descriptor *a);
extern struct Bmp *BMP_CreateFromArchive(u32 arc, u32 member, u32 heap2, u32 heap);
extern u32 BMP_GetByteSize(const struct Bmp *bmp);
extern void *BMP_GetPixels(const struct Bmp *bmp);
extern u32 func_02040B58(u32 index, const void *src, u32 size);
extern u32 ARC_UTIL_UploadBgPaletteAddFromArchive(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u16 a7);
extern void func_020413B0(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
void func_021BE868(struct Ov208Gfx *g)
{
    g->f14 = BMP_WIN_Create(5, 0, 0, 0x10, 1, 13, 0);
    BMP_Clear((struct CharBuf *)((int)func_02045770((struct Descriptor *)g->f14)), 0);
    BMP_WIN_TransferChars((struct Descriptor *)g->f14);
    g->f18 = BMP_CreateFromArchive(0x9f, 14, 0, g->heap);
    g->f20 = BMP_GetByteSize(g->f18);
    g->f1c = func_02040B58(5, BMP_GetPixels(g->f18), g->f20);
    ARC_UTIL_UploadBgPaletteAddFromArchive(0x9f, 0x25, 5, 0, g->f1c, 0xc0, 0, g->heap);
    func_020413B0(5, 0, 0, 0x20, 0x18, 13);
    g->f24 = (int)func_02045B38(0, 2, 0xea, g->heap);
}
