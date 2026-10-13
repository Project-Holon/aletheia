/*
 * function: GPOWER_GetExpiringPowerId
 * address:  0x02010F18
 * packet:   pkt_02010F18
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Returns the byte-table entry g_0214621C of the first of the thirteen counter slots whose value is 1,
 * or 0x30 when none is. The loop index is the Slot enum (as in GPOWER_ClearAll): an int index lets
 * mwcc fold the constant entry guard away.
 *
 * symbols:
 *   g_021461E8  0x021461E8  data
 *   g_0214621C  0x0214621C  data
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned int   u32;

typedef enum { SLOT_0 = 0, SLOT_MAX = 13 } Slot;

extern u32 g_021461E8[];
extern u8 g_0214621C[];

u8 GPOWER_GetExpiringPowerId(void)
{
    Slot i;

    for (i = 0; i < SLOT_MAX; i++) {
        if (g_021461E8[i] == 1)
            return g_0214621C[i];
    }
    return 0x30;
}
