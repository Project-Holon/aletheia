/*
 * function: GAME_BEACON_ACCESSOR_AllocInfo
 * address: 0x02165B10
 * packet: pkt_ov010_02165B10
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_02030734 0x02030734 arm
 *   GAME_BEACON_ACCESSOR_FileName 0x021729D4 data a4
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern const char GAME_BEACON_ACCESSOR_FileName[];
u8 *GAME_BEACON_ACCESSOR_AllocInfo(u32 heap) { return func_02030734(heap,0x5c,1,GAME_BEACON_ACCESSOR_FileName,0x1b3); }
