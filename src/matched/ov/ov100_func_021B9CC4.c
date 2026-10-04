/*
 * function: func_021B9CC4
 * address: 0x021B9CC4
 * packet: pkt_ov100_021B9CC4
 * region: ov100
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_020399A8 0x020399A8 arm
 *   func_02039CB4 0x02039CB4 arm
 *   func_0201283C 0x0201283C thumb
 *   func_02009CA8 0x02009CA8 thumb
 *   func_0203D3A8 0x0203D3A8 arm
 *   func_02039C68 0x02039C68 arm
 *   func_02027858 0x02027858 thumb
 *   func_021B95B8 0x021B95B8 thumb ov100
 *   func_021B9C50 0x021B9C50 thumb ov100
 */
typedef unsigned short u16;
typedef unsigned char u8;
struct Entry;
extern struct Entry *func_020399A8(void);
struct Link;
extern unsigned int func_02039CB4(struct Link *p, unsigned int lo, unsigned int hi);
typedef unsigned int   u32;
struct BigObj;
struct TaskMenu;
extern u32 func_0201283C(const struct BigObj *p);
extern void func_02009CA8(void *account, void *out);
extern int func_0203D3A8(struct Entry *a, u16 b, u16 c, u32 d);
struct Link;
extern void func_02039C68(struct Link *p, unsigned int lo, unsigned int hi);
extern void func_02027858(struct TaskMenu *m);
extern void func_021B95B8(u8 *p, u32 v);
extern void func_021B9C50(int a);
void func_021B9CC4(int a)
{
 u8 x[12];
 int k=12;
 if(func_02039CB4((struct Link *)func_020399A8(),0x7b,k)!=0) {
  if(*(int *)(a+0x24c)==7) {
   func_02009CA8((void *)func_0201283C((const struct BigObj *)(**(int **)(a+0x244))),x);
   if(func_0203D3A8(func_020399A8(),0xc03,k,(u32)x)!=0) {
    func_02039C68((struct Link *)func_020399A8(),0x79,k);
    func_021B95B8((u8 *)a,(u32)func_021B9C50);
    if(*(int *)(a+0xcc0)!=0) {
     func_02027858((struct TaskMenu *)(*(int *)(a+0xcc0)));
     *(int *)(a+0xcc0)=0;
    }
   }
  } else {
   func_02039C68((struct Link *)func_020399A8(),0x79,k);
   if(*(int *)(a+0xcc0)!=0) {
    func_02027858((struct TaskMenu *)(*(int *)(a+0xcc0)));
    *(int *)(a+0xcc0)=0;
   }
   func_021B95B8((u8 *)a,(u32)func_021B9C50);
  }
 }
}
