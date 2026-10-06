/*
 * function: func_021D9A1C
 * address: 0x021D9A1C
 * packet: pkt_ov123_021D9A1C
 * region: ov123
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021D9FB0 0x021D9FB0 thumb ov123
 *   func_0204ADA4 0x0204ADA4 arm
 *   func_0204A8D4 0x0204A8D4 arm
 *   func_0204AFD8 0x0204AFD8 arm
 *   func_02030EAC 0x02030EAC arm
 *   func_0204B1CC 0x0204B1CC arm
 *   func_0204A5AC 0x0204A5AC arm
 *   func_02040DA8 0x02040DA8 arm
 *   func_020403F4 0x020403F4 arm
 *   func_02040588 0x02040588 arm
 *   func_0203F9B4 0x0203F9B4 arm
 *   func_020307B0 0x020307B0 arm
 *   func_02034A5C 0x02034A5C arm
 *   ov_id 0x00000043 data
 */
#include "../include/Obj03802.h"
typedef unsigned char u8;
typedef enum { C0=0 } Counter;
extern u8 ov_id[];
extern void func_021D9FB0(unsigned int p);
extern void func_0204ADA4(unsigned int i);
extern void func_0204A8D4(unsigned int i);
extern void func_0204AFD8(unsigned int i);
typedef unsigned int   u32;
struct Bank;
struct Node;
extern void func_02030EAC(struct Node *n);
extern u32 func_0204B1CC(struct Bank *bank);
extern void func_0204A5AC(void);
extern void func_02040DA8(u32 idx, u32 count, u32 tile);
extern void func_020403F4(unsigned int);
extern void func_02040588(unsigned int,unsigned int);
extern void func_0203F9B4(void);
extern u32 func_020307B0(void *p);
extern void func_02034A5C(int);
void func_021D9A1C(u8 *p)
{
    Counter i;
    func_021D9FB0((unsigned int)p);
    if (((struct Obj03802 *)p)->f8) {
        func_02030EAC(((struct Obj03802 *)p)->f8);
        ((struct Obj03802 *)p)->f8=0;
        ((struct Obj03802 *)p)->fC=0;
    }
    i=0;
    do { if (*(void **)(p+i*4+0x988)) func_0204ADA4((unsigned int)(*(void **)(p+i*4+0x988))); i++; } while(i<3);
    for(;i<6;i++) if (*(void **)(p+i*4+0x988)) func_0204A8D4((unsigned int)(*(void **)(p+i*4+0x988)));
    for(;i<9;i++) if (*(void **)(p+i*4+0x988)) func_0204AFD8((unsigned int)(*(void **)(p+i*4+0x988)));
    if (((struct Obj03802 *)p)->f984) func_02030EAC(((struct Obj03802 *)p)->f984);
    func_02030EAC(((struct Obj03802 *)p)->f980);
    func_0204B1CC(((struct Obj03802 *)p)->f97C);
    func_0204A5AC();
    func_02040DA8(1,1,0);
    func_02040DA8(6,1,0);
    func_020403F4(5);
    func_020403F4(4);
    func_02040588(5,0);
    func_0203F9B4();
    func_020307B0(p);
    func_02034A5C((int)ov_id);
}
