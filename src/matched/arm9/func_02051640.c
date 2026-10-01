/*
 * function: func_02051640
 * address:  0x02051640
 * packet:   pkt_02051640
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Unlabelled ARM leaf in the ARM9 module. Reads the word at +0xC.
 * Filed as the witness for an ov094 caller.
 *
 * Addresses are Black-image addresses.
 */

void *func_02051640(char *p)
{
    return *(void **)(p + 0xc);
}
