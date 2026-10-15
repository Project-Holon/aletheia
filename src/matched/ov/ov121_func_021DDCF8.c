/*
 * function: MYSTERY_ALBUM_LoadBgPalette
 * address: 0x021DDCF8
 * packet: pkt_ov121_021DDCF8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding after the return.
 * symbols:
 *   func_021DC064 0x021DC064 thumb ov121
 *   func_020490F4 0x020490F4 arm
 *   ARC_UTIL_UploadPaletteFromHandle 0x02049BDC arm
 *   BG_SYS_FillTileMap 0x020413B0 arm
 *   func_020409B4 0x020409B4 arm
 *   ARC_TOOL_DeleteHandle 0x02049238 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
extern int func_021DC064(void *p);
extern void *func_020490F4(unsigned int id, unsigned int heap);
typedef unsigned int   u32;
extern void ARC_UTIL_UploadPaletteFromHandle(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6);
extern void BG_SYS_FillTileMap(u8 index, u8 x0, u8 y0, u8 w, u8 h, u8 pal);
extern void func_020409B4(u32 index);
extern void ARC_TOOL_DeleteHandle(void *);
void MYSTERY_ALBUM_LoadBgPalette(unsigned *p,void *context,u16 heap)
{
    int which=0;
    u16 id;
    void *arc;
    if (p[0]>=4) which=4;
    id=func_021DC064(context);
    arc=func_020490F4(34,heap);
    ARC_UTIL_UploadPaletteFromHandle(arc,4,which,id*32,p[2]*32,32,heap);
    BG_SYS_FillTileMap((u8)p[0],0,0,34,24,p[2]);
    func_020409B4((u8)p[0]);
    ARC_TOOL_DeleteHandle(arc);
}
