/*
 * function: func_02206B14
 * address:  0x02206B14
 * packet:   pkt_ov094_02206B14
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 */

extern void func_020061E4(int a);

void func_02206B14(char *p)
{
    if (*(int *)(p + 0x54) != 3 || *(int *)(p + 0x58) == 6)
        func_020061E4(0x548);
}
