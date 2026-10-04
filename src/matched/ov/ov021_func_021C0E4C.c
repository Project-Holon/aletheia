/*
 * function: func_021C0E4C
 * address:  0x021C0E4C
 * packet:   pkt_ov021_021C0E4C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021A5728  0x021A5728  thumb  ov021
 *   func_021A3990  0x021A3990  thumb  ov021
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02082BCC  0x02082BCC  arm
 *   func_021A3960  0x021A3960  thumb  ov021
 *   func_021C0E98  0x021C0E98  thumb  ov021
 * Addresses are Black-image addresses.
 */
#include "../include/Obj06070.h"

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Desc;
extern u32 func_021A5728(u8 *p);
extern u32 func_021A3990(u8 *p);
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
struct Obj;
extern void *func_020124E8(struct Obj *p);
extern void func_02082BCC(void *p, int v, int n);
extern void *func_021A3960(unsigned char *p);
extern int func_021C0E98(u32 unused, int *st, u8 *p);

void *func_021C0E4C(u32 a, u16 b, u32 c, u32 d)
{
    u32 t;
    void *task;
    u32 *w;

    t = func_021A5728((u8 *)a);
    task = func_020122C0((void *)func_021A3990((u8 *)t), 0, func_021C0E98, 0x24);
    w = func_020124E8(task);
    func_02082BCC(w, 0, 0x24);
    w[0] = a;
    ((struct Obj06070 *)w)->f4 = b;
    ((struct Obj06070 *)w)->f6 = d;
    w[7] = c;
    w[8] = (u32)func_021A3960((void *)t);
    return task;
}
