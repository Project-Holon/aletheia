/*
 * function: func_021DA434
 * address:  0x021DA434
 * packet:   pkt_021DA434
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02156CD0  0x02156CD0  thumb  ov009
 *   g_021E2C8C     0x021E2C8C  data
 *
 * Unblocked by matching func_02156CD0 (ov009, EXACT): the +0002 call site now
 * attests as `matched`.  A live module (non-zero from 0x02156CD0) takes the
 * 0x020399A8 handle into 0x0203D3A8 as the 0x2402/4 entry of the 0x021E2C8C
 * block, anything else reports 1.
 */

typedef unsigned long u32;

extern int func_02156CD0(void);
extern int func_020399A8(void);
extern int func_0203D3A8(void *a, unsigned int b, unsigned int c, unsigned int d);
extern u32 g_021E2C8C[];

int func_021DA434(void)
{
    if (func_02156CD0() != 0)
        return func_0203D3A8(func_020399A8(), 0x2402, 4, (u32)g_021E2C8C);
    return 1;
}

