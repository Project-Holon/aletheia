/*
 * function: func_021B9B7C
 * address: 0x021B9B7C
 * packet: pkt_ov100_021B9B7C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0201A918 0x0201A918 thumb
 *   func_0203D3F8 0x0203D3F8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9AD8 0x021B9AD8 thumb ov100
 */
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *,unsigned int,unsigned int);
extern int func_0201A918(void);
typedef unsigned int   u32;
extern u32 func_0203D3F8(u32 entry, u32 sendID, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);
struct Link;
extern void func_02039C68(struct Link *,u32,u32);
typedef unsigned char  u8;
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021B9AD8(int a);
void func_021B9B7C(int a)
{
 int k=12;
 if(func_02039CB4((struct Link *)func_020399A8(),0x7e,k)!=0) {
  int p=(int)func_020399A8();
  int q=func_0201A918();
  if(func_0203D3F8(p,0xff,0xc02,q,(*(int **)(a+0x244))[1],0,0,1)!=0) {
   func_02039C68((struct Link *)func_020399A8(),0x7a,k);
   func_021B95B8((u8 *)a,(u32)func_021B9AD8);
  }
 }
}
