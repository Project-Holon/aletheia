/*
 * function: func_0217ECA4
 * address:  0x0217ECA4
 * packet:   pkt_ov009_0217ECA4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   DIFF
 *
 * sdk:      sendto (gsplatformsocket)
 *
 * near miss: sendto: 84 bytes. Only diff is a register swap in the 4x2-byte struct copy loop: original source pointer r5 / dest r6, 1.1p1 has source r6 / dest r5 (7 instrs). Tried struct shapes (packed, u8 data[6], u16 data[3]), src/dst locals, declaration order, const, memcpy.
 *
 * symbols:
 *   func_0215F5B4                  0x0215F5B4  arm ov009
 *   func_0217EB00                  0x0217EB00  arm ov009
 */

struct SOCSockAddr { unsigned char len; unsigned char family; unsigned char data[6]; };
extern int func_0215F5B4(int s, void *buf, int len, int flags, void *sockTo);
extern int func_0217EB00(int rcode, int errCode);

int func_0217ECA4(int sock, char *buf, int len, int flags, struct SOCSockAddr *addr, int tolen)
{
    struct SOCSockAddr remoteAddr;
    struct SOCSockAddr *src = addr;
    int rcode;

    remoteAddr = *src;
    remoteAddr.len = tolen;
    rcode = func_0215F5B4(sock, buf, len, flags, &remoteAddr);
    return func_0217EB00(rcode, -1);
}