/*
 * file:     unit_021DD25C.c
 * unit:     yes
 * function: func_021DD25C, func_021DD290
 * address:  0x021DD25C
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02094798  0x02094798  arm
 */
#include "../../matched/arm9_sdk/libc/string.h"

typedef struct SAKEInternal {
    unsigned char pad0[0x24];
    int profileSet;
    int profileId;
    char loginTicket[25];
} SAKEInternal;

extern char *func_02094798(char *dst, const char *src);
void func_021DD25C(char *p, int b, int c, int d);
void func_021DD290(SAKEInternal *sake, int profileId, const char *loginTicket);


void func_021DD25C(char *p, int b, int c, int d)
{
    func_02094798(p + 4, (const char *)b);
    func_02094798(p + 0x18, (const char *)d);
    *(int *)(p + 0x14) = c;
    *(int *)p = 1;
}


/*
 * sdk:      sakeSetProfile (sakemain.o)
 *
 * Closed (w5_nm): the 25-byte ticket copy is memcpy through string.h; the struct
 * assignment loaded the byte pair in the converse order. The parameter is const char *
 * (DWARF: char *); with plain char * the copy compiles 4 bytes longer.
 */
void func_021DD290(SAKEInternal *sake, int profileId, const char *loginTicket)
{
    sake->profileId = profileId;
    memcpy(sake->loginTicket, loginTicket, 25);
    sake->profileSet = 1;
}
