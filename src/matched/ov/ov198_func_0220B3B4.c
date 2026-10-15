/*
 * function: B_PLIST_ANM_CopySubSpriteTiles
 * address: 0x0220B3B4
 * packet: pkt_ov198_0220B3B4
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   B_PLIST_ANM_BlitTileRect 0x0220B460 thumb ov198
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern void B_PLIST_ANM_BlitTileRect(u16 *,u16 *,int,int,u8,u8);
void B_PLIST_ANM_CopySubSpriteTiles(char *p,u16 *src)
{
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0xC3C),src,0,0,30,17);
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1038),src,0,17,30,17);
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1434),src,0,34,30,17);
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1830),src,0,51,16,6);
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0x18F0),src,16,51,16,6);
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0x19B0),src,0,57,16,6);
    B_PLIST_ANM_BlitTileRect((u16 *)(p+0x1A70),src,16,57,16,6);
}
