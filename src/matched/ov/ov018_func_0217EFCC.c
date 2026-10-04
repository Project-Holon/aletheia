/*
 * function: func_0217EFCC
 * address: 0x0217EFCC
 * packet: pkt_ov018_0217EFCC
 * region: ov018
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: two zero padding bytes at 0x0217F006.
 * lever: assign the shifted mask before the flag; its flag store schedules
 * ahead of the shift while retaining separate constant-one registers.
 * symbols:
 *   func_020120F4 0x020120F4 thumb
 *   func_02012B58 0x02012B58 thumb
 *   func_0217F008 0x0217F008 thumb ov018
 */
#include "../include/Obj00399.h"
typedef unsigned char u8;
typedef struct { u8 a, b, c, d; int e, f; } State;
struct BigObj;
struct Ctx;
extern void *func_020120F4(const struct Ctx *p);
extern u8 func_02012B58(const struct BigObj *p);
extern void func_0217F008(char *, char *);
void func_0217EFCC(char *p, char *q)
{
    State *s;
    void *h;
    s = (State *)(p + 0xd8);
    h = func_020120F4(((struct Obj00399 *)p)->f0);
    if (q == 0) {
        s->a = func_02012B58(h);
        s->b = 1 << s->a;
        s->c = 1;
        s->d = 0;
        s->e = 0;
        s->f = 0;
    } else {
        func_0217F008(p, q);
    }
}
