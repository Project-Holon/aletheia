/*
 * function: func_0219E00C
 * address:  0x0219E00C
 * packet:   pkt_ov021_0219E00C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_0216D6BC  0x0216D6BC  thumb  ov010
 *   func_02163F10  0x02163F10  thumb  ov010
 *   func_0219E370  0x0219E370  thumb  ov021
 *   func_0219E6C8  0x0219E6C8  thumb  ov021
 *   func_0216D568  0x0216D568  thumb  ov010
 *   func_0216D60C  0x0216D60C  thumb  ov010
 *   func_0216D674  0x0216D674  thumb  ov010
 *   func_0216D7CC  0x0216D7CC  thumb  ov010
 *   func_020061E4  0x020061E4  thumb
 * Addresses are Black-image addresses.
 */
#include "../include/Obj05013.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

typedef struct {
    u16 a;
    u16 b;
    s16 c;
    u16 d;
    u16 e;
    u16 f;
} S;

extern u8 *func_0216D6BC();
extern void func_02163F10();
extern void func_0219E370(u32, u16, u32);
extern void func_0219E6C8(u32, u16);
extern void func_0216D568(void *p, u32 v);
extern void func_0216D60C(u32, u16);
extern void func_0216D674(void *p, u16 v);
extern void func_0216D7CC(u8 *p);
extern void func_020061E4(u32 a);

void func_0219E00C(u32 o, u32 id, u32 p, u8 q, S s, u32 fn)
{
    u8 *e;

    e = func_0216D6BC(o, 0x10);
    e[0xc] = id;
    ((struct Obj05013 *)e)->f0 = p;
    e[0xd] = q;
    e[0xe] = s.a;
    e[0xf] = s.c;
    ((struct Obj05013 *)e)->f8 = s.e;
    if (p == 0) {
        func_02163F10(o);
    } else {
        func_0219E370(o, id, 8);
        func_0219E6C8(o, id);
    }
    func_0216D568((void *)o, 0xa0);
    func_0216D60C(o, id);
    func_0216D674((void *)o, s.a);
    func_0216D7CC((u8 *)o);
    if (fn) {
        func_020061E4(fn);
    }
}
