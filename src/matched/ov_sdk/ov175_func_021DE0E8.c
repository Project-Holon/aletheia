/*
 * function: sakeiDeleteRecordValidateInput
 * address:  0x021DE0E8
 * packet:   pkt_ov175_021DE0E8
 * region:   ov175
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * SDK provenance: sakeiDeleteRecordValidateInput (TwlDWC/libdwcgssake.TWL.HYB.a,
 * sakerequestmodif.o), ov175.  A null record reads as the "out of range" 4,
 * a live record as 0.
 */

typedef unsigned int u32;

int sakeiDeleteRecordValidateInput(void *p)
{
    return *(u32 *)(*(u32 *)((char *)p + 8)) != 0 ? 0 : 4;
}
