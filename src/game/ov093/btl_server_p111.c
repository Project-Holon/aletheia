/*
 * file:     btl_server_p111.c
 * unit:     yes
 * function: func_021CB174, func_021CB1A4
 * address:  0x021CB174
 * region:   ov093
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_021B8C50 0x021B8C50 thumb ov093
 *   func_021B8E28 0x021B8E28 thumb ov093
 *   func_021BB85C 0x021BB85C thumb ov093
 *   func_021B9BF0 0x021B9BF0 thumb ov093
 *   func_021B8CB0 0x021B8CB0 thumb ov093
 */
#include "../../matched/include/Obj09978.h"
#include "../../matched/include/Obj09979.h"

struct S2;
struct Unk021B8CB0;
typedef unsigned char u8;

typedef unsigned int   u32;

extern u8 func_021B8C50(char **p, u32 v, int k);
extern void func_021B8E28(u8 *, u8, u8 *, u8 *);
extern u8 *func_021BB85C(u8 *, unsigned int);
extern u32 func_021B9BF0(struct S2 *p, u32 i);
extern u8 func_021B8CB0(struct Unk021B8CB0 **p, u8 x);
void *func_021CB174(u8 *p, unsigned int n, int k);
void *func_021CB1A4(u8 *p, u8 n);

/*
 * interface: func_021B8C50 forwards live r1/r2 to func_021B8C20 and returns r0.
 */
void *func_021CB174(u8 *p, unsigned int n, int k)
{
    u8 out[2];
    func_021B8E28(*(u8 * *)&((struct Obj09978 *)p)->f4, func_021B8C50(((struct Obj09978 *)p)->f4, n, k), out + 1, out);
    return (void *)func_021B9BF0(*(void **)(func_021BB85C(*(u8 * *)&((struct Obj09978 *)p)->f0, out[1]) + 4), out[0]);
}

void *func_021CB1A4(u8 *p, u8 n)
{
    u8 out[2];
    func_021B8E28(*(u8 * *)&((struct Obj09979 *)p)->f4, func_021B8CB0(((struct Obj09979 *)p)->f4, n), out + 1, out);
    return (void *)func_021B9BF0(*(void **)(func_021BB85C(*(u8 * *)&((struct Obj09979 *)p)->f0, out[1]) + 4), out[0]);
}
