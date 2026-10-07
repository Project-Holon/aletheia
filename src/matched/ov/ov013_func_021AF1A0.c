/*
 * function: func_021AF1A0
 * address:  0x021AF1A0
 * packet:   pkt_ov013_021AF1A0
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   d_021B3C80     0x021B3C80  data  ov013
 *   func_0202EB0C  0x0202EB0C  thumb
 *   func_0208B480  0x0208B480  arm
 *   func_0208B528  0x0208B528  arm
 *   func_02073AB4  0x02073AB4  arm
 *   func_02073898  0x02073898  arm
 *   func_021B3844  0x021B3844  arm  ov013
 *   func_0208BEF0  0x0208BEF0  arm
 *   func_02156FDC  0x02156FDC  thumb  ov009
 */

#include "../include/G_Work.h"

typedef unsigned char u8;

typedef struct Work Work;

extern struct Work *d_021B3C80;
typedef unsigned int   u32;
extern u32 func_0202EB0C(void);
extern int func_0208B480(void);
extern int func_0208B528(void);
extern void func_02073AB4(void *p);
struct X;
extern void func_02073898(struct X *x);
extern void func_021B3844(void);
extern unsigned int func_0208BEF0(unsigned int status);
extern void func_02156FDC(u32 a, void *p, int b);

void func_021AF1A0(void)
{
    void (*cb)(void);

    if (d_021B3C80 == 0) {
        return;
    }
    cb = d_021B3C80->f1984;
    if (func_0202EB0C() == 0) {
        func_0208B480();
    } else {
        func_0208B528();
    }
    func_02073AB4(d_021B3C80->f19B8);
    func_02073898((struct X *)d_021B3C80->f19B8);
    func_021B3844();
    func_0208BEF0(0);
    func_02156FDC(0, d_021B3C80->f880, 0);
    func_02156FDC(0, d_021B3C80, 0);
    d_021B3C80 = 0;
    if (cb) {
        cb();
    }
}
