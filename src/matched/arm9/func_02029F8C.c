/*
 * function: RINGTONE_SYS_TickRing
 * address:  0x02029F8C
 * packet:   pkt_02029F6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   GFL_USE_StopSeSlot  0x020061F8  thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int GFL_USE_IsSeSlotBusy(u32 a0);
extern void GFL_USE_StopSeSlot(int a);
extern void GFL_USE_PlaySeInSlot(void *arg, int i);

int RINGTONE_SYS_TickRing(u16 *p)
{
    if (p[2] != 0) {
        p[2] = p[2] - 1;
    }
    if (p[2] == 0) {
        if (GFL_USE_IsSeSlotBusy(4) == 1) {
            GFL_USE_StopSeSlot(4);
        }
        return 0;
    }
    if (GFL_USE_IsSeSlotBusy(4) == 0) {
        GFL_USE_PlaySeInSlot((void *)0x662, 4);
    }
    return 1;
}
