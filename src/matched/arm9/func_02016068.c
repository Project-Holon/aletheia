/*
 * function: MCSS_GetMosaic
 * address:  0x02016068
 * packet:   pkt_02016068
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Reads bits 24..27 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef struct {
    char pad[0x140];
    unsigned int padbits : 24;
    unsigned int value : 4;
} Data;

u8 MCSS_GetMosaic(Data *p)
{
    return p->value;
}
