/*
 * function: func_021B9770
 * address: 0x021B9770
 * packet: pkt_ov220_021B9770
 * region: ov220
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * volatile: hardware accesses at 021B9794 and 021B9798/021B979E.
 * symbols:
 *   func_020403F4 0x020403F4 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0201C6EC 0x0201C6EC thumb
 *   func_0201C4C0 0x0201C4C0 thumb
 *   func_0201D83C 0x0201D83C thumb
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 *   func_021B9FF0 0x021B9FF0 thumb ov220
 *   func_021B9C70 0x021B9C70 thumb ov220
 *   func_021B9B20 0x021B9B20 thumb ov220
 *   func_021B99D8 0x021B99D8 thumb ov220
 *   func_021BA178 0x021BA178 thumb ov220
 *   d_021BA370 0x021BA370 data a4
 */
#include "../include/Obj01297.h"
typedef unsigned char u8;
typedef struct {unsigned first;char pad[40];} Entry;
extern const Entry d_021BA370[];
typedef unsigned int   u32;
struct Node;
struct PrintSys;
extern void func_020403F4(u32 i);
extern void func_02030EAC(struct Node *n);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_0201D83C(void *ptr);
extern void func_020306F0(unsigned int heap);
struct S020315D4;
extern void func_020315D4(struct S020315D4 *p);
extern void func_021B9FF0(u8 *p);
extern void func_021B9C70(unsigned char *p);
extern void func_021B9B20(void *);
extern void func_021B99D8(void *);
extern void func_021BA178(unsigned char *p);
int func_021B9770(void *state,int unused1,int unused2,char *p)
{
    int i;
    for(i=0;i<1u;i++) func_020403F4((u8)d_021BA370[i].first);
    *(volatile unsigned short *)0x04001050=0;
    *(volatile unsigned *)0x04001000 &=0xFFFF1FFF;
    func_021B9FF0((u8 *)p);
    func_021B9C70((unsigned char *)p);
    func_021B9B20(p);
    func_021B99D8(p);
    func_02030EAC(((struct Obj01297 *)p)->f14);
    func_0201C6EC(((struct Obj01297 *)p)->f10);
    func_0201C4C0(((struct Obj01297 *)p)->f10);
    func_0201D83C(((struct Obj01297 *)p)->fC);
    func_021BA178(((struct Obj01297 *)p)->f8);
    func_020315D4(state);
    func_020306F0(131);
    return 1;
}
