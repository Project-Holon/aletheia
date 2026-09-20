/*
 * function: func_02072A08
 * address:  0x02072A08
 * packet:   pkt_020729C0
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   MATCH
 * note:     re-verified 2026-09-20: MATCH; see verify output
 */

typedef unsigned int u32;

struct Struct0214DEC0 {
    u32 field0;
    u32 field4;
    u32 field8;
};

extern struct Struct0214DEC0 g_0214DEC0;

void func_02072A08(u32 bit)
{
    g_0214DEC0.field4 &= ~(1U << bit);
}
