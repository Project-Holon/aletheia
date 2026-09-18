/*
 * function: func_020515B4
 * address:  0x020515B4
 * packet:   pkt_02051504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * blocker:  PC24 func_02052634 at +0x0c: 0x02052634 (pkt_0205250C, 116 bytes) open, no outside branch
 *
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020515B4.c \
 *       --func func_020515B4 --addr 0x020515B4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern int func_02052634(u32 a);

void func_020515B4(void *p)
{
    *(u32 *)((char *)p + 8) = func_02052634(*(u32 *)p);
}
