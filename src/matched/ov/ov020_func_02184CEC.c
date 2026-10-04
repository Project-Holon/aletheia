/*
 * function: func_02184CEC
 * address:  0x02184CEC
 * packet:   pkt_ov020_02184CEC
 * region:   ov020
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02012984  0x02012984  thumb
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02188CE8  0x02188CE8  thumb  ov021
 *   func_021AAAF0  0x021AAAF0  thumb  ov021
 */
#include "../include/Obj00248.h"

typedef unsigned short u16;

typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Ctx;
void *func_020120F4(const struct Ctx *p);
void *func_0201210C(const struct Ctx *p);
u8 func_02012984(const struct BigObj *p);
u16 func_02188C9C(u8 *p);
u32 func_02188CE8(u8 *p);
void func_021AAAF0(int x, int y);

void func_02184CEC(void **o, void *p)
{
    void *a = func_020120F4(p);
    void *b = func_0201210C(p);
    u16 c = func_02012984(a);

    o[0] = p;
    o[1] = a;
    o[2] = b;
    ((struct Obj00248 *)o)->fC = func_02188C9C(b);
    ((struct Obj00248 *)o)->f40 = 0;
    ((struct Obj00248 *)o)->f44 = 0;
    ((struct Obj00248 *)o)->f48 = c;
    ((struct Obj00248 *)o)->f4A = c;
    func_021AAAF0(func_02188CE8(o[2]), 1);
}
