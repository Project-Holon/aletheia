/*
 * function: func_021DCB94
 * address: 0x021DCB94
 * packet: pkt_ov137_021DCB94
 * region: ov137
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: separate q=(u8 *)((u32)p+4) keeps the updated buffer base;
 *   assigning p+=4 or retaining an integer parameter gave 50 bytes/DIFF.
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   func_02082D44 0x02082D44 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
extern void func_02082D44(const void *,void *,u32);
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
void func_021DCB94(u8 *p,u32 id,const void *data,u32 size) {u8 *q;void *v;v=GFL_NET_HANDLE_GetCurrentHandle();q=(u8 *)((u32)p+4);func_02082D44(data,q+4,size);GFL_NET_SendToHandle(v,(u16)id,(u16)(size+4),(u32)q+4);}
