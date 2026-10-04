/*
 * function: func_0202B4F0
 * address:  0x0202B4F0
 * packet:   pkt_0202B4BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_0202B2CC.c is now a manifest entry (matched class)
 *
 * Release pair: tear the node down with func_0202B5D4, then free it.
 *
 * symbols:
 *   func_0202B5D4  0x0202B5D4  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B4F0.c \
 *       --func func_0202B4F0 --addr 0x0202B4F0 --thumb --cc 1.1p1
 */

typedef unsigned char u8;

typedef unsigned int   u32;
extern void func_0202B5D4(u32 a);
extern void func_020307B0(void *p);

void func_0202B4F0(u8 *p)
{
    func_0202B5D4((u32)p);
    func_020307B0(p);
}
