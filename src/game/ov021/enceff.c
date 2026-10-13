/*
 * file:     enceff.c
 * unit:     yes
 * function: func_021CF45C, func_021CF480, func_021CF498, func_021CF51C, func_021CF520, func_021CF52C, func_021CF54C, func_021CF560, func_021CF564, func_021CF580, func_021CF59C, func_021CF5AC, func_021CF5D8, func_021CF748, func_021CF7DC, func_021CF844, func_021CF8E4, func_021CF940, func_021CF9AC, func_021CFA04, func_021CFA1C, func_021CFA58, func_021CFA88, func_021CFAC0, func_021CFB1C, func_021CFB68, func_021CFBA8, func_021CFC14, func_021CFC4C, func_021CFC80, func_021CFCF4, func_021CFD08, func_021CFD88, func_021CFDBC, func_021CFEA0, func_021CFEF0, func_021CFF28, func_021CFF78, func_021CFFDC, func_021D0014, func_021D004C, func_021D0084, func_021D00B8, func_021D0114
 * address:  0x021CF45C
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 * Split from trial_house.c at 0x021CEDA0 (lane L136, __FILE__ anchor enceff.c at 021CF45C/021CF52C (d_021DE5FC); 021CEDA0..021D0114 are its helpers and the ov010 script command handlers that use them).
 *
 * symbols:
 *   func_0201F02C  0x0201F02C  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_0201EE0C  0x0201EE0C  thumb
 *   func_02045808  0x02045808  arm
 *   d_021DE5FC     0x021DE5FC  data  ov021  a4
 *   func_02030734  0x02030734  arm
 *   func_020307B0  0x020307B0  arm
 *   func_02188C80  0x02188C80  thumb  ov021
 *   func_0203038C  0x0203038C  arm
 *   func_02012374  0x02012374  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_021DB4FC     0x021DB4FC  data  a4
 *   func_02034AC4  0x02034AC4  arm
 *   abs_id_4b      0x0000004B  data
 *   abs_id_4d      0x0000004D  data
 *   ov075_id       0x0000004B  data
 *   func_02034A5C  0x02034A5C  arm
 *   func_02188C9C  0x02188C9C  thumb  ov021
 *   func_02013E40  0x02013E40  thumb
 *   func_02188CB4  0x02188CB4  thumb  ov021
 *   func_021A30C8  0x021A30C8  thumb  ov021
 *   func_021AB0F0  0x021AB0F0  thumb  ov021
 *   func_021AB0F8  0x021AB0F8  thumb  ov021
 *   func_021AB2BC  0x021AB2BC  thumb  ov021
 *   func_021AB364  0x021AB364  thumb  ov021
 *   func_021AB37C  0x021AB37C  thumb  ov021
 *   func_0202A230  0x0202A230  thumb
 *   func_0202A3FC  0x0202A3FC  thumb
 *   func_0202A3D8  0x0202A3D8  thumb
 *   func_02188D58  0x02188D58  thumb  ov021
 *   func_020140D8  0x020140D8  thumb
 *   d_021DB7E0     0x021DB7E0  data  ov021  a2
 *   d_021DB7F6     0x021DB7F6  data  ov021  a1
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_02159AE8  0x02159AE8  thumb  ov010
 *   func_0215897C  0x0215897C  thumb  ov010
 *   func_020122C0  0x020122C0  thumb
 *   func_02012944  0x02012944  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020124E4  0x020124E4  thumb
 *   func_020120F4  0x020120F4  thumb
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C  0x02017E1C  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_020079BC  0x020079BC  thumb
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BAC8  0x0200BAC8  thumb
 *   func_0200BBEC  0x0200BBEC  thumb
 *   func_02017E88  0x02017E88  thumb
 *   func_0201210C  0x0201210C  thumb
 *   func_02188D24  0x02188D24  thumb  ov021
 *   func_021BB990  0x021BB990  thumb  ov021
 *   abs_id_39      0x00000039  data
 *   d_021F3900     0x021F3900  data  ov057  a4
 *   func_02008854  0x02008854  thumb
 *   func_02008990  0x02008990  thumb
 *   d_021DB834  0x021DB834  data  a4
 *   func_021587B0  0x021587B0  thumb  ov010
 *   func_02159058  0x02159058  thumb  ov010
 *   func_02158F74  0x02158F74  thumb  ov010
 *   func_02045994  0x02045994  arm
 *   func_0200BE48  0x0200BE48  thumb
 *   func_02009470  0x02009470  thumb
 *   func_0200E878  0x0200E878  thumb
 *   func_02012F38  0x02012F38  thumb
 *   func_02009634  0x02009634  thumb
 *   func_0200973C  0x0200973C  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008554  0x02008554  thumb
 *   func_02008550  0x02008550  thumb
 *   func_02025C74  0x02025C74  thumb
 *   func_02025B64  0x02025B64  thumb
 *   func_0201F048  0x0201F048  thumb
 *   func_02008570  0x02008570  thumb
 *   func_0201F094  0x0201F094  thumb
 *   func_0201EE60  0x0201EE60  thumb
 *   func_02009628  0x02009628  thumb
 *   func_0201F198  0x0201F198  thumb
 *   func_02159B10  0x02159B10  thumb  ov010
 *   func_02009590  0x02009590  thumb
 *   sub_020095C8  0x020095C8  thumb
 *   func_02009698  0x02009698  thumb
 *   sub_020095FC  0x020095FC  thumb
 *   sub_02009618  0x02009618  thumb
 *   func_02011330  0x02011330  thumb
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef signed short s16;

struct GameSystem;
struct GameData;
struct GameEvent;
struct FieldMap;
struct FieldPlayer;
struct ScriptVm;
struct ScrcmdWork;
struct ScriptWork;
struct SaveControl;
struct WordSet;
struct Strbuf;
struct PokeParty;
struct PokemonParam;
struct BoxData;
struct BattleBoxSave;
struct WifiHistory;
struct HistoryEntry;
struct PlayerLocation;
struct MyStatus;

/* Encounter effect (ENCEFF): one effect plays before a battle. */
struct EncEffWork;
typedef void (*EncEffUpdateFunc)(struct EncEffWork *eff, u32 self, u32 arg0, u32 arg1);

