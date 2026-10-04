/*
 * function: func_021C3E3C
 * address: 0x021C3E3C
 * packet: pkt_ov136_021C3E3C
 * region: ov136
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * tail: 021C3E9A..021C3E9C zero alignment padding.
 * symbols:
 *   func_0203064C 0x0203064C arm
 *   func_0203159C 0x0203159C arm
 *   func_02082AC0 0x02082AC0 arm
 *   func_021C409C 0x021C409C thumb ov136
 *   func_02031324 0x02031324 arm
 */
#include "../include/Obj08196.h"
#include "../include/Obj08197.h"
#include "../include/Obj23488.h"
typedef unsigned char u8;
typedef unsigned short u16;
extern void func_0203064C(unsigned, unsigned, unsigned);
extern void *func_0203159C(void *, unsigned, unsigned);
extern void func_02082AC0(unsigned, void *, unsigned);
extern void *func_021C409C(void *, unsigned);
extern void *func_02031324(unsigned);
int func_021C3E3C(void *a, void *b, u8 *p)
{
    u8 *q;
    func_0203064C(1, 0x63, 0x1000);
    q = func_0203159C(a, 0x20, 0x63);
    func_02082AC0(0, q, 0x20);
    ((struct Obj08197 *)q)->f0 = 0x63;
    *(u8 * *)&((struct Obj08197 *)q)->f10 = func_021C409C(((struct Obj08196 *)p)->f14, 0x63);
    if (((struct Obj08196 *)p)->f0 == 1) (*(u8 **)(q + 0x10))[0xB] = p[0xF];
    if ((*(u8 **)(q + 0x10))[0xB] >= 0xC) (*(u8 **)(q + 0x10))[0xB] = 0;
    ((struct Obj23488 *)(*(u8 * *)&((struct Obj08197 *)q)->f10))->f0 = ((struct Obj08196 *)p)->f0;
    ((struct Obj08197 *)q)->f1C = func_02031324(0x63);
    return 1;
}
