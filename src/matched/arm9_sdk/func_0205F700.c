/*
 * function: func_0205F700
 * address:  0x0205F700
 * packet:   pkt_0205DC74
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK symbol: NCFG_GetFormatVersion (backup.o, libncfg.TWL.HYB.a)
 *
 * symbols:
 *   NCFGi_InitBackupMemory   0x0205F648  arm
 *   FormatVersionNumber      0x02146B00  data
 */

extern long NCFGi_InitBackupMemory(void);
extern unsigned char FormatVersionNumber;

unsigned char func_0205F700(void)
{
    long result = NCFGi_InitBackupMemory();
    unsigned char version;

    if (result != 0)
        return 0;
    version = FormatVersionNumber;
    if (version == 0xff)
        return 0x10;
    return version;
}
