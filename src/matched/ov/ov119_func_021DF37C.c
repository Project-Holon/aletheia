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
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021E12AC 0x021E12AC thumb ov119
 *   func_021D8A24 0x021D8A24 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021DF338 0x021DF338 thumb ov119
 */
typedef unsigned char u8;
typedef unsigned short u16;

struct Entry;
extern struct Entry *func_020399A8(void);
typedef unsigned int   u32;
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
struct Link;
extern void func_02039C68(struct Link *p,unsigned int lo,unsigned int hi);
extern int func_021E12AC(char *);
extern int func_021D8A24(void *);
extern void func_021D8E84(void *,int);
extern void func_021DF338(void *);
void func_021DF37C(u8 *p) {
 unsigned h=(unsigned)func_020399A8();
 u8 b;
 if(func_021E12AC((char *)p)) {
  if(func_021D8A24(p)) {
   b=10;
   if(func_0203D3A8((void *)h,0xc00,1,(u32)(&b))) {
    func_02039C68((struct Link *)func_020399A8(),26,8);
    func_021D8E84(p,(int)func_021DF338);return;
   }
  } else {p[0x11e0]=10;p[0x11e1]=10;func_021D8E84(p,(int)func_021DF338);}
 }
}
