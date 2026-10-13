/*
 * function: TRIAL_HOUSE_IsDeliveryIdReceived
 * address:  0x021D1058
 * packet:   pkt_ov021_021D1058
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Bit test in the 128-bit field at +0x28; out-of-range indices read as set.
 * Region ov021: ov021 holds this Thumb leaf next to its setter 0x021D1080 and
 * ov021 TRIAL_HOUSE_DeliveryTaskMain calls the pair as test-then-set; ov016 is ARM here and
 * ov093 has an unrelated push-lr function at this address (wave A1 witness).
 * Addresses are Black-image addresses.
 */

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct Flags {
    u8 pad[0x28];
    u8 bits[16];
} Flags;

u8 TRIAL_HOUSE_IsDeliveryIdReceived(Flags *p, u32 n)
{
    if (n < 0x80) {
        return (p->bits[(u8)(n >> 3)] >> (u8)(n & 7)) & 1;
    }
    return 1;
}
