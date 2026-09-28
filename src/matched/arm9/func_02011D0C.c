/*
 * function: func_02011D0C
 * address:  0x02011D0C
 * packet:   pkt_020116E0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_02011610  0x02011610  thumb
 *   func_02048B44  0x02048B44  arm
 *
 * Identical to func_02011CF0 except for the second callee, func_02048B44.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02011D0C.c \
 *       --func func_02011D0C --addr 0x02011D0C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;

extern void func_02011610(void *a1, u8 *buf);
extern void func_02048B44(void *a0, const u8 *buf);

void func_02011D0C(void *a0, void *a1)
{
    u8 buf[0xc];

    func_02011610(a1, buf);
    func_02048B44(a0, buf);
}
