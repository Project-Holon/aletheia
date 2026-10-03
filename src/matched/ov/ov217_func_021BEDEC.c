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
 *   func_021C2654 0x021C2654 thumb ov217
 *   func_021C2664 0x021C2664 thumb ov217
 *   func_021C2674 0x021C2674 thumb ov217
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern u32 func_021BF810(void *p);
extern unsigned func_021C2654(void *,unsigned,unsigned);
extern unsigned func_021C2664(void *,unsigned,unsigned);
extern unsigned func_021C2674(void *,unsigned,unsigned);
void func_021BEDEC(char *p)
{
    unsigned r,g,b;
    void *color;
    if (*(unsigned *)(p+0x3c8)==0 || *(unsigned *)(p+0x3d0)==1 || func_021BF810(p)==0) return;
    color=p+56;
    r=func_021C2654(color,*(u8 *)(p+0x2b8),*(u8 *)(p+0x2b9));
    g=func_021C2664(color,*(u8 *)(p+0x2b8),*(u8 *)(p+0x2b9));
    b=func_021C2674(color,*(u8 *)(p+0x2b8),*(u8 *)(p+0x2b9));
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
