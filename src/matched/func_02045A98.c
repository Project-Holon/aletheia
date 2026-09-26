/*
 * function: func_02045A98
 * address:  0x02045A98
 * packet:   pkt_02045A98
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   d_020A7E7C  0x020A7E7C  data
 *
 * A two-instruction ARM read accessor used all over the ARM9 image (the
 * halfword at 0x020A7E7C, a UI/input mode word).  The literal pool word is
 * attested by sole-ref/data: 0x020A7E7C is a mapped pool-word object with 99
 * referring sites, none of them this 16-byte range.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02045A98.c \
 *       --func func_02045A98 --addr 0x02045A98 --cc 1.1p1 --arm --region arm9
 */

typedef unsigned short u16;

extern volatile u16 d_020A7E7C;

u16 func_02045A98(void)
{
    return d_020A7E7C;
}
