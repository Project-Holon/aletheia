/*
 * function: func_021C6E64
 * address:  0x021C6E64
 * packet:   pkt_ov136_021C6E64
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021C5C64  0x021C5C64  thumb
 *   func_021C6284 0x021C6284 thumb
 *   func_021C62BC 0x021C62BC thumb
 *   func_021C66B8 0x021C66B8 thumb
 *   func_021C71A8 0x021C71A8 thumb
 *   func_021C7298 0x021C7298 thumb
 */
#include "../include/Obj00127.h"

typedef unsigned char u8;
typedef unsigned int u32;
extern void func_021C66B8(u8 *, int, u32);
extern void func_021C7298(void *p, int v);
extern void func_021C5C64(u8 *);
extern void func_021C62BC(u8 *);
extern void func_021C6284(u8 *);
extern void func_021C71A8(u8 *, int, int);
void func_021C6E64(u8 *p)
{
    func_021C66B8(*(u8 * *)&((struct Obj00127 *)p)->f8, 2, 0);
    func_021C7298(*(u8 * *)&((struct Obj00127 *)p)->f8, 1);
    func_021C5C64(p);
    func_021C62BC(p);
    func_021C6284(p);
    func_021C71A8(p, 0, 0xD);
}
