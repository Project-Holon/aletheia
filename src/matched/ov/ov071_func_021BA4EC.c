/*
 * function: func_021BA4EC
 * address: 0x021BA4EC
 * packet: pkt_ov071_021BA4EC
 * region: ov071
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * note: trailing two-byte alignment padding.
 * symbols:
 *   func_02045EC0 0x02045EC0 arm
 *   func_02045770 0x02045770 arm
 *   func_0201C6FC 0x0201C6FC thumb
 *   func_02045808 0x02045808 arm
 */
#include "../include/Obj09901.h"
#include "../include/Obj13189.h"
typedef unsigned int   u32;
struct MsgBank;
struct PrintSys;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
struct Descriptor;
extern void *func_02045770(struct Descriptor *);
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);
void func_021BA4EC(char *p, char *q) {
    unsigned s, h;
    s = (unsigned int)func_02045EC0((struct MsgBank *)(((struct Obj09901 *)p)->f28),38);
    h = ((struct Obj09901 *)p)->f8;
    func_0201C6FC((struct PrintSys *)h,(unsigned)func_02045770((struct Descriptor *)((struct Obj13189 *)q)->fC),0,4,(void *)s,((struct Obj09901 *)p)->fC);
    q[16] = 1;
    func_02045808((struct U16Vec *)s);
}
