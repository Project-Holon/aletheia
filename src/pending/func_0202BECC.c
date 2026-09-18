/*
 * function: func_0202BECC
 * address:  0x0202BECC
 * packet:   pkt_0202BECC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 * blocker: func_0202BF90 - byte-correct but 2 bytes off (register numbering), so still unfiled.
 *
 * Guarded one-argument forward: only when the node's first word is set does
 * func_0202BF90 get called with the node itself.
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202BECC.c \
 *       --func func_0202BECC --addr 0x0202BECC --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern void func_0202BF90(u8 *p, u32 key);

void func_0202BECC(u8 *p, u32 key)
{
    if (*(u32 *)p != 0) {
        func_0202BF90(p, key);
    }
}
