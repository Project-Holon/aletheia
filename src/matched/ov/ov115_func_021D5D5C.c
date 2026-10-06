/*
 * function: func_021D5D5C
 * address: 0x021D5D5C
 * packet: pkt_ov115_021D5D5C
 * region: ov115
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * evidence: 5FE8 forwards the pointer returned by matched 0201FDA0;
 * this caller consumes that return. All six observed ov115 caller sites
 * (45F8,4630,46F4,47AE,488E,4926) set mode to literal0/1, so meaningful
 * Template fields are initialized on reachable case0. Complete original
 * contexts/reference search: B10/5D5C-interface-proof.txt; body unchanged.
 * symbols:
 *   func_020457B0 0x020457B0 arm
 *   func_02045CAC 0x02045CAC arm
 *   func_02027778 0x02027778 thumb
 *   func_02045808 0x02045808 arm
 *   func_0207D658 0x0207D658 arm
 *   func_02027CFC 0x02027CFC thumb
 *   func_021D5FE8 0x021D5FE8 thumb ov115
 */
#include "../include/Obj01535.h"
#include "../include/Obj05321.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct {
    u32 heap;
    u8 count, pad[3];
    const void *items;
    u32 param;
    u8 x, y, a, b;
} Template;
struct MsgBank;
struct U16Vec;
extern struct U16Vec *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045CAC(struct MsgBank *bank, u32 index, void *dest);
struct TaskMenu;
struct TaskMenuTmpl;
extern struct TaskMenu *func_02027778(struct TaskMenuTmpl *tmpl, void *arg1);
extern void func_02045808(struct U16Vec *vec);
extern void func_0207D658(u32, int, int);
extern void func_02027CFC(u8 *, int);
extern void *func_021D5FE8(u8 *, int, int);
void *func_021D5D5C(u8 *p, int mode, int flag, int selected)
{
    u8 *q = p + 0x54;
    Template t;
    ((struct Obj01535 *)q)->f0 = ((struct Obj05321 *)p)->f50;
    switch (((struct Obj01535 *)q)->f0) {
    case 0:
        t.heap = ((struct Obj05321 *)p)->f4C;
        t.count = 2;
        t.items = q + 4;
        switch (mode) {
        case 0: t.x = 32; t.y = 13; t.param = 1; break;
        case 1: t.x = 32; t.y = 24; t.param = 1; break;
        }
        t.a = 13;
        t.b = 3;
        ((struct Obj01535 *)q)->f4 = func_020457B0(100, ((struct Obj05321 *)p)->f4C);
        func_02045CAC(((struct Obj05321 *)p)->f1C, 28, ((struct Obj01535 *)q)->f4);
        ((struct Obj01535 *)q)->f8 = 0x39e0;
        ((struct Obj01535 *)q)->f10 = func_020457B0(100, ((struct Obj05321 *)p)->f4C);
        func_02045CAC(((struct Obj05321 *)p)->f1C, 29, ((struct Obj01535 *)q)->f10);
        ((struct Obj01535 *)q)->f14 = 0x39e0;
        ((struct Obj01535 *)q)->f20 = func_02027778((struct TaskMenuTmpl *)(&t), ((struct Obj01535 *)q)->f1C);
        func_02045808(((struct Obj01535 *)q)->f4);
        func_02045808(((struct Obj01535 *)q)->f10);
        if (flag != 0) func_0207D658(0x04001050, 17, -8);
        func_02027CFC(*(u8 * *)&((struct Obj01535 *)q)->f20, selected);
        break;
    case 1:
        ((struct Obj01535 *)q)->f24 = func_021D5FE8(p, mode, selected);
        ((struct Obj01535 *)q)->f28 = -1;
        break;
    }
    return q;
}
