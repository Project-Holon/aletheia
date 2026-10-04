/*
 * function: func_02169928
 * address:  0x02169928
 * packet:   pkt_ov010_02169928
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02046F48  0x02046F48  arm
 *   func_0206E954  0x0206E954  arm
 *   func_0206E964  0x0206E964  arm
 *   func_0206A2CC  0x0206A2CC  arm
 *   func_0206A4AC  0x0206A4AC  arm
 *   func_02069D14  0x02069D14  arm
 */
#include "../include/Obj12388.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Tagged;
extern void *func_02046F48(struct Tagged *p);
extern u8 *func_0206E954(void *p);
extern unsigned char *func_0206E964(unsigned char *p);
extern void func_0206A2CC(void *a, void *b);
extern void func_0206A4AC(void *a, void *b);
extern void func_02069D14(void *a, void *b);

static inline u32 *Get(u8 *r, u32 idx)
{
    u8 *h;

    h = r + 8;
    if (h != 0 && idx < r[9])
        return (u32 *)(h + ((struct Obj12388 *)r)->fE + 4 + idx * 4);
    return 0;
}

void func_02169928(void *a, void *b, void *c)
{
    u8 *r;
    u32 *q;
    u8 *res;
    void *m;
    void *y;

    res = func_02046F48(b);
    y = func_02046F48(c);
    m = 0;
    r = func_0206E954(res);
    if (r != 0 && (q = Get(r, 0)) != 0)
        res = r + *q;
    else
        res = 0;
    if (y != 0)
        m = func_0206E964(y);
    if (m != 0) {
        func_0206A2CC(res, m);
        func_0206A4AC(res, m);
    }
    func_02069D14(a, res);
}
