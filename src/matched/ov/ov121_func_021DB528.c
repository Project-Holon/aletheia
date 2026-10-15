/*
 * function: MYSTERY_ALBUM_UpdateSlots
 * address: 0x021DB528
 * packet: pkt_ov121_021DB528
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   MYSTERY_ALBUM_DeleteSlotActor 0x021DB938 thumb ov121
 *   BG_SYS_PushTile 0x020409B4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void MYSTERY_ALBUM_DeleteSlotActor(char *,int,u16);
extern void BG_SYS_PushTile(u32);
void MYSTERY_ALBUM_UpdateSlots(char *p,int a) { int i; for(i=0;i<4;i++) MYSTERY_ALBUM_DeleteSlotActor(p,a,i); BG_SYS_PushTile(3); }
