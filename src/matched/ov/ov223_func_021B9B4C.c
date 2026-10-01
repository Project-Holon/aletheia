/*
 * function: func_021B9B4C
 * address: 0x021B9B4C
 * region: ov223
 * isa: thumb
 * packet: pkt_ov223_021B9B4C
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * status: EXACT
 * Parent cleared larger follower; push r3,r4 and bx lr establish Thumb code.
 * symbols:
 *   table 0x021BC78C data a4
 */
typedef unsigned short u16;
extern u16 table[][5];
int func_021B9B4C(char *p)
{
    int select=0;
    if(*(int *)(p+72)==0) select=1;
    if(*(int *)(p+76)==table[*(int *)(p+68)][select]) return 1;
    return 0;
}
