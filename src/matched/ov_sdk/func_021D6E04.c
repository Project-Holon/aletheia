/*
 * function: DWCi_LSTlPushFront
 * address:  0x021D6E04
 * packet:   pkt_021D6DF4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_LSTlPushFront   0x021D6E04  arm
 *   DWCi_LSTlInsert  0x021D6DC4  arm
 *
 * Tail-call DWCi_LSTlInsert with the pointer held at +0x04.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_LSTlPushFront.c \
 *       --func DWCi_LSTlPushFront --addr 0x021D6E04 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void DWCi_LSTlInsert(void *pos, void *ob);

void DWCi_LSTlPushFront(char *p, void *ob)
{
    DWCi_LSTlInsert(*(void **)(p + 4), ob);
}
