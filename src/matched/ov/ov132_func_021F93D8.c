/*
 * function: func_021F93D8
 * address: 0x021F93D8
 * packet: pkt_ov132_021F93D8
 * region: ov132
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0201CE48 0x0201CE48 thumb
 *   func_02045808 0x02045808 arm
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045EC0 0x02045EC0 arm
 *   func_0201CCE4 0x0201CCE4 thumb
 *   func_0201C6FC 0x0201C6FC thumb
 * abi: 0201CCE4 forwards the pointer result of matched 0201CD10; the caller stores it at d8.
 */
#include "../include/Obj00832.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef enum { ZERO } Zero;
struct CharBuf;
struct Descriptor;
struct MsgBank;
struct Rec3;
struct U16Vec;
extern void func_0201CE48(struct Rec3 *p);
extern void func_02045808(struct U16Vec *vec);
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void *func_0201CCE4(void *, u32, u32, void *, void *, u32, void *, u32, u16, u32);
struct PrintSys;
extern void func_0201C6FC(struct PrintSys *p, u32 a, u32 b, u32 c, void *s, u32 e);
void func_021F93D8(u8 *p, u16 index, u32 speed)
{
    Zero zero;
    if (((struct Obj00832 *)p)->fD8) {
        func_0201CE48(((struct Obj00832 *)p)->fD8);
        ((struct Obj00832 *)p)->fD8 = 0;
    }
    if (((struct Obj00832 *)p)->fE0) {
        func_02045808(((struct Obj00832 *)p)->fE0);
        ((struct Obj00832 *)p)->fE0 = 0;
    }
    func_02043B5C(func_02045770(((struct Obj00832 *)p)->fD0), 0);
    zero = ZERO;
    ((struct Obj00832 *)p)->fE0 = func_02045EC0(((struct Obj00832 *)p)->fDC, index);
    if (speed != 255) {
        ((struct Obj00832 *)p)->fD8 = func_0201CCE4(((struct Obj00832 *)p)->fD0, zero, zero,
            ((struct Obj00832 *)p)->fE0, ((struct Obj00832 *)p)->fD4, speed,
            ((struct Obj00832 *)p)->fCC, 2, ((struct Obj00832 *)p)->f0, zero);
    } else {
        func_0201C6FC(((struct Obj00832 *)p)->fE8, (u32)func_02045770(((struct Obj00832 *)p)->fD0),
            zero, zero, ((struct Obj00832 *)p)->fE0, *(u32 *)&((struct Obj00832 *)p)->fD4);
        ((struct Obj00832 *)p)->fE4 = 1;
        func_02045808(((struct Obj00832 *)p)->fE0);
        ((struct Obj00832 *)p)->fE0 = (void *)zero;
    }
}
