/*
 * function: BOX2_MAIN_SetBodySlots
 * address:  0x021DF11C
 * packet:   pkt_021DC9A0
 * region:   ov170
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   BOX2_MAIN_SetSceneSlots  0x021DF0D4  thumb  ov170
 *
 * Forward with index 19.
 */

typedef unsigned int   u32;
extern void BOX2_MAIN_SetSceneSlots(char *p, int base, u32 bits);

void BOX2_MAIN_SetBodySlots(char *p, int b)
{
    BOX2_MAIN_SetSceneSlots(p, 0x13, b);
}

