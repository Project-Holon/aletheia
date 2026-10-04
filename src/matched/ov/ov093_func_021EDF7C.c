/*
 * function: func_021EDF7C
 * address:  0x021EDF7C
 * packet:   pkt_ov093_021EDF7C
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021B98AC  0x021B98AC  thumb  ov093
 *   func_021D59B4  0x021D59B4  thumb  ov093
 *   func_021D5440  0x021D5440  thumb  ov093
 *   func_021EDE54  0x021EDE54  thumb  ov093
 *   func_021F8AE8  0x021F8AE8  thumb  ov094
 */
#include "../include/Obj05234.h"
#include "../include/Obj21617.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u8 *func_021B98AC(char *const *q, u8 b);
extern int func_021D59B4(u8 *p, int k);
extern u8 func_021D5440(u8 *p);
extern void func_021EDE54(u8 *p);
extern void func_021F8AE8(int i, u32 v);

void func_021EDF7C(u8 *p, u8 b)
{
    u8 *r;
    u16 h;
    u8 t;

    r = (u8 *)func_021B98AC(*(char *const * *)&((struct Obj21617 *)(*(u8 * *)&((struct Obj05234 *)p)->f0))->f138, b);
    h = func_021D59B4(r, 0x10);
    t = func_021D5440(r);
    if (h != ((struct Obj05234 *)p)->f8 || t != p[0xc]) {
        p[0xc] = t;
        ((struct Obj05234 *)p)->f8 = h;
        func_021EDE54(p);
    }
    p[0xd] = 0;
    func_021F8AE8(b, h);
}
