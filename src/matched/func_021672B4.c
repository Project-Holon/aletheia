/*
 * function: func_021672B4
 * address:  0x021672B4
 * packet:   pkt_021672B4
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02190788  0x02190788  thumb
 *   func_021907C0  0x021907C0  thumb
 *   func_02045730  0x02045730  arm
 *   func_020409B4  0x020409B4  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02190788();
extern int func_021907C0();
extern int func_02045730();
extern int func_020409B4();

int func_021672B4(int a0)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 0x14);
    a0 = func_02190788(a0);
loc_021672BE:
a0 = *(int *)((char *)t4 + 0x14);
    a0 = func_021907C0(a0);
loc_021672C4:
    a0 = func_02045730(a0);
loc_021672C8:
    a0 = func_020409B4(a0);
loc_021672CC:
    return a0;}
