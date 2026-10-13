/*
 * function: RINGTONE_SYS_OnWake
 * address:  0x02029FE4
 * packet:   pkt_02029FE4
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   gRingtone     0x02146944  data
 *   RINGTONE_SYS_PostEvent  0x0202A084  thumb
 *
 * ringtone_sys.c: forward the global ringtone state (gRingtone, set by
 * RINGTONE_SYS_Create) to RINGTONE_SYS_PostEvent with event 2, a pool-word tail call.
 * The two thunks 0x02029FD0 / 0x02029FE4 differ only in the event id.
 */

typedef unsigned int u32;

extern u32 *gRingtone;
extern void RINGTONE_SYS_PostEvent(u32 *state, int event);

void RINGTONE_SYS_OnWake(void)
{
    RINGTONE_SYS_PostEvent(gRingtone, 2);
}
