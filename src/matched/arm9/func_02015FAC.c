/*
 * function: func_02015FAC
 * address:  0x02015FAC
 * packet:   pkt_02015FAC
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Reads the low byte of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef struct {
    char pad[0x140];
    unsigned int value : 8;
} Data;

u8 func_02015FAC(Data *p)
{
    return p->value;
}
