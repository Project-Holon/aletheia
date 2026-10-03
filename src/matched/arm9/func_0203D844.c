/*
 * function: func_0203D844
 * address:  0x0203D844
 * packet:   pkt_0203D7C8
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Copies 0x70 bytes from the net context into the destination.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0203D844.c \
 *       --func func_0203D844 --addr 0x0203D844 --arm --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void *func_0203D788(void);
extern void func_02082D44(void *dst, const void *src, u32 size);

void func_0203D844(void *dst)
{
    func_02082D44(dst, func_0203D788(), 0x70);
}
