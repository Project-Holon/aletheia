/*
 * function: func_02037258
 * address:  0x02037258
 * packet:   pkt_02037234
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   func_0203D788  0x0203D788  arm
 *   func_0203D6BC  0x0203D6BC  arm
 *   func_0203D680  0x0203D680  arm
 *
 * The current capacity, or the measured one: when the state object's byte at
 * +0x64 is set and its halfword at +0x6C is non-zero, that halfword is the
 * answer; otherwise the two measurement calls are multiplied.
 *
 * The conjunction is the reason both loads after the first comparison are
 * conditional (`ldrhne`, `cmpne`) and the early return is a bare `popne`:
 * written as one `&&` in a single `if`, mwcc keeps the whole guard inside the
 * flags.  The product is a plain `mul`, so the function returns a 32-bit
 * value, not a narrowed one.
 *
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/func_02037258.c \
 *       --func func_02037258 --addr 0x02037258 --cc 1.1p1 --arm
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern u8  *func_0203D788(void);
extern u32  func_0203D6BC(void);
extern u32  func_0203D680(void);

u32 func_02037258(void)
{
    u8 *p;

    p = func_0203D788();
    if (p[0x64] != 0 && *(u16 *)(p + 0x6C) != 0)
        return *(u16 *)(p + 0x6C);
    return func_0203D6BC() * func_0203D680();
}
