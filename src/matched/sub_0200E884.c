/*
 * function: sub_0200E884
 * address:  0x0200E884
 * packet:   pkt_0200E684
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   sub_020071CC  0x020071CC  thumb
 *   func_02082A90 0x02082A90  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/sub_0200E884.c \
 *       --func sub_0200E884 --addr 0x0200E884 --cc 1.1p1
 */

typedef unsigned int u32;

extern void *sub_020071CC(void *sys, u32 id);
extern void  func_02082A90(void *dest, const void *src, u32 size);

void sub_0200E884(void *sys, void *src)
{
    void *obj = sub_020071CC(src, 0x40);
    func_02082A90(sys, obj, 0x10);
}
