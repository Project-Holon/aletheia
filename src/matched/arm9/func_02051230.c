/*
 * function: func_02051230
 * address:  0x02051230
 * packet:   pkt_02051230
 * isa:      arm
 * status:   EXACT
 * note:     re-verified 2026-09-20: MATCH; see verify output
 * symbols:
 *   func_02046BFC  0x02046BFC  arm
 *   func_02046C10  0x02046C10  arm
 *   func_0206164C  0x0206164C  arm
 *   func_02061808  0x02061808  arm
 *   func_02052A50  0x02052A50  arm
 *   func_02051394  0x02051394  arm
 *   func_02030DA8  0x02030DA8  arm
 *   func_02051A3C  0x02051A3C  arm
 *   func_02051A54  0x02051A54  arm
 *   func_02051AA0  0x02051AA0  arm
 *   func_02051AB8  0x02051AB8  arm
 *   func_020513F8  0x020513F8  arm
 */
#include "../include/Obj02319.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed int     s32;

extern int func_02046BFC(void);
extern int func_02046C10(void);
extern void func_0206164C(u8 *p);
extern void func_02061808(u8 *p);
extern void func_02052A50(u32 a, u32 b);
extern void func_02051394(u8 *o);
extern void func_02030DA8(u32 a, u32 b, u8 *c, u32 d);

void func_02051230(u8 *o, u32 a1, u32 a2, u32 a3)
{
    u32 f;
    u32 v;
    u32 z;
    s32 i;

    z = 0;
    f = (func_02046BFC() == 1) ? 1 : 2;
    v = func_02046C10();
    if (v == 1)
        v = 4;
    else
        v = 8;
    f |= v;
    o[0x258] = (u8)f;
    if (f & 1) {
        func_0206164C(o + 0x58);
        ((struct Obj02319 *)o)->f18 = 0x02051A3C;
    } else if (f & 2) {
        for (i = 0; i < 0x40; i++)
            *(u32 *)(o + 0x58 + i * 4) = z;
        ((struct Obj02319 *)o)->f18 = 0x02051A54;
        *(u16 *)(o + 0x200 + 0x5c) = z;
    }
    if (f & 4) {
        func_02061808(o + 0x158);
        ((struct Obj02319 *)o)->f1C = 0x02051AA0;
    } else if (f & 8) {
        for (i = 0; i < 0x40; i++)
            *(u32 *)(o + 0x158 + i * 4) = z;
        ((struct Obj02319 *)o)->f1C = 0x02051AB8;
        *(u16 *)(o + 0x200 + 0x5e) = z;
    }
    v = ((struct Obj02319 *)o)->f0;
    ((struct Obj02319 *)o)->f4 = a1;
    func_02052A50(v, a1);
    if (a2 == 1) {
        func_02051394(o);
        return;
    }
    if (a3 == 0)
        return;
    func_02030DA8(a3, 0x020513F8, o, 0);
}
