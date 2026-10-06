/*
 * function: func_0217BCDC
 * address:  0x0217BCDC
 * packet:   pkt_ov018_0217BCDC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_02012114  0x02012114  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02012B58  0x02012B58  thumb
 *   func_02175598  0x02175598  thumb  ov011
 *   func_0201210C  0x0201210C  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A3220  0x021A3220  thumb  ov021
 *   func_021A3074  0x021A3074  thumb  ov021
 *   func_0216D8C0  0x0216D8C0  thumb  ov010
 *   func_021A322C  0x021A322C  thumb  ov021
 */
#include "../include/Obj09388.h"

typedef unsigned char u8;
typedef unsigned short u16;

typedef struct { u16 f : 3; u16 g : 13; } Fh;
typedef struct { u8 lo : 4; u8 b4 : 1; u8 hi : 3; } Fb;
typedef struct { int x, y, z; } Vec;

struct BigObj;
struct Ctx;
struct Sub0200852CObj;
extern void *func_020120F4(const struct Ctx *p);
typedef unsigned int   u32;
struct Ctx;
extern u32 func_02012114(const struct Ctx *p);
extern u8 *func_02012944(void *p);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u8 func_02012B58(const struct BigObj *p);
extern u16 func_02175598(u8 *o, u32 id);
extern void *func_0201210C(const struct Ctx *p);
struct Obj00020;
extern void *func_02188CB4(struct Obj00020 *p);
extern void func_021A3220(u8 *p, u32 res);
extern void *func_021A3074(unsigned char *p);
extern void func_0216D8C0(void *, Vec *);
extern void func_021A322C(u8 *p);

void func_0217BCDC(u8 *p, void *a1, int id, u8 kind, u8 flag)
{
    int res;
    void *obj;
    int has;
    int x;
    int y = (int)func_020120F4(a1);
    Vec v = { 0, 0, 0 };

    if (func_02012114(a1) == 0)
        return;
    x = (int)func_02012944(func_020120F4(a1));
    has = func_02008550((const struct Sub0200852CObj *)x);
    if (p != 0) {
        if (id == 0xFFFF) {
            if (((Fh *)(p + 0x86))->f == func_02012B58((const struct BigObj *)y))
                id = 0;
        }
        if (id == 0) {
            kind = has == 0 ? 3 : 4;
            flag = has;
        }
        if (((struct Obj09388 *)p)->f88 == id)
            return;
        ((struct Obj09388 *)p)->f88 = id;
        ((Fb *)(p + 0x8A))->lo = kind;
        ((Fb *)(p + 0x8A))->b4 = flag;
        p[0x900] = 1;
        res = func_02175598(p + 0x70, x);
    } else {
        id = 0;
        res = 1;
        if (has)
            res = 4;
    }
    obj = func_02188CB4(func_0201210C(a1));
    func_021A3220(obj, (u16)res);
    func_0216D8C0(func_021A3074(obj), &v);
    if (id == 0)
        func_021A322C(obj);
}
