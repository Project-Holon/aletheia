/*
 * function: GAME_DATA_ClearUnionInfo
 * address:  0x0201281C
 * packet:   pkt_02012800
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_CheckZoneFlag  0x02161D64  thumb  ov010
 *   MI_CpuFill8  0x02082BCC  arm
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_ClearUnionInfo.c \
 *       --func GAME_DATA_ClearUnionInfo --addr 0x0201281C --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void MI_CpuFill8(void *dst, int c, u32 n);
extern int EVENT_FIELD_PROCLINK_CheckZoneFlag(int a0);

void GAME_DATA_ClearUnionInfo(u8 *obj)
{
    MI_CpuFill8(obj + 0x214, 0, 0x1e8);
    EVENT_FIELD_PROCLINK_CheckZoneFlag((int)(obj + 0x3fc));
}
