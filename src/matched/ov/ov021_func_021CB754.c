/*
 * function: func_021CB754
 * address:  0x021CB754
 * packet:   pkt_ov021_021CB754
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02158F58  0x02158F58  thumb  ov010
 *   func_02158F54  0x02158F54  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0201296C  0x0201296C  thumb
 *   func_02012ED8  0x02012ED8  thumb
 *   func_020071CC  0x020071CC  thumb
 *   func_0200D884  0x0200D884  thumb
 *   func_021CD688  0x021CD688  thumb  ov021
 *   func_021CD5A4  0x021CD5A4  thumb  ov021
 */
#include "../include/Obj05095.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_0215A5F4(void *p);
extern int func_02158F58(int a0);
extern void *func_02158F54(void *a);
struct Big;
struct BigObj;
struct Blk3C;
struct Ctx;
struct Sub020071CCCtrl;
extern void *func_020120F4(const struct Ctx *p);
extern void *func_02012EBC(struct Big *p);
extern u32 func_0201296C(const struct BigObj *p);
extern void *func_02012ED8(struct Big *p);
extern void *func_020071CC(struct Sub020071CCCtrl *ctrl, u32 id);
extern u32 func_0200D884(struct Blk3C *p, u32 id, void *out);
extern u32 func_021CD688(u8 *p);
extern u32 func_021CD5A4(u32 *p);

int func_021CB754(u32 unused, u32 a)
{
    void *s, *h;
    void *t;
    u8 *p;
    int r;
    u32 z;

    t = func_0215A5F4((void *)a);
    func_02158F58((int)t);
    s = func_020120F4(func_02158F54(t));
    h = func_02012EBC(s);
    func_0201296C(s);
    p = func_02012ED8(s);
    z = 0;
    func_0200D884(func_020071CC(h, 0x39), 0, 0);
    func_020071CC(h, 0x3A);
    r = func_021CD688((u8 *)(((struct Obj05095 *)p)->f71C));
    if (r != 0) {
        func_021CD5A4((u32 *)(((struct Obj05095 *)p)->f71C));
        ((struct Obj05095 *)p)->f71C = z;
        switch (r) {
        case 1:
            **(u16 * *)&((struct Obj05095 *)p)->f720 = z;
            return 1;
        case 2:
            **(u16 * *)&((struct Obj05095 *)p)->f720 = 1;
            return 1;
        case 4:
        default:
            **(u16 * *)&((struct Obj05095 *)p)->f720 = 2;
            return 1;
        }
    }
    return z;
}
