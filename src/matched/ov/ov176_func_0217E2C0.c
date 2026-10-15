/*
 * function: LIVEBATTLEMATCH_IRC_SendSyncValue
 * address: 0x0217E2C0
 * packet: pkt_ov176_0217E2C0
 * region: ov176
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_GetHandleNetID 0x0203D1A4 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
struct Link;
extern u32 GFL_NET_GetHandleNetID(struct Link *p);
extern u32 GFL_NET_SendData(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
u32 LIVEBATTLEMATCH_IRC_SendSyncValue(int unused,int a) {int flag;int v;v=GFL_NET_GetHandleNetID((struct Link *)((int)GFL_NET_HANDLE_GetCurrentHandle()));flag=1;if(v!=0)flag=0;return GFL_NET_SendData((int)GFL_NET_HANDLE_GetCurrentHandle(),(u8)flag,0x1f03,4,(int)a,(int)1,(int)1,(int)1);}
