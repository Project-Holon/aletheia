/*
 * function: func_021B9BE4
 * address: 0x021B9BE4
 * packet: pkt_ov100_021B9BE4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0203D378 0x0203D378 arm
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9B7C 0x021B9B7C thumb ov100
 */
typedef unsigned short u16;

typedef unsigned int   u32;
struct Entry;
struct Link;
extern struct Entry *func_020399A8(void);
extern u32 func_02039CB4(struct Link *,u32,u32);
extern unsigned func_0203D378(void);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
extern void func_02039C68(struct Link *, u32, u32);
typedef unsigned char  u8;
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021B9B7C(int a);
void func_021B9BE4(int a)
{
 int k=12;
 if(func_02039CB4((struct Link *)func_020399A8(),0x7d,k)!=0) {
  if(func_0203D378()!=0) {
   if(func_0203D3A8(func_020399A8(),0xc05,4,*(int *)(a+0x244)+0x18)!=0) {
    func_02039C68((struct Link *)func_020399A8(),0x7e,k);
    func_021B95B8((u8 *)a,(u32)func_021B9B7C);
   }
  } else {
   func_02039C68((struct Link *)func_020399A8(),0x7e,k);
   func_021B95B8((u8 *)a,(u32)func_021B9B7C);
  }
 }
}
