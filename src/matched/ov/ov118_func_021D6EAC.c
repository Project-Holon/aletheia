/*
 * function: func_021D6EAC
 * address:  0x021D6EAC
 * packet:   pkt_021D6EAC
 * region:   ov118
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_021D6E6C  0x021D6E6C  thumb  ov118
 *   BUTTON_MAN_SetCallback  0x02051A24  arm  arm9
 *   BUTTON_MAN_SetUserData  0x02051A2C  arm  arm9
 *
 * Addresses are Black-image addresses.
 *
 * Promoted from MATCH by the recursive-unblocker lane: the ARM9 storage
 * setters BUTTON_MAN_SetUserData/BUTTON_MAN_SetCallback (0x02051A2C / 0x02051A24) now have
 * EXACT arm9 shard entries (pkt_02051A2C / pkt_02051A24), so both calls
 * resolve via `matched`.  Verified EXACT, 32 bytes.
 */

typedef unsigned int   u32;
extern u32 func_02051774(void);
extern void BUTTON_MAN_SetUserData(void *p, int v);
extern void BUTTON_MAN_SetCallback(void *p, int v);
extern void func_021D6E6C(void *obj, int on);

void func_021D6EAC(void *p)
{
    BUTTON_MAN_SetUserData(p, func_02051774());
    BUTTON_MAN_SetCallback(p, (int)func_021D6E6C);
}
