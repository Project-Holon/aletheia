/*
 * function: func_021DAF68
 * address: 0x021DAF68
 * packet: pkt_ov119_021DAF68
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   func_021D9C00 0x021D9C00 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;

extern int func_021E12AC(char *p);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int);
struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern void func_021D9C00(char *p);
void func_021DAF68(void *p) {
 unsigned id=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(func_021E12AC(p)) {
  if(func_021D8A24(p)) {
   b=2;
   if(GFL_NET_SendToHandle((void *)id,0xc0f,1,(u32)(&b))) func_021D8E84(p,(int)func_021D9C00);
  } else { func_021D8E84(p,(int)func_021D9C00); }
 }
}
