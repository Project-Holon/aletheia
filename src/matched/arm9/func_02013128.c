/*
 * function: BTL_SETUP_SetParty
 * address:  0x02013128
 * packet:   pkt_02013128
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *
 * Unlabelled Thumb thunk in the ARM9 module (zonedata.c). Tail-calls
 * POKEPARTY_Copy (the 0x534-byte container copy in unit_0201AC2C.c,
 * prototype (src, dst)) with the second argument as source and the i-th
 * pointer of the table at +0x24 as destination.
 *
 * Addresses are Black-image addresses.
 */

struct Rec534;
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);

void BTL_SETUP_SetParty(void *p, void *src, int i)
{
    POKEPARTY_Copy(src, ((void **)((char *)p + 0x24))[i]);
}
