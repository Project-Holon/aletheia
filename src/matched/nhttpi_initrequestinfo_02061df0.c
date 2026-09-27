/*
 * function: NHTTPi_InitRequestInfo
 * address:  0x02061DF0
 * packet:   pkt_02060000
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *
 * Original (12 bytes, no relocation):
 *   mov r1, #0
 *   str r1, [r0]
 *   bx  lr
 *
 * Zero the first word of the request-info object.  Recovered signature
 * from the member DWARF (NHTTP_request.c:36): void
 * NHTTPi_InitRequestInfo(NHTTPRequestInfo *reqInfo_p); one word store, so
 * the first member is a 32-bit field.
 */

typedef unsigned int u32;

void NHTTPi_InitRequestInfo(u32 *reqInfo_p)
{
    *reqInfo_p = 0;
}
