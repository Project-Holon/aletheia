/*
 * function: func_020273C4
 * address:  0x020273C4
 * packet:   pkt_020273C4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled leaf accessor matched to give overlay call sites a `matched`
 * witness.  Addresses are Black-image addresses.
 *
 * symbols:
 *   func_020273C4  0x020273C4  thumb
 */

typedef struct { unsigned short lo : 8; unsigned short hi : 8; } F;

void func_020273C4(char *p, unsigned short v)
{
    ((F *)(p + 0x48))->lo = 0;
    *(unsigned short *)(p + 0x4e) = v;
}
