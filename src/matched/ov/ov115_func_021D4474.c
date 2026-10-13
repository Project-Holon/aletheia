/*
 * function: func_021D4474
 * address: 0x021D4474
 * packet: pkt_ov115_021D4474
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   OS_IsRunOnTwl 0x02085D3C arm
 *   GFL_NET_StartSession 0x0203CBAC arm
 *   GFL_NET_STATE_WifiStartMatch 0x0203C8A8 arm
 *   GFL_NET_RestartWithDefaultTimeout 0x0203D34C arm
 *   func_021D5C24 0x021D5C24 thumb ov115
 *   func_021D592C 0x021D592C thumb ov115
 *   func_021D426C 0x021D426C thumb ov115
 *   func_021D4430 0x021D4430 thumb ov115
 *   d_021D6560 0x021D6560 data a4
 *   d_021D65C0 0x021D65C0 data a4
 *   d_021D6640 0x021D6640 data a4
 */
#include "../include/Obj13849.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern int OS_IsRunOnTwl(void);
struct Req;
extern void GFL_NET_StartSession(struct Req *req, u32 a2, u32 a3);
extern void GFL_NET_STATE_WifiStartMatch(void);
extern void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
extern void func_021D5C24(void *,int);
extern void func_021D592C(u8 *);
extern void func_021D426C(u8 *,u32);
extern void func_021D4430(u8 *);
extern u8 d_021D6560[];
extern u8 d_021D65C0[];
extern u8 d_021D6640[];
#define W(k) (*(int *)(p+(k)))
#define P(k) (*(u8 **)(p+(k)))
void func_021D4474(u8 *p) {
 int z; if(OS_IsRunOnTwl()) *(u32 *)(d_021D6560+0x48)=0x79000; else *(u32 *)(d_021D6560+0x48)=0x5e400; if(*(int *)(P(0x40)+0xc)==44) *(u32 *)(d_021D6560+0x48)=0x50000; else if(*(int *)(P(0x40)+0xc)==36) *(u32 *)(d_021D6560+0x48)=0x6e000; if(*(int *)(P(0x40)+0xc)!=10) *(u32 *)(d_021D6560+0x40)=0; z=0; d_021D65C0[7]=*(int *)(P(0x40)+0xc); *(u32 *)d_021D6640=*(int *)(P(0x40)+0xc); GFL_NET_StartSession((struct Req *)d_021D6560,z,(u32)p); GFL_NET_STATE_WifiStartMatch(); if(!*(int *)(P(0x40)+8)) GFL_NET_RestartWithDefaultTimeout(z,((struct Obj13849 *)p)->fC); else GFL_NET_RestartWithDefaultTimeout(1,((struct Obj13849 *)p)->fC); func_021D5C24((void *)W(0x38),23); func_021D592C(P(0x34)); func_021D426C(p,(u32)func_021D4430);
}
