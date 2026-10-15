/*
 * function: THE_END_GRAPHIC_LoadGraphics
 * address: 0x021B9788
 * packet: pkt_ov182_021B9788
 * region: ov182
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: 2-byte zero alignment at 021B980E after code; next function 021B9810.
 * symbols:
 *   func_020490F4 0x020490F4 arm
 *   func_02049B68 0x02049B68 arm
 *   func_02049658 0x02049658 arm
 *   func_020498F4 0x020498F4 arm
 *   GPOWER_GetSpecialPowerId 0x020111E8 thumb
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 *   BG_SYS_PushTile 0x020409B4 arm
 *   func_02040588 0x02040588 arm
 */
typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
extern void *func_020490F4(u32 id, u32 heap);
extern void func_02049B68(void *a, u32 b, u32 c, u32 d, u32 e, u16 f);
extern u32 func_02049658(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern void func_020498F4(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u16 g);
extern u32 GPOWER_GetSpecialPowerId(void);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void ARC_TOOL_DeleteHandle(unsigned char *);
extern void BG_SYS_PushTile(u32 index);
extern void func_02040588(unsigned char which, unsigned char enable);
void THE_END_GRAPHIC_LoadGraphics(unsigned short *p)
{
    unsigned char *q = func_020490F4(0xdc, *p);
    func_02049B68(q, 2, 0, 0, 0, *p);
    func_02049658(q, 3, 1, 0, 0, 0, *p);
    func_020498F4(q, 5, 1, 0, 0, 0, *p);
    if (GPOWER_GetSpecialPowerId() == 0x14)
        BG_SYS_FillTileMap(1, 0, 0, 0x20, 0x18, 1);
    ARC_TOOL_DeleteHandle(q);
    BG_SYS_PushTile(1);
    func_02040588(1, 1);
    func_02040588(2, 0);
}
