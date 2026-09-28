/*
 * function: func_0215A690
 * address:  0x0215A690
 * packet:   pkt_0215A690
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: dependency of func_02159254 (tail-call pool word
 * 0x0215A691), which in turn unblocks func_02159260.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

int func_0215A690(char *a0)
{
    u16 *p = (u16 *)(*(char **)(a0 + 0x20) + 0x106);

    if (*p == 0)
        return 1;
    (*p)--;
    return 0;
}
