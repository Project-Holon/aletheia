/*
 * function: func_021BAC30
 * address: 0x021BAC30
 * packet: pkt_ov110_021BAC30
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021BCF18 0x021BCF18 thumb ov110
 */
#include "../include/Obj22339.h"
typedef unsigned char u8;
extern void func_021BCF18(void *,int);
void func_021BAC30(u8 *p,int mode)
{
    func_021BCF18(((struct Obj22339 *)p)->f64,mode);
}
