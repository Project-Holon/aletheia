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
extern struct Entry *func_020399A8(void);
extern int func_02039CB4(void *,int,int);
extern unsigned func_0203D378(void);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
extern int func_02039C68(void *, int, int);
extern void func_021B95B8(int,void (*)(void));
extern void func_021B9B7C(void);
void func_021B9BE4(int a)
{
 int k=12;
 if(func_02039CB4(func_020399A8(),0x7d,k)!=0) {
  if(func_0203D378()!=0) {
   if(func_0203D3A8(func_020399A8(),0xc05,4,*(int *)(a+0x244)+0x18)!=0) {
    func_02039C68(func_020399A8(),0x7e,k);
    func_021B95B8(a,func_021B9B7C);
   }
  } else {
   func_02039C68(func_020399A8(),0x7e,k);
   func_021B95B8(a,func_021B9B7C);
  }
 }
}
