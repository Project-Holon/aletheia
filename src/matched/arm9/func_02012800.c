/*
 * function: GAME_DATA_TakeUnionInfo
 * address:  0x02012800
 * packet:   pkt_02012800
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   EVENT_FIELD_PROCLINK_CheckZoneFlag  0x02161D64  thumb  ov010
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/GAME_DATA_TakeUnionInfo.c \
 *       --func GAME_DATA_TakeUnionInfo --addr 0x02012800 --cc 1.1p1 --thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed char s8;

extern void func_02082D44(void *dst, const void *src, u32 n);
extern int EVENT_FIELD_PROCLINK_CheckZoneFlag(int a0);

void GAME_DATA_TakeUnionInfo(u8 *obj, void *dst)
{
    func_02082D44(dst, obj + 0x214, 0x1e8);
    EVENT_FIELD_PROCLINK_CheckZoneFlag((int)(obj + 0x214));
}
