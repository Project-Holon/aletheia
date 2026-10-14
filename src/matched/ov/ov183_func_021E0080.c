/*
 * function: func_021E0080
 * address: 0x021E0080
 * packet: pkt_ov183_021E0080
 * region: ov183
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   BR_POKESEARCH_Close 0x021FFE70 thumb ov186
 *   BR_POKESEARCH_Destroy 0x021FFC6C thumb ov186
 *   func_020409B4 0x020409B4 arm
 */
#include "../include/Obj14434.h"
typedef unsigned short u16;
typedef unsigned int   u32;
extern void BR_POKESEARCH_Close(char *p);
extern void BR_POKESEARCH_Destroy(char *p);
extern void func_020409B4(u32 index);
int func_021E0080(char *p)
{
    BR_POKESEARCH_Close(((struct Obj14434 *)p)->f1C);
    BR_POKESEARCH_Destroy(((struct Obj14434 *)p)->f1C);
    func_020409B4(4);
    return 1;
}
