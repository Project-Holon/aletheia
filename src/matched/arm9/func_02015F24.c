/*
 * function: func_02015F24
 * address:  0x02015F24
 * packet:   pkt_02015F24
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Unlabelled Thumb leaf in the ARM9 module. Reads byte 1 of the record behind the pointer at +0x30.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef struct {
    char pad[0x30];
    u8 *p30;
} S;

u8 func_02015F24(S *s)
{
    return s->p30[1];
}
