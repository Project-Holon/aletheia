/*
 * function: FIELD_WFBC_DATA_LOCAL_MoveBoredPeopleToBackList
 * address:  0x02186470
 * packet:   pkt_ov020_02186470
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * note: 2026-10-05 (wD9r lane166): EXACT. The tests use the items local (items + i * 0x18), the body
 *   calls spell the address again as base + 8 + i * 0x18, as in the matched siblings ov010 02161DC4
 *   and ov020 021862A8 (a = p + 8 for the tests, p + 8 + i * 0x18 for the result). The second spelling
 *   is a separate invariant in the if body; LICM probably hoists it before the (u16)id conversion, so the
 *   items web is a late temp that interferes with id and takes r4 (a0 r4, id r5 as in the image).
 *
 * symbols:
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   EVENT_FIELD_PROCLINK_IsReturnEntryValid  0x02161ECC  thumb
 *   FIELD_WFBC_DATA_LOCAL_IsMoodZero  0x02186BA8  thumb
 *   ZONEDATA_IsZoneInTableDFEC  0x02013DE0  thumb
 *   FIELD_WFBC_DATA_LOCAL_PushPersonFront  0x02186B2C  thumb
 *   EVENT_FIELD_PROCLINK_ClearReturnEntry  0x02161E78  thumb
 *   EVENT_FIELD_PROCLINK_CompactReturnList  0x02161E60  thumb
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Rec44;
struct SaveBlock;
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern char *GAME_DATA_GetSecondUnionInfo(int a);
extern int EVENT_FIELD_PROCLINK_IsReturnEntryValid(char *p);
extern int FIELD_WFBC_DATA_LOCAL_IsMoodZero(u8 *p);
extern int ZONEDATA_IsZoneInTableDFEC(u16 a0);
extern char *FIELD_WFBC_DATA_LOCAL_PushPersonFront(char *p, char *src);
extern void EVENT_FIELD_PROCLINK_ClearReturnEntry(char *p);
extern void EVENT_FIELD_PROCLINK_CompactReturnList(char *p, int a);

void FIELD_WFBC_DATA_LOCAL_MoveBoredPeopleToBackList(int a0)
{
    char *q;
    u32 id;
    char *base;
    char *items;
    u16 key;
    int i;

    id = GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((struct SaveBlock *)a0));
    base = GAME_DATA_GetSecondUnionInfo(a0);
    i = 0;
    q = base + 0xF8;
    items = base + 8;
    key = id;
    for (; i < 10; i++) {
        if (EVENT_FIELD_PROCLINK_IsReturnEntryValid(items + i * 0x18) != 0 && FIELD_WFBC_DATA_LOCAL_IsMoodZero((u8 *)(items + i * 0x18)) != 0 && ZONEDATA_IsZoneInTableDFEC(key) == 0) {
            FIELD_WFBC_DATA_LOCAL_PushPersonFront(q, base + 8 + i * 0x18);
            EVENT_FIELD_PROCLINK_ClearReturnEntry(base + 8 + i * 0x18);
        }
    }
    EVENT_FIELD_PROCLINK_CompactReturnList(base, 0);
}
