/*
 * function: func_020160CC
 * address:  0x020160CC
 * packet:   pkt_020160CC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Reads the halfword behind the pointer at +0x28.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned short u16;
typedef struct {
    char pad[0x28];
    u16 *p28;
} S;

u16 func_020160CC(S *s)
{
    return *s->p28;
}
