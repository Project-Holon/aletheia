/*
 * function: func_021C62BC
 * address:  0x021C62BC
 * packet:   pkt_ov136_021C62BC
 * region:   ov136
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0201F73C   0x0201F73C  thumb
 *   func_02041B6C    0x02041B6C  arm
 *   func_02045334            0x02045334  arm
 *   func_02045374   0x02045374  arm
 *   func_02045730   0x02045730  arm
 */
#include "../include/Obj00127.h"
#include "../include/Obj23566.h"
#include "../include/Obj23567.h"

typedef unsigned char u8;
typedef unsigned int u32;
struct Cfg;
struct Descriptor;
extern void func_0201F73C(void *a0, int a1, int a2, int a3);
extern void func_02045334(struct Descriptor *d);
extern void func_02045374(struct Cfg *cfg);
extern u8 func_02045730(struct Descriptor *p);
extern void func_02041B6C(u32 bit);
void func_021C62BC(u8 *p)
{
    void *q;
    func_0201F73C(((struct Obj23566 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->fA8, 2, 0x3E2, 0xD);
    q = ((struct Obj23567 *)(*(u8 * *)&((struct Obj00127 *)p)->f8))->fA8;
    func_02045334(q);
    func_02045374(q);
    func_02041B6C(func_02045730(q));
}
