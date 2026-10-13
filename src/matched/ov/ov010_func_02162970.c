/*
 * function: EVENTDATA_SYSTEM_SearchBgEventScriptId
 * address:  0x02162970
 * packet:   pkt_ov010_02162970
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT*
 *
 * Finds the trigger that fires at a place: walks the 0x14-byte entries,
 * tests position (mode 0) or map cell (mode 1), then filters by entry
 * kind against the facing/type argument. Answers the entry id or 0xFFFF.
 *
 * Levers (2026-09-28 tree_ov010_4): one guarded body (single 0xFFFF
 * exit), the count held in a u32 local (a u16 local is re-read from its
 * spill slot before the guard), and case 5 as `type == 2 || type == 3`,
 * which 1.1p1 folds to a loop-hoisted `(u16)(type + 0xFFFE) <= 1`
 * (`(u16)(type - 2) <= 1` gives `subs #2` instead).
 *
 * symbols:
 *   EVENTDATA_SYSTEM_IsBgEventGridHit  0x02162E48  thumb  ov010
 *   EVENTDATA_SYSTEM_IsBgEventRailHit  0x02162E9C  thumb  ov010
 *   EVENTDATA_SYSTEM_GetHiddenItemFlag  0x02164708  thumb  ov010
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int s32;

typedef struct Trigger {
    u16 id;             /* 0x00 */
    u16 kind2;          /* 0x02 */
    u16 kind;           /* 0x04 */
    u16 mode;           /* 0x06 */
    s32 data[3];        /* 0x08 */
} Trigger;

typedef struct TriggerSet {
    u8 pad00[0x12];
    u16 count;          /* 0x12 */
    u8 pad14[8];
    Trigger *list;      /* 0x1C */
} TriggerSet;

struct CellKey;
struct VecFx32;
extern int EVENTDATA_SYSTEM_IsBgEventGridHit(struct Trigger *t, const struct VecFx32 *pos);
extern int EVENTDATA_SYSTEM_IsBgEventRailHit(struct Trigger *t, const struct CellKey *k);
extern u16 EVENTDATA_SYSTEM_GetHiddenItemFlag(u16 id);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);

u16 EVENTDATA_SYSTEM_SearchBgEventScriptId(TriggerSet *set, void *flags, const void *where, u16 type)
{
    Trigger *t;
    u16 i;
    u32 count;

    t = set->list;
    if (t != 0) {
    count = set->count;
    for (i = 0; i < count; i++, t++) {
        if (t->mode == 0) {
            if (!EVENTDATA_SYSTEM_IsBgEventGridHit(t, where))
                continue;
        } else {
            if (!EVENTDATA_SYSTEM_IsBgEventRailHit(t, where))
                continue;
        }
        if (t->kind2 == 2) {
            if (ZONEDATA_CheckEventFlag(flags, EVENTDATA_SYSTEM_GetHiddenItemFlag(t->id)) == 0)
                return t->id;
            continue;
        }
        switch (t->kind) {
        case 0:
            if (type == 0)
                return t->id;
            break;
        case 1:
            if (type == 3)
                return t->id;
            break;
        case 2:
            if (type == 2)
                return t->id;
            break;
        case 3:
            if (type == 1)
                return t->id;
            break;
        case 4:
            return t->id;
        case 5:
            if (type == 2 || type == 3)
                return t->id;
            break;
        case 6:
            if (type <= 1)
                return t->id;
            break;
        }
    }
    }
    return 0xFFFF;
}
