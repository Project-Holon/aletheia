/*
 * function: func_0202F038
 * address:  0x0202F038
 * packet:   pkt_0202EF98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_020437AC   0x020437AC  arm
 *   func_020307B0   0x020307B0  arm
 *   func_02045770   0x02045770  arm
 *   func_02043B5C   0x02043B5C  arm
 *   func_02045334   0x02045334  arm
 *   func_020452E8   0x020452E8  arm
 *   func_02030EAC   0x02030EAC  arm
 *   func_02031194   0x02031194  arm
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202F038.c \
 *       --func func_0202F038 --addr 0x0202F038 --cc 1.1p1 --thumb
 */
#include "../include/Obj01809.h"

typedef unsigned char u8;
typedef unsigned int  u32;

struct CharBuf;
struct Descriptor;
struct Node;
struct Obj020437AC;
struct TcblNode;
extern void func_020437AC(struct Obj020437AC *p);
extern void func_020307B0(void *p);
struct Descriptor;
extern void *func_02045770(struct Descriptor *a);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void func_02045334(struct Descriptor *a);
extern void func_020452E8(struct Descriptor *d);
extern void func_02030EAC(struct Node *n);
extern void func_02031194(struct TcblNode *n);

void func_0202F038(u8 *p)
{
    if (((struct Obj01809 *)p)->f0 == 0 && ((struct Obj01809 *)p)->f4 == 0) {
        func_020437AC((struct Obj020437AC *)(((struct Obj01809 *)p)->fC));
        func_020307B0(p);
        return;
    }

    ((struct Obj01809 *)p)->f18 = 0;
    func_02043B5C((struct CharBuf *)((u32)func_02045770((struct Descriptor *)((struct Obj01809 *)p)->f8)), ((struct Obj01809 *)p)->f12);
    func_02045334((struct Descriptor *)((struct Obj01809 *)p)->f8);
    func_020452E8((struct Descriptor *)(((struct Obj01809 *)p)->f8));
    func_020437AC((struct Obj020437AC *)(((struct Obj01809 *)p)->fC));

    if (((struct Obj01809 *)p)->f0 != 0) {
        func_02030EAC((struct Node *)(((struct Obj01809 *)p)->f0));
        func_020307B0(p);
        return;
    }

    if (((struct Obj01809 *)p)->f4 != 0)
        func_02031194((struct TcblNode *)(((struct Obj01809 *)p)->f4));
}
