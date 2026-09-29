/*
 * function: func_02206B30
 * address:  0x02206B30
 * packet:   pkt_ov094_02206B30
 * region:   ov094
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020061E4  0x020061E4  thumb
 *
 * lane S13 leaf of func_0220648C
 */

extern void func_020061E4(int a);

void func_02206B30(char *p)
{
    if (*(int *)(p + 0x58) != 6) {
        if (*(int *)(p + 0x54) != 3) {
            func_020061E4(0x54d);
        }
    } else {
        func_020061E4(0x54c);
    }
}
