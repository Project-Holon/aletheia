/*
 * function: func_021B9750
 * address:  0x021B9750
 * packet:   pkt_ov071_021B9750
 * region:   ov071
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02045EC0  0x02045EC0  arm
 *   func_02045770  0x02045770  arm
 *   func_0201C6FC  0x0201C6FC  thumb
 *   func_02045808  0x02045808  arm
 */
#include "../include/Obj02123.h"
#include "../include/Obj13182.h"
#include "../include/Obj13183.h"
#include "../include/Obj20750.h"

typedef unsigned int u32;
typedef unsigned char u8;

struct Descriptor;
struct MsgBank;
struct U16Vec;
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_02045770(struct Descriptor *p);
struct PrintSys;
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
extern void func_02045808(struct U16Vec *vec);

void func_021B9750(char *a, char *b)
{
    void *r6;
    char *r4;
    void *r7;

    r6 = func_02045EC0(((struct Obj20750 *)(*(char * *)&((struct Obj02123 *)a)->f4))->f28, 0x22);
    r4 = *(char * *)&((struct Obj02123 *)a)->f4;
    r7 = ((struct Obj13183 *)r4)->f8;
    func_0201C6FC(r7, (u32)func_02045770(((struct Obj13182 *)b)->f288), 0x18, 4, r6, (u32)(((struct Obj13183 *)r4)->fC));
    ((struct Obj13182 *)b)->f28C = 1;
    func_02045808(r6);
}
