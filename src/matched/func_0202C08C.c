/*
 * function: func_0202C08C
 * address:  0x0202C08C
 * packet:   pkt_0202BE00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocker func_0202B6AC.c is now a manifest entry (matched class)
 *
 * Runs func_0202C198 then func_0202C140 over the object.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C08C.c \
 *       --func func_0202C08C --addr 0x0202C08C --thumb --cc 1.1p1
 */

typedef unsigned char u8;

extern void func_0202C198(u8 *p);
extern void func_0202C140(u8 *p);

void func_0202C08C(u8 *p)
{
    func_0202C198(p);
    func_0202C140(p);
}
