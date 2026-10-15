/*
 * function: MYSTERY_ALBUM_CreateEntryArc
 * address: 0x021DBF10
 * packet: pkt_ov121_021DBF10
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   MYSTERY_ALBUM_GetEntryKind 0x021DC024 thumb ov121
 *   func_020490F4 0x020490F4 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int MYSTERY_ALBUM_GetEntryKind(void *); extern void *func_020490F4(u32,u16);
void *MYSTERY_ALBUM_CreateEntryArc(void *p,u16 heap) { switch(MYSTERY_ALBUM_GetEntryKind(p)) { case 1:return func_020490F4(7,heap); case 2:return func_020490F4(25,heap); default:return func_020490F4(34,heap); } }
