/*
 * function: func_021DBF9C
 * address: 0x021DBF9C
 * packet: pkt_ov121_021DBF9C
 * region: ov121
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT*
 * extent: two bytes of zero alignment padding follow the return.
 * symbols:
 *   func_021DC024 0x021DC024 thumb ov121
 *   func_021DC02C 0x021DC02C thumb ov121
 *   POKE_TOOL_CalcGraphicIndex  0x0201BABC  thumb  arm9
 *   FILE_UTIL_Get  0x02020E60  arm  arm9
 */
#include "../include/Obj06452.h"
typedef unsigned short u16;
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_021DC024(void *);
extern char *func_021DC02C(void *);
extern u32 POKE_TOOL_CalcGraphicIndex(u32 species, u32 form, u32 gender, u32 isEgg);
extern u32 FILE_UTIL_Get(u32,u32);
int func_021DBF9C(void *p)
{
    char *q;
    switch(func_021DC024(p)) {
    case 1:
        q=func_021DC02C(p);
        return POKE_TOOL_CalcGraphicIndex(((struct Obj06452 *)q)->f1A,((struct Obj06452 *)q)->f1C,((struct Obj06452 *)q)->f35,((struct Obj06452 *)q)->f5C);
    case 2:
        q=func_021DC02C(p);
        return FILE_UTIL_Get((u16)((struct Obj06452 *)q)->f0,1);
    default: return 12;
    }
}
