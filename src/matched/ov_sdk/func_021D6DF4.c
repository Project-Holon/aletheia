/*
 * function: DWCi_LSTlPushBack
 * address:  0x021D6DF4
 * packet:   pkt_021D6DF4
 * region:   ov016
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * symbols:
 *   DWCi_LSTlPushBack   0x021D6DF4  arm
 *   DWCi_LSTlInsert  0x021D6DC4  arm
 *
 * Tail-call DWCi_LSTlInsert with the argument advanced by 8.
 * Addresses are Black-image addresses.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/DWCi_LSTlPushBack.c \
 *       --func DWCi_LSTlPushBack --addr 0x021D6DF4 --region ov016 --cc dsi/1.1p1 --arm
 */

extern void DWCi_LSTlInsert(void *pos, void *ob);

void DWCi_LSTlPushBack(char *p, void *ob)
{
    DWCi_LSTlInsert(p + 8, ob);
}
