/*
 * function: func_021C8C88
 * address:  0x021C8C88
 * packet:   pkt_ov021_021C8C88
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates task func_021C8BFC with a 0x28 byte work area, fills it from the
 * owner, and loads three resources (0x55E, 0x6E2, 0x769) through
 * func_02006148.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_02006148  0x02006148  thumb
 *   func_021C8BFC  0x021C8BFC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Work8C88 {
    void *sys;
    u8 *owner;
    u8 *f8;
    void *fC;
    u32 f10;
    u32 f14;
    u32 f18;
    int f1C;
    int f20;
    int f24;
};

typedef int (*TaskFn)(void *task, int *state, void *work);

extern void *func_020122C0(void *a, u32 b, TaskFn fn, u32 size);
extern struct Work8C88 *func_020124E8(void *task);
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(unsigned char *p);
extern int func_02006148(u32 a0);
extern int func_021C8BFC(void *task, int *state, void *work);

void *func_021C8C88(u32 prio, void *sys, u8 *owner)
{
    void *v = func_02188CB4(owner);
    void *task = func_020122C0(sys, prio, func_021C8BFC, 0x28);
    struct Work8C88 *w = func_020124E8(task);

    w->sys = sys;
    w->owner = owner;
    w->f8 = (u8 *)v;
    w->fC = func_021A3074(w->f8);
    w->f10 = 0;
    w->f14 = 0;
    w->f18 = 0;
    w->f1C = func_02006148(0x55E);
    w->f20 = func_02006148(0x6E2);
    w->f24 = func_02006148(0x769);
    return task;
}
