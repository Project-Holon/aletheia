/*
 * function: func_021BDC78
 * address: 0x021BDC78
 * packet: pkt_ov093_021BDC78
 * region: ov093
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * symbols:
 *   func_021D5440 0x021D5440 thumb ov093
 *   func_021B8DDC 0x021B8DDC thumb ov093
 *   func_021CD4B0 0x021CD4B0 thumb ov093
 */
#include "../include/Obj00003.h"
typedef unsigned char u8;
typedef unsigned int u32;
extern u8 func_021D5440(u8 *p);
extern u8 func_021B8DDC(u32 x);
extern void func_021CD4B0(void *w, volatile u32 id, ...);
void func_021BDC78(u8 *p, u8 *a)
{
    u8 id;
    int value;
    id = func_021D5440(a);
    value = func_021B8DDC(id);
    func_021CD4B0(((struct Obj00003 *)p)->fC, 0x3b, value, id);
}
