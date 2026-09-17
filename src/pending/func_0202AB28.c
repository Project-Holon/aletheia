/*
 * function: func_0202AB28
 * address:  0x0202AB28
 * packet:   pkt_0202A188
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Runs func_0202AB84 then releases the object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202AB28.c \
 *       --func func_0202AB28 --addr 0x0202AB28 --thumb --cc 1.1p1
 */

typedef unsigned char u8;

extern void func_0202AB84(u8 *p);
extern void func_020307B0(void *p);

void func_0202AB28(u8 *p)
{
    func_0202AB84(p);
    func_020307B0(p);
}
