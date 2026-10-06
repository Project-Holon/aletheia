/*
 * function: func_021E0B34
 * address: 0x021E0B34
 * packet: pkt_ov119_021E0B34
 * region: ov119
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021E10D8 0x021E10D8 thumb ov119
 *   func_02045CAC 0x02045CAC arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_021E1024 0x021E1024 thumb ov119
 *   func_021E1030 0x021E1030 thumb ov119
 *   func_021DFD30 0x021DFD30 thumb ov119
 *   func_02040588 0x02040588 arm
 *   func_0203D34C 0x0203D34C arm
 *   func_0204E720 0x0204E720 arm
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021E0BA4 0x021E0BA4 thumb ov119
 */
#include "../include/Obj00001.h"
typedef unsigned short u16;
typedef signed int     s32;
typedef unsigned int   u32;
extern void func_021E10D8(char *p);
struct MsgBank;
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern void func_021E1024(void *);
extern void func_021E1030(char *p);
typedef unsigned char  u8;
extern void func_021DFD30(u8 *p, u32 v);
extern void func_02040588(u32 which, unsigned char enable);
extern void func_0203D34C(u32 a, u32 b);
extern void func_0204E720(u32 a, s32 b, s32 c, s32 d);
extern void func_021D8E84(void *,int);
extern void func_021E0BA4(void *);
void func_021E0B34(char *p) {func_021E10D8(p);func_02045CAC((struct MsgBank *)(*(int *)&((struct Obj00001 *)p)->f720),50,(void *)(*(int *)&((struct Obj00001 *)p)->f738));*(int *)&((struct Obj00001 *)p)->f644=(int)func_0201F5DC((void *)6,15,0,((struct Obj00001 *)p)->f5F4);func_021E1024(p);func_021E1030(p);func_021DFD30((u8 *)p,0);func_02040588(6,1);func_0203D34C(1,((struct Obj00001 *)p)->f5F4);func_0204E720(3,16,0,2);func_021D8E84(p,(int)func_021E0BA4);}
