/*
 * function: func_02206B90
 * address:  0x02206B90
 * packet:   pkt_ov094_02206B90
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

typedef unsigned int   u32;
extern void func_020061E4(u32 a);

void func_02206B90(char *p)
{
    if (*(int *)(p + 0x54) != 3 || *(int *)(p + 0x58) == 6)
        func_020061E4(0x54d);
}
