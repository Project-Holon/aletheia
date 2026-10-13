/*
 * function: func_021BA238
 * address: 0x021BA238
 * packet: pkt_ov093_021BA238
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * extent: trailing two bytes are alignment padding at 0x021BA24E.
 * symbols:
 *   func_021B92D4 0x021B92D4 thumb ov093
 *   BTL_SERVER_NotifyLevelUp 0x021BB8BC thumb ov093
 */
#include "../include/Obj07746.h"
extern void func_021B92D4(char *, void *, int);
typedef unsigned int   u32;
typedef unsigned char  u8;
extern void BTL_SERVER_NotifyLevelUp(u8 *p, u32 *q);
void func_021BA238(char *p, void *m)
{
    func_021B92D4(p, m, 0);
    BTL_SERVER_NotifyLevelUp(((struct Obj07746 *)p)->f8, m);
}
