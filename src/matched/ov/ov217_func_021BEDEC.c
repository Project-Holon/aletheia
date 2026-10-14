/*
 * function: func_021BEDEC
 * address: 0x021BEDEC
 * packet: pkt_ov217_021BEDEC
 * region: ov217
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * lever: named color=p+56 keeps the shared sub-block base in r4, avoiding repeated address setup.
 * volatile: hardware writes at 021BEE54,021BEE58,021BEE6A,021BEE70..021BEE88.
 * F810 retains original guard fields visibly loaded in r1/r2.
 * symbols:
 *   func_021BF810 0x021BF810 thumb ov217
 *   GRAPHTABLE_GetEntryRed 0x021C2654 thumb ov217
 *   GRAPHTABLE_GetEntryGreen 0x021C2664 thumb ov217
 *   GRAPHTABLE_GetEntryBlue 0x021C2674 thumb ov217
 */
#include "../include/Obj00021.h"
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021BF810(void *p);
extern unsigned GRAPHTABLE_GetEntryRed(void *,unsigned,unsigned);
extern unsigned GRAPHTABLE_GetEntryGreen(void *,unsigned,unsigned);
extern unsigned GRAPHTABLE_GetEntryBlue(void *,unsigned,unsigned);
void func_021BEDEC(char *p)
{
    unsigned r,g,b;
    void *color;
    if (((struct Obj00021 *)p)->f3C8==0 || ((struct Obj00021 *)p)->f3D0==1 || func_021BF810(p)==0) return;
    color=p+56;
    r=GRAPHTABLE_GetEntryRed(color,((struct Obj00021 *)p)->f2B8,((struct Obj00021 *)p)->f2B9);
    g=GRAPHTABLE_GetEntryGreen(color,((struct Obj00021 *)p)->f2B8,((struct Obj00021 *)p)->f2B9);
    b=GRAPHTABLE_GetEntryBlue(color,((struct Obj00021 *)p)->f2B8,((struct Obj00021 *)p)->f2B9);
    *(volatile unsigned *)0x040004a4=0x001f00c0;
    *(volatile unsigned *)0x04000500=1;
    *(volatile unsigned *)0x04000480=(u16)(r | (g<<5) | (b<<10));
    *(volatile unsigned *)0x0400048c=0x096cfc68;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x0400048c=0x0a7afc68;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x0400048c=0x0a7afda1;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x0400048c=0x096cfda1;
    *(volatile unsigned *)0x0400048c=0;
    *(volatile unsigned *)0x04000504=0;
}
