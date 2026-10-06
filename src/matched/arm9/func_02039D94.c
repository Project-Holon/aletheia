/*
 * function: func_02039D94
 * address:  0x02039D94
 * packet:   pkt_02039D94
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D4     0x021469D4  data
 *   file_020A7A68  0x020A7A68  data
 *   msg_020A7A94   0x020A7A94  data
 *   func_020395E0  0x020395E0  arm
 *   func_020395EC  0x020395EC  arm
 *   func_0203996C  0x0203996C  arm
 *   func_02039160  0x02039160  arm
 *   func_020399B8  0x020399B8  arm
 *   func_02039A5C  0x02039A5C  arm
 *   func_02039338  0x02039338  arm
 *   func_020399A8  0x020399A8  arm
 *   func_02039CD8  0x02039CD8  arm
 *   func_0203A2F0  0x0203A2F0  arm
 *   func_0203A28C  0x0203A28C  arm
 *   func_0203D378  0x0203D378  arm
 *   func_0203D394  0x0203D394  arm
 *   func_0203D4D0  0x0203D4D0  arm
 *   func_0203D3A8  0x0203D3A8  arm
 *   func_0203D650  0x0203D650  arm
 *   func_0203D798  0x0203D798  arm
 *   func_02034714  0x02034714  arm
 *
 * The net_handle.c tick (docs/families/net_handle.h).  Closed from the
 * 652-byte / 14-out source of docs/notes/pkt_02039D94.c.txt with two
 * changes:
 *   1. The two owner callbacks at g+0x14 / g+0x10 each TAKE func_0203D650's
 *      result as their argument: `a = g->get_a(func_0203D650())`.  That is
 *      why the image calls through r1 (`ldr r1, [r4, #0x14]; blx r1`):
 *      r0 is holding the argument.  Called with no argument the compile
 *      goes through r0 (4 bytes out).
 *   2. Phases 2 and 4 reuse the entry pointer `e` for the own entry
 *      (func_0203996C(0xff)); there is no separate `own` local.  With a
 *      separate local the own pointer and the loop index swap sb/sl in
 *      phase 2 (or r6/r7 in phase 4).
 */
#include "../include/Obj04750.h"
#include "../include/Obj08835.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern int func_020395E0(int slot);
typedef signed int     s32;
struct Entry;
struct NetEntry;
struct Obj;
extern int func_020395EC(struct Entry *a);
extern struct Entry *func_0203996C(s32 idx);
extern u32 func_02039160(u16 mode);
extern u32 func_020399B8(u8 *e);
extern void func_02039A5C(void);
extern u16 func_02039338(void);
struct Entry;
extern struct Entry *func_020399A8(void);
extern int func_02039CD8(struct Obj *p);
extern u32 func_0203A2F0(u32 a0, u32 a1);
extern u16 func_0203A28C(u16 mask, u32 idx, u32 set);
extern u32 func_0203D378(void);
extern u32 func_0203D394(struct NetEntry *e);
extern u32 func_0203D4D0(u8 *e, u32 a, u32 b, u32 c, void *d, u32 e2, u32 f, u32 g2);
extern int func_0203D3A8(struct Entry *a, u32 b, u32 c, u32 d);
extern u32 func_0203D650(void);
extern void *func_0203D798(void);
extern void func_02034714(const char *file, u32 line, const char *msg);

extern u8 *g_021469D4;
extern const char file_020A7A68[];
extern const char msg_020A7A94[];

void func_02039D94(void)
{
    u8 *e;
    u8 *g;
    int i;

    for (i = 0; i < 8; i++) {
        u32 s = func_020395E0(i);
        e = (u8 *)func_0203996C(s);
        if (func_02039160((u16)s) == 0)
            func_020399B8(e);
    }

    func_02039A5C();

    if (func_0203D378() != 0) {
        e = (u8 *)func_0203996C(0xff);
        for (i = 0; i < 9; i++) {
            u8 *r = g_021469D4 + i;
            if (r[0x18] != 1)
                continue;
            if (func_0203D4D0(e, r[0x10], 8, 2,
                              g_021469D4 + i * 2, 0, 0, 0) == 0)
                continue;
            if ((g_021469D4 + i)[0x10] == 0)
                func_02034714(file_020A7A68, 0x29a, msg_020A7A94);
            (g_021469D4 + i)[0x18] = 0;
        }
    }

    for (i = 0; i < 9; i++) {
        u8 *p;
        p = (u8 *)func_0203996C(func_020395E0(i));
        if (func_0203D394((struct NetEntry *)p) == 0)
            continue;
        if (p[0x49] == 0)
            continue;
        if (func_020395EC((struct Entry *)p) == 0xff)
            continue;
        if (func_0203D3A8((struct Entry *)p, (u16)7, (u16)4, (u32)(p + 0x46)) != 0)
            p[0x49] = 0;
    }

    if (func_02039338() == 0) {
        e = (u8 *)func_0203996C(0xff);
        if (e != 0) {
            for (i = 0; i < 8; i++) {
                u8 *s = *(u8 **)(e + i * 4 + 8);
                if (s == 0 || s[0xd] == 0)
                    continue;
                if (func_0203A2F0(((struct Obj04750 *)e)->f40, i) != 0)
                    continue;
                if (func_02039CD8((struct Obj *)e) != 0)
                    ((struct Obj04750 *)e)->f40 =
                        func_0203A28C(((struct Obj04750 *)e)->f40, i, 1);
            }
        }
    }

    g = func_0203D798();
    if (g[0x65] == 4)
        return;

    e = (u8 *)func_020399A8();
    if (e[0x4e] != 1)
        return;

    if (((struct Obj08835 *)g)->f10 != 0 && ((struct Obj08835 *)g)->f14 != 0) {
        u32 a;
        u32 b;
        a = (*(u32 (**)(u32))(g + 0x14))(func_0203D650());
        b = (*(u32 (**)(u32))(g + 0x10))(func_0203D650());
        if (func_0203D3A8((struct Entry *)e, (u16)0xa, (u16)a, (u32)((void *)b)) != 0)
            e[0x4e] = 0;
    } else {
        e[0x4e] = 0;
    }
}

