/*
 * function: sakeiGetMyRecordsProcessSoapResponse
 * address:  0x021DEB98
 * packet:   pkt_021DEB98
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   sakeiReadOutputRecords  0x021DE2E0  arm
 *   (none)
 *
 * Five-argument forward to sakeiReadOutputRecords (ov175): the object itself
 *  *  is the first argument, its +0x0c cursor is passed bare and +4, and the
 *  *  +0x08 block contributes its second and third words.
 */

typedef unsigned long u32;

extern void sakeiReadOutputRecords(u32 a, u32 b, u32 c, u32 d, u32 e);

void sakeiGetMyRecordsProcessSoapResponse(char *obj)
{
    u32 *ip = *(u32 **)(obj + 8);
    u32 v = *(u32 *)(obj + 0xc);
    sakeiReadOutputRecords((u32)obj, v + 4, v, ip[2], ip[1]);
}

