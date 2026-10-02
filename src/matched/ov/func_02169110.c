/*
 * function: func_02169110
 * address:  0x02169110
 * packet:   pkt_02169110
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02012EBC  0x02012EBC  thumb
 *   func_02008B14  0x02008B14  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_02012EBC();
extern int func_02008B14();

int func_02169110(int a0)
{

    a0 = func_02012EBC(a0);
loc_02169116:
    a0 = func_02008B14(a0);
loc_0216911A:
a0 = *(int *)((char *)a0 + 0x18);
    return a0;}
