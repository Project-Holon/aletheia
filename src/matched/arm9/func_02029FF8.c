/*
 * function: RINGTONE_SYS_StartRing
 * address:  0x02029FF8
 * packet:   pkt_02029F6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   GFL_USE_PlaySeInSlot  0x0200616C  thumb
 */

typedef unsigned short u16;
typedef unsigned int   u32;

extern int GFL_USE_IsSeSlotBusy(u32 a0);
extern void GFL_USE_PlaySeInSlot(void *arg, int i);

void RINGTONE_SYS_StartRing(u16 *p)
{
    if (GFL_USE_IsSeSlotBusy(4) == 0) {
        GFL_USE_PlaySeInSlot((void *)0x662, 4);
    }
    p[2] = 0x384;
}
