/*
 * function: func_0217ECA4
 * address:  0x0217ECA4
 * packet:   pkt_ov009_0217ECA4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      sendto (gsplatformsocket)
 *
 * Closed (w4_nm): the address copy is memcpy(&remoteAddr, addr, sizeof(remoteAddr))
 * with the string.h prototype, so mwccarm inlines it as the two-byte loop with the
 * object's source/dest registers (the struct assignment swapped them).
 *
 * symbols:
 *   func_0215F5B4                  0x0215F5B4  arm ov009
 *   func_0217EB00                  0x0217EB00  arm ov009
 */

#include "../../../matched/arm9_sdk/libc/string.h"

struct SOCSockAddr { unsigned char len; unsigned char family; unsigned char data[6]; };
extern int func_0215F5B4(int s, void *buf, int len, int flags, void *sockTo);
extern int func_0217EB00(int rcode, int errCode);

int func_0217ECA4(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen)
{
    struct SOCSockAddr remoteAddr;
    int rcode;

    memcpy(&remoteAddr, addr, sizeof(remoteAddr));
    remoteAddr.len = tolen;
    rcode = func_0215F5B4(sock, buf, len, flags, &remoteAddr);
    return func_0217EB00(rcode, -1);
}
