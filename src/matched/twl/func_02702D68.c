/*
 * function: NWMi_ForceUnloadDeviceCallback
 * address: 0x02702D68
 * packet: pkt_twl_02702D68
 * region: twl
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: arm
 * status: EXACT
 *
 * Function with no listing label, matched inside src/game/twl/unit_02702D68.c and filed here.
 *
 * symbols:
 *   d_027341C8 0x027341C8 data twl
 */

typedef unsigned char u8;
extern u8 d_027341C8;

/* Sets a one-byte flag. */
static void NWMi_ForceUnloadDeviceCallback(void)
{
    d_027341C8 = 1;
}
