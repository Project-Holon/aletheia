/*
 * function: func_0203D634
 * address:  0x0203D634
 * packet:   pkt_0203D578
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Returns the byte at +0x62 of the net context.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D634.c \
 *       --func func_0203D634 --addr 0x0203D634 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8 *func_0203D788(void);

u32 func_0203D634(void)
{
    return func_0203D788()[0x62];
}
