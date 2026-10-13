/*
 * function: WEATHER_STORM_UpdateThunder
 * address:  0x021EF950
 * packet:   pkt_ov026_021EF950
 * region:   ov026
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   func_020056EC  0x020056EC  thumb
 *   GFL_USE_GetSeSlot  0x02006148  thumb
 *   GFL_USE_IsSeSlotBusy  0x02006224  thumb
 *   WEATHER_TASK_PlaySeWithVoice  0x021A2604  thumb  ov021
 *   WEATHER_STORM_ResetThunderTimer  0x021EF93C  thumb  ov026
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;
typedef signed short   s16;

extern u32 func_020056EC(u32 v);
extern int GFL_USE_GetSeSlot(u32 a0);
extern int GFL_USE_IsSeSlotBusy(u32 a0);
extern void WEATHER_TASK_PlaySeWithVoice(u8 *p, int a, int b);
extern void WEATHER_STORM_ResetThunderTimer(s16 *p);

void WEATHER_STORM_UpdateThunder(int a, s16 *p, int c)
{
    if (c == 0) {
        return;
    }
    if (p[6] > p[7] - 0x4A) {
        return;
    }
    p[9]++;
    if (p[9] < p[10]) {
        return;
    }
    if (GFL_USE_IsSeSlotBusy(GFL_USE_GetSeSlot(0x71F)) == 0) {
        int t = func_020056EC(0x1B) + 0x64;
        WEATHER_TASK_PlaySeWithVoice((u8 *)a, 0x71E, t);
        WEATHER_STORM_ResetThunderTimer(p);
        return;
    }
    p[9] = p[10] - 10;
}
