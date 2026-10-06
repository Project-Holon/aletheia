/*
 * function: func_021F6060
 * address: 0x021F6060
 * packet: pkt_ov215_021F6060
 * region: ov215
 * compiler: 1.1p1
 * flags: -O4,p
 * isa: thumb
 * lang: c99
 * status: EXACT
 * symbols:
 *   func_02049B40 0x02049B40 arm
 *   func_020450F0 0x020450F0 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045334 0x02045334 arm
 *   func_0201F5DC 0x0201F5DC thumb
 *   func_02045B38 0x02045B38 arm
 *   func_0203101C 0x0203101C arm
 *   func_0201DD78 0x0201DD78 thumb
 *   func_02041B6C 0x02041B6C arm
 *   func_02040588 0x02040588 arm
 */
#include "../include/Obj01296.h"
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
extern void func_02049B40(u32,u32,u32,u32,u32,u16);
extern u32 func_020450F0(u32,u32,u32,u32,u8,u8,u8);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
struct CharBuf;
struct MsgBank;
struct Tcbl;
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *);
extern void *func_0201F5DC(void *a0, u32 a1, u32 a2, u32 a3);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern struct Tcbl *func_0203101C(u16 heap, u16 tag, u32 count, u32 workSize);
extern void func_0201DD78(u32,u32,u32);
extern void func_02041B6C(u32);
extern void func_02040588(unsigned char which, unsigned char enable);
void func_021F6060(int unused,char *p)
{
    func_02049B40(23,5,0,32,32,((struct Obj01296 *)p)->f0);
    ((struct Obj01296 *)p)->f5C=func_020450F0(1,0,0,1,1,1,0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01296 *)p)->f5C)),0);
    func_02045334((struct Descriptor *)((struct Obj01296 *)p)->f5C);
    ((struct Obj01296 *)p)->f58=func_020450F0(1,1,19,30,4,1,0);
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01296 *)p)->f58)),15);
    func_02045334((struct Descriptor *)((struct Obj01296 *)p)->f58);
    ((struct Obj01296 *)p)->f60=(u32)func_0201F5DC((void *)1,2,0,((struct Obj01296 *)p)->f0);
    ((struct Obj01296 *)p)->f64=(u32)func_02045B38(0,3,260,((struct Obj01296 *)p)->f0);
    ((struct Obj01296 *)p)->f54=(u32)func_0203101C(((struct Obj01296 *)p)->f0,((struct Obj01296 *)p)->f0,1,0);
    func_0201DD78(1,2,15);
    func_02041B6C(1);
    ((struct Obj01296 *)p)->f50=0;
    ((struct Obj01296 *)p)->f68=0;
    ((struct Obj01296 *)p)->f6C=0;
    func_02040588(1,0);
}
