/*
 * function: func_02155C28
 * address:  0x02155C28
 * packet:   pkt_ov009_02155C28
 * region:   ov009
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * MATCH-capped: g_02158264 (ov009 data) has no witness outside this range;
 * bytes are correct. The loop fills 0x20 entries of the array at
 * g_02158264 + 0x17C / +0x1FC.
 *
 * symbols:
 *   func_0203D798  0x0203D798  arm
 *   g_02158264    0x02158264  data  ov009
 */

typedef int s32;

extern char *g_02158264;
extern void func_0203D798(void);

void func_02155C28(s32 a, s32 b)
{
    s32 i;

    func_0203D798();
    for (i = 0; i < 0x20; i++) {
        if (*(s32 *)(g_02158264 + i * 4 + 0x17C) == -1) {
            *(s32 *)(g_02158264 + i * 4 + 0x17C) = a;
            *(s32 *)(g_02158264 + i * 4 + 0x1FC) = b;
        }
    }
}
