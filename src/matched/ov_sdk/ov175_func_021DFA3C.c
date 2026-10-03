/*
 * function: func_021DFA3C
 * address:  0x021DFA3C
 * packet:   pkt_021DFA3C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_021DF8D4  0x021DF8D4  arm
 *   func_0217EAE0  0x0217EAE0  arm
 *
 * Tear a live record down: a null handle is not an error (2), a clear +0x50
 * flag means nothing is live (0), otherwise reset the record and run the
 * ov175 field destructor on the owner.
 */

typedef int s32;
typedef unsigned int u32;

extern void func_021DF8D4(char *p);
extern void func_0217EAE0(void *);

s32 func_021DFA3C(void *p)
{
    if (p == 0)
        return 2;
    if (*(u32 *)((char *)p + 0x50) != 0) {
        func_021DF8D4(p);
        func_0217EAE0(p);
    }
    return 0;
}
