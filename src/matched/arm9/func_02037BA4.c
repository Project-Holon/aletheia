/*
 * function: func_02037BA4
 * address:  0x02037BA4
 * packet:   pkt_02037A6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   g_021469D0      0x021469D0  data
 *   func_02039338   0x02039338  arm
 *   func_020393A8   0x020393A8  arm
 *   func_02037B08   0x02037B08  arm
 *
 * 64 bytes gated on the byte at +0x1EC of the object the global pointer names:
 * when it is set, the first getter's non-zero answer runs func_02037B08 and
 * returns, the second getter's non-zero answer returns without it, and
 * everything else runs func_02037B08.  The two `bl func_02037B08` are separate
 * copies in the original, which is what the two arms give.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037BA4.c \
 *       --func func_02037BA4 --addr 0x02037BA4 --cc 1.1p1 --arm
 */

typedef unsigned char u8;

extern char *g_021469D0;
typedef unsigned short u16;
extern u16 func_02039338(void);
extern int   func_020393A8(void);
extern void  func_02037B08(void);

void func_02037BA4(void)
{
    if (*(u8 *)(g_021469D0 + 0x1EC) == 0)
        return;
    if (func_02039338() == 0) {
        if (func_020393A8() == 0)
            func_02037B08();
        return;
    }
    func_02037B08();
}
