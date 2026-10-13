/*
 * function: func_021D9CFC
 * address: 0x021D9CFC
 * packet: pkt_ov119_021D9CFC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D9C00 0x021D9C00 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern int func_021D8A24(void *);
extern int func_021E12AC(char *p);
extern void func_021D8E84(void *,int);
struct Entry;
extern void func_021D9C00(char *p);
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void func_02039C68(struct Link *,unsigned,unsigned);
void func_021D9CFC(u8 *p) { int kind=func_021D8A24(p); u8 b; if(func_021E12AC((char *)p)) { if(kind==0) {p[0x11e0]=1;p[0x11e1]=1;func_021D8E84(p,(int)func_021D9C00);return;} b=1; if(GFL_NET_SendToHandle(GFL_NET_HANDLE_GetCurrentHandle(),0xc00,1,(u32)(&b))==0) return; func_02039C68((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);func_021D8E84(p,(int)func_021D9C00); } }
