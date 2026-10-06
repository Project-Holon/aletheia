/*
 * function: func_021D53D0
 * address: 0x021D53D0
 * packet: pkt_ov123_021D53D0
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 021D54DE follow the return.
 * symbols:
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_021D4A64 0x021D4A64 thumb ov123
 *   func_020307B0 0x020307B0 arm
 *   func_020403F4 0x020403F4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02031140 0x02031140 arm
 *   func_020450C8 0x020450C8 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020315D4 0x020315D4 arm
 *   func_020306F0 0x020306F0 arm
 */
#include "../include/Obj00772.h"
#include "../include/Obj22940.h"
typedef unsigned char u8;
typedef unsigned int   u32;
struct Bank;
struct Descriptor;
struct Node;
struct Obj;
struct PrintSys;
struct Rec3;
struct S02031140;
struct S020315D4;
struct TaskMenu;
struct TaskMenuState;
extern u32 func_020221A4(void);
extern void func_0204B3B4(struct Obj *p);
extern void func_0204ADA4(u32 i);
extern void func_0204A8D4(u32 i);
extern void func_0204AFD8(u32 i);
extern void func_02030EAC(struct Node *n);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_0202F038(u8 *p);
extern void func_0201CE48(struct Rec3 *p);
extern void func_02027858(struct TaskMenu *m);
extern void func_021D4A64(char *);
extern u32 func_020307B0(void *p);
extern int func_02028604(int a0);
extern void func_020403F4(u32 i);
extern void func_0201C6EC(struct PrintSys *p);
extern void func_0201C4C0(struct PrintSys *p);
extern u32 func_020452E8(struct Descriptor *d);
extern void func_02031140(struct S02031140 *p);
extern u32 func_02027FD8(struct TaskMenuState *s);
extern void func_020450C8(void);
extern void func_0203F9B4(void);
extern void func_020315D4(struct S020315D4 *p);
extern void func_020306F0(unsigned int);
int func_021D53D0(void *a,int b,u8 *out,char *p)
{
    int i;
    if(!func_020221A4()) return 0;
    for(i=0;i<3;i++) func_0204B3B4(*(void **)(p+i*4+0x2a0));
    func_0204ADA4((u32)(((struct Obj00772 *)p)->f290));
    func_0204A8D4((u32)(((struct Obj00772 *)p)->f294));
    func_0204AFD8((u32)(((struct Obj00772 *)p)->f298));
    func_02030EAC(((struct Obj00772 *)p)->f2B0);
    func_0204B1CC(((struct Obj00772 *)p)->f2AC); func_0204A5AC();
    if(((struct Obj00772 *)p)->f288) { func_0202F038(((struct Obj00772 *)p)->f288); ((struct Obj00772 *)p)->f288=0; }
    if(((struct Obj00772 *)p)->f228) func_0201CE48(((struct Obj00772 *)p)->f228);
    if(((struct Obj00772 *)p)->f238) { func_02027858(((struct Obj00772 *)p)->f238); ((struct Obj00772 *)p)->f238=0; }
    func_021D4A64(p);
    ((struct Obj22940 *)out)->f1C8=((struct Obj00772 *)p)->f8;
    func_020307B0(((struct Obj00772 *)p)->f280); func_020307B0(((struct Obj00772 *)p)->f284);
    func_02028604((int)(((struct Obj00772 *)p)->f22C)); func_020403F4(5);
    func_0201C6EC(((struct Obj00772 *)p)->f234); func_0201C4C0(((struct Obj00772 *)p)->f234);
    if(((struct Obj00772 *)p)->f224) func_020452E8(((struct Obj00772 *)p)->f224);
    func_02031140(((struct Obj00772 *)p)->f230); func_02027FD8(((struct Obj00772 *)p)->f254);
    func_020450C8(); func_0203F9B4(); func_020315D4(a); func_020306F0(31);
    return 1;
}
