/*
 * function: func_0216711C
 * address: 0x0216711C
 * packet: pkt_ov010_0216711C
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two zero alignment bytes at 0x02167152 precede the next function.
 * symbols:
 *   func_02082BCC 0x02082BCC arm
 *   func_02188C84 0x02188C84 thumb ov021
 *   func_02188C54 0x02188C54 thumb ov021
 */
#include "../include/Obj05899.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ctx;
extern void *func_0201210C(const struct Ctx *p);
extern void *func_020120F4(const struct Ctx *p);
extern void func_02082BCC(void *, int, int);
extern u16 func_02188C84(u8 *p);
extern u32 func_02188C54(u8 *p);
void func_0216711C(u8 *p, void *sys) {
    void *field;
    field = func_0201210C(sys);
    func_02082BCC(p, 0, 32);
    ((struct Obj05899 *)p)->f0 = func_02188C84(field);
    ((struct Obj05899 *)p)->f4 = sys;
    ((struct Obj05899 *)p)->f8 = func_020120F4(sys);
    ((struct Obj05899 *)p)->fC = field;
    ((struct Obj05899 *)p)->f10 = func_02188C54(field);
}
