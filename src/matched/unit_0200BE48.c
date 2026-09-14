/*
 * A whole translation unit, matched as one byte range.  Written from the
 * disassembly in asm/arm9/src/002_020095C8.s.
 *
 * unit:     yes
 * address:  0x0200BE48
 * packet:   pkt_0200B448
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * function: func_0200BE48, func_0200BE54, func_0200BE6C
 *
 * 60 bytes, 0x0200BE48..0x0200BE84, 3 functions, one of which carries no
 * label in the generated listing.
 *
 * The lookup of the save block with id 0x35 and the two directions of an
 * eight halfword copy in and out of it.  Both loops count **down** from 8
 * with `subs`/`bne` and no compare at all, which a `for (i = 0; i < 8; i++)`
 * does not produce: that spelling keeps the induction variable and costs a
 * `cmp` and a `blt`.  `for (i = 8; i != 0; i--)` over an unsigned counter is
 * what gives the original's six instruction body, and so does the equivalent
 * `do`/`while (--i != 0)`.
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern void *func_020071CC(void *sys, u32 id);

u16 *func_0200BE48(void *sys);

u16 *func_0200BE48(void *sys)
{
    return func_020071CC(sys, 0x35);
}

void func_0200BE54(void *sys, const u16 *src)
{
    u16 *d = func_0200BE48(sys);
    u32 i;

    for (i = 8; i != 0; i--) {
        *d++ = *src++;
    }
}

void func_0200BE6C(void *sys, u16 *dest)
{
    const u16 *s = func_0200BE48(sys);
    u32 i;

    for (i = 8; i != 0; i--) {
        *dest++ = *s++;
    }
}
