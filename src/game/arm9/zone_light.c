/*
 * file:     zone_light.c
 * unit:     yes
 * function: ZONEDATA_GetTimeLightColors, ZONEDATA_GetLightTableMember, ZONEDATA_LoadLightTable, ZONEDATA_FindLightEntryColors
 * address:  0x0201493C
 * region:   arm9
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Cut from mcss.c by tools/splitfile.py.
 *
 * symbols:
 *   ZONEDATA_GetLightId  0x02013F2C  thumb
 *   ZONEDATA_GetAreaId  0x02013B38  thumb
 *   ZONEDATA_CreateAreaData  0x0201407C  thumb
 *   ZONEDATA_GetAreaLightType  0x020140DC  thumb
 *   ZONEDATA_DeleteAreaData  0x020140B4  thumb
 *   GFL_HEAP_Free   0x020307B0  arm
 *   sub_0209E054_Map  0x0209E054  data
 *   ARC_TOOL_GetMemberSize       0x020490A8  arm
 *   ARC_TOOL_LoadMember       0x02048F60  arm
 *   VEC_Fx16Normalize   0x0207CDB8  arm
 *   TIMEZONE_GetLight  0x02011400  thumb
 *   _u32_div_f                   0x0209C2B0  arm
 */
#include "field_status_shared_types.h"
#include "zone_light_shared_types.h"

/* One 0x34-byte record of the time-of-day light table. */
struct LightTableEntry {
    u16 hourKey;                        /* 0x00 */
    s16 minute;                         /* 0x02 */
    u8  pad0[4];
    u16 colorA[4];                      /* 0x08 */
    s16 dir[4][3];                      /* 0x10 */
    u16 colorB[4];                      /* 0x28 */
    u8  pad1[4];
};

extern u32 ZONEDATA_GetLightId(u32 id);

extern u32 ZONEDATA_GetAreaId(u32 id);

extern void *ZONEDATA_CreateAreaData(u16 heap, u32 zoneLightId, u32 season);
struct AreaData;

extern u8 ZONEDATA_GetAreaLightType(struct AreaData *areaData);

extern u32 ZONEDATA_DeleteAreaData(struct AreaData *areaData);

extern u32 GFL_HEAP_Free(void *p);

extern u32   ARC_TOOL_GetMemberSize(u32 archive, u32 member);

extern void *ARC_TOOL_LoadMember(u32 archive, u32 member, u32 heap);

extern void  VEC_Fx16Normalize(void *dest, const void *src);

extern u8 TIMEZONE_GetLight(int season, int key);

void ZONEDATA_GetTimeLightColors(u32 zoneId, u32 hour, u32 minute, u32 lightTableId, u32 season, u16 *outColors, u16 heapId);

u16 ZONEDATA_GetLightTableMember(u32 index);

void *ZONEDATA_LoadLightTable(u32 archive, u32 member, u32 *countOut, u32 heap);

void ZONEDATA_FindLightEntryColors(u8 *table, u32 count, s32 time, u32 season, u16 *out);

extern u32 sub_0209E054_Map[];

/*
 * The three-way fallback load of the 0x34-byte time-of-day table (member
 * 0x3e for an explicit id, 0x52 for the id ZONEDATA_GetLightId maps, else 0x3d
 * built through ZONEDATA_CreateAreaData), then ZONEDATA_FindLightEntryColors over it and a free.
 *
 * Closed in wave 13 by the declaration, not the body: the seventh
 * parameter is a u16 heap id (the ov094 caller at 0x021F7702 loads it
 * with ldrh), written `(heap & 0x7fff) | 0x8000` at each of the four
 * uses.  The earlier note (docs/notes/pkt_0201493C.c.txt) read it as the
 * low half of a word through `*(u16 *)((char *)&b0 + 8)` and had to spell
 * the first tag as 0x10000000; with the real parameter type both of its
 * "back-end tie-breaks" (the pooled 0x0FFFFFFF + 1 tag and the late b0
 * reload) disappear.
 */
