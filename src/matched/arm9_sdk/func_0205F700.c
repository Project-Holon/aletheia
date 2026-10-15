/*
 * function: NCFG_GetFormatVersion
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

#include "../include/G_NCFGBackupBss.h"

extern long NCFGi_InitBackupMemory(void);
extern struct NCFGBackupBss FormatVersionNumber;

unsigned char NCFG_GetFormatVersion(void)
{
    long result;
    unsigned char version;

    result = NCFGi_InitBackupMemory();
    if (result != 0) {
        return 0;
    }
    version = (*(unsigned char *)&FormatVersionNumber);
    if (version == 0xFF) {
        version = 0x10;
    }
    return version;
}
