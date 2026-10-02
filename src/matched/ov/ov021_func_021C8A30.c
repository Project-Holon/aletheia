/*
 * function: func_021C8A30
 * address:  0x021C8A30
 * packet:   pkt_ov021_021C8A30
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Creates task func_021C89BC with a 0x1C byte work area and fills it from the
 * owner object.
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188CB4  0x02188CB4  thumb
 *   func_021A3074  0x021A3074  thumb
 *   func_0216D5F8  0x0216D5F8  thumb  ov010
 *   func_021C89BC  0x021C89BC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

struct Work8A30 {
    void *sys;
    u8 *owner;
    u8 *f8;
    void *fC;
    u32 f10;
    u16 f14;
    u16 pad16;
    u32 f18;
};

typedef int (*TaskFn)(void *task, int *state, void *work);

extern void *func_020122C0(void *a, u32 b, TaskFn fn, u32 size);
extern struct Work8A30 *func_020124E8(void *task);
extern void *func_02188CB4(u8 *p);
extern void *func_021A3074(unsigned char *p);
extern u16 func_0216D5F8(void *p);
extern int func_021C89BC(void *task, int *state, void *work);

void *func_021C8A30(u32 prio, void *sys, u8 *owner)
{
    void *task = func_020122C0(sys, prio, func_021C89BC, 0x1C);
    struct Work8A30 *w = func_020124E8(task);

    w->sys = sys;
    w->owner = owner;
    w->f8 = func_02188CB4(owner);
    w->fC = func_021A3074(w->f8);
    w->f10 = 0;
    w->f14 = func_0216D5F8(w->fC);
    w->f18 = 0;
    return task;
}
