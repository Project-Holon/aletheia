/*
 * function: func_02073898
 * address:  0x2073898
 * packet:   pkt_02073624
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Releases the registered slot when one is held: the mask to drop is the value
 *  * in +0x4c itself, and the same zero then clears +0x4c and +0x50 out of one
 *  * `mov r0, #0`.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct X { u8 pad00[0x4c]; u32 f4c; u32 f50; };
extern void func_02072974(u32);

void func_02073898(struct X *x)
{
    if (x->f4c == 0) return;
    func_02072974(x->f4c);
    x->f4c = 0;
    x->f50 = 0;
}
