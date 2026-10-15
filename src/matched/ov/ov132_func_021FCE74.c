/*
 * function: MUS_COMM_FUNC_SendCommand
 * address: 0x021FCE74
 * packet: pkt_ov132_021FCE74
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendData 0x0203D3F8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
struct Request {u8 kind;u32 value;};
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern u32 GFL_NET_SendData(u32,u32,u32,u32,u32,u32,u32,u32);
void MUS_COMM_FUNC_SendCommand(int unused,int kind,u32 value,u32 id) {struct Entry *e;struct Request request;e=GFL_NET_HANDLE_GetCurrentHandle();request.kind=kind;request.value=value;GFL_NET_SendData((u32)e,id,0x1100,8,(u32)&request,1,0,0);}
