/*
 * unit: no
 * function: B_PLIST_ANM_UpdateSelectedTile
 * address: 0x0220BBF0
 * packet: pkt_ov198_0220BBF0
 * region: ov198
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_02211128 0x02211128 thumb ov198
 *   B_PLIST_ANM_UploadTileBuffer 0x0220B6D0 thumb ov198
 */
typedef unsigned char u8;typedef unsigned short u16;typedef unsigned int u32;
extern int func_02211128(u8 *,u8 *,u8 *,int);extern void B_PLIST_ANM_UploadTileBuffer(u8 *,u8,u8,u8);
void B_PLIST_ANM_UpdateSelectedTile(u8 *p){u8 pair[2];if(func_02211128(p,pair+1,pair,0)==1)B_PLIST_ANM_UploadTileBuffer(p,6,0,0);else B_PLIST_ANM_UploadTileBuffer(p,6,3,0);}
