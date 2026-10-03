/*
 * function: func_021D8010
 * address: 0x021D8010
 * packet: pkt_ov116_021D8010
 * region: ov116
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F250 0x0201F250 thumb
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02012FFC 0x02012FFC thumb
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201F73C 0x0201F73C thumb
 *   func_02045334 0x02045334 arm
 */
typedef unsigned short u16;
typedef unsigned u32;
struct Rec3;
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045CAC(u32,u32,u32);
extern void func_0201F250(u32,u32,u32);
extern u32 func_02045770(u32);
extern void func_02043B5C(u32,int);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(u32,int,int,u32,u32,u32,u32,int,u16,int);
extern void func_0201F73C(u32,int,u16,int);
extern void func_02045334(u32);
#define I(k) (*(u32 *)((char *)p+(k)))
void func_021D8010(void *p,u32 a) {
 if(I(0x9a4)!=0) {func_0201CE48((void *)I(0x9a4)); I(0x9a4)=0;}
 func_02045CAC(I(0x990),a,I(0x99c));
 func_0201F250(I(0x994),I(0x9a0),I(0x99c));
 func_02043B5C(func_02045770(I(0x97c)),15);
 func_0201DD78(1,2,15);
 I(0x9a4)=(u32)func_0201CCE4(I(0x97c),0,0,I(0x9a0),I(0x998),func_02012FFC(),I(0x9a8),2,*(u16 *)((char *)p+4),15);
 func_0201F73C(I(0x97c),1,I(0x984),13);
 func_02045334(I(0x97c));
}
