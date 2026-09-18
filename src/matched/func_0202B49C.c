/*
 * function: func_0202B49C
 * address:  0x0202B49C
 * packet:   pkt_0202B49C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_0202B2CC.c is now a manifest entry (matched class)
 *
 * Resolves the node's 0x14 descriptor into the 0x18 slot and, when that
 * succeeds, feeds the resolved handle and the key derived from the node's
 * second word to func_0202B2CC.
 *
 * symbols:
 *   func_0202B374  0x0202B374  thumb
 *   func_02012984  0x02012984  thumb
 *   func_0202B2CC  0x0202B2CC  thumb
 *
 * Verified with:
 *   python tools/match.py one --src src/pending/func_0202B49C.c \
 *       --func func_0202B49C --addr 0x0202B49C --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32  func_0202B374(u32 desc);
extern u32  func_02012984(u32 a);
extern void func_0202B2CC(u32 handle, u32 key);

void func_0202B49C(u8 *p)
{
    u32 r = func_0202B374(*(u32 *)(p + 0x14));

    *(u32 *)(p + 0x18) = r;
    if (r != 0) {
        func_0202B2CC(*(u32 *)(p + 0x18), func_02012984(*(u32 *)(p + 8)));
    }
}
