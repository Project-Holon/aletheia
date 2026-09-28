/*
 * function: WCMi_Notify
 * address:  0x021659B4
 * packet:   pkt_ov009_021659B4
 * region:   ov009
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      arm
 * status:   EXACT
 *
 * sdk:      WCMi_Notify (system.o)
 *
 * symbols:
 *   WCMi_NotifyEx                   0x021659f8 arm
 *   g_021AA7D4                      0x021AA7D4 data
 */

extern void WCMi_NotifyEx(short notify, short result, void *para0, void *para1, long para2);
extern char g_021AA7D4[];

void WCMi_Notify(short result, void *para0, void *para1, long para2)
{
    short notifyId = *(short *)(*(char **)(g_021AA7D4 + 4) + 0x1000 + 0x2da);

    *(short *)(*(char **)(g_021AA7D4 + 4) + 0x1000 + 0x2da) = 0;
    WCMi_NotifyEx(notifyId, result, para0, para1, para2);
}
