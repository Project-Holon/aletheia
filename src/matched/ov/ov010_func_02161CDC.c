/*
 * function: EVENT_FIELD_PROCLINK_StartCommProc
 * address: 0x02161CDC
 * packet: pkt_ov010_02161CDC
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * isa: thumb
 * status: EXACT
 * symbols:
 *   GF_STANDARD_GetCachedTime 0x0203F4CC arm
 *   COMM_PLAYER_SUPPORT_GetSeasonFromClock 0x0202E888 thumb
 *   EVENT_FIELD_PROCLINK_SetCommProcParam 0x02161C84 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned u32;
typedef struct { u32 hour, minute, second; } RtcTime;
typedef struct { u32 a,b,c; u8 d,e,f; u8 g:7; u8 h:1; } S;
struct RtcTime;
extern void GF_STANDARD_GetCachedTime(struct RtcTime *time);
extern u8 COMM_PLAYER_SUPPORT_GetSeasonFromClock(void);
extern void EVENT_FIELD_PROCLINK_SetCommProcParam(S *, int, int, u8, u32, u8, u8, u8);
void EVENT_FIELD_PROCLINK_StartCommProc(S *s, int a, int b, u8 d)
{
    RtcTime time;
    u8 day;
    GF_STANDARD_GetCachedTime((struct RtcTime *)(&time));
    day = COMM_PLAYER_SUPPORT_GetSeasonFromClock();
    EVENT_FIELD_PROCLINK_SetCommProcParam(s, a, b, d, 0, time.hour, time.minute, day);
}
