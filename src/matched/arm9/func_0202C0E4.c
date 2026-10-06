/*
 * function: func_0202C0E4
 * address:  0x0202C0E4
 * packet:   pkt_0202BE00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Resolves the object through func_0202C24C and, when found, forwards the
 * argument through func_0202C330.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C0E4.c \
 *       --func func_0202C0E4 --addr 0x0202C0E4 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Obj0202C244;
extern u32 func_0202C24C(struct Obj0202C244 *p);
extern u32 func_0202C330(void *p, u32 idx);

void func_0202C0E4(u8 *p, u32 a)
{
    u32 r = func_0202C24C((struct Obj0202C244 *)p);

    if (r != 0) {
        func_0202C330((void *)r, a);
    }
}
