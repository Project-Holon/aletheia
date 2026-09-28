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
 * sdk:      NCFG_GetFormatVersion (backup.o)
 *
 * symbols:
 *   NCFGi_InitBackupMemory           0x0205f648 arm
 *   FormatVersionNumber              0x02146b00 data
 */

extern long func_0205F648(void);
extern unsigned char FormatVersionNumber;

unsigned char func_0205F700(void)
{
    long result;
    unsigned char version;

    result = func_0205F648();
    if (result != 0) {
        return 0;
    }
    version = FormatVersionNumber;
    if (version == 0xFF) {
        version = 0x10;
    }
    return version;
}
