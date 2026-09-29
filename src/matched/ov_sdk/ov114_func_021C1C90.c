/*
 * function: func_021C1C90
 * address:  0x021C1C90
 * packet:   pkt_ov114_021C1C90
 * region:   ov114
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      ghiEncryptorSslDecryptFunc (libdwcgsghttp.TWL.HYB.a(ghttpencryption.o))
 *
 * notes:    `mov r0, #3; bx lr`; ghttpSetRequestEncryptionEngine's relocation at
 *           +0xE4 (ABS32 ghiEncryptorSslDecryptFunc) is the pool word at
 *           0x021C1180.  Byte-identical to 0x021C1C88: the name comes from that
 *           relocation.  Seeded in layout/function_starts.txt.
 */

int func_021C1C90(void)
{
    return 3;
}
