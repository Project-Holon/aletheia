/*
 * function: func_0203E420
 * address:  0x0203E420
 * packet:   pkt_0203DC70
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * net_irc_wireless.c.  Runs the context's +0x78 method on the caller's
 * argument, copies 0x4C bytes of its result to +0xB4 and returns the +0x90
 * buffer.  The earlier notes (func_0203E420.c.txt, pkt_0203E420.c.txt) read
 * the function as taking no argument; the image keeps r0 untouched through
 * the global load (`ldr r1, =g`), which is the argument being forwarded to
 * the method, the same shape as func_0203E458.
 *
 * symbols:
 *   g_021469F0     0x021469F0  data
 *   func_02082D44  0x02082D44  arm
 */

typedef unsigned char u8;
typedef unsigned int  u32;

struct Ctx {
    u8    pad_00[0x78];
    void *(*fn_78)(void *arg);
};

extern struct Ctx *g_021469F0;
extern void func_02082D44(const void *src, void *dst, u32 size);

void *func_0203E420(void *arg)
{
    struct Ctx *p = g_021469F0;
    void *r;

    if (p == 0)
        return 0;
    r = p->fn_78(arg);
    func_02082D44(r, (u8 *)p + 0xB4, 0x4C);
    return (u8 *)p + 0x90;
}
