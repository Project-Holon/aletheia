/*
 * function: func_02156DC4
 * address:  0x02156DC4
 * packet:   pkt_02156DC4
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of func_021DA5D0 (ov123) +004A. Coherent
 * Thumb code in ov009 (ov010 holds the tail of another function), so the ov009
 * shard makes that site attest as `matched`.
 *
 * symbols:
 *   g_021A8264  0x021A8264  data  ov009
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern int *g_021A8264;

void func_02156DC4(int a0, int a1)
{
    *(int *)((char *)g_021A8264 + 0x28C) = a0;
    *(int *)((char *)g_021A8264 + 0x290) = a1;
}
