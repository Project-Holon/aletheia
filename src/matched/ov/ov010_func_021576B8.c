/*
 * function: func_021576B8
 * address:  0x021576B8
 * packet:   pkt_021576B8
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: matched so the ABS32 site in
 * ov010_func_021576C4 attests as `matched`.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void func_021576B8(char *a0, int a1)
{
    *(u32 *)(a0 + 0x31BC) = a1;
}
