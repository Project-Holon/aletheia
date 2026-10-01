/*
 * function: func_021AF23C
 * address:  0x021AF23C
 * packet:   pkt_ov021_021AF23C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * blocker: func_02158F88 (0x02158F88, ov010, thumb) is an unlabelled ov010
 * leaf (adds r0, #0x40; bx lr: returns p + 0x40) in the word run after
 * func_02158F58, outside this lane's write set. Every concrete byte matches;
 * filing that leaf makes this EXACT. (2026-10-01)
 *
 * symbols:
 *   func_02158F88  0x02158F88  thumb  ov010
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;
typedef signed char    s8;

extern u8 *func_02158F88(u32 a);
extern int func_02006224(int i);

int func_021AF23C(u32 a)
{
    int i;
    u8 *p;

    p = func_02158F88(a);

    for (i = 0; i < 5; i++) {
        if (*p & (1 << i)) {
            if (func_02006224(i) == 1)
                return 1;
        }
    }
    *p = 0;
    return 0;
}
