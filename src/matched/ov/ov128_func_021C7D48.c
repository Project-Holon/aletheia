/*
 * function: func_021C7D48
 * address: 0x021C7D48
 * packet: pkt_ov128_021C7D48
 * region: ov128
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021CA444 0x021CA444 thumb ov128
 *   func_021CA458 0x021CA458 thumb ov128
 *   func_0204B3B4 0x0204B3B4 arm
 *   func_020452E8 0x020452E8 arm
 *   func_02045808 0x02045808 arm
 *   func_021C4080 0x021C4080 thumb ov127
 *   func_021C3F80 0x021C3F80 thumb ov127
 *   func_021C88BC 0x021C88BC thumb ov128
 */
#include "../include/Obj03281.h"
typedef unsigned char u8;
extern void func_021CA444(char *);
extern void func_021CA458(char *p, void *q);
struct Descriptor;
struct Obj;
struct TaskMenuState;
struct U16Vec;
extern void func_0204B3B4(struct Obj *p);
extern void func_020452E8(struct Descriptor *d);
extern void func_02045808(struct U16Vec *vec);
extern void func_02027FD8(struct TaskMenuState *s);
extern void func_021C4080(u8 *p);
extern void func_021C3F80(u8 *);
extern void func_021C88BC(u8 *,u8 *);
void func_021C7D48(u8 *p, void *unused, u8 *a)
{
    int i;
    int offset;
    func_021CA444((char *)a);
    func_021CA458((char *)a,a + 12);
    func_0204B3B4(((struct Obj03281 *)p)->f1A4);
    func_0204B3B4(((struct Obj03281 *)p)->f1A0);
    func_020452E8(((struct Obj03281 *)p)->f108);
    func_02045808(((struct Obj03281 *)p)->f110);
    func_02027FD8(((struct Obj03281 *)p)->f190);
    func_02045808(((struct Obj03281 *)p)->f178);
    func_02045808(((struct Obj03281 *)p)->f184);
    offset=0x1a4;
    i=0;
    offset=0x118;
    for (; i < 4; i++) {
        func_02045808(*(void **)(p + i * 12 + offset));
        func_02045808(*(void **)(p + i * 12 + 0x148));
    }
    func_021C4080(((struct Obj03281 *)p)->f104);
    func_021C3F80(*(u8 * *)&((struct Obj03281 *)p)->f104);
    for(i=0;i<3;i++) func_021C88BC(p + 12 + i * 0x4c,a);
    for(i=0;i<2;i++) func_020452E8(*(void **)(p + i * 8 + 0xf0));
}
