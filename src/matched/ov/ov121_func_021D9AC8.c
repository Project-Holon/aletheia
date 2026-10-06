/*
 * function: func_021D9AC8
 * address: 0x021D9AC8
 * packet: pkt_ov121_021D9AC8
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x021D9B26.
 * symbols:
 *   func_02045770 0x02045770 arm
 *   func_02043B5C 0x02043B5C arm
 *   func_02045838 0x02045838 arm
 *   func_021D9BC0 0x021D9BC0 thumb ov121
 */
#include "../include/Obj01057.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef signed short s16;
typedef struct { int x; int y; } Pair;
struct CharBuf;
struct Descriptor;
extern void *func_02045770(struct Descriptor *p);
extern void func_02043B5C(struct CharBuf *buf, u8 value);
struct U16Vec;
extern void func_02045838(struct U16Vec *dst, struct U16Vec *src);
extern void func_021D9BC0(void *, int, Pair *);
typedef unsigned int   u32;
extern void func_0201C724(void *owner, u32 a, u32 b, u32 c, u32 d, u32 e, u16 f);
void func_021D9AC8(u8 *p, int a, int b)
{
    Pair xy;
    void *q;
    func_02043B5C(func_02045770(((struct Obj01057 *)p)->fC), ((struct Obj01057 *)p)->f16 & 31);
    func_02045838(((struct Obj01057 *)p)->f10, (struct U16Vec *)a);
    func_021D9BC0(p, b, &xy);
    q = ((struct Obj01057 *)p)->f8;
    func_0201C724(q, (u32)func_02045770(((struct Obj01057 *)p)->f0), (s16)xy.x, (s16)xy.y,
                 (u32)(((struct Obj01057 *)p)->f10), b, ((struct Obj01057 *)p)->f16);
    p[4] = 1;
}
