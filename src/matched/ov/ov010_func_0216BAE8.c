/*
 * function: SCRCMD_RESEARCH_GetMissionHoursLeft
 * address: 0x0216BAE8
 * packet: pkt_ov010_0216BAE8
 * region: ov010
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * arithmetic: subtract in u32, then interpret the resulting sign bit as
 * target int before the BPL clamp; this preserves SUB wrapping without bounds.
 * interface: BB18's old file says void, but this caller loads p into r0
 * at 0216BAFC and BB18 forwards entry r0 to 0200C0F0; preserve that input.
 * symbols:
 *   SYMBOL_SAVE_GetBitBlock 0x0200E394 thumb
 *   BEACON_GetFromSave 0x0200C0E8 thumb
 *   BEACON_GetEntryCount 0x0200C32C thumb
 *   SCRCMD_RESEARCH_GetMissionElapsedHours 0x0216BB18 thumb ov010
 *   SCRCMD_RESEARCH_GetMissionTimeLimitHours 0x0216BBC4 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *SYMBOL_SAVE_GetBitBlock(void *a0);
extern void *BEACON_GetFromSave(void *sys);
struct Blk34;
extern u8 BEACON_GetEntryCount(struct Blk34 *p);
extern int SCRCMD_RESEARCH_GetMissionElapsedHours(void *sys);
extern int SCRCMD_RESEARCH_GetMissionTimeLimitHours(int index);
u16 SCRCMD_RESEARCH_GetMissionHoursLeft(int p)
{
    int index, elapsed, x;
    SYMBOL_SAVE_GetBitBlock((void *)p);
    index = BEACON_GetEntryCount(BEACON_GetFromSave((void *)p));
    elapsed = SCRCMD_RESEARCH_GetMissionElapsedHours((void *)p);
    x = (int)((u32)SCRCMD_RESEARCH_GetMissionTimeLimitHours((u8)index) - (u32)elapsed);
    if (x < 0) x = 0;
    return (u16)x;
}
