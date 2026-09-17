/*
 * function: func_0202C070
 * address:  0x0202C070
 * packet:   pkt_0202BE00
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   MATCH
 *
 * Creates a node through func_0202C124, prepares it with func_0202C118 and
 * binds the argument with func_0202C148.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_0202C070.c \
 *       --func func_0202C070 --addr 0x0202C070 --thumb --cc 1.1p1
 */

typedef unsigned char u8;
typedef unsigned int  u32;

extern u8  *func_0202C124(void);
extern void func_0202C118(void);
extern void func_0202C148(u8 *p, u8 *arg);

u8 *func_0202C070(u8 *p)
{
    u8 *r = func_0202C124();

    func_0202C118();
    func_0202C148(r, p);
    return r;
}
