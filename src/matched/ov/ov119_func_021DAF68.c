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
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_021D9C00 0x021D9C00 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;

extern int func_021E12AC(char *p);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int);
extern unsigned func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern void func_021D9C00(char *p);
void func_021DAF68(void *p) {
 unsigned id=func_020399A8();
 u8 b;
 if(func_021E12AC(p)) {
  if(func_021D8A24(p)) {
   b=2;
   if(func_0203D3A8((void *)id,0xc0f,1,&b)) func_021D8E84(p,(int)func_021D9C00);
  } else { func_021D8E84(p,(int)func_021D9C00); }
 }
}
