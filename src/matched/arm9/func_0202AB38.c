/*
 * function: func_0202AB38
 * address:  0x0202AB38
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_0202AB7C.c is now a manifest entry (matched class)
 *
 * When func_0202ACC8 reports non-zero, runs func_0202ACCC.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AB38.c \
 *       --func func_0202AB38 --addr 0x0202AB38 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u32 func_0202ACC8(void *obj);
extern void func_0202ACCC(u8 *p);

void func_0202AB38(u8 *p)
{
    if (func_0202ACC8(p) != 0) {
        func_0202ACCC(p);
    }
}
