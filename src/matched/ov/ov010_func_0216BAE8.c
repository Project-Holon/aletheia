/*
 * function: FIELD_G3D_MAP_GetMissionHoursLeft
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
 *   func_0200E394 0x0200E394 thumb
 *   func_0200C0E8 0x0200C0E8 thumb
 *   func_0200C32C 0x0200C32C thumb
 *   FIELD_G3D_MAP_GetMissionElapsedHours 0x0216BB18 thumb ov010
 *   FIELD_G3D_MAP_GetMissionTimeLimitHours 0x0216BBC4 thumb ov010
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
extern void *func_0200E394(void *a0);
extern void *func_0200C0E8(void *sys);
struct Blk34;
extern u8 func_0200C32C(struct Blk34 *p);
extern int FIELD_G3D_MAP_GetMissionElapsedHours(void *sys);
extern int FIELD_G3D_MAP_GetMissionTimeLimitHours(int index);
u16 FIELD_G3D_MAP_GetMissionHoursLeft(int p)
{
    int index, elapsed, x;
    func_0200E394((void *)p);
    index = func_0200C32C(func_0200C0E8((void *)p));
    elapsed = FIELD_G3D_MAP_GetMissionElapsedHours((void *)p);
    x = (int)((u32)FIELD_G3D_MAP_GetMissionTimeLimitHours((u8)index) - (u32)elapsed);
    if (x < 0) x = 0;
    return (u16)x;
}
