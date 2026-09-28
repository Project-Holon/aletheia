/*
 * function: func_0216D63C
 * address:  0x0216D63C
 * packet:   pkt_0216D63C
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: dependency of func_0217C294 (ov018 tail-call
 * thunk), which unblocks func_0216AC90 and func_0216ACCC.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_0216D63C(char *a0, int a1)
{
    switch (a1) {
    case 0:
        return *(u16 *)(a0 + 0x20);
    case 1:
        return *(u16 *)(a0 + 0x22);
    case 2:
        return *(u16 *)(a0 + 0x24);
    default:
        return 0;
    }
}