/* Work of one running effect (0x20 bytes). */
typedef struct EncEffWork {
    struct GameEvent *effect;    /* 0x00: effect event made by the builder */
    EncEffUpdateFunc update;     /* 0x04 */
    struct FieldMap *fieldMap;   /* 0x08 */
    u32 overlayIds[3];           /* 0x0C: overlays loaded for this effect */
    int overlayCount;            /* 0x18 */
    void *effectWork;            /* 0x1C: memory owned by the effect */
} EncEffWork;

/* One row of the effect table (0x14 bytes, ENCEFF_KIND_COUNT rows). */
typedef struct EncEffEntry {
    struct GameEvent *(*build)(struct GameSystem *gameSystem, struct FieldMap *fieldMap, u32 arg);   /* 0x00 */
    EncEffUpdateFunc update;                                /* 0x04 */
    int overlayId;                                          /* 0x08: -1 for none */
    u32 buildArg;                                           /* 0x0C */
    u32 minLevel;                                           /* 0x10 */
} EncEffEntry;

enum {
    ENCEFF_KIND_COUNT = 0x25,
    ENCEFF_KIND_FALLBACK = 7,
    ENCEFF_MAX_OVERLAYS = 3
};

/* Pokemon data ids read through the party, box and battle box getters. */
enum {
    MON_DATA_OT_ID = 7,
    MON_DATA_IS_EGG = 0x4C,
    MON_DATA_HAS_SPECIES = 0xA9
};

enum {
    BOX_COUNT = 0x18,
    BOX_SLOT_COUNT = 30,
    BATTLE_BOX_SLOT_COUNT = 6
};

/* Distinct original-trainer ids found so far (0xCC bytes). */
#define OT_ID_LIST_MAX 50
typedef struct OtIdList {
    int count;
    int ids[OT_ID_LIST_MAX];
} OtIdList;

/* Work of the original-trainer count task (0xD8 bytes allocated). */
typedef struct OtCountTask {
    u32 playerId;       /* 0x00: own trainer id, never counted */
    int nextBox;        /* 0x04: next PC box to scan */
    u16 *result;        /* 0x08: script variable that receives the count */
    OtIdList list;      /* 0x0C */
} OtCountTask;

/* A gift left by an Entralink visitor, shown at a map spot (0x14 bytes). */
typedef struct IntrudeOfferSlot {
    u16 senderName[8];  /* 0x00 */
    u16 offerId;        /* 0x10: 0 for an empty slot */
    u8 spotIndex;       /* 0x12: row of the spot table */
    u8 reserved13;
} IntrudeOfferSlot;

#define INTRUDE_OFFER_SLOT_COUNT 20
typedef struct IntrudeOfferLog {
    u8 header[0x10];
    IntrudeOfferSlot slot[INTRUDE_OFFER_SLOT_COUNT];
} IntrudeOfferLog;

/* Where an offer waits: tile position and zone (8 bytes per row). */
typedef struct IntrudeOfferSpot {
    s16 x;
    s16 y;
    s16 z;
    u16 zoneId;
} IntrudeOfferSpot;

/* Up to five Wi-Fi history partners with the same language (16 bytes, synced with the save). */
#define PARTNER_CANDIDATE_MAX 5
typedef struct PartnerCandidates {
    u8 language;                              /* 0x00 */
    u8 count;                                 /* 0x01 */
    u8 mode;                                  /* 0x02 */
    u8 viewId[PARTNER_CANDIDATE_MAX];         /* 0x03: trainer view of the partner */
    u8 historyIndex[PARTNER_CANDIDATE_MAX];   /* 0x08: entry in the Wi-Fi history */
    u8 reserved0D[3];
} PartnerCandidates;

enum {
    WIFI_HISTORY_ENTRY_COUNT = 20,
    WIFI_HISTORY_FIELD_MARKED = 5,
    WIFI_HISTORY_FIELD_INFO = 6
};

