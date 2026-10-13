/*
 * function: func_021DEDBC
 * address: 0x021DEDBC
 * packet: pkt_ov119_021DEDBC
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GFL_NET_HANDLE_GetCurrentHandle 0x020399A8 arm
 *   GFL_NET_SendToHandle 0x0203D3A8 arm
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DED74 0x021DED74 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;

struct Entry;
extern struct Entry *GFL_NET_HANDLE_GetCurrentHandle(void);
typedef unsigned int   u32;
extern int GFL_NET_SendToHandle(struct Entry *a, u32 b, u32 c, u32 d);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int);
extern void func_021DED74(void *);
void func_021DEDBC(void *p) {
 unsigned h=(unsigned)GFL_NET_HANDLE_GetCurrentHandle();
 u8 b;
 if(func_021D8A24(p)) {
  b=1;
  if(GFL_NET_SendToHandle((void *)h,0xc0a,1,(u32)(&b))) {func_021D8E84(p,(int)func_021DED74);return;}
 } else {func_021D8E84(p,(int)func_021DED74);}
}
