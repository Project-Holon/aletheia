/*
 * function: MCSS_SetMepachiDrawLast
 * address:  0x02016394
 * packet:   pkt_02016394
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 30 of the control word at +0x140.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    char pad[0x140];
    unsigned int lo : 30;
    unsigned int f : 1;
    unsigned int hi : 1;
} S;

void MCSS_SetMepachiDrawLast(S *s, int f)
{
    s->f = f;
}
