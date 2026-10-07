/*
 * function: func_021DD290
 * address:  0x021DD290
 * packet:   pkt_ov175_021DD290
 * region:   ov175
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sakeSetProfile (sakemain.o)
 *
 * Closed (w5_nm): the 25-byte ticket copy is memcpy through string.h; the struct
 * assignment loaded the byte pair in the converse order. The parameter is const char *
 * (DWARF: char *); with plain char * the copy compiles 4 bytes longer.
 *
 * symbols:
 *   (none)
 */

#include "../../../matched/arm9_sdk/libc/string.h"

typedef struct SAKEInternal {
    unsigned char pad0[0x24];
    int profileSet;
    int profileId;
    char loginTicket[25];
} SAKEInternal;

void func_021DD290(SAKEInternal *sake, int profileId, const char *loginTicket)
{
    sake->profileId = profileId;
    memcpy(sake->loginTicket, loginTicket, 25);
    sake->profileSet = 1;
}
