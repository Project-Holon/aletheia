/*
 * function: func_021B9784
 * address:  0x021B9784
 * packet:   pkt_ov069_021B9784
 * region:   ov069
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020307B0  0x020307B0  arm
 *   func_02045808  0x02045808  arm
 *   func_0201ED04  0x0201ED04  thumb
 *   func_02045C04  0x02045C04  arm
 *   func_02030EAC  0x02030EAC  arm
 *   func_02049238  0x02049238  arm
 */
#include "../include/Obj01132.h"

typedef unsigned char u8;

extern void func_020307B0(void *p);
struct Node;
struct Rec;
struct U16Vec;
struct WordSet;
extern void func_02045808(struct U16Vec *vec);
extern void func_0201ED04(struct WordSet *p);
extern void func_02045C04(struct Rec *rec);
extern void func_02030EAC(struct Node *n);
extern void func_02049238(void *p);

void func_021B9784(u8 *p)
{
    int i;

    func_020307B0(((struct Obj01132 *)p)->f8);
    for (i = 0; i < 7; i++) {
        func_02045808(*(void **)(p + i * 4 + 0x100));
    }
    func_02045808(((struct Obj01132 *)p)->fFC);
    func_0201ED04(((struct Obj01132 *)p)->fF8);
    func_02045C04(((struct Obj01132 *)p)->fF4);
    func_02030EAC(((struct Obj01132 *)p)->f150);
    func_02049238(((struct Obj01132 *)p)->f0);
}
