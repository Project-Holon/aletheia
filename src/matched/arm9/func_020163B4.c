/*
 * function: MCSS_SetSysFlag
 * address:  0x020163B4
 * packet:   pkt_020163B4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Unlabelled Thumb leaf in the ARM9 module. Sets bit 1 of the flag word at +0x2C.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

typedef struct {
    char pad[0x2c];
    unsigned int b0 : 1;
    unsigned int b1 : 1;
} Obj;

void MCSS_SetSysFlag(Obj *p, int v)
{
    p->b1 = v;
}
