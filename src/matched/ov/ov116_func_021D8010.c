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
#include "../include/Obj22630.h"
typedef unsigned short u16;
typedef unsigned u32;
struct Rec3;
extern void func_0201CE48(struct Rec3 *p);
typedef unsigned char  u8;
struct CharBuf;
struct MsgBank;
struct WordSet;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void func_0201F250(struct WordSet *ws, void *dst, void *src);
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_0201DD78(u32 r, u32 g, u32 b);
extern signed char func_02012FFC(void);
extern void *func_0201CCE4(u32,int,int,u32,u32,u32,u32,int,u16,int);
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
#define I(k) (*(u32 *)((char *)p+(k)))
void func_021D8010(void *p,u32 a) {
 if(I(0x9a4)!=0) {func_0201CE48((void *)I(0x9a4)); I(0x9a4)=0;}
 func_02045CAC((struct MsgBank *)I(0x990),a,(void *)I(0x99c));
 func_0201F250((struct WordSet *)I(0x994),(void *)I(0x9a0),(void *)I(0x99c));
 func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)I(0x97c))),15);
 func_0201DD78(1,2,15);
 I(0x9a4)=(u32)func_0201CCE4(I(0x97c),0,0,I(0x9a0),I(0x998),func_02012FFC(),I(0x9a8),2,((struct Obj22630 *)p)->f4,15);
 func_0201F73C((void *)I(0x97c),1,(u16)I(0x984),13);
 func_02045334((struct Descriptor *)I(0x97c));
}
