/*
 * function: func_0204ED24
 * address:  0x0204ED24
 * packet:   pkt_0204EA64
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT*
 *
 * symbols:
 *   func_0204F27C  0x0204F27C  arm
 *   func_020307B0  0x020307B0  arm
 *
 * Free an actor and its two sub-objects, in +8, +4, self order.
 */

typedef unsigned char u8;

extern void func_0204F27C(void *p);
extern void func_020307B0(void *p);

void func_0204ED24(void *p)
{
    func_0204F27C(p);
    func_020307B0(*(void **)((u8 *)p + 8));
    func_020307B0(*(void **)((u8 *)p + 4));
    func_020307B0(p);
}