void ZONEDATA_GetTimeLightColors(u32 zoneId, u32 hour, u32 minute, u32 lightTableId,
                   u32 season, u16 *outColors, u16 heapId)
{
    u32 count;
    void *table = 0;
    s32 hourSeconds;
    s32 minuteSeconds;

    minuteSeconds = minute * 0x3c;
    hourSeconds = hour * 0xe10;

    if (lightTableId != 0) {
        table = ZONEDATA_LoadLightTable(0x3e, ZONEDATA_GetLightTableMember(lightTableId), &count, (u16)((heapId & 0x7fff) | 0x8000));
    }
    if (table == 0) {
        u32 mapped = ZONEDATA_GetLightId((u16)zoneId);
        if (mapped != 0xfffffff)
            table = ZONEDATA_LoadLightTable(0x52, mapped, &count, (u16)((heapId & 0x7fff) | 0x8000));
    }
    if (table == 0) {
        void *zoneLight = ZONEDATA_CreateAreaData((heapId & 0x7fff) | 0x8000, ZONEDATA_GetAreaId((u16)zoneId), season);
        table = ZONEDATA_LoadLightTable(0x3d, ZONEDATA_GetAreaLightType(zoneLight), &count, (u16)((heapId & 0x7fff) | 0x8000));
        ZONEDATA_DeleteAreaData((void *)zoneLight);
    }
    ZONEDATA_FindLightEntryColors(table, count, minuteSeconds + hourSeconds, season, outColors);
    GFL_HEAP_Free(table);
}

u16 ZONEDATA_GetLightTableMember(u32 i)
{
    return sub_0209E054_Map[i];
}

/*
 * Load a record table out of an archive sub-file: the sub-file's byte size
 * divided by 0x34 is the record count (unsigned divide, `_u32_div_f`), the
 * count is handed back through a3's slot and the block itself is loaded by
 * ARC_TOOL_LoadMember.  Each 0x34-byte record carries four 6-byte vectors at +0x10
 * (a VecFx16 triple plus a spare halfword) and each is normalized in place
 * before the count is returned.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ZONEDATA_LoadLightTable.c \
 *       --func ZONEDATA_LoadLightTable --addr 0x02014A20 --cc 1.1p1 --thumb
 */
void *ZONEDATA_LoadLightTable(u32 archive, u32 member, u32 *countOut, u32 heap)
{
    u32 recordCount;
    u32 recordIdx;
    u8 *dir;
    u8 *table;
    int dirIdx;

    recordCount = ARC_TOOL_GetMemberSize(archive, member) / 0x34;
    *countOut = recordCount;
    table = ARC_TOOL_LoadMember(archive, member, heap);
    for (recordIdx = 0; recordIdx < recordCount; recordIdx++) {
        dir = table + recordIdx * 0x34 + 0x10;
        for (dirIdx = 0; dirIdx < 4; dirIdx++) {
            VEC_Fx16Normalize(dir + dirIdx * 6, dir + dirIdx * 6);
        }
    }
    return table;
}

/*
 * Scans the 0x34-byte-stride table at a0 for the element whose 3600*hour +
 * 60*minute value first climbs past a2 while the best so far is still at or
 * below it, then returns that element's eight halfword fields through the
 * caller's buffer (the four at +8 and the four at +0x28).
 *
 * Shape notes:
 *  - the index runs from 0 and the loop is entered only when a1 != 0, so the
 *    counter's first comparison sits at the bottom (`cmp r4, a1 / blo`) and
 *    the guard at the top is a bare `adds r0, r1, #0 / beq`);
 *  - the element's +2 field is signed (`ldrsh` with a register offset,
 *    docs/idioms/ldrsh-register-offset-is-signedness.md), which is why both
 *    comparisons on the running value are `bgt`;
 *  - `i % a1` is one call to the unsigned divmod helper with the remainder
 *    read out of r1, so the source must stay a modulo expression and not a
 *    hand-rolled subtraction loop;
 *  - the two products are two statements (`v = 0xE10 * ...; v += ...;`).
 *    Written as one expression mwcc evaluates the s16 arm first and the
 *    15-byte window at +0x2C comes out in the other order.
 *
 * Verified with:
 *   python tools/match.py one --src src/matched/ZONEDATA_FindLightEntryColors.c \
 *       --func ZONEDATA_FindLightEntryColors --addr 0x02014A80 --cc 1.1p1 --thumb
 */
void ZONEDATA_FindLightEntryColors(u8 *table, u32 count, s32 time, u32 season, u16 *out)
{
    u32 i;
    s32 prevTime;
    s32 entryTime;
    u32 chosen;
    struct LightTableEntry *e;

    prevTime = 0;
    i = 0;
    if (count != 0) {
        do {
            e = (struct LightTableEntry *)(table + i * 0x34);
            entryTime = 0xE10 * (s32)TIMEZONE_GetLight(season, e->hourKey);
            entryTime += e->minute * 0x3C;
            if (prevTime <= time && entryTime > time) {
                break;
            }
            prevTime = entryTime;
            i++;
        } while (i < count);
    }

    chosen = i % count;
    e = (struct LightTableEntry *)(table + chosen * 0x34);
    out[0] = e->colorA[0];
    out[1] = e->colorA[1];
    out[2] = e->colorA[2];
    out[3] = e->colorA[3];
    out[4] = e->colorB[0];
    out[5] = e->colorB[1];
    out[6] = e->colorB[2];
    out[7] = e->colorB[3];
}
