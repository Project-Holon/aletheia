/*
 * function: func_021E203C
 * address:  0x021E203C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   func_02021ED8   0x02021ED8  thumb
 *
 * Return the +0x28 field when the +0x6c sub-object test is zero, else 3.
 */

typedef unsigned int   u32;
extern u32 func_02021ED8(const char *ptr);


int func_021E203C(void *p)
{
    if (func_02021ED8((const char *)(*(int *)(*(int *)((char *)p + 0x2c) + 0x6c))) == 0)
        return *(int *)((char *)p + 0x28);
    return 3;
}

