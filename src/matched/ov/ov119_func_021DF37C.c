/*
 * function: func_021DF37C
 * address: 0x021DF37C
 * packet: pkt_ov119_021DF37C
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   GFL_NET_HANDLE_SetTimingSyncRange 0x02039C68 arm
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF338 0x021DF338 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void GFL_NET_HANDLE_SetTimingSyncRange(struct Link *p,unsigned int lo,unsigned int hi);
extern int func_021E12AC(char *);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int);
extern void func_021DF338(void *);
void func_021DF37C(u8 *p) {
 unsigned h=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(func_021E12AC((char *)p)) {
  if(func_021D8A24(p)) {
   b=10;
   if(GFL_NET_SendToHandle((void *)h,0xc00,1,(u32)(&b))) {
    GFL_NET_HANDLE_SetTimingSyncRange((struct Link *)GFL_NET_HANDLE_GetCurrentHandle(),26,8);
    func_021D8E84(p,(int)func_021DF338);return;
   }
  } else {p[0x11e0]=10;p[0x11e1]=10;func_021D8E84(p,(int)func_021DF338);}
 }
}
