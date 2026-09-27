/*
 * function: func_02155648
 * address:  0x02155648
 * packet:   pkt_ov009_02155648
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * MATCH-capped: g_02158264 (ov009 data) has no witness outside this range
 * (sole-ref data refused: address interior/between known starts). Bytes are
 * correct; the pool word is the only image-wide reference.
 *
 * symbols:
 *   g_02158264  0x02158264  data  ov009
 */

typedef int s32;

extern char *g_02158264;

void func_02155648(s32 a, s32 b)
{
    *(s32 *)(g_02158264 + 0x27C) = a;
    *(s32 *)(g_02158264 + 0x280) = b;
}
