/*
 * function: func_020514F4
 * address:  0x020514F4
 * packet:   pkt_02051504
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 * blocker:  ABS32 func_02052770 at +0x0c (tail-call pool word): 0x02052770 (pkt_0205250C, 312 bytes) open, no witness
 *
 * NOTE ON PACKET: this 16-byte leaf sits at 0x020514F4..0x02051504, in the
 * four-byte gap between packet pkt_02051230 (ends 0x020514F4) and packet
 * pkt_02051504 (starts 0x02051504) - the last instruction word of the
 * 0x02051414 dump plus a pool word.  The listing does label it
 * (`func_020514F4` at asm/arm9/src/019_0204D434.s:5680), but its only caller
 * in the whole image is the `bl` at 0x02051594 inside func_02051574, which is
 * itself inside pkt_02051504's range, so the `label` class cannot attest it for
 * that caller.  Filing it here as its own entry makes it a `matched` witness
 * for func_02051574 instead, which is the only reason it is in this shard.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_020514F4.c \
 *       --func func_020514F4 --addr 0x020514F4 --cc 1.1p1 --arm
 */

typedef unsigned int u32;

extern int func_02052770(u32 a);

int func_020514F4(u32 *p)
{
    return func_02052770(*p);
}
