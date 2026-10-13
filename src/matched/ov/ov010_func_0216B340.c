/*
 * function: func_0216B340
 * address:  0x0216B340
 * packet:   pkt_ov010_0216B340
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020120F4  0x020120F4  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_02012138  0x02012138  thumb
 *   INTRUDE_COMM_GetPartnerSlot  0x021767A0  thumb  ov011
 *   func_0216B3EC  0x0216B3EC  thumb  ov010
 */
#include "../include/Obj05904.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Ctx;
struct Desc;
typedef struct { int a, b, c; } V12;

extern void *func_020120F4(const struct Ctx *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
struct Work;
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC();
extern unsigned int func_02012138(const struct Ctx *p);
extern u8 INTRUDE_COMM_GetPartnerSlot(void *a, void *b);
extern int func_0216B3EC(void *evt, u32 *state, struct Work *w);

struct Desc *func_0216B340(int a0, int a1, V12 *a2, int a3, int a4)
{
    void *h;
    struct Desc *r;
    u8 *p;

    h = func_020120F4((const struct Ctx *)a0);
    r = func_020122C0((void *)a0, 0, (void *)func_0216B3EC, 0x24);
    p = func_020124E8((struct Obj *)r);
    func_02082BCC(p, 0, 0x24);
    *(V12 *)(p + 8) = *a2;
    ((struct Obj05904 *)p)->f14 = a3;
    ((struct Obj05904 *)p)->f0 = 0;
    p[0x16] = a4;
    ((struct Obj05904 *)p)->f1C = a1;
    if (INTRUDE_COMM_GetPartnerSlot((void *)((int)func_02012138((const struct Ctx *)a0)), h) == 4)
        ((struct Obj05904 *)p)->f20 = 1;
    return r;
}
