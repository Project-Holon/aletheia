/*
 * function: EVENT_ID_AreSlotsClear
 * address:  0x0202F738
 * packet:   pkt_0202F498
 * region:   arm9
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 * symbols:
 *   POKE_TOOL_GetBoxValue  0x02017E88  thumb
 *   FILE_UTIL_Check12E4  0x020212E4  thumb
 */

typedef unsigned short u16;

typedef unsigned int   u32;
extern u32 POKE_TOOL_GetBoxValue(void *p, u32 id, u32 v);
extern u32 FILE_UTIL_Check12E4(u16 v);

int EVENT_ID_AreSlotsClear(void *p, int a1)
{
    int i;

    for (i = 0; i < 4; i++) {
        if (FILE_UTIL_Check12E4((u16)POKE_TOOL_GetBoxValue(p, i + 0x36, 0)) != 0) {
            return 0;
        }
    }
    return 1;
}
