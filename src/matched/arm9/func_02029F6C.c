/*
 * function: RINGTONE_SYS_RegisterSleepCallbacks
 * address:  0x02029F6C
 * packet:   pkt_02029F6C
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * blocker:  02029FD0 label
 * blocker:  02029FE4 label
 *
 * symbols:
 *   RINGTONE_SYS_OnSleep  0x02029FD0  thumb
 *   RINGTONE_SYS_OnWake  0x02029FE4  thumb
 *   UI_SetResumeAndSuspendHooks  0x0203508C  arm
 *   gRingtone     0x02146944  data
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;


extern u32  gRingtone;
extern void RINGTONE_SYS_OnSleep(void);
extern void RINGTONE_SYS_OnWake(void);
extern void UI_SetResumeAndSuspendHooks(u32 a, u32 b, u32 c);

void RINGTONE_SYS_RegisterSleepCallbacks(void)
{
    if (gRingtone != 0) {
        UI_SetResumeAndSuspendHooks((u32)((void *)RINGTONE_SYS_OnSleep), (u32)((void *)RINGTONE_SYS_OnWake), gRingtone);
    }
}
