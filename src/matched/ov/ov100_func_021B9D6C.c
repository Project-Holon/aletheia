/*
 * function: func_021B9D6C
 * address: 0x021B9D6C
 * packet: pkt_ov100_021B9D6C
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02008468 0x02008468 thumb
 *   func_02012944 0x02012944 thumb
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9CC4 0x021B9CC4 thumb ov100
 */
typedef unsigned short u16;

struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_02008468(void);
typedef unsigned char  u8;
extern u8 *func_02012944(void *p);
typedef unsigned int   u32;
struct Entry;
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
struct Link;
extern void func_02039C68(struct Link *,unsigned int,unsigned int);
extern void func_021B95B8(int,void (*)(void));
extern void func_021B9CC4(int a);
void func_021B9D6C(int a) {
 int p=(int)func_020399A8();
 int k=func_02008468();
 int v=(int)func_02012944((void *)(**(int **)(a+0x244)));
 if(func_0203D3A8((void *)p,0xc01,k,v)!=0) {
  func_02039C68((struct Link *)func_020399A8(),0x7b,12);
  func_021B95B8(a,(void (*)(void))func_021B9CC4);
 }
}
