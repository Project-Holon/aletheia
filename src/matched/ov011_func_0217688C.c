/*
 * function: func_0217688C
 * address:  0x0217688C
 * packet:   pkt_0217688C
 * region:   ov011
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: callee of func_0216AF3C (ov010) at +0032. The
 * address is Thumb code in ov011 (ARM/data in the overlapping ov009), so the
 * matched shard makes that site attest as `matched`.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

void func_0217688C(u8 *a0, u8 a1)
{
    a0[0x8E0] = a1;
    a0[0x8E1] = 1;
}
