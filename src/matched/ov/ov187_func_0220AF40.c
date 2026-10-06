/*
 * packet: pkt_ov187_0220AF40
 * function: func_0220AF40
 * address: 0x0220AF40
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * region: ov187
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082BCC 0x02082BCC arm
 *   func_0200B400 0x0200B400 thumb
 *   func_0220B008 0x0220B008 thumb ov187
 *   func_0220B0F8 0x0220B0F8 thumb ov187
 *   d_0220B2A0 0x0220B2A0 data a4
 */
#include "../include/Obj24881.h"
extern void func_0203064C(unsigned, unsigned, unsigned);
struct Obj0203159C;
extern void *func_0203159C(struct Obj0203159C *obj, unsigned int size, unsigned int heap);
extern void *func_02082BCC(void *, int, unsigned);
extern void func_0200B400(unsigned);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct S;
extern void func_0220B008(struct S *p, u32 a, u32 b, u32 c);
extern void func_0220B0F8(u8 *p, u32 v);
extern const char d_0220B2A0[];
int func_0220AF40(struct Obj0203159C *a, unsigned unused, unsigned mode)
{
    char *p;
    func_0203064C(1, 0x59, 0x12000);
    p = func_0203159C(a, 0x17f4, 0x59);
    func_02082BCC(p, 0, 0x17f4);
    ((struct Obj24881 *)p)->f17F0 = mode;
    func_0200B400(0x59);
    func_0220B008((struct S *)p, (unsigned)d_0220B2A0, (unsigned)p, 0x59);
    func_0220B0F8((u8 *)p, 0);
    return 1;
}
