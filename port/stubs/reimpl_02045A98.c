/*
 * func_02045A98 -- the global end-of-string code unit.  REIMPLEMENTATION,
 * not a match.
 *
 * src/matched/func_02045E3C.c (status EXACT) calls it once, before the loop,
 * and compares every decrypted unit against the result:
 *
 *     u16 eos = func_02045A98();
 *     ...  if (*str == eos) return i;
 *
 * so the function is a nullary getter for the terminator.  The value is
 * attested twice, independently of the address:
 *
 *   - tools/assets/text.py decodes every sub-file of a/0/0/2 and
 *     re-encodes it byte-identically with 0xFFFF as the terminator
 *     (`text.py roundtrip-all`); a different terminator would not round
 *     trip.
 *   - func_02045E3C.c's own header records 0xFFFF for this build.
 *
 * Caveat worth carrying forward: layout/symbols_sdk.txt lists 0x02045A98 as
 * TwlSDK GX_GetBankForLCDC.  That cannot be what the message decoder calls,
 * and the entry is not flagged `?`, so either libmatch.py has a false
 * positive at this address or the game overrules the SDK symbol here (the
 * same situation docs/HANDOFF.md records for 0x020749B4 / FATFS_FormatDrive).
 * Worth one look from the matching lane; it does not change the port.
 */

#include "stubs.h"

u16 func_02045A98(void)
{
    return 0xFFFF;
}
