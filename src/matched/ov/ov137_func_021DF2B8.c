/*
 * function: GURU2_MAIN_StateWaitSync3
 * address: 0x021DF2B8
 * packet: pkt_ov137_021DF2B8
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_HANDLE_IsTimingSyncRange 0x02039CB4 arm
 *   GFL_NET_SYSTEM_GetCurrentAid 0x02039338 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Link;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_HANDLE_IsTimingSyncRange(struct Link *,u32,u32);
extern u16 GFL_NET_SYSTEM_GetCurrentAid(void);
int GURU2_MAIN_StateWaitSync3(int *p) { if(GFL_NET_HANDLE_IsTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),204,40)) { if(GFL_NET_SYSTEM_GetCurrentAid()==0) *p=33; else *p=34; } return 0; }
