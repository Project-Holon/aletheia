/*
 * function: func_0202B67C
 * address:  0x0202B67C
 * packet:   pkt_0202B67C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202B67C.c \\
 *       --func func_0202B67C --addr 0x0202B67C --thumb --cc 1.1p1
 *
 * Closed: every byte reproduces and the site that held it open is now attested.
 */
#include "../include/Obj02011.h"

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202AB28(void *p);
extern void func_0202C08C(u8 *p);
extern void func_0202B404(u8 *p);
extern void func_0202BEBC(u8 *p);
extern void func_0202C0C0(u32 *a0);

void func_0202B67C(u8 *p)
{
    func_0202AB28(*(u8 * *)&((struct Obj02011 *)p)->f10);
    *(u32 *)&((struct Obj02011 *)p)->f10 = 0;
}
