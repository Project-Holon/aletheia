/*
 * function: func_02168AEC
 * address:  0x02168AEC
 * packet:   pkt_02168AEC
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Recursive MATCH unblocker: ABS32 target of func_021D0BCC (ov021) +0008.
 * Coherent Thumb code in ov010 (ARM data in ov009), so the ov010 shard makes
 * that site attest as `matched`.
 *
 * symbols:
 *   g_0217208C  0x0217208C  data  ov010  a2
 *   g_0217208E  0x0217208E  data  ov010  a2
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

extern u16 g_0217208C[];
extern u16 g_0217208E[];

u16 func_02168AEC(u16 a0)
{
    u32 i;

    for (i = 0; i < 0x35; i++) {
        if (g_0217208C[i * 2] == a0)
            return g_0217208E[i * 2];
    }
    return 0xA;
}
