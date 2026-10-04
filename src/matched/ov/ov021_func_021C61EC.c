/*
 * function: func_021C61EC
 * address:  0x021C61EC
 * packet:   pkt_ov021_021C61EC
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   func_02188E30  0x02188E30  thumb  ov021
 *   func_02012374  0x02012374  thumb
 *   func_021C622C  0x021C622C  thumb  ov021
 */
#include "../include/Obj06083.h"

typedef unsigned char u8;

typedef unsigned int   u32;
struct Desc;
struct Evt;
struct Obj;
extern struct Desc *func_020122C0(void *owner, void *a, void *b, u32 size);
extern void *func_020124E8(struct Obj *p);
extern u32 func_02188E30(u8 *p);
extern void func_02012374(struct Evt *evt, struct Evt **out);
extern void func_021C622C(void);

void func_021C61EC(void *a, void *b, void *c)
{
    void *task;
    u8 *w;

    task = func_020122C0(b, 0, func_021C622C, 8);
    w = func_020124E8(task);
    w[0] = 3;
    w[1] = 0;
    w[2] = 2;
    w[3] = 0;
    ((struct Obj06083 *)w)->f4 = func_02188E30(c);
    func_02012374(a, task);
}
