/*
 * function: sub_02010A5C
 * address:  0x02010A5C
 * packet:   pkt_02010A5C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0203064C  0x0203064C  arm
 *   func_0203159C  0x0203159C  arm
 *   func_02082BCC  0x02082BCC  arm
 *   sub_020124F4   0x020124F4  thumb
 *   sub_02012EBC   0x02012EBC  thumb
 *   sub_02009448   0x02009448  thumb
 *   sub_020092EC   0x020092EC  thumb
 */
#include "../include/Obj04833.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void  func_0203064C(u32 a, u32 b, u32 c);
extern u8   *func_0203159C(void *a, int b, int c);
extern void  func_02082BCC(void *dst, int val, unsigned n);
extern void *sub_020124F4(u16 heap);
struct Big;
struct Sub02009448Obj;
extern void *sub_02012EBC(struct Big *p);
extern struct Sub02009448Obj *sub_02009448(void *sys);
struct Sub02009210Obj;
extern u8 sub_020092EC(const struct Sub02009210Obj *obj);

int sub_02010A5C(void *a0)
{
    u8 *p;
    void *sys;

    func_0203064C(1, 0x67, 0x78000);
    p = func_0203159C(a0, 0x1d8, 0x67);
    func_02082BCC(p, 0, 0x1d8);
    ((struct Obj04833 *)p)->f1D0 = 0x67;
    sys = sub_020124F4(0x67);
    ((struct Obj04833 *)p)->f44 = sys;
    if (sub_020092EC((const struct Sub02009210Obj *)sub_02009448(sub_02012EBC(sys))) != 0) {
        ((struct Obj04833 *)p)->f1D4 = 1;
        ((struct Obj04833 *)p)->f54 = 1;
    } else {
        ((struct Obj04833 *)p)->f1D4 = 0;
        ((struct Obj04833 *)p)->f54 = 0;
    }
    return 1;
}
