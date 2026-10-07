/*
 * file:     unit_021AEB20_p04.c
 * unit:     yes
 * function: func_021AF18C, func_021AF1A0, func_021AF210, func_021AF238, func_021AF2AC
 * address:  0x021AF18C
 * region:   ov013
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
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
 *   func_021B3064 0x021B3064 arm ov013
 *   func_021B21A4  0x021B21A4  arm  ov013
 *   func_021B2254  0x021B2254  arm  ov013
 */
#include "../../matched/include/G_Work.h"

struct X;
typedef unsigned char u8;

typedef unsigned int u32;

typedef struct Work Work;

extern u32 func_0202EB0C(void);
extern int func_0208B480(void);
extern int func_0208B528(void);
extern void func_02073AB4(void *p);
extern void func_02073898(struct X *x);
extern void func_021B3844(void);
extern unsigned int func_0208BEF0(unsigned int status);
extern void func_02156FDC(u32 a, void *p, int b);
extern void func_021B3064(void *);
extern int func_021B21A4(u8 i);
extern int func_021B2254(int a);
void func_021AF18C(void (*cb)(void));
void func_021AF1A0(void);
int func_021AF210(void);
int func_021AF238(u32 mask, int n);
int func_021AF2AC(int n);
extern struct Work *d_021B3C80;


void func_021AF18C(void (*cb)(void))
{
    *(void (**)(void))(((u8 *)d_021B3C80) + 0x1984) = cb;
}


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

int func_021AF210(void)
{
    int a[4];
    if (d_021B3C80 != 0) {
        func_021B3064(a);
        if (a[1] > 2) return a[0];
    }
    return 0;
}


int func_021AF238(u32 mask, int n)
{
    int i;

    if (d_021B3C80 == 0 || d_021B3C80->f19A8 != 3) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (i == n) {
            continue;
        }
        if (!(mask & (1 << i))) {
            continue;
        }
        if (d_021B3C80->a[i] == 1) {
            continue;
        }
        if (func_021B21A4(i)) {
            return 0;
        }
        d_021B3C80->a[i] = 1;
    }
    return 1;
}


int func_021AF2AC(int n)
{
    int i;

    if (d_021B3C80 == 0 || d_021B3C80->f19A8 != 3) {
        return 0;
    }
    for (i = 0; i < 2; i++) {
        if (i == n) {
            continue;
        }
        if (d_021B3C80->a[i] != 1) {
            continue;
        }
        if (func_021B2254((u8)i)) {
            return 0;
        }
        d_021B3C80->a[i] = 0;
    }
    return 1;
}
