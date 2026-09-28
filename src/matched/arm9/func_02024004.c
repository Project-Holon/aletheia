/*
 * function: func_02024004
 * address:  0x02024004
 * packet:   pkt_02024004
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   d_021468FC  0x021468FC  data
 *
 * Unlabelled Thumb leaf (no prologue, so disasm.py prints the run as ARM
 * data). A three-way guard on the object at 0x021468FC: mode 3 needs both
 * the +0x3C and +0x1C words clear, mode 1 only +0x3C, mode 2 only +0x1C;
 * anything else returns 0. The pointer is loaded from the pool word at
 * 0x02024040.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned int u32;

extern u32 d_021468FC[];

int func_02024004(int a)
{
    if (a == 3) {
        if (d_021468FC[0x3C / 4] == 0 && d_021468FC[0x1C / 4] == 0)
            return 1;
    } else if (a == 1) {
        if (d_021468FC[0x3C / 4] == 0)
            return 1;
    } else if (a == 2) {
        if (d_021468FC[0x1C / 4] == 0)
            return 1;
    }
    return 0;
}
