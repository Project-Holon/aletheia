/*
 * function: func_021B7740
 * address: 0x021B7740
 * packet: pkt_ov172_021B7740
 * region: ov172
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * Trailing 0x021B77B2..021B77B4 is two-byte alignment padding.
 * symbols:
 *   func_021BDFE4 0x021BDFE4 thumb ov172
 *   func_021BE100 0x021BE100 thumb ov172
 *   func_021BE0A4 0x021BE0A4 thumb ov172
 *   func_021B8BA4 0x021B8BA4 thumb ov172
 *   func_021B796C 0x021B796C thumb ov172
 */
#include "../include/Obj00415.h"
typedef unsigned char u8;
extern unsigned int func_021BDFE4(void *);
extern int func_021BE100(void);
extern u8 func_021BE0A4(void *);
extern unsigned int func_021B8BA4(int, char *, int);
extern void func_021B796C(void *, char *, int);
void func_021B7740(void *p, char *q, int a, int b)
{
    char *base;
    u8 i;
    base = (char *)func_021BDFE4(p);
    ((struct Obj00415 *)q)->f14 = 1;
    if (((struct Obj00415 *)q)->f18 == 0) ((struct Obj00415 *)q)->f18 = a;
    if (((struct Obj00415 *)q)->f1C == 0) ((struct Obj00415 *)q)->f1C = b;
    ((struct Obj00415 *)q)->f10 = 0;
    ((struct Obj00415 *)q)->f2C = 0;
    if (func_021BE100() == 0)
        ((struct Obj00415 *)q)->f10 |= (u8)(1 << func_021BE0A4(p));
    for (i = 0; i < 4; i++) {
        if (func_021B8BA4((int)p, base, i) == 1)
            func_021B796C(p, q, i);
    }
}
