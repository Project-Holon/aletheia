/*
 * function: func_0201F79C
 * address:  0x0201F79C
 * packet:   pkt_0201F5BC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * A width-narrowing wrapper on func_0201F73C, and the only evidence in the
 * image that func_0201F73C's third parameter is u16: the single
 * `lsls #16 / lsrs #16` pair here is the argument conversion, so the wrapper
 * takes the tile base as a full word and the worker takes it as a halfword.
 *
 * symbols:
 *   func_0201F73C  0x0201F73C  thumb
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0201F79C.c \
 *       --func func_0201F79C --addr 0x0201F79C --cc 1.1p1 --thumb
 */
typedef unsigned short u16;
typedef unsigned int   u32;

extern void func_0201F73C(void *desc, u32 kind, u16 base, u32 pal);

void func_0201F79C(void *desc, u32 kind, u32 base, u32 pal)
{
    func_0201F73C(desc, kind, (u16)base, pal);
}
