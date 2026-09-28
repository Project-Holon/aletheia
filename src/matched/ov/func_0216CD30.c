/*
 * function: func_0216CD30
 * address:  0x0216CD30
 * packet:   pkt_0216CD30
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02030DA4  0x02030DA4  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02049238  0x02049238  arm
 *   func_0216D4E4  0x0216D4E4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02030DA4();
extern int func_020307B0();
extern int func_02049238();
extern int func_0216D4E4();

void func_0216CD30(int a0, int a1)
{
    int t4;

t4 = a0 + 0;
a0 = *(int *)((char *)t4 + 0x20);
    a0 = func_02030DA4(a0);
loc_0216CD3A:
a0 = *(int *)((char *)t4 + 0x1c);
    a0 = func_020307B0(a0);
loc_0216CD40:
a0 = *(int *)((char *)t4 + 0x10);
    a0 = func_02049238(a0);
loc_0216CD46:
a0 = t4 + 0;
a1 = 0x10;
    a0 = func_0216D4E4(a0, a1);
loc_0216CD4E:
    return;}
