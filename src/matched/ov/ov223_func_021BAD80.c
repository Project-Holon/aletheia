/*
 * function: PSEL_UploadBgPalette
 * address: 0x021BAD80
 * packet: pkt_ov223_021BAD80
 * region: ov223
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing ADFA halfword is zero alignment padding.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 */
typedef unsigned short u16;
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *, unsigned, unsigned, unsigned, unsigned, unsigned, u16);
extern void ARC_TOOL_DeleteHandle(void *);
extern void BG_SYS_PushTile(unsigned);
void PSEL_UploadBgPalette(u16 *p)
{
    void *object;
    object = func_020490F4(205, *p);
    ARC_UTIL_UploadPaletteFromHandle(object, 7, 4, 256, 256, 256, *p);
    func_02049658(object, 16, 4, 0, 0, 0, *p);
    func_020498F4(object, 19, 4, 0, 0, 0, *p);
    func_020498F4(object, 20, 5, 0, 0, 0, *p);
    ARC_TOOL_DeleteHandle(object);
    BG_SYS_PushTile(4);
    BG_SYS_PushTile(5);
}
