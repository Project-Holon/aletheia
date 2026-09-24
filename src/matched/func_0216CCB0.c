/*
 * function: func_0216CCB0
 * address:  0x0216CCB0
 * packet:   pkt_0216CCB0
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_0216E290  0x0216E290  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int func_0216E290();
extern int func_020307B0();

int func_0216CCB0(int a0)
{
    int t4;

t4 = a0 + 0;
    a0 = func_0216E290();
loc_0216CCB8:
a0 = *(int *)((char *)t4 + 0x44);
    a0 = func_020307B0(a0);
loc_0216CCBE:
a0 = *(int *)((char *)t4 + 0x18);
    a0 = func_020307B0(a0);
loc_0216CCC4:
a0 = t4 + 0;
    a0 = func_020307B0(a0);
loc_0216CCCA:
    return a0;}
