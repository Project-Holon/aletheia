/*
 * function: func_021751DC
 * address:  0x021751DC
 * packet:   pkt_021751DC
 * region:   ov012
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Recursive MATCH unblocker: callee of func_0217FF78 (ov019) +0024. Only ov012
 * has a function start here (ov011 holds the interior of a larger function,
 * ov009 ARM data), so the ov012 shard makes that site attest as `matched`.
 * The caller's scratch buffer is u32[5] and this leaf copies exactly 0x14
 * bytes into it.
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    int w[5];
} E;

int func_021751DC(char *a0, int a1, E *out)
{
    E *e = (E *)(a0 + 0xE0 + a1 * 0x14);
    u8 old;

    *out = *e;
    old = *(u8 *)(a0 + 0x130 + a1);
    *(u8 *)(a0 + 0x130 + a1) = 0;
    return old;
}
