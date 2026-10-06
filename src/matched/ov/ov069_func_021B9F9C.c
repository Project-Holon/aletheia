/*
 * function: func_021B9F9C
 * address: 0x021B9F9C
 * packet: pkt_ov069_021B9F9C
 * region: ov069
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * symbols:
 *   func_021B9FF0 0x021B9FF0 thumb ov069
 *   func_021B9FC8 0x021B9FC8 thumb ov069
 *   func_020061E4 0x020061E4 thumb
 */
#include "../include/Obj13149.h"
struct Rec;
extern void func_021B9FF0(char *p, struct Rec *tbl, int idx);
extern void func_021B9FC8(char *p, int i);
typedef unsigned int   u32;
extern void func_020061E4(u32 a);
void func_021B9F9C(char *p, int i)
{
    func_021B9FF0(p, ((struct Obj13149 *)p)->f8, (int)((unsigned)i + (unsigned)((struct Obj13149 *)p)->f160 * 10u));
    func_021B9FC8(p, i);
    func_020061E4(0x548);
}
