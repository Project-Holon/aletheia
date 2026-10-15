/*
 * function: POKETRADE_DEMO_MIDDLE_SetupEmitterB
 * address:  0x021D6F0C
 * packet:   pkt_021D6F0C
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   POKETRADE_DEMO_MIDDLE_UpdateEmitterB  0x021D6ECC  thumb  ov118
 *   BUTTON_MAN_SetCallback  0x02051A24  arm  arm9
 *   BUTTON_MAN_SetUserData  0x02051A2C  arm  arm9
 *
 * Addresses are Black-image addresses.
 *
 * Promoted from MATCH by the recursive-unblocker lane: the ARM9 storage
 * setters BUTTON_MAN_SetUserData/BUTTON_MAN_SetCallback now have EXACT arm9 shard entries
 * (pkt_02051A2C / pkt_02051A24), so both calls resolve via `matched`.
 * Verified EXACT, 32 bytes.
 */

typedef unsigned int   u32;
extern u32 func_02051774(void);
extern void BUTTON_MAN_SetUserData(void *p, int v);
extern void BUTTON_MAN_SetCallback(void *p, int v);
extern void POKETRADE_DEMO_MIDDLE_UpdateEmitterB(void *obj, int on);

void POKETRADE_DEMO_MIDDLE_SetupEmitterB(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)POKETRADE_DEMO_MIDDLE_UpdateEmitterB);
}
