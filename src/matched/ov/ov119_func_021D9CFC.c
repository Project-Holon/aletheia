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
 *   func_020399A8 0x020399A8 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 */
typedef unsigned short u16;
typedef unsigned char u8;
extern int func_021D8A24(void *);
extern int func_021E12AC(void *);
extern void func_021D8E84(void *,int);
extern void func_021D9C00(void *);
extern void *func_020399A8(void);
extern int func_0203D3A8(void *a, u16 b, u16 c, void *d);
extern void func_02039C68(void *,unsigned,unsigned);
void func_021D9CFC(u8 *p) { int kind=func_021D8A24(p); u8 b; if(func_021E12AC(p)) { if(kind==0) {p[0x11e0]=1;p[0x11e1]=1;func_021D8E84(p,(int)func_021D9C00);return;} b=1; if(func_0203D3A8(func_020399A8(),0xc00,1,&b)==0) return; func_02039C68(func_020399A8(),26,8);func_021D8E84(p,(int)func_021D9C00); } }
