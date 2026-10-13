/*
 * function: FLD_BTL_INST_TOOL_GetRandomU16
 * address:  0x02168824
 * packet:   pkt_02168824
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   func_0209C2B0  0x0209C2B0  arm
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u32 func_020056EC(u32 range);
extern int func_0209C2B0();

int FLD_BTL_INST_TOOL_GetRandomU16(void)
{
    int a0;
    int a1;
    int t4;

t4 = 0;
t4 = ~t4;
a0 = t4 + 0;
    a0 = func_020056EC(a0);
loc_02168830:
a1 = (unsigned)t4 >> 0x10;
    a0 = func_0209C2B0(a0, a1);
loc_02168836:
a0 = a0 << 0x10;
a0 = (unsigned)a0 >> 0x10;
    return a0;}
