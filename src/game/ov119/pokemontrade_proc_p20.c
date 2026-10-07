/*
 * file:     pokemontrade_proc_p20.c
 * unit:     yes
 * function: func_021DCC38, func_021DCC78, func_021DCCB8, func_021DCCF8
 * address:  0x021DCC38
 * region:   ov119
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021DC854 0x021DC854 thumb ov119
 *   func_021DC894 0x021DC894 thumb ov119
 *   func_021DCBA4 0x021DCBA4 thumb ov119
 *   func_021D8E84 0x021D8E84 thumb ov119
 *   func_021D4B88 0x021D4B88 thumb ov117
 *   func_021D59B0 0x021D59B0 thumb ov118
 *   func_021D6F2C 0x021D6F2C thumb ov118
 *   func_021D4AB4 0x021D4AB4 thumb ov118
 */
#include "../../matched/include/Obj01728.h"

extern void *func_021DC854(void *, int);
extern int func_021DC894(int a, int b, char *q, char *p, int n);
extern void func_021DCBA4(char *a, char *p);
extern void func_021D8E84(void *, int);
extern void func_021D4B88(unsigned char *);
extern void func_021D59B0(unsigned char *);
extern void func_021D6F2C(unsigned char *);
extern void func_021D4AB4(unsigned char *);
int func_021DCC38(void *a, int b, char *c);
int func_021DCC78(void *a, int b, char *c);
int func_021DCCB8(void *a, int b, char *c);
int func_021DCCF8(void *a, int b, char *c);

int func_021DCC38(void *a, int b, char *c)
{
    void *p;
    int r;
    p = func_021DC854(a, 0xc6000);
    ((struct Obj01728 *)c)->f14 = ((struct Obj01728 *)c)->f30;
    r = func_021DC894((int)a, b, c, p, 4);
    func_021DCBA4(c, p);
    func_021D8E84(p, (int)func_021D4B88);
    return r;
}

int func_021DCC78(void *a, int b, char *c)
{
    void *p;
    int r;
    p = func_021DC854(a, 0x96000);
    ((struct Obj01728 *)c)->f14 = ((struct Obj01728 *)c)->f30;
    r = func_021DC894((int)a, b, c, p, 7);
    func_021DCBA4(c, p);
    func_021D8E84(p, (int)func_021D59B0);
    return r;
}

int func_021DCCB8(void *a, int b, char *c)
{
    void *p;
    int r;
    p = func_021DC854(a, 0x96000);
    ((struct Obj01728 *)c)->f14 = ((struct Obj01728 *)c)->f30;
    r = func_021DC894((int)a, b, c, p, 8);
    func_021DCBA4(c, p);
    func_021D8E84(p, (int)func_021D6F2C);
    return r;
}

int func_021DCCF8(void *a, int b, char *c)
{
    void *p;
    int r;
    p = func_021DC854(a, 0x96000);
    ((struct Obj01728 *)c)->f14 = ((struct Obj01728 *)c)->f30;
    r = func_021DC894((int)a, b, c, p, 6);
    func_021DCBA4(c, p);
    func_021D8E84(p, (int)func_021D4AB4);
    return r;
}