extern u32 func_020307B0(void *work);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 line);
extern struct GameSystem *func_02188C80(struct FieldMap *fieldMap);
extern u32 func_0203038C(u32 key);
extern void func_02012374(struct GameEvent *parent, struct GameEvent *child);
extern void *func_020124E8(struct GameEvent *event);
extern int func_02034AC4(s32 overlayId);
extern void func_02034A5C(s32 overlayId);
extern u16 func_02188C9C(struct FieldMap *fieldMap);
extern u16 func_02013E40(u32 zoneId);
extern struct FieldPlayer *func_02188CB4(struct FieldMap *fieldMap);
extern u32 func_021A30C8(struct FieldPlayer *player);
extern u16 func_021AB0F0(u32 attr);
extern u16 func_021AB0F8(u32 attr);
extern int func_021AB2BC(u16 tileType);
extern int func_021AB364(u16 tileType);
extern int func_021AB37C(u32 tileType);
extern u32 func_0202A230(void *trainerData, u32 index);
extern u8 func_0202A3FC(u32 trainerClass);
extern u8 func_0202A3D8(u32 trainerClass);
extern u32 func_02188D58(struct FieldMap *fieldMap);
extern u8 func_020140D8(u32 areaData);
extern struct GameSystem *func_0215A5DC(struct ScrcmdWork *cmdWork);
extern struct GameData *func_0215A5E4(struct ScrcmdWork *cmdWork);
extern struct ScriptWork *func_0215A5F4(struct ScrcmdWork *cmdWork);
extern u16 *func_02159AE8(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern u16 func_02159B10(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
extern u16 func_02011330(struct ScriptVm *vm);
extern void func_0215897C(struct ScriptWork *scriptWork, struct GameEvent *event);
extern struct GameEvent *func_020122C0(struct GameSystem *gameSystem, void *parent, void *func, u32 workSize);
extern struct GameSystem *func_020124E4(struct GameEvent *event);
extern struct GameData *func_020120F4(struct GameSystem *gameSystem);
extern struct FieldMap *func_0201210C(struct GameSystem *gameSystem);
extern struct MyStatus *func_02012944(struct GameData *gameData);
extern struct SaveControl *func_02012EBC(struct GameData *gameData);
extern PartnerCandidates *func_02012F38(struct GameData *gameData);
extern struct PokeParty *func_02012934(struct GameData *gameData);
extern struct BoxData *func_0201293C(struct GameData *gameData);
extern u32 func_02008530(const void *myStatus);
extern u8 func_0200856C(const void *myStatus);
extern u8 func_02008554(const void *myStatus);
extern u8 func_02008550(const void *myStatus);
extern u8 func_02008570(const void *myStatus);
extern u32 func_0201AA18(struct PokeParty *party);
extern struct PokemonParam *func_0201AB28(struct PokeParty *party, u32 index);
extern u32 func_02017E1C(struct PokemonParam *mon, u32 dataId, u32 arg);
extern int func_020079BC(struct BoxData *boxData, u32 box, u32 slot, int dataId, int arg);
extern struct BattleBoxSave *func_0200BAC8(struct SaveControl *saveControl);
extern struct PokemonParam *func_0200BBEC(struct BattleBoxSave *battleBox, u32 team, u32 slot);
extern u32 func_02017E88(struct PokemonParam *mon, u32 dataId, u32 arg);
extern int *func_021BB990(int overlayId, int *mapFunc, const int *procData);
extern u32 func_02188D24(struct FieldMap *fieldMap);
extern struct PlayerLocation *func_02008854(struct SaveControl *saveControl);
extern u16 func_02008990(const struct PlayerLocation *location);
extern IntrudeOfferLog *func_0200BE48(struct SaveControl *saveControl);
extern struct ScriptWork *func_021587B0(struct GameEvent *event, int scriptId, int arg1, int heapId);
extern void func_02159058(struct ScriptWork *scriptWork, int param0, int param1, int param2, u16 param3);
extern struct WordSet *func_02158F74(struct ScriptWork *scriptWork);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02045994(struct Strbuf *dest, const u16 *src, u32 length);
extern void func_02045808(struct Strbuf *str);
extern void func_0201EE0C(struct WordSet *wordSet, u32 index, const struct Strbuf *src, u32 a, u32 b, u32 c);
extern struct WifiHistory *func_02009470(struct SaveControl *saveControl);
extern struct HistoryEntry *func_0200973C(struct WifiHistory *history, int index);
extern u32 func_02009634(const struct WifiHistory *history, u32 index, u32 field);
extern u8 func_02009628(const struct WifiHistory *history);
extern u8 func_02009590(struct WifiHistory *history, struct MyStatus *myStatus, u32 arg);
extern u8 sub_020095C8(const struct WifiHistory *history);
extern void func_02009698(struct WifiHistory *history, int index, u32 field, u32 value);
extern void sub_020095FC(struct WifiHistory *history, int value);
extern void sub_02009618(struct WifiHistory *history, int value);
extern int func_0200E878(PartnerCandidates *candidates);
extern u32 func_02025C74(u32 outfit);
extern u8 func_02025B64(u32 language);
extern void func_0201F048(struct WordSet *wordSet, u32 index, u32 number);
extern void func_0201F094(struct WordSet *wordSet, u32 index, u32 a, u32 number);
extern void func_0201F02C(struct WordSet *wordSet, u32 index, const void *myStatus);
extern void func_0201EE60(struct WordSet *wordSet, u32 index, u16 value);
extern void func_0201F198(struct WordSet *wordSet, u32 index, u32 value);
extern void func_0201EFA4(struct WordSet *wordSet, u32 index, u32 a, u32 b, u32 c, u32 d);

extern char d_021DE5FC[];
extern char abs_id_4b[];
extern char abs_id_4d[];
extern unsigned char ov075_id[];
extern const EncEffEntry d_021DB4FC[];
extern const u16 d_021DB7E0[];
extern const u8 d_021DB7F6[];
extern char abs_id_39[];
extern char d_021F3900[];
extern const IntrudeOfferSpot d_021DB834[];

EncEffWork *func_021CF45C(u32 heapId, struct FieldMap *fieldMap);
int func_021CF480(EncEffWork *eff);
void func_021CF498(EncEffWork *eff, struct GameEvent *parentEvent, int kind);
struct GameEvent *func_021CF51C(EncEffWork *eff);
void func_021CF520(EncEffWork *eff, u32 unused, u32 arg0, u32 arg1);
void func_021CF52C(EncEffWork *eff, u32 size, u32 heapId);
void func_021CF54C(EncEffWork *eff);
void *func_021CF560(EncEffWork *eff);
void func_021CF564(EncEffWork *eff, u32 overlayId);
void func_021CF580(EncEffWork *eff);
void func_021CF59C(EncEffWork *eff);
void func_021CF5AC(EncEffWork *eff);
void func_021CF5D8(int species, int effectId, int hasWildOpponent, struct FieldMap *fieldMap, u32 *outEffectKind, u16 *outBgmId);
void func_021CF748(void *trainerData, struct FieldMap *fieldMap, int *outEffectKind, u16 *outBgmId);
int func_021CF7DC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021CF844(struct GameEvent *event, int *seq, OtCountTask *task);
int func_021CF8E4(u32 playerId, struct GameData *gameData, OtIdList *list);
int func_021CF940(u32 playerId, struct GameData *gameData, u32 box, OtIdList *list);
int func_021CF9AC(u32 playerId, struct GameData *gameData, u32 team, OtIdList *list);
int func_021CFA04(int playerId, int otId, OtIdList *list);
int func_021CFA1C(int otId, OtIdList *list);
int func_021CFA58(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021CFA88(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021CFAC0(IntrudeOfferLog *log, int zoneId, int x, int y, int z);
void func_021CFB1C(IntrudeOfferLog *log, int index, IntrudeOfferSlot *dest);
const IntrudeOfferSpot *func_021CFB68(IntrudeOfferLog *log, int *index);
int func_021CFBA8(struct GameEvent *event, u32 seq, const IntrudeOfferSlot *offer);
struct GameEvent *func_021CFC14(struct GameSystem *gameSystem, u32 heapId, int slotIndex);
void func_021CFC4C(struct GameSystem *gameSystem, int language, u32 mode);
void func_021CFC80(struct WifiHistory *history, PartnerCandidates *out, u32 language, u32 mode);
u8 func_021CFCF4(PartnerCandidates *candidates, u32 index);
int func_021CFD08(struct WordSet *wordSet, struct GameSystem *gameSystem, PartnerCandidates *candidates, int index, u32 variant);
int func_021CFD88(int outfitVariant, u32 trainerId, u32 tier, int variant, int isSpecialLanguage);
void func_021CFDBC(struct WordSet *wordSet, struct GameData *gameData, u32 historyIndex);
int func_021CFEA0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021CFEF0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021CFF28(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021CFF78(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021CFFDC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D0014(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D004C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D0084(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D00B8(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);
int func_021D0114(struct ScriptVm *vm, struct ScrcmdWork *cmdWork);

EncEffWork *func_021CF45C(u32 heapId, struct FieldMap *fieldMap)
{
    EncEffWork *eff = func_02030734(heapId, sizeof(EncEffWork), 1, d_021DE5FC, 0x6c);

    eff->fieldMap = fieldMap;
    eff->overlayCount = 0;
    return eff;
}

int func_021CF480(EncEffWork *eff)
{
    func_021CF54C(eff);
    func_021CF5AC(eff);
    return func_020307B0(eff);
}

/* Builds the effect of kind idx from the table, loading its overlay first. */
void func_021CF498(EncEffWork *eff, struct GameEvent *parentEvent, int kind)
{
    struct GameEvent *effect;
    struct GameSystem *gameSystem;
    struct FieldMap *fieldMap = eff->fieldMap;

    gameSystem = func_02188C80(fieldMap);
    if (kind >= ENCEFF_KIND_COUNT) {
        kind = 0;
    }
    if (func_0203038C(0x15) < d_021DB4FC[kind].minLevel) {
        kind = ENCEFF_KIND_FALLBACK;
    }
    if (d_021DB4FC[kind].overlayId != -1) {
        func_021CF564(eff, d_021DB4FC[kind].overlayId);
    }
    effect = d_021DB4FC[kind].build(gameSystem, fieldMap, d_021DB4FC[kind].buildArg);
    func_02012374(parentEvent, effect);
    eff->effect = func_020124E8(effect);
    eff->update = d_021DB4FC[kind].update;
}

struct GameEvent *func_021CF51C(EncEffWork *eff)
{
    return eff->effect;
}

/* Calls the update function of the effect, if it has one. */
void func_021CF520(EncEffWork *eff, u32 unused, u32 arg0, u32 arg1)
{
    if (eff->update != 0) {
        eff->update(eff, (u32)eff->update, arg0, arg1);
    }
}

void func_021CF52C(EncEffWork *eff, u32 size, u32 heapId)
{
    eff->effectWork = func_02030734(heapId, size, 1, d_021DE5FC, 0xe3);
}

void func_021CF54C(EncEffWork *eff)
{
    void *work = eff->effectWork;
    if (work != 0) {
        func_020307B0(work);
        eff->effectWork = 0;
    }
}

void *func_021CF560(EncEffWork *eff)
{
    return eff->effectWork;
}

/* Loads an overlay and remembers its id for the unload. */
void func_021CF564(EncEffWork *eff, u32 overlayId)
{
    func_02034AC4(overlayId);
    eff->overlayIds[eff->overlayCount++] = overlayId;
}

void func_021CF580(EncEffWork *eff)
{
    func_021CF564(eff, (u32)abs_id_4b);
    func_021CF564(eff, (u32)abs_id_4d);
}

void func_021CF59C(EncEffWork *eff)
{
    func_021CF564(eff, (u32)ov075_id);
}

/* Unloads the overlays in reverse order. */
void func_021CF5AC(EncEffWork *eff)
{
    int i;

    if (eff->overlayCount > 0) {
        while (eff->overlayCount > 0) {
            i = eff->overlayCount - 1;
            if (eff->overlayIds[i] != 0) {
                func_02034A5C(eff->overlayIds[i]);
            }
            eff->overlayCount--;
        }
    }
}

/*
 * Picks the effect kind (index into the effect table) and the battle BGM
 * for a battle against a wild or scripted opponent. Legendary species have
 * their own kinds; other battles depend on the tile the player stands on.
 */
void func_021CF5D8(int species, int effectId, int hasWildOpponent, struct FieldMap *fieldMap, u32 *outEffectKind, u16 *outBgmId)
{
    u32 attr;
    u16 tileType;
    u16 parentZoneId;
    u32 effectKind;
    u16 bgmId;

    parentZoneId = func_02013E40(func_02188C9C(fieldMap));
    switch (species) {
    case 0x23B:
        *outBgmId = 0x469;
        *outEffectKind = 0x23;
        return;
    case 0x283:
        *outBgmId = 0x474;
        *outEffectKind = 0x20;
        return;
    case 0x284:
        *outBgmId = 0x475;
        *outEffectKind = 0x20;
        return;
    case 0x286:
        *outBgmId = 0x476;
        *outEffectKind = 0x20;
        return;
    case 0x27D:
        *outBgmId = 0x468;
        *outEffectKind = 0x1f;
        return;
    case 0x1EE:
        *outBgmId = 0x478;
        *outEffectKind = 0x1f;
        return;
    case 0x27E:
    case 0x27F:
    case 0x280:
    case 0x287:
        *outBgmId = 0x478;
        *outEffectKind = 0x22;
        return;
    case 0x281:
    case 0x282:
    case 0x285:
        *outBgmId = 0x477;
        *outEffectKind = 0x21;
        return;
    }
    if (effectId == 1) {
        *outBgmId = 0x469;
        *outEffectKind = 0x1f;
        return;
    }
    if (effectId == 4) {
        if (parentZoneId == 0xd6) {
            *outBgmId = 0x469;
        } else {
            *outBgmId = 0x468;
        }
        *outEffectKind = 2;
        return;
    }
    attr = func_021A30C8(func_02188CB4(fieldMap));
    tileType = func_021AB0F0(attr);
    if (func_021AB0F8(attr) & 2) {
        bgmId = 0x468;
        effectKind = 2;
    } else if (func_021AB2BC(tileType)) {
        if (hasWildOpponent) {
            bgmId = 0x469;
            effectKind = 1;
        } else {
            bgmId = 0x468;
            effectKind = 0;
        }
    } else if (func_021AB364(tileType)) {
        bgmId = 0x468;
        effectKind = 0;
    } else {
        if (func_021AB37C(tileType)) {
            bgmId = 0x468;
            effectKind = 4;
        } else {
            bgmId = 0x468;
            effectKind = 3;
        }
    }
    *outEffectKind = effectKind;
    if (parentZoneId == 0xd6) {
        *outBgmId = 0x469;
    } else {
        *outBgmId = bgmId;
    }
}

/*
 * Picks the effect kind and the battle BGM for a trainer battle: from the
 * trainer's two class groups when the first is below 11, otherwise from the
 * tile and the area the player stands in.
 */
void func_021CF748(void *trainerData, struct FieldMap *fieldMap, int *outEffectKind, u16 *outBgmId)
{
    int areaIsInner = 1;
    u32 trainerClass = func_0202A230(trainerData, 1);
    u32 bgmGroup = func_0202A3FC(trainerClass);
    u32 effectGroup = func_0202A3D8(trainerClass);
    int effectKind;

    if (bgmGroup < 0xb) {
        *outBgmId = d_021DB7E0[bgmGroup];
        *outEffectKind = d_021DB7F6[effectGroup];
        return;
    }
    {
        u32 attr = func_021A30C8(func_02188CB4(fieldMap));
        u32 tileType = func_021AB0F0(attr);

        if (func_021AB0F8(attr) & 2) {
            effectKind = 6;
        } else if (func_021AB37C(tileType) != 0) {
            effectKind = 8;
        } else {
            if (func_020140D8(func_02188D58(fieldMap)) == 0) {
                areaIsInner = 0;
            }
            effectKind = 5;
            if (areaIsInner == 0) {
                effectKind = 7;
            }
        }
    }
    *outBgmId = 0x46a;
    *outEffectKind = effectKind;
}

/*
 * Script command: starts the task that counts the original trainers of
 * the player's Pokemon other than the player, and stores the count in a
 * script variable when the task ends.
 */
int func_021CF7DC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork = func_0215A5F4(cmdWork);
    struct GameSystem *gameSystem = func_0215A5DC(cmdWork);
    struct GameData *gameData = func_0215A5E4(cmdWork);
    u16 *resultVar = func_02159AE8(vm, cmdWork);
    struct GameEvent *taskEvent;
    struct MyStatus *myStatus;
    OtCountTask *task;

    taskEvent = func_020122C0(gameSystem, 0, func_021CF844, 0xd8);
    myStatus = func_02012944(gameData);
    task = func_020124E8(taskEvent);
    task->playerId = func_02008530(myStatus);
    task->list.count = 0;
    task->nextBox = 0;
    task->result = resultVar;
    func_0215897C(scriptWork, taskEvent);
    return 1;
}

/*
 * Task body: scans the party, then two PC boxes per frame, then the battle
 * box. Ends when all are scanned or the list is full.
 */
int func_021CF844(struct GameEvent *event, int *seq, OtCountTask *task)
{
    OtIdList *list;
    int finished = 0;
    struct GameData *gameData;
    int i;

    gameData = func_020120F4(func_020124E4(event));
    switch (*seq) {
    case 0:
        func_021CF8E4(task->playerId, gameData, &task->list);
        (*seq)++;
        break;
    case 1: {
        int firstBox = task->nextBox;
        list = &task->list;
        for (i = finished; i < 2; i++) {
            func_021CF940(task->playerId, gameData, firstBox + i, list);
            task->nextBox++;
            if (task->nextBox >= BOX_COUNT) {
                (*seq)++;
                break;
            }
        }
        break;
    }
    case 2:
        func_021CF9AC(task->playerId, gameData, finished, &task->list);
        finished = 1;
        break;
    }
    if (task->list.count >= OT_ID_LIST_MAX) {
        finished = 1;
    }
    if (finished) {
        *task->result = task->list.count;
        return 1;
    }
    return 0;
}

/* Adds the original trainers of the non-egg party Pokemon to the list. */
int func_021CF8E4(u32 playerId, struct GameData *gameData, OtIdList *list)
{
    struct PokeParty *party = func_02012934(gameData);
    int partyCount = func_0201AA18(party);
    int added = 0;
    int i;

    for (i = 0; i < partyCount; i++) {
        struct PokemonParam *mon = func_0201AB28(party, i);
        if (func_02017E1C(mon, MON_DATA_IS_EGG, 0) == 0) {
            u32 otId = func_02017E1C(mon, MON_DATA_OT_ID, 0);
            if (func_021CFA04(playerId, otId, list) != 0) {
                added++;
            }
        }
    }
    return added;
}

/* Adds the original trainers of the non-egg Pokemon of one PC box to the list. */
int func_021CF940(u32 playerId, struct GameData *gameData, u32 box, OtIdList *list)
{
    struct BoxData *boxData = func_0201293C(gameData);
    int added = 0;
    int i;

    for (i = 0; i < BOX_SLOT_COUNT; i++) {
        if (func_020079BC(boxData, box, i, MON_DATA_HAS_SPECIES, 0) != 0) {
            if (func_020079BC(boxData, box, i, MON_DATA_IS_EGG, 0) == 0) {
                u32 otId = func_020079BC(boxData, box, i, MON_DATA_OT_ID, 0);
                if (func_021CFA04(playerId, otId, list) != 0) {
                    added++;
                }
            }
        }
    }
    return added;
}

/* Adds the original trainers of one battle box team to the list. */
int func_021CF9AC(u32 playerId, struct GameData *gameData, u32 team, OtIdList *list)
{
    struct BattleBoxSave *battleBox;
    int i;
    int added;

    battleBox = func_0200BAC8(func_02012EBC(gameData));
    added = 0;
    for (i = 0; i < BATTLE_BOX_SLOT_COUNT; i++) {
        struct PokemonParam *mon = func_0200BBEC(battleBox, team, i);
        if (func_02017E88(mon, MON_DATA_HAS_SPECIES, 0) != 0) {
            u32 otId = func_02017E88(mon, MON_DATA_OT_ID, 0);
            if (func_021CFA04(playerId, otId, list) != 0) {
                added++;
            }
        }
    }
    return added;
}

/* Adds an original trainer id to the list unless it is the player's own. */
int func_021CFA04(int playerId, int otId, OtIdList *list)
{
    int added = 0;

    if (playerId != otId) {
        added = func_021CFA1C(otId, list);
    }
    return added;
}

/* Adds an id to the list when it is not in there yet and the list has room. */
int func_021CFA1C(int otId, OtIdList *list)
{
    int i;

    if (list->count >= OT_ID_LIST_MAX) {
        return 0;
    }
    for (i = 0; i < list->count; i++) {
        if (otId == list->ids[i]) {
            return 0;
        }
    }
    list->ids[i] = otId;
    list->count++;
    return 1;
}

/*
 * Script command: starts the field sub process of overlay 57 with the map
 * function of the current field map. abs_id_39 is overlay id 57 (pool ABS32
 * 0x39); d_021F3900 is ov057 data.
 */
int func_021CFA58(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct FieldMap *fieldMap;

    func_0215A5F4(cmdWork);
    fieldMap = func_0201210C(func_0215A5DC(cmdWork));
    func_021BB990((int)abs_id_39, (int *)func_02188D24(fieldMap), (const int *)d_021F3900);
    return 0;
}

/* Script command: stores a value of the saved player location in a script variable. */
int func_021CFA88(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct PlayerLocation *location;
    u16 *resultVar;

    func_0215A5F4(cmdWork);
    location = func_02008854(func_02012EBC(func_020120F4(func_0215A5DC(cmdWork))));
    resultVar = func_02159AE8(vm, cmdWork);
    *resultVar = func_02008990(location);
    return 0;
}

/*
 * Searches the offer slots for one that waits at this zone and tile (the
 * height may be off by one). Returns the slot index, or 0xff.
 */
int func_021CFAC0(IntrudeOfferLog *log, int zoneId, int x, int y, int z)
{
    int i;
    IntrudeOfferSlot *slot = log->slot;

    for (i = 0; i < INTRUDE_OFFER_SLOT_COUNT; i++, slot++) {
        const IntrudeOfferSpot *spot;
        if (slot->offerId == 0) {
            return 0xff;
        }
        spot = &d_021DB834[slot->spotIndex];
        if (spot->zoneId == zoneId && spot->x == x && spot->z == z && spot->y - 1 <= y && y <= spot->y + 1) {
            return i;
        }
    }
    return 0xff;
}

/* Copies offer slot i out and shifts the later slots down by one. */
void func_021CFB1C(IntrudeOfferLog *log, int index, IntrudeOfferSlot *dest)
{
    *dest = log->slot[index];
    for (index++; index < INTRUDE_OFFER_SLOT_COUNT; index++) {
        log->slot[index - 1] = log->slot[index];
    }
    log->slot[INTRUDE_OFFER_SLOT_COUNT - 1].offerId = 0;
}

/* Walks the slots from *index to the next used one and returns its spot row. */
const IntrudeOfferSpot *func_021CFB68(IntrudeOfferLog *log, int *index)
{
    int i = *index;

    if (i < INTRUDE_OFFER_SLOT_COUNT) {
        do {
            if (log->slot[i].offerId != 0) {
                const IntrudeOfferSpot *spot = &d_021DB834[log->slot[i].spotIndex];
                (*index)++;
                return spot;
            }
            i = ++*index;
        } while (i < INTRUDE_OFFER_SLOT_COUNT);
    }
    return 0;
}

/*
 * Event task: starts the offer script with the offer id as parameter and
 * registers the sender's name in word 3.
 */
int func_021CFBA8(struct GameEvent *event, u32 seq, const IntrudeOfferSlot *offer)
{
    IntrudeOfferSlot copy = *offer;
    struct ScriptWork *scriptWork;
    struct WordSet *wordSet;
    struct Strbuf *name;

    scriptWork = func_021587B0(event, 0x0AFC, 0, 0x15);
    func_02159058(scriptWork, copy.offerId, 0, 0, 0);
    wordSet = func_02158F74(scriptWork);
    name = func_020457B0(8, 0x15);
    func_02045994(name, (const u16 *)&copy, 8);
    func_0201EE0C(wordSet, 3, name, 1, 1, 2);
    func_02045808(name);
    return 0;
}

/* Takes offer slot slotIndex out of the log and starts the event task that shows it. */
struct GameEvent *func_021CFC14(struct GameSystem *gameSystem, u32 heapId, int slotIndex)
{
    struct GameEvent *taskEvent = func_020122C0(gameSystem, 0, func_021CFBA8, 0x14);
    IntrudeOfferSlot *offer = func_020124E8(taskEvent);

    func_021CFB1C(func_0200BE48(func_02012EBC(func_020120F4(gameSystem))), slotIndex, offer);
    return taskEvent;
}

/*
 * Fills the partner candidates in the save sync block for a language, or
 * clears them when the language is out of range.
 */
void func_021CFC4C(struct GameSystem *gameSystem, int language, u32 mode)
{
    struct GameData *gameData = func_020120F4(gameSystem);
    PartnerCandidates *candidates = func_02012F38(gameData);

    if (language < 0xe9) {
        func_021CFC80(func_02009470(func_02012EBC(gameData)), candidates, language, mode);
        return;
    }
    func_0200E878(candidates);
}

/* Collects up to five Wi-Fi history partners of one language into out. */
void func_021CFC80(struct WifiHistory *history, PartnerCandidates *out, u32 language, u32 mode)
{
    int i;

    out->language = language;
    out->mode = mode;
    out->count = 0;
    for (i = 0; i < WIFI_HISTORY_ENTRY_COUNT; i++) {
        if ((u8)func_02009634(history, i, WIFI_HISTORY_FIELD_INFO) != 0) {
            struct HistoryEntry *entry = func_0200973C(history, i);
            u32 entryLanguage;
            if (entry != 0 && (entryLanguage = func_0200856C(entry), entryLanguage == language)) {
                u32 outfit = func_02008554(entry);
                if (outfit > 0xf) {
                    outfit = (func_02008550(entry) != 0) ? 0xf : 0xb;
                }
                out->historyIndex[out->count] = i;
                out->viewId[out->count] = func_02025C74(outfit);
                out->count++;
                if (out->count >= PARTNER_CANDIDATE_MAX) {
                    break;
                }
            }
        }
    }
}

/* Returns the history index of candidate i, or 0xff. */
u8 func_021CFCF4(PartnerCandidates *candidates, u32 index)
{
    u8 historyIndex = 0xff;

    if (index < PARTNER_CANDIDATE_MAX && index < candidates->count) {
        historyIndex = candidates->historyIndex[index];
    }
    return historyIndex;
}

/*
 * Registers the words of candidate index and returns the index of the
 * greeting message for that partner (4 when the index is out of range).
 */
int func_021CFD08(struct WordSet *wordSet, struct GameSystem *gameSystem, PartnerCandidates *candidates, int index, u32 variant)
{
    u32 outfitVariant, trainerId, tier, historyIndex;
    struct HistoryEntry *entry;
    struct WifiHistory *history;
    struct GameData *gameData;
    u32 isSpecialLanguage;

    isSpecialLanguage = 0;
    gameData = func_020120F4(gameSystem);
    history = func_02009470(func_02012EBC(gameData));
    if (index >= PARTNER_CANDIDATE_MAX) {
        return 4;
    }
    historyIndex = candidates->historyIndex[index];
    func_021CFDBC(wordSet, gameData, historyIndex);
    entry = func_0200973C(history, historyIndex);
    outfitVariant = func_02008550(entry);
    tier = func_02009634(history, historyIndex, 4);
    trainerId = func_02008530(entry);
    if (func_02025B64(func_02012F38(gameData)->language)) {
        isSpecialLanguage = 1;
    }
    return func_021CFD88(outfitVariant, trainerId, tier, variant, isSpecialLanguage);
}

/* Computes the greeting message index from the partner's data. */
int func_021CFD88(int outfitVariant, u32 trainerId, u32 tier, int variant, int isSpecialLanguage)
{
    int index;

    if (isSpecialLanguage != 0) {
        index = 4;
    } else {
        index = 0x44;
    }
    if (tier < 5) {
        index += tier * 0xc;
    }
    if (outfitVariant != 0) {
        index += 6;
    }
    if (variant == 0) {
        index++; index += trainerId % 5;
    }
    return index;
}

/* Registers the words (names, numbers) of one Wi-Fi history partner in the word set. */
void func_021CFDBC(struct WordSet *wordSet, struct GameData *gameData, u32 historyIndex)
{
    struct WifiHistory *history;
    struct HistoryEntry *entry;
    u32 value;
    u8 language;

    history = func_02009470(func_02012EBC(gameData));
    language = func_02012F38(gameData)->language;
    entry = func_0200973C(history, historyIndex);
    func_0201F048(wordSet, 0, language);
    if (func_02025B64(language)) {
        func_0201F094(wordSet, 1, language, func_02008570(entry));
    }
    func_0201F02C(wordSet, 3, func_02012944(gameData));
    func_0201EE60(wordSet, 5, func_02009634(history, historyIndex, 0));
    func_0201F198(wordSet, 6, func_02009628(history));
    func_0201F02C(wordSet, 7, entry);
    value = func_02009634(history, historyIndex, 3);
    if (value == 0) {
        value = 1;
    }
    func_0201EFA4(wordSet, 8, value, 3, 0, 1);
    func_0201EE60(wordSet, 9, func_02009634(history, historyIndex, 1));
    language = func_02009634(history, historyIndex, 2);
    func_0201F198(wordSet, 10, language);
}

/* Script command: stores the number of countries in the Wi-Fi history, looked up with the argument. */
int func_021CFEA0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u32 arg;
    struct GameData *gameData;
    struct WifiHistory *history;
    struct GameSystem *gameSystem;
    u16 *resultVar;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    arg = func_02159B10(vm, cmdWork);
    resultVar = func_02159AE8(vm, cmdWork);
    gameData = func_020120F4(gameSystem);
    history = func_02009470(func_02012EBC(gameData));
    *resultVar = func_02009590(history, func_02012944(gameData), arg);
    return 0;
}

/* Script command: stores the number of entries of the Wi-Fi history. */
int func_021CFEF0(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u16 *resultVar;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    resultVar = func_02159AE8(vm, cmdWork);
    *resultVar = sub_020095C8(func_02009470(func_02012EBC(func_020120F4(gameSystem))));
    return 0;
}

/* Script command: marks the Wi-Fi history entry of partner candidate n. */
int func_021CFF28(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameData *gameData;
    PartnerCandidates *candidates;
    u32 historyIndex;
    u8 candidateIndex;

    func_0215A5F4(cmdWork);
    gameData = func_020120F4(func_0215A5DC(cmdWork));
    candidates = func_02012F38(gameData);
    candidateIndex = func_02159B10(vm, cmdWork);
    historyIndex = func_021CFCF4(candidates, candidateIndex);
    if (historyIndex != 0xff) {
        func_02009698(func_02009470(func_02012EBC(gameData)), historyIndex, WIFI_HISTORY_FIELD_MARKED, 1);
    }
    return 0;
}

/* Script command: stores 1 when the history entry of partner candidate n is marked. */
int func_021CFF78(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameData *gameData;
    PartnerCandidates *candidates;
    u32 candidateIndex, historyIndex;
    u16 *resultVar;

    func_0215A5F4(cmdWork);
    gameData = func_020120F4(func_0215A5DC(cmdWork));
    candidates = func_02012F38(gameData);
    candidateIndex = func_02159B10(vm, cmdWork);
    resultVar = func_02159AE8(vm, cmdWork);
    *resultVar = 0;
    historyIndex = func_021CFCF4(candidates, candidateIndex);
    if (historyIndex != 0xff) {
        if ((u8)func_02009634(func_02009470(func_02012EBC(gameData)), historyIndex, WIFI_HISTORY_FIELD_MARKED)) {
            *resultVar = 1;
        }
    }
    return 0;
}

/* Script command: sets the rating level of the Wi-Fi history. */
int func_021CFFDC(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u8 ratingLevel;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    ratingLevel = func_02159B10(vm, cmdWork);
    sub_020095FC(func_02009470(func_02012EBC(func_020120F4(gameSystem))), ratingLevel);
    return 0;
}

/* Script command: sets the greeting set of the Wi-Fi history. */
int func_021D0014(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u8 greetingSet;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    greetingSet = func_02159B10(vm, cmdWork);
    sub_02009618(func_02009470(func_02012EBC(func_020120F4(gameSystem))), greetingSet);
    return 0;
}

/* Script command: stores the greeting set of the Wi-Fi history. */
int func_021D004C(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct GameSystem *gameSystem;
    u16 *resultVar;

    func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    resultVar = func_02159AE8(vm, cmdWork);
    *resultVar = func_02009628(func_02009470(func_02012EBC(func_020120F4(gameSystem))));
    return 0;
}

/* Script command: fills the partner candidates for a language and mode read from the script. */
int func_021D0084(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    func_0215A5F4(cmdWork);
    func_021CFC4C(func_0215A5DC(cmdWork), func_02159B10(vm, cmdWork), func_02159B10(vm, cmdWork));
    return 0;
}

/* Script command: stores the greeting message index for partner candidate n. */
int func_021D00B8(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    struct ScriptWork *scriptWork;
    struct GameSystem *gameSystem;
    struct WordSet *wordSet;
    PartnerCandidates *candidates;
    u32 candidateIndex, variant;
    u16 *resultVar;

    scriptWork = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    candidates = func_02012F38(func_020120F4(gameSystem));
    wordSet = func_02158F74(scriptWork);
    candidateIndex = func_02159B10(vm, cmdWork);
    variant = func_02011330(vm);
    resultVar = func_02159AE8(vm, cmdWork);
    *resultVar = func_021CFD08(wordSet, gameSystem, candidates, candidateIndex, variant);
    return 0;
}

/* Script command: stores 1 when the player's language value is set. */
int func_021D0114(struct ScriptVm *vm, struct ScrcmdWork *cmdWork)
{
    u16 *resultVar = func_02159AE8(vm, cmdWork);

    *resultVar = func_0200856C(func_02012944(func_020120F4(func_0215A5DC(cmdWork)))) != 0 ? 1 : 0;
    return 0;
}
