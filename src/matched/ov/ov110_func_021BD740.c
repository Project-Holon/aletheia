/*
 * function: func_021BD740
 * address: 0x021BD740
 * packet: pkt_ov110_021BD740
 * region: ov110
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT*
 * Extent remainder: two-byte zero alignment padding.
 * symbols:
 *   func_02024584 0x02024584 thumb
 *   func_02024598 0x02024598 thumb
 */
#include "../include/Obj05295.h"
typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
extern u8 func_02024584(u32 i);
extern void func_02024598(void *,int,int);
void func_021BD740(u8 *p,void *out,int v)
{
    p[2]=0;
    ((struct Obj05295 *)p)->f0=v;
    p[3]=func_02024584(((struct Obj05295 *)p)->f0);
    func_02024598(out,((struct Obj05295 *)p)->f0,*(s8 *)&((struct Obj05295 *)p)->f2);
}
