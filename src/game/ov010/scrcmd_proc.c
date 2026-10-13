/*
 * file:     scrcmd_proc.c
 * unit:     yes
 * function: func_0215B488, func_0215B4AC, func_0215B4DC, func_0215B500, func_0215B558, func_0215B5A8, func_0215B5BC, func_0215B660, func_0215B6C0, func_0215B704, func_0215B74C, func_0215B7E8, func_0215B824, func_0215B848, func_0215B888, func_0215B904, func_0215B994, func_0215BA18, func_0215BAB0, func_0215BAF4, func_0215BB50, func_0215BBD0, func_0215BCA0, func_0215BCE8, func_0215BD2C, func_0215BE24, func_0215BF30, func_0215BF7C, func_0215BFD4, func_0215C01C, func_0215C064, func_0215C0D0, func_0215C138, func_0215C180, func_0215C200, func_0215C2D0, func_0215C40C, func_0215C4C8, func_0215C510, func_0215C558, func_0215C584, func_0215C5B0, func_0215C5EC, func_0215C610, func_0215C63C, func_0215C69C, func_0215C6F0, func_0215C700, func_0215C72C, func_0215C7C4, func_0215C7E0, func_0215C870, func_0215C89C, func_0215C95C, func_0215CA64, func_0215CAB4, func_0215CB08, func_0215CBF0, func_0215CC38, func_0215CC4C, func_0215CCE8, func_0215CD3C, func_0215CD80, func_0215CDB8, func_0215CDF0, func_0215CE70, func_0215CE98, func_0215CEBC, func_0215CEE8, func_0215CF00, func_0215CF54, func_0215CF84, func_0215CFB4, func_0215CFD8, func_0215CFFC, func_0215D034, func_0215D06C, func_0215D0A4, func_0215D0D4, func_0215D110, func_0215D14C, func_0215D198, func_0215D1E4, func_0215D2A4
 * address:  0x0215B488
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * Merged by tools/restructure.py from the src/matched files of these functions.
 *
 * symbols:
 *   func_02159B10 0x02159B10 thumb ov010
 *   func_02159AE8 0x02159AE8 thumb ov010
 *   d_02171170 0x02171170 data a2
 *   func_0215A5E4  0x0215A5E4  thumb  ov010
 *   func_02012934  0x02012934  thumb
 *   func_0201AA18  0x0201AA18  thumb
 *   func_0201AB28  0x0201AB28  thumb
 *   func_02017E1C   0x02017E1C  thumb
 *   POKE_TOOL_HealParty  0x0201BA34  thumb
 *   func_02011330  0x02011330  thumb
 *   func_02017E40  0x02017E40  thumb
 *   func_0201AB08  0x0201AB08  thumb
 *   POKEPARTY_FindFirstNonEgg  0x0201AB18  thumb
 *   func_0201AA14  0x0201AA14  thumb
 *   func_0201AA1C  0x0201AA1C  thumb
 *   func_0201AA50  0x0201AA50  thumb
 *   func_0201AA88  0x0201AA88  thumb
 *   func_0201AAD4  0x0201AAD4  thumb
 *   func_0201293C  0x0201293C  thumb
 *   func_02007984  0x02007984  thumb
 *   func_020079A0  0x020079A0  thumb
 *   func_0215A5DC  0x0215A5DC  thumb  ov010
 *   func_0215A5CC  0x0215A5CC  thumb  ov010
 *   func_02012944  0x02012944  thumb
 *   POKE_TOOL_DecodePartyParam  0x02017D30  thumb
 *   func_020180F4  0x020180F4  thumb
 *   func_020181F4  0x020181F4  thumb
 *   POKE_TOOL_EncodePartyParam  0x02017D70  thumb
 *   func_02008530  0x02008530  thumb
 *   func_020457B0  0x020457B0  arm
 *   func_02008500  0x02008500  thumb
 *   STRBUF_IsEqual  0x0204589C  arm
 *   func_02045808  0x02045808  arm
 *   func_02008550  0x02008550  thumb
 *   g0209DF08      0x0209DF08  data  a1
 *   func_0215A5F4  0x0215A5F4  thumb  ov010
 *   func_020120F4  0x020120F4  thumb
 *   func_02017988  0x02017988  thumb
 *   func_0200CA1C  0x0200CA1C  thumb
 *   func_0200CFA0  0x0200CFA0  thumb
 *   func_020185C4  0x020185C4  thumb
 *   d_02171180     0x02171180  data   ov010  a2
 *   d_0217118E     0x0217118E  data   ov010  a2
 *   d_02171190     0x02171190  data   ov010  a2
 *   POKE_TOOL_SetRotomFormMove  0x02017A20  thumb
 *   func_0216F948  0x0216F948  thumb  ov010
 *   func_0216FAA0  0x0216FAA0  thumb  ov010
 *   func_020307B0  0x020307B0  arm
 *   d_02171182 0x02171182 data a1
 *   func_020173F0  0x020173F0  thumb
 *   func_02008510  0x02008510  thumb
 *   func_0201ADE4  0x0201ADE4  thumb
 *   func_0201AE1C  0x0201AE1C  thumb
 *   func_0201AE14  0x0201AE14  thumb
 *   func_02045EC0  0x02045EC0  arm
 *   func_0202F190  0x0202F190  thumb
 *   func_0201A98C  0x0201A98C  thumb
 *   g_020A7370     0x020A7370  data
 *   func_020186C8 0x020186C8 thumb
 *   POKE_TOOL_CreateEx 0x02017430 thumb
 *   func_02020FE4 0x02020FE4 thumb
 *   PALANM_GetPairedCodeForFirst 0x0202142C thumb
 *   func_020127A4 0x020127A4 thumb
 *   func_02012AC8 0x02012AC8 thumb
 *   func_02013E4C 0x02013E4C thumb
 *   POKE_TOOL_GetBoxParam  0x020185F4  thumb
 *   func_020074D8  0x020074D8  thumb
 *   func_0200CDE0  0x0200CDE0  thumb
 *   func_02012F08 0x02012F08 thumb
 *   func_0200C278 0x0200C278 thumb
 *   func_0200C29C 0x0200C29C thumb
 *   func_0200C274 0x0200C274 thumb
 *   FIELD_STATUS_CreateFieldOpenEvent   0x020145CC  thumb
 *   func_0215897C   0x0215897C  thumb  ov010
 *   func_0201210C  0x0201210C  thumb
 *   FIELD_STATUS_CreateFieldCloseEvent  0x020144DC  thumb
 *   func_02158FB4  0x02158FB4  thumb  ov010
 *   func_02030734  0x02030734  arm
 *   GAMESYSTEM_CallProc  0x020120B4  thumb
 *   func_020113D0  0x020113D0  thumb
 *   d_021728F0     0x021728F0  data  a1
 *   func_02158FB8  0x02158FB8  thumb  ov010
 *   GAMESYSTEM_GetProcStatus  0x020120F0  thumb
 *   func_02158FBC  0x02158FBC  thumb  ov010
 *   BAG_PARAM_Create  0x0202E474  thumb
 *   ov070_id       0x00000046  data
 *   d_021BB96C     0x021BB96C  data  ov070 a4
 *   func_02014840  0x02014840  thumb
 *   ov136_id       0x00000088  data
 *   d_021C78A4     0x021C78A4  data  ov136  a1
 *   func_0216F940  0x0216F940  thumb  ov010
 *   func_0216F918 0x0216F918 thumb ov010
 *   func_02014808 0x02014808 thumb
 *   ov173_id 0x000000AD data
 *   d_021B81D0 0x021B81D0 data ov173 a4
 *   func_02012138  0x02012138  thumb
 *   func_02158344  0x02158344  thumb  ov010
 *   func_02012B58  0x02012B58  thumb
 *   func_0215841C  0x0215841C  thumb  ov010
 *   func_02175FB4  0x02175FB4  thumb  ov011
 *   func_0215840C  0x0215840C  thumb  ov010
 *   func_02012EBC  0x02012EBC  thumb
 *   func_0200BE48  0x0200BE48  thumb
 *   INTRUDE_COMM_BuildLocalProfile  0x02175648  thumb  ov011
 *   d_021BA758     0x021BA758  data  ov099  a1
 *   ov071_id       0x00000047  data
 *   func_02158F50  0x02158F50  thumb  ov010
 *   func_02161B90  0x02161B90  thumb  ov010
 *   ov174_id       0x000000AE  data
 *   d_021B74A0     0x021B74A0  data  a1 ov174
 *   func_02165344  0x02165344  thumb  ov010
 *   ov221_id       0x000000DD  data
 *   ov222_id       0x000000DE  data
 *   ov224_id       0x000000E0  data
 *   d_021BA1A4     0x021BA1A4  data  ov221  a4
 *   d_021BA250     0x021BA250  data  ov222  a4
 *   d_021B9BF8     0x021B9BF8  data  ov224  a4
 *   ov223_id       0x000000DF  data
 *   d_021BC8C4     0x021BC8C4  data  ov223
 *   func_020124AC  0x020124AC  thumb
 *   EVENT_WIFIBATTLEMATCH_Entry  0x02154438  thumb  ov002
 *   ov002_id       0x00000002  data
 *   EVENT_MENUPROC_Entry  0x021543BC  thumb  ov003
 *   ov003_id       0x00000003  data
 *   func_02034AC4  0x02034AC4  arm
 *   func_02034A5C  0x02034A5C  arm
 *   func_021F36C0  0x021F36C0  thumb  ov037
 *   ov037_id       0x00000025  data
 *   func_021F36E8 0x021F36E8 thumb ov037
 *   func_021F3724 0x021F3724 thumb ov037
 *   func_021F3768  0x021F3768  thumb  ov037
 *   func_021F3800 0x021F3800 thumb ov037
 *   func_02188D50  0x02188D50  thumb
 *   func_021C3400  0x021C3400  thumb  ov021
 *   func_021C32F4 0x021C32F4 thumb ov021
 *   func_021C335C  0x021C335C  thumb
 *   func_0200BDB0  0x0200BDB0  thumb
 *   func_021C3204 0x021C3204 thumb ov021
 *   func_021C3270 0x021C3270 thumb ov021
 *   func_021C340C  0x021C340C  thumb
 *   func_021C34C4  0x021C34C4  thumb
 *   func_021C34F8 0x021C34F8 thumb ov021
 *   func_021C341C 0x021C341C thumb ov021
 *   func_021C3490 0x021C3490 thumb ov021
 *   func_021C34B4 0x021C34B4 thumb ov021
 *   func_021BE8D4  0x021BE8D4  thumb
 *   func_021BE92C  0x021BE92C  thumb
 *   func_02012374  0x02012374  thumb
 *   func_02014910  0x02014910  thumb
 *   func_0200CA38  0x0200CA38  thumb
 *   func_020122C0  0x020122C0  thumb
 *   func_020124E8  0x020124E8  thumb
 *   d_02172900     0x02172900  data
 */

struct GameData;
struct ScriptVm;
struct PokemonParam;
struct Strbuf;
struct MyStatus;
struct ZukanSave;
struct GameSystem;
struct Party;
struct MsgBank;
struct PersonalData;
struct PlayerWork;
struct BoxPokemonParam;
struct MiscSave;
struct GameEvent;
struct PlayerProfile;
typedef unsigned short u16;

typedef unsigned char u8;

typedef unsigned int u32;

typedef short s16;

typedef signed int     s32;

typedef unsigned long long u64;

typedef enum { B_FALSE, B_TRUE } Bool;

/* Creation request shared by the party and box helpers (offsets as read). */
typedef struct PokemonSpec {
    u16 heapId;         /* 0x00 */
    u16 pad02;
    int species;        /* 0x04 */
    int form;           /* 0x08 */
    int level;          /* 0x0C */
    int heldItem;       /* 0x10 */
    int genderMode;     /* 0x14 */
    int natureMode;     /* 0x18 */
    int shinyMode;      /* 0x1C */
    int ballItem;       /* 0x20 */
} PokemonSpec;

/* Record the overlay-launch helper parks in the script's event slot. */
typedef struct ScriptProcHandoff {
    void *work;         /* 0x00 */
    u32 userData;       /* 0x04 */
    u32 onFinish;       /* 0x08, function called with the record when set */
} ScriptProcHandoff;

typedef struct BagResultVars { u16 *selectedVar; u16 *itemVar; } BagResultVars;

typedef struct BagParamResult { char pad[0x34]; u32 selected; u32 itemId; } BagParamResult;

typedef struct BagCloseData { BagParamResult *bagParam; BagResultVars *resultVars; } BagCloseData;

typedef struct GtsParam {
    void *gameData;     /* 0x00 */
    u32 result;         /* 0x04, written by the overlay */
} GtsParam;

typedef struct GtsCallbackData {
    GtsParam *param;
    u16 *resultVar;
} GtsCallbackData;

typedef struct MoveRelearnParam {
    void *mon;          /* 0x00 */
    void *myStatus;     /* 0x04 */
    u32 flags;          /* 0x08 */
    void *gameSystem;   /* 0x0C */
    void *relearnMoves; /* 0x10 */
    u8 pad14[5];
    u8 enabled;         /* 0x19 */
    u8 learned;         /* 0x1A, set by the overlay */
} MoveRelearnParam;

typedef struct RelearnCallbackData {
    MoveRelearnParam *param;
    u16 *resultVar;
} RelearnCallbackData;

typedef struct PlayerName {
    u16 chars[20];
} PlayerName;

typedef struct PlayerProfile {
    u32 words[4];
} PlayerProfile;

typedef struct PlayerRecord {
    u8 data[0x28];
} PlayerRecord;

typedef struct CommState {
    u8 pad00[0x86];
    u16 localPlayerId : 3;  /* 0x086 */
    u16 reserved : 13;
    u8 pad88[0x1AC - 0x88];
    PlayerRecord records[1];    /* 0x1AC */
} CommState;

typedef struct ProfileProcWork {
    void *gameSystem;   /* 0x00 */
    PlayerName name;    /* 0x04 */
    PlayerProfile profile;  /* 0x2C */
    u8 playerIndex;     /* 0x3C */
    u8 isRemote;        /* 0x3D */
    u8 pad3E[2];
} ProfileProcWork;

typedef struct ValueProcParam {
    u16 value;          /* 0x00 */
    u16 pad02;
    void *gameData;     /* 0x04 */
} ValueProcParam;

typedef struct ModeProcParam {
    void *gameData;     /* 0x00 */
    u32 value;          /* 0x04 */
} ModeProcParam;

typedef struct WifiBattleMatchParam {
    void *fieldMap;     /* 0x00 */
    u32 enabled;        /* 0x04 */
    u32 flag;           /* 0x08 */
    u32 matchKind;      /* 0x0C */
} WifiBattleMatchParam;

typedef struct MenuProcParam { u32 fieldMap; u32 mode; } MenuProcParam;

typedef struct PartyMenuParam {
    void *party;        /* 0x00 */
    u32 pad04[2];
    u32 listWork;       /* 0x0C */
    u32 pad10[9];
    u32 menuType;       /* 0x34 */
    u32 cursorPos;      /* 0x38 */
    u32 selectedPos;    /* 0x3C */
} PartyMenuParam;

typedef struct PartyMenuState {
    void *party;        /* 0x00 */
    u32 listWork;       /* 0x04 */
    u32 gameData;       /* 0x08 */
    u8 enabled;         /* 0x0C */
    u8 cursor;          /* 0x0D */
    u8 partyCount;      /* 0x0E */
    u8 selectedPos;     /* 0x0F */
    u8 reserved10;      /* 0x10 */
    u8 pad11[7];
    u32 zukanSave;      /* 0x18 */
} PartyMenuState;

typedef struct DaycareEventWork {
    void *gameSystem;           /* 0x00 */
    void *fieldMap;             /* 0x04 */
    PartyMenuParam *menuParam;  /* 0x08 */
    PartyMenuState *menuState;  /* 0x0C */
    u16 *resultVar;             /* 0x10 */
} DaycareEventWork;

extern u16 func_02159B10(void *, void *);
extern u16 *func_02159AE8(void *, void *);
extern void *func_0215A5E4(void *);
extern void *func_02012934(const struct GameData *);
extern u32 func_0201AA18(void *);
extern void *func_0201AB28(void *, u32 idx);
extern u32 func_02017E1C(void *, u32 id, u32);
extern void POKE_TOOL_HealParty(void *);
extern u16 func_02011330(struct ScriptVm *);
extern void func_02017E40(void *, u32 id, u32);
extern u32 func_0201AB08(void *);
extern u32 POKEPARTY_FindFirstNonEgg(void *);
extern u32 func_0201AA14(void *);
extern u32 func_0201AA1C(void *);
extern u32 func_0201AA50(void *);
extern u32 func_0201AA88(void *);
extern u32 func_0201AAD4(void *);
extern u32 func_0201293C(const struct GameData *);
extern int func_02007984(void *);
extern int func_020079A0(void *);
extern void *func_0215A5DC(void *);
extern u16 func_0215A5CC(void *);
extern u8 *func_02012944(void *);
extern u32 POKE_TOOL_DecodePartyParam(struct PokemonParam *);
extern void func_020180F4(void *, int move);
extern void func_020181F4(void *, u16 move, u32 slot);
extern u32 POKE_TOOL_EncodePartyParam(struct PokemonParam *, u32);
extern u32 func_02008530(const struct MyStatus *obj);
extern struct Strbuf *func_020457B0(u32 capacity, u32 heapId);
extern void func_02008500(void *player, void *str);
extern int STRBUF_IsEqual(struct Strbuf *, struct Strbuf *);
extern void func_02045808(struct Strbuf *vec);
extern u8 func_02008550(const struct MyStatus *obj);
extern void *func_0215A5F4(void *);
extern void *func_020120F4(const struct GameSystem *);
extern u32 func_02017988(void *, u32);
extern void *func_0200CA1C(void *);
extern void func_0200CFA0(struct ZukanSave *, void *);
extern u32 POKE_TOOL_SetRotomFormMove(void *, u32 idx, u32 val);
extern u16 *func_0216F948(void *mon, u32 heap);
extern int func_0216FAA0(u16 *);
extern u32 func_020307B0(void *);
extern void func_020185C4(void *);
extern void *func_020173F0(u32 species, u32 level, u64 id, u32 heap);
extern void *func_02008510(void *, int tag);
extern void *func_0201ADE4(unsigned int species, int form, unsigned int heap);
extern u32 func_0201AE1C(const struct PersonalData *, u32 field);
extern void func_0201AE14(void *);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern void func_0202F190(void *mon, u32, void *, u32, u32 heap);
extern u32 func_0201A98C(struct Party *, const struct PokemonParam *src);
extern u32 func_020186C8(u32, int, int, int, int, int);
extern void *POKE_TOOL_CreateEx(u16, u16, u64, u32, u64, u16);
extern int func_02020FE4(u16, u32, u16);
extern unsigned short PALANM_GetPairedCodeForFirst(int);
extern void *func_020127A4(struct GameData *);
extern u16 func_02012AC8(const struct PlayerWork *);
extern u32 func_02013E4C(u32 id);
extern void *POKE_TOOL_GetBoxParam(void *);
extern int func_020074D8(void **save, const struct BoxPokemonParam *src);
extern void func_0200CDE0(struct ZukanSave *, void *);
extern void *func_02012F08(int *);
extern u32 func_0200C278(struct MiscSave *, u32);
extern u32 func_0200C29C(struct MiscSave *, u32);
extern u32 func_0200C274(struct MiscSave *);
extern void *FIELD_STATUS_CreateFieldOpenEvent(void *);
extern void func_0215897C(void *, void *);
extern void *func_0201210C(const struct GameSystem *);
extern int FIELD_STATUS_CreateFieldCloseEvent(int, int);
extern void *func_02158FB4(void *);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern void GAMESYSTEM_CallProc(struct GameSystem *, u32 id, void *, void *);
extern void func_020113D0(char *, int val);
extern u32 func_02158FB8(void *);
extern u32 GAMESYSTEM_GetProcStatus(const struct GameSystem *);
extern int func_02158FBC();
extern void *BAG_PARAM_Create(const struct GameData *, int, int, int);
extern void *func_02014840(char *, int, int, int, int, int, int);
extern int func_0216F940();
extern void *func_0216F918(u32 heap);
extern void *func_02014808(char *, int, int, int, int, int, int);
extern u32 func_02012138(const struct GameSystem *);
extern int func_02158344(int);
extern u8 func_02012B58(const struct GameData *);
extern u8 func_0215841C(void *);
extern int func_02175FB4(u8 *);
extern PlayerName *func_0215840C(CommState *, int idx);
extern void *func_02012EBC(struct GameData *);
extern u16 *func_0200BE48(void *);
extern void INTRUDE_COMM_BuildLocalProfile(void *sv, struct PlayerProfile *o);
extern void *func_02158F50(void *);
extern void *func_02161B90(void *, void *, int kind, int sub, int flag);
extern void func_02165344(void);
extern struct GameEvent *func_020124AC(void *, u32, u32 (*fn)(void *, u32), u32);
extern void EVENT_WIFIBATTLEMATCH_Entry(s32, s32 *);
extern void EVENT_MENUPROC_Entry(void);
extern int func_02034AC4(s32 handle);
extern void func_02034A5C(s32 handle);
extern void func_021F36C0(unsigned int, int, int);
extern void func_021F36E8(void *, int);
extern void func_021F3724(unsigned int, int);
extern void func_021F3768(unsigned int, unsigned short **);
extern void func_021F3800(unsigned int);
extern void *func_02188D50(void *);
extern int func_021C3400(void *);
extern void func_021C32F4(unsigned int *, unsigned int);
extern void func_021C335C(void **);
extern void *func_0200BDB0(void *);
extern void func_021C3204(unsigned int *, unsigned int, unsigned int);
extern void func_021C3270(unsigned int *, unsigned int, unsigned int);
extern int func_021C340C();
extern u8 func_021C34C4(void **);
extern void *func_021C34F8(void *, unsigned int);
extern int func_021C341C(unsigned int *, unsigned int);
extern int func_021C3490(void **, int);
extern int func_021C34B4(void **, int);
extern void *func_021BE8D4(void *, void *, int, int);
extern void *func_021BE92C(void *, void *, int, int, int, int, int);
extern void func_02012374(struct GameEvent *evt, struct GameEvent **out);
extern void *func_02014910(char *, int, int, int);
extern u32 func_0200CA38(struct ZukanSave *);
extern struct GameEvent *func_020122C0(void *owner, void *, void *, u32 size);
extern void *func_020124E8(struct GameEvent *);
int func_0215B488(int, int);
int func_0215B4AC(void *, u32, void **);
int func_0215B4DC(void *, void *, void *);
int func_0215B500(int, int);
int func_0215B558(int, int);
int func_0215B5A8(int, int);
int func_0215B5BC(void *, void *);
int func_0215B660(int, int, int);
int func_0215B6C0(int, int, int);
int func_0215B704(int, int, int);
int func_0215B74C(int, int);
int func_0215B7E8(int, int);
int func_0215B824(int, int, int);
int func_0215B848(int, int);
int func_0215B888(void *, void *);
int func_0215B904(void *, void *);
int func_0215B994(void *, void *);
int func_0215BA18(void *, void *);
int func_0215BAB0(int, int, int);
int func_0215BAF4(void *, void *);
int func_0215BB50(void *, void *);
int func_0215BBD0(void *, void *);
int func_0215BCA0(int, int, int);
int func_0215BCE8(void *, void *);
int func_0215BD2C(void *, void *);
int func_0215BE24(void *, void *);
int func_0215BF30(void *, void *);
int func_0215BF7C(void *, void *);
int func_0215BFD4(int, int, int);
int func_0215C01C(void *, void *);
int func_0215C064(void *, void *);
int func_0215C0D0(void *, void *);
int func_0215C138(void *, void *);
int func_0215C180(void *, void *);
int func_0215C200(void *, void *);
int func_0215C2D0(void *, void *);
void *func_0215C40C(void *, PokemonSpec *);
int func_0215C4C8(void *, void *);
int func_0215C510(void *, void *);
int func_0215C558(int, int);
int func_0215C584(int, int);
int func_0215C5B0(void *, void *);
int func_0215C5EC(void *, void *);
int func_0215C610(int, int);
void func_0215C63C(void *, void *, u32 overlayId, const void *procData, void *procWork, u32 onFinish, u32 userData);
int func_0215C69C(int, int);
int func_0215C6F0(int, int);
void func_0215C700(BagCloseData *closeData);
int func_0215C72C(void *, void *);
void func_0215C7C4(GtsCallbackData *callbackData);
int func_0215C7E0(void *, void *);
int func_0215C870(int, int);
int func_0215C89C(void *, void *);
int func_0215C95C(void *, void *);
int func_0215CA64(void *, void *);
int func_0215CAB4(void *, void *);
int func_0215CB08(void *, void *);
int func_0215CBF0(void *, void *);
int func_0215CC38(int, int);
int func_0215CC4C(void *, void *);
int func_0215CCE8(void *, void *);
int func_0215CD3C(void *, void *);
int func_0215CD80(void *, void *);
int func_0215CDB8(void *, void *);
int func_0215CDF0(void *, void *);
int func_0215CE70(void *, void *);
int func_0215CE98(int, int);
int func_0215CEBC(void *, void *);
int func_0215CEE8(int, int);
int func_0215CF00(void *, void *);
int func_0215CF54(void *, void *);
int func_0215CF84(void *, void *);
int func_0215CFB4(int, int);
int func_0215CFD8(int, int);
int func_0215CFFC(void *, void *);
int func_0215D034(void *, void *);
int func_0215D06C(void *, void *);
int func_0215D0A4(void *, void *);
int func_0215D0D4(void *, void *);
int func_0215D110(void *, void *);
int func_0215D14C(void *, void *);
int func_0215D198(void *);
int func_0215D1E4(void *event, u32 *seq, DaycareEventWork *work);
void *func_0215D2A4(void *gameSystem, void *fieldMap, u16 *resultVar);
extern const u16 d_02171170[];
extern u8 g0209DF08;
extern u16 d_02171180[];
extern struct { u16 paramId; u16 maxValue; } d_0217118E[6];
extern const u8 d_02171182[];
extern void *g_020A7370;
extern const char d_021728F0[];
extern const u8 d_021BB96C[];
extern u8 ov070_id[];
extern const u8 d_021C78A4[];
extern u8 ov136_id[];
extern const u8 d_021B81D0[];
extern u8 ov173_id[];
extern const u8 d_021BA758[];
extern u8 ov071_id[];
extern const u8 d_021B74A0[];
extern u8 ov174_id[];
extern const u8 d_021BA1A4[];
extern const u8 d_021BA250[];
extern const u8 d_021B9BF8[];
extern u8 ov221_id[];
extern u8 ov222_id[];
extern u8 ov224_id[];
extern const u8 d_021BC8C4[];
extern u8 ov223_id[];
extern u8 ov002_id[];
extern char ov003_id[];
extern char ov037_id[];
extern const char d_02172900[];


/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int func_0215B488(int vm,int cmdWork)
{
    int tableIndex = func_02159B10((void *)vm,(void *)cmdWork);
    u16 *resultVar = func_02159AE8((void *)vm,(void *)cmdWork);
    *resultVar = d_02171170[tableIndex];
    return 0;
}



int func_0215B4AC(void *cmdWork, u32 partyIndex, void **outMemberArg)
{
    int isValid;
    u32 slotIndex;
    void **outMember;
    int partyCount;
    void *member;
    void *gameData;
    void *party;

slotIndex = partyIndex + 0;
outMember = outMemberArg;
    gameData = func_0215A5E4(cmdWork);
    party = func_02012934(gameData);
    partyCount = func_0201AA18(party);
    if (slotIndex >= (unsigned)partyCount) goto outOfRange;
isValid = 1;
    goto store;
outOfRange:
isValid = 0;
slotIndex = 0;
store:
    member = func_0201AB28(party, slotIndex);
*outMember = member;
    return isValid;}



/*
 * Unpacks a record into a local and, when the overlay call says it took,
 * forwards the record and the third argument to the arm9 side.
 */
int func_0215B4DC(void *cmdWork, void *partyIndex, void *paramId)
{
    int member;

    if (func_0215B4AC(cmdWork, (u32)partyIndex, (void **)(&member)) == 1)
        return func_02017E1C((void *)member, (u32)paramId, 0);

    return 0;
}



int func_0215B500(int callArg0, int callArg1)
{
    int callArg2;
    int moveIdCopy;
    int monCopy;
    int zero;

moveIdCopy = callArg1 + 0;
callArg1 = 0x4c;
callArg2 = 0;
monCopy = callArg0 + 0;
zero = 0;
    callArg0 = func_02017E1C((void *)callArg0, callArg1, callArg2);
    if (callArg0 == 0) goto checkSlots;
callArg0 = zero + 0;
    return callArg0;
checkSlots:
callArg0 = monCopy + 0;
callArg1 = 0x36;
callArg2 = zero + 0;
    callArg0 = func_02017E1C((void *)callArg0, callArg1, callArg2);
    if (moveIdCopy == callArg0) goto found;
callArg0 = monCopy + 0;
callArg1 = 0x37;
callArg2 = zero + 0;
    callArg0 = func_02017E1C((void *)callArg0, callArg1, callArg2);
    if (moveIdCopy == callArg0) goto found;
callArg0 = monCopy + 0;
callArg1 = 0x38;
callArg2 = zero + 0;
    callArg0 = func_02017E1C((void *)callArg0, callArg1, callArg2);
    if (moveIdCopy == callArg0) goto found;
callArg0 = monCopy + 0;
callArg1 = 0x39;
callArg2 = zero + 0;
    callArg0 = func_02017E1C((void *)callArg0, callArg1, callArg2);
    if (moveIdCopy != callArg0) goto notFound;
found:
callArg0 = 1;
    return callArg0;
notFound:
callArg0 = zero + 0;
    return callArg0;}


int func_0215B558(int vm, int cmdWork)
{
    u16 *firstResultVar = func_02159AE8((void *)vm, (void *)cmdWork);
    u16 *secondResultVar = func_02159AE8((void *)vm, (void *)cmdWork);
    int mon;
    if (func_0215B4AC((void *)cmdWork, func_02159B10((void *)vm, (void *)cmdWork), (void **)(&mon)) == 1) {
        *firstResultVar = func_02017E1C((void *)mon, 0xAE, 0);
        *secondResultVar = func_02017E1C((void *)mon, 0xAF, 0);
    } else {
        *firstResultVar = 0;
        *secondResultVar = 0;
    }
    return 0;
}



int func_0215B5A8(int callArg0, int callArg1)
{
    void *gameData;
    void *party;

callArg0 = callArg1 + 0;
    gameData = func_0215A5E4((void *)callArg0);
    party = func_02012934(gameData);
    POKE_TOOL_HealParty(party);
callArg0 = 0;
    return callArg0;}


#pragma opt_lifetimes off


#pragma opt_propagation off


/*
 * 2026-10-05 (wave P14 C6): closed with per-function opt_lifetimes off plus
 * opt_propagation off. Without them the two zeros (the named argument zero z
 * and the initial sum) merge into one register and the first add folds to
 * adds r0,r0,#0 (35 B off, 166 B). opt_lifetimes off alone: 2 B off.
 */
int func_0215B5BC(void *vm, void *cmdWork)
{
    u16 *resultVar = (u16 *)func_02159AE8(vm, cmdWork);
    int partyIndex = func_02159B10(vm, cmdWork);
    int zero = 0;
    u16 evTotal = 0;
    void *mon;
    if (func_0215B4AC(cmdWork, partyIndex, &mon) == 1) {
        evTotal = zero + (u16)func_02017E1C(mon, 0xD, zero);
        evTotal = evTotal + (u16)func_02017E1C(mon, 0xE, zero);
        evTotal = evTotal + (u16)func_02017E1C(mon, 0xF, zero);
        evTotal = evTotal + (u16)func_02017E1C(mon, 0x10, zero);
        evTotal = evTotal + (u16)func_02017E1C(mon, 0x11, zero);
        evTotal = evTotal + (u16)func_02017E1C(mon, 0x12, zero);
    }
    *resultVar = evTotal;
    return 0;
}


#pragma opt_lifetimes reset


#pragma opt_propagation reset



int func_0215B660(int callArg0, int callArg1, int callArg2)
{
    unsigned char monSlot[4];
    int workOrValue;
    int vmOrZero;
    u16 *resultVar;
vmOrZero = callArg0 + 0;
workOrValue = callArg1 + 0;
    resultVar = func_02159AE8((void *)callArg0, (void *)callArg1);
callArg0 = vmOrZero + 0;
callArg1 = workOrValue + 0;
    callArg0 = func_02159B10((void *)callArg0, (void *)callArg1);
callArg1 = callArg0 + 0;
vmOrZero = 0;
callArg0 = workOrValue + 0;
callArg2 = (int)(monSlot + 0);
*resultVar = vmOrZero;
    callArg0 = func_0215B4AC((void *)callArg0, callArg1, (void **)callArg2);
    if (callArg0 != 1) goto done;
    callArg0 = *(int *)monSlot;
callArg1 = 0xa0;
callArg2 = vmOrZero + 0;
    callArg0 = (int)func_02017E1C((void *)callArg0, callArg1, callArg2);
callArg0 = callArg0 << 0x10;
workOrValue = (unsigned)callArg0 >> 0x10;
    callArg0 = *(int *)monSlot;
callArg1 = 0xa1;
callArg2 = vmOrZero + 0;
    callArg0 = (int)func_02017E1C((void *)callArg0, callArg1, callArg2);
callArg0 = callArg0 << 0x10;
callArg0 = (unsigned)callArg0 >> 0x10;
    if (workOrValue == callArg0) goto differ;
    callArg0 = *(int *)monSlot;
callArg1 = 0x4c;
callArg2 = vmOrZero + 0;
    callArg0 = (int)func_02017E1C((void *)callArg0, callArg1, callArg2);
    if (callArg0 != 1) goto done;
differ:
callArg0 = 1;
*resultVar = callArg0;
done:
callArg0 = 0;
    return callArg0;
}



int func_0215B6C0(int callArg0, int callArg1, int callArg2)
{
    unsigned char monSlot[4];
    int cmdWorkCopy;
    int vmOrZero;
    u16 *resultVar;
vmOrZero = callArg0 + 0;
cmdWorkCopy = callArg1 + 0;
    resultVar = func_02159AE8((void *)callArg0, (void *)callArg1);
callArg0 = vmOrZero + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)func_02159B10((void *)callArg0, (void *)callArg1);
callArg1 = callArg0 + 0;
vmOrZero = 0;
callArg0 = cmdWorkCopy + 0;
callArg2 = (int)(monSlot + 0);
*resultVar = vmOrZero;
    callArg0 = func_0215B4AC((void *)callArg0, callArg1, (void **)callArg2);
    if (callArg0 != 1) goto done;
    callArg0 = *(int *)monSlot;
callArg1 = 0x4c;
callArg2 = vmOrZero + 0;
    callArg0 = func_02017E1C((void *)callArg0, callArg1, callArg2);
    if (callArg0 != 0) goto isEgg;
*resultVar = vmOrZero;
    goto done;
isEgg:
callArg0 = 1;
*resultVar = callArg0;
done:
callArg0 = 0;
    return callArg0;
}



int func_0215B704(int callArg0, int callArg1, int callArg2)
{
    unsigned char monSlot[4];
    int cmdWorkCopy;
    int vmOrZero;
    u16 *resultVar;
vmOrZero = callArg0 + 0;
cmdWorkCopy = callArg1 + 0;
    resultVar = func_02159AE8((void *)callArg0, (void *)callArg1);
callArg0 = vmOrZero + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)func_02159B10((void *)callArg0, (void *)callArg1);
callArg1 = callArg0 + 0;
vmOrZero = 0;
callArg0 = cmdWorkCopy + 0;
callArg2 = (int)(monSlot + 0);
*resultVar = vmOrZero;
    callArg0 = func_0215B4AC((void *)callArg0, callArg1, (void **)callArg2);
    if (callArg0 != 1) goto done;
    callArg0 = *(int *)monSlot;
callArg1 = 0x4c;
callArg2 = vmOrZero + 0;
    callArg0 = (int)func_02017E1C((void *)callArg0, (u32)callArg1, (u32)callArg2);
    if (callArg0 != 0) goto done;
    callArg0 = *(int *)monSlot;
callArg1 = 9;
callArg2 = vmOrZero + 0;
    callArg0 = (int)func_02017E1C((void *)callArg0, (u32)callArg1, (u32)callArg2);
*resultVar = callArg0;
done:
callArg0 = 0;
    return callArg0;
}


int func_0215B74C(int vm, int cmdWork)
{
    int partyIndex = func_02159B10((void *)vm, (void *)cmdWork);
    int amount = func_02159B10((void *)vm, (void *)cmdWork);
    int operation = func_02011330((struct ScriptVm *)vm);
    int mon = 0;
    u8 friendship;
    if (func_0215B4AC((void *)cmdWork, partyIndex, (void **)(&mon)) == 0) {
        return 0;
    }
    if (func_02017E1C((void *)mon, 0x4C, 0) == 1) {
        return 0;
    }
    friendship = func_02017E1C((void *)mon, 9, 0);
    switch (operation) {
    case 0:
        if ((u32)amount > 0xFF) {
            friendship = 0xFF;
        } else {
            friendship = amount;
        }
        break;
    case 1:
        if (friendship + amount > 0xFF) {
            friendship = 0xFF;
        } else {
            friendship = friendship + (u8)amount;
        }
        break;
    case 2:
        if (friendship < amount) {
            friendship = 0;
        } else {
            friendship = friendship - (u8)amount;
        }
        break;
    }
    func_02017E40((void *)mon, 9, friendship);
    return 0;
}


int func_0215B7E8(int vm,int cmdWork)
{
    u16 *resultVar = func_02159AE8((void *)vm,(void *)cmdWork);
    int partyIndex = func_02159B10((void *)vm,(void *)cmdWork);
    if (func_0215B4DC((void *)cmdWork,(void *)partyIndex,(void *)0x4C) != 0) *resultVar = 0x28A; else *resultVar = func_0215B4DC((void *)cmdWork,(void *)partyIndex,(void *)5);
    return 0;
}



int func_0215B824(int callArg0, int callArg1, int callArg2)
{
    int cmdWorkCopy;
    int vmCopy;
    u16 *resultVar;

vmCopy = callArg0 + 0;
cmdWorkCopy = callArg1 + 0;
    resultVar = func_02159AE8((void *)callArg0, (void *)callArg1);
callArg0 = vmCopy + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)func_02159B10((void *)callArg0, (void *)callArg1);
callArg1 = callArg0 + 0;
callArg0 = cmdWorkCopy + 0;
callArg2 = 0x6f;
    callArg0 = func_0215B4DC((void *)callArg0, (void *)callArg1, (void *)callArg2);
*resultVar = callArg0;
callArg0 = 0;
    return callArg0;}



int func_0215B848(int callArg0, int callArg1)
{
    int vmOrMode;
    int cmdWorkCopy;
    unsigned short *resultVar;
    void *party;

vmOrMode = callArg0 + 0;
cmdWorkCopy = callArg1 + 0;
    resultVar = func_02159AE8((void *)callArg0, (void *)callArg1);
callArg0 = vmOrMode + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)func_02159B10((void *)callArg0, (void *)callArg1);
vmOrMode = callArg0 + 0;
callArg0 = cmdWorkCopy + 0;
    party = func_0215A5E4((void *)callArg0);
    party = func_02012934(party);
    if (vmOrMode == 1) goto nonEgg;
    if (vmOrMode != 2) goto none;
    callArg0 = func_0201AB08(party);
truncate:
callArg0 = callArg0 << 0x10;
callArg0 = (unsigned)callArg0 >> 0x10;
    goto store;
nonEgg:
    callArg0 = POKEPARTY_FindFirstNonEgg(party);
    goto truncate;
none:
callArg0 = 0;
store:
*resultVar = callArg0;
callArg0 = 0;
    return callArg0;}



int func_0215B888(void *vm, void *cmdWork)
{
    u16 *resultVar = func_02159AE8(vm, cmdWork);
    int countKind = func_02159B10(vm, cmdWork);
    void *party = func_02012934(func_0215A5E4(cmdWork));
    int result;

    switch (countKind) {
    case 0:
        result = func_0201AA18(party);
        break;
    case 1:
        result = func_0201AA1C(party);
        break;
    case 2:
        result = func_0201AA50(party);
        break;
    case 3:
        result = func_0201AA88(party);
        break;
    case 4:
        result = func_0201AAD4(party);
        break;
    case 5: {
        int capacity = func_0201AA14(party);
        int count = func_0201AA18(party);
        if (capacity < count) {
            result = 0;
        } else {
            result = capacity - count;
        }
        break;
    }
    default:
        result = 0;
        break;
    }
    *resultVar = result;
    return 0;
}



int func_0215B904(void *vm, void *cmdWork)
{
    u32 species = func_02159B10(vm, cmdWork);
    u16 *resultVar = func_02159AE8(vm, cmdWork);
    void *party = func_02012934(func_0215A5E4(cmdWork));
    u16 partyCount = func_0201AA18(party);
    u16 matchCount = 0;
    int i;

    if (species != 0 && species <= 0x289) {
        for (i = 0; i < partyCount; i++) {
            void *member = func_0201AB28(party, i);
            u16 memberSpecies;

            if (member != 0 && func_02017E1C(member, 0x4C, 0) == 0) {
                memberSpecies = func_02017E1C(member, 5, 0);
                if (memberSpecies == species) {
                    matchCount++;
                }
            }
        }
        *resultVar = matchCount;
    } else {
        *resultVar = 0;
    }
    return 0;
}



int func_0215B994(void *vm, void *cmdWork)
{
    u16 *resultVar = func_02159AE8(vm, cmdWork);
    int countKind = func_02159B10(vm, cmdWork);
    void *gameData = func_0215A5E4(cmdWork);
    void *boxManager = (void *)func_0201293C(gameData);
    int result;

    func_02012934(gameData);
    switch (countKind) {
    case 0:
        result = func_02007984(boxManager);
        break;
    case 1:
    case 2:
        result = func_020079A0(boxManager);
        break;
    case 3:
        result = func_02007984(boxManager) - func_020079A0(boxManager);
        break;
    case 5: {
        int storedCount = func_02007984(boxManager);
        if (storedCount > 720) {
            result = 0;
        } else {
            result = 720 - storedCount;
        }
        break;
    }
    default:
        result = 0;
        break;
    }
    *resultVar = result;
    return 0;
}



int func_0215BA18(void *vm, void *cmdWork)
{
    u32 species = func_02159B10(vm, cmdWork);
    u16 *foundVar = func_02159AE8(vm, cmdWork);
    u16 *indexVar = func_02159AE8(vm, cmdWork);
    void *party = func_02012934(func_0215A5E4(cmdWork));
    u16 partyCount = func_0201AA18(party);
    int i;

    if (species != 0 && species <= 0x289) {
        for (i = 0; i < partyCount; i++) {
            void *member = func_0201AB28(party, i);
            u16 memberSpecies;

            if (member != 0 && func_02017E1C(member, 0x4C, 0) == 0) {
                memberSpecies = func_02017E1C(member, 5, 0);
                if (memberSpecies == species) {
                    break;
                }
            }
        }
        if (i < partyCount) {
            *foundVar = 1;
            *indexVar = i;
        } else {
            *foundVar = 0;
        }
    } else {
        *foundVar = 0;
    }
    return 0;
}



int func_0215BAB0(int callArg0, int callArg1, int callArg2)
{
    int mon;
    int cmdWorkCopy;
    int vmCopy;
    int moveId;
    u16 *resultVar;
vmCopy = callArg0 + 0;
cmdWorkCopy = callArg1 + 0;
    resultVar = func_02159AE8((void *)callArg0, (void *)callArg1);
callArg0 = vmCopy + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)func_02159B10((void *)callArg0, (void *)callArg1);
moveId = callArg0 + 0;
callArg0 = vmCopy + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)func_02159B10((void *)callArg0, (void *)callArg1);
callArg1 = callArg0 + 0;
callArg0 = 0;
*resultVar = callArg0;
callArg0 = cmdWorkCopy + 0;
callArg2 = (int)&mon;
    callArg0 = func_0215B4AC((void *)callArg0, callArg1, (void **)callArg2);
    if (callArg0 != 1) goto done;
    callArg0 = mon;
callArg1 = moveId + 0;
    callArg0 = func_0215B500(callArg0, callArg1);
    if (callArg0 != 1) goto done;
callArg0 = 1;
*resultVar = callArg0;
done:
callArg0 = 0;
    return callArg0;
}



int func_0215BAF4(void *vm, void *cmdWork)
{
    void *party = func_02012934(func_0215A5E4(cmdWork));
    u16 *resultVar = func_02159AE8(vm, cmdWork);
    void *moveId = (void *)func_02159B10(vm, cmdWork);
    int i;
    int partyCount = func_0201AA18(party);

    *resultVar = 6;
    for (i = 0; i < partyCount; i++) {
        if (func_0215B500((int)func_0201AB28(party, i), (int)moveId) == 1) {
            *resultVar = i;
            break;
        }
    }
    return 0;
}



int func_0215BB50(void *vm, void *cmdWork)
{
    void *gameData;
    u16 heapId;
    u16 *resultVar;
    int species;
    int form;
    int level;
    PokemonSpec spec;

    func_0215A5DC(cmdWork);
    gameData = func_0215A5E4(cmdWork);
    heapId = func_0215A5CC(cmdWork);
    func_02012934(gameData);
    func_02012944(gameData);
    resultVar = func_02159AE8(vm, cmdWork);
    species = func_02159B10(vm, cmdWork);
    form = func_02159B10(vm, cmdWork);
    level = func_02159B10(vm, cmdWork);
    spec.heapId = heapId;
    spec.species = species;
    spec.form = form;
    spec.level = level;
    spec.heldItem = 0;
    spec.genderMode = 2;
    spec.natureMode = 2;
    spec.shinyMode = 2;
    spec.ballItem = 4;
    *resultVar = func_0215C510(gameData, &spec);
    return 0;
}







/*
 * Sibling of func_0215BB50 (same request record, eight reads instead of
 * three, three of them clamped to 2), and of func_0215C200: the u16 locals
 * are what make the second clamp reload its value from the spill slot.
 */
int func_0215BBD0(void *vm, void *cmdWork)
{
    void *gameData;
    u16 heapId;
    u16 *resultVar;
    u16 species;
    u16 form;
    u16 level;
    u16 genderMode;
    u16 natureMode;
    u16 shinyMode;
    u16 heldItem;
    u16 ballItem;
    PokemonSpec spec;

    func_0215A5DC(cmdWork);
    gameData = func_0215A5E4(cmdWork);
    heapId = func_0215A5CC(cmdWork);
    func_02012934(gameData);
    func_02012944(gameData);
    resultVar = func_02159AE8(vm, cmdWork);
    species = func_02159B10(vm, cmdWork);
    form = func_02159B10(vm, cmdWork);
    level = func_02159B10(vm, cmdWork);
    genderMode = func_02159B10(vm, cmdWork);
    natureMode = func_02159B10(vm, cmdWork);
    shinyMode = func_02159B10(vm, cmdWork);
    heldItem = func_02159B10(vm, cmdWork);
    ballItem = func_02159B10(vm, cmdWork);
    spec.heapId = heapId;
    spec.species = species;
    spec.form = form;
    spec.level = level;
    spec.heldItem = heldItem;
    spec.genderMode = genderMode;
    if (spec.genderMode >= 3)
        spec.genderMode = 2;
    spec.natureMode = natureMode;
    if (spec.natureMode >= 3)
        spec.natureMode = 2;
    spec.shinyMode = shinyMode;
    if (spec.shinyMode >= 3)
        spec.shinyMode = 2;
    spec.ballItem = ballItem;
    *resultVar = func_0215C510(gameData, &spec);
    return 0;
}







int func_0215BCA0(int callArg0, int callArg1, int callArg2)
{
    int mon;
    int moveSlot;
    int moveCount;
    int zero;
    u16 *resultVar;
moveCount = callArg0 + 0;
moveSlot = callArg1 + 0;
    resultVar = func_02159AE8((void *)callArg0, (void *)callArg1);
callArg0 = moveCount + 0;
callArg1 = moveSlot + 0;
    callArg0 = (int)func_02159B10((void *)callArg0, (void *)callArg1);
callArg1 = callArg0 + 0;
callArg0 = moveSlot + 0;
callArg2 = (int)&mon;
moveCount = 0;
    callArg0 = func_0215B4AC((void *)callArg0, callArg1, (void **)callArg2);
    if (callArg0 != 1) goto store;
moveSlot = moveCount + 0;
zero = moveCount + 0;
countSlot:
callArg1 = moveSlot + 0;
    callArg0 = mon;
callArg1 = callArg1 + 0x36;
callArg2 = zero + 0;
    callArg0 = func_02017E1C((void *)callArg0, callArg1, callArg2);
    if (callArg0 == 0) goto nextSlot;
moveCount = moveCount + 1;
nextSlot:
moveSlot = moveSlot + 1;
    if (moveSlot < 4) goto countSlot;
store:
*resultVar = moveCount;
callArg0 = 0;
    return callArg0;
}







int func_0215BCE8(void *vm, void *cmdWork)
{
    u16 *resultVar;
    void *partyIndex;
    char *moveSlot;
    void *mon;

    resultVar = func_02159AE8(vm, cmdWork);
    partyIndex = (char *)func_02159B10(vm, cmdWork);
    moveSlot = (char *)func_02159B10(vm, cmdWork);
    if (func_0215B4AC(cmdWork, (u32)partyIndex, &mon) == 1) {
        *resultVar = func_02017E1C(mon, (u32)(moveSlot + 0x36), 0);
    } else {
        *resultVar = 0;
    }
    return 0;
}







/*
 * Script command: reads a party slot, a move slot and a move. A move slot
 * past 4 goes to func_020180F4 (teach into a free slot); a zero move deletes
 * the slot, shifting the later moves (ids 0x36 move, 0x3A pp, 0x3E pp-ups)
 * down one; otherwise func_020181F4 sets the move into the slot.
 */
int func_0215BD2C(void *vm, void *cmdWork)
{
    u16 partyIndex;
    u16 moveSlot;
    u16 move;
    void *mon;
    u32 saved;
    u8 i;
    u32 m;
    u32 ppUp;
    u32 pp;

    partyIndex = func_02159B10(vm, cmdWork);
    moveSlot = func_02159B10(vm, cmdWork);
    move = func_02159B10(vm, cmdWork);
    if (func_0215B4AC(cmdWork, partyIndex, &mon) == 0) {
        return 0;
    }
    saved = POKE_TOOL_DecodePartyParam(mon);
    if (moveSlot > 4) {
        func_020180F4(mon, move);
    } else if (move == 0) {
        i = moveSlot;
        if (moveSlot < 3) {
            for (; i < 3; i++) {
                m = func_02017E1C(mon, i + 0x37, 0);
                if (m == 0) {
                    break;
                }
                ppUp = func_02017E1C(mon, i + 0x3F, 0);
                pp = func_02017E1C(mon, i + 0x3B, 0);
                func_02017E40(mon, i + 0x36, m);
                func_02017E40(mon, i + 0x3E, ppUp);
                func_02017E40(mon, i + 0x3A, pp);
            }
        }
        func_02017E40(mon, i + 0x36, 0);
        func_02017E40(mon, i + 0x3E, 0);
        func_02017E40(mon, i + 0x3A, 0);
    } else {
        func_020181F4(mon, move, (u8)moveSlot);
    }
    POKE_TOOL_EncodePartyParam(mon, saved);
    return 0;
}







/*
 * Script command: is the party member in the given slot the player's own
 * catch (trainer id, OT name, OT gender and game version all match)?
 * Writes the answer to a script variable.
 *
 * Levers (2026-09-28 tree_ov010_4): the allocation check as
 * `if (a && b) {...} else fail` (moves the failure block after the name
 * test), the name test as `== 0` (STRBUF_IsEqual answers "equal"), and the
 * version read into a local before the compare (`cmp r0, r1`).
 */
int func_0215BE24(void *vm, void *cmdWork)
{
    void *myStatus;
    void *mon;
    u16 *resultVar;
    u32 partyIndex;
    u32 heapId;
    void *monOtName;
    void *playerName;
    u32 gameVersion;

    resultVar = func_02159AE8(vm, cmdWork);
    partyIndex = func_02159B10(vm, cmdWork);
    myStatus = func_02012944(func_0215A5E4(cmdWork));
    mon = 0;
    if (!func_0215B4AC(cmdWork, partyIndex, &mon)) {
        *resultVar = 0;
        return 0;
    }
    if (func_02017E1C(mon, 7, 0) != func_02008530(myStatus)) {
        *resultVar = 0;
        return 0;
    }
    heapId = func_0215A5CC(cmdWork);
    monOtName = func_020457B0(16, heapId);
    playerName = func_020457B0(16, heapId);
    if (monOtName != 0 && playerName != 0) {
        func_02017E1C(mon, 0x8D, (u32)monOtName);
        func_02008500(myStatus, playerName);
        if (STRBUF_IsEqual(monOtName, playerName) == 0) {
            func_02045808(monOtName);
            func_02045808(playerName);
            *resultVar = 0;
            return 0;
        }
    } else {
        *resultVar = 0;
        return 0;
    }
    func_02045808(monOtName);
    func_02045808(playerName);
    if (func_02017E1C(mon, 0x9A, 0) != func_02008550(myStatus)) {
        *resultVar = 0;
        return 0;
    }
    gameVersion = func_02017E1C(mon, 0x77, 0);
    if (gameVersion != g0209DF08) {
        *resultVar = 0;
        return 0;
    }
    *resultVar = 1;
    return 0;
}







int func_0215BF30(void *vm, void *cmdWork)
{
    void *partyIndex = (void *)func_02159B10(vm, cmdWork);
    void *form = (void *)func_02159B10(vm, cmdWork);
    void *gameData;
    void *mon;

    func_0215A5F4(cmdWork);
    gameData = func_020120F4(func_0215A5DC(cmdWork));
    mon = func_0201AB28(func_02012934(gameData), (u32)partyIndex);
    func_02017988(mon, (u32)form);
    func_0200CFA0(func_0200CA1C(gameData), mon);
    return 0;
}







int func_0215BF7C(void *vm, void *cmdWork)
{
    void *partyIndex = (void *)func_02159B10(vm, cmdWork);
    void *form = (void *)func_02159B10(vm, cmdWork);
    void *moveSlot = (void *)func_02159B10(vm, cmdWork);
    void *gameData;
    void *mon;

    func_0215A5F4(cmdWork);
    gameData = func_020120F4(func_0215A5DC(cmdWork));
    mon = func_0201AB28(func_02012934(gameData), (u32)partyIndex);
    POKE_TOOL_SetRotomFormMove(mon, (u32)moveSlot, (u32)form);
    func_0200CFA0(func_0200CA1C(gameData), mon);
    return 0;
}







int func_0215BFD4(int callArg0, int callArg1, int callArg2)
{
    int mon;
    int cmdWorkCopy;
    int partyIndex;
    int heapId;
    void *relearnMoves;
    u16 *resultVar;
partyIndex = callArg0 + 0;
cmdWorkCopy = callArg1 + 0;
    resultVar = func_02159AE8((void *)callArg0, (void *)callArg1);
callArg0 = partyIndex + 0;
callArg1 = cmdWorkCopy + 0;
    callArg0 = (int)func_02159B10((void *)callArg0, (void *)callArg1);
partyIndex = callArg0 + 0;
callArg0 = cmdWorkCopy + 0;
    callArg0 = func_0215A5CC((void *)callArg0);
heapId = callArg0 + 0;
callArg0 = cmdWorkCopy + 0;
callArg1 = partyIndex + 0;
callArg2 = (int)&mon;
    callArg0 = func_0215B4AC((void *)callArg0, callArg1, (void **)callArg2);
    if (callArg0 != 1) goto done;
    callArg0 = mon;
callArg1 = heapId + 0;
    relearnMoves = func_0216F948((void *)callArg0, callArg1);
    callArg0 = func_0216FAA0(relearnMoves);
*resultVar = callArg0;
    callArg0 = func_020307B0(relearnMoves);
done:
callArg0 = 0;
    return callArg0;
}







int func_0215C01C(void *vm, void *cmdWork)
{
    u16 *resultVar = func_02159AE8(vm, cmdWork);
    int partyIndex = func_02159B10(vm, cmdWork);
    int tableIndex = func_02159B10(vm, cmdWork);
    u16 monValue = func_0215B4DC(cmdWork, (void *)partyIndex, (void *)0x95);

    if (monValue == d_02171180[tableIndex]) {
        *resultVar = 1;
    } else {
        *resultVar = 0;
    }
    return 0;
}







int func_0215C064(void *vm, void *cmdWork)
{
    u16 *firstResultVar = func_02159AE8(vm, cmdWork);
    u16 *secondResultVar = func_02159AE8(vm, cmdWork);
    u16 *thirdResultVar = func_02159AE8(vm, cmdWork);
    void *mon;

    if (func_0215B4AC(cmdWork, func_02159B10(vm, cmdWork), &mon) == 1) {
        *firstResultVar = func_02017E1C(mon, 0x92, 0);
        *secondResultVar = func_02017E1C(mon, 0x93, 0);
        *thirdResultVar = func_02017E1C(mon, 0x94, 0);
    } else {
        *firstResultVar = 0;
        *secondResultVar = 0;
        *thirdResultVar = 0;
    }
    return 0;
}







int func_0215C0D0(void *vm, void *cmdWork)
{
    int partyIndex = func_02159B10(vm, cmdWork);
    u32 paramId = func_02159B10(vm, cmdWork);
    u32 value = func_02159B10(vm, cmdWork);
    void *mon;
    u32 i;

    for (i = 0; i < 6; i++) {
        if (paramId == d_0217118E[i].paramId) {
            if (value <= d_0217118E[i].maxValue && func_0215B4AC(cmdWork, partyIndex, &mon) == 1) {
                func_02017E40(mon, paramId, value);
                func_020185C4(mon);
            }
            return 0;
        }
    }
    return 0;
}






/*
 * lever: selector remains live in r2 and is func_0215B4DC's third argument.
 */
int func_0215C138(void *vm, void *cmdWork)
{
    u16 *resultVar;
    u32 partyIndex;
    u32 paramId;
    u32 i;
    resultVar = func_02159AE8(vm, cmdWork);
    partyIndex = func_02159B10(vm, cmdWork);
    paramId = func_02159B10(vm, cmdWork);
    for (i = 0; i < 12; i++) {
        if (paramId == d_02171182[i]) {
            *resultVar = func_0215B4DC(cmdWork, (void *)partyIndex, (void *)paramId);
            return 0;
        }
    }
    *resultVar = 0;
    return 0;
}





/*
 * Script command: reads a destination variable and three arguments,
 * fills a 0x24-byte spec on the stack (function 0x0215C4C8 consumes it)
 * and stores the returned value through the destination.
 */
int func_0215C180(void *vm, void *cmdWork)
{
    void *gameData;
    u16 heapId;
    u16 *resultVar;
    u32 species;
    u32 form;
    u32 level;
    PokemonSpec spec;

    func_0215A5DC(cmdWork);
    gameData = func_0215A5E4(cmdWork);
    heapId = func_0215A5CC(cmdWork);
    func_02012934(gameData);
    func_02012944(gameData);
    resultVar = func_02159AE8(vm, cmdWork);
    species = func_02159B10(vm, cmdWork);
    form = func_02159B10(vm, cmdWork);
    level = func_02159B10(vm, cmdWork);
    spec.heapId = heapId;
    spec.species = species;
    spec.form = form;
    spec.level = level;
    spec.heldItem = 0;
    spec.genderMode = 2;
    spec.natureMode = 2;
    spec.shinyMode = 2;
    spec.ballItem = 4;
    *resultVar = func_0215C4C8(gameData, &spec);
    return 0;
}





/*
 * Script command, sibling of func_0215C180: reads a destination variable
 * and eight arguments, three of them clamped to 2 when 3 or more, fills
 * the 0x24-byte spec func_0215C4C8 consumes and stores its result.
 *
 * The arguments are u16 (func_02159B10 returns u16): the widening copy
 * into each int field is why the clamp of the spilled one reloads its
 * slot, and comparing the int field (not the u16 local) gives blt.
 */
int func_0215C200(void *vm, void *cmdWork)
{
    void *gameData;
    u16 heapId;
    u16 *resultVar;
    u16 species;
    u16 form;
    u16 level;
    u16 genderMode;
    u16 natureMode;
    u16 shinyMode;
    u16 heldItem;
    u16 ballItem;
    PokemonSpec spec;

    func_0215A5DC(cmdWork);
    gameData = func_0215A5E4(cmdWork);
    heapId = func_0215A5CC(cmdWork);
    func_02012934(gameData);
    func_02012944(gameData);
    resultVar = func_02159AE8(vm, cmdWork);
    species = func_02159B10(vm, cmdWork);
    form = func_02159B10(vm, cmdWork);
    level = func_02159B10(vm, cmdWork);
    genderMode = func_02159B10(vm, cmdWork);
    natureMode = func_02159B10(vm, cmdWork);
    shinyMode = func_02159B10(vm, cmdWork);
    heldItem = func_02159B10(vm, cmdWork);
    ballItem = func_02159B10(vm, cmdWork);
    spec.heapId = heapId;
    spec.species = species;
    spec.form = form;
    spec.level = level;
    spec.heldItem = heldItem;
    spec.genderMode = genderMode;
    if (spec.genderMode >= 3) {
        spec.genderMode = 2;
    }
    spec.natureMode = natureMode;
    if (spec.natureMode >= 3) {
        spec.natureMode = 2;
    }
    spec.shinyMode = shinyMode;
    if (spec.shinyMode >= 3) {
        spec.shinyMode = 2;
    }
    spec.ballItem = ballItem;
    *resultVar = func_0215C4C8(gameData, &spec);
    return 0;
}





/*
 * Script command: add a level-1 Pokemon egg of the given species and
 * form to the party (hatch counter from the personal data, the egg name
 * from message 0x28A), writing 1 to the result word, or 0 when the
 * party is full. First draft.
 */
int func_0215C2D0(void *vm, void *cmdWork)
{
    void *gameData;
    u32 heapId;
    void *party;
    void *myStatus;
    u16 *resultVar;
    u32 species;
    u32 form;
    void *mon;
    u32 tempStrbuf;
    u32 personal;
    u32 hatchCycles;

    func_0215A5DC(cmdWork);
    gameData = func_0215A5E4(cmdWork);
    heapId = func_0215A5CC(cmdWork);
    party = func_02012934(gameData);
    myStatus = func_02012944(gameData);
    resultVar = func_02159AE8(vm, cmdWork);
    species = func_02159B10(vm, cmdWork);
    form = func_02159B10(vm, cmdWork);
    if ((int)func_0201AA14(party) <= (int)func_0201AA18(party)) {
        *resultVar = 0;
        return 0;
    }
    mon = func_020173F0(species, 1, (u64)-1, heapId);
    func_02017E40(mon, 0x6F, form);
    tempStrbuf = (u32)func_02008510(func_02012944(gameData), heapId);
    func_02017E40(mon, 0x8D, tempStrbuf);
    func_02045808((struct Strbuf *)tempStrbuf);
    personal = (u32)func_0201ADE4((u16)func_02017E1C(mon, 5, 0), (u16)func_02017E1C(mon, 0x6F, 0), heapId);
    hatchCycles = func_0201AE1C((const struct PersonalData *)personal, 0x15);
    func_0201AE14((void *)personal);
    func_02017E40(mon, 9, hatchCycles);
    func_02017E40(mon, 0x4C, 1);
    tempStrbuf = (u32)func_02045EC0(g_020A7370, 0x28A);
    func_02017E40(mon, 0x73, tempStrbuf);
    func_02045808((struct Strbuf *)tempStrbuf);
    func_020185C4(mon);
    func_0202F190(mon, 5, myStatus, 0xEA63, heapId);
    func_0201A98C(party, mon);
    func_020307B0(mon);
    *resultVar = 1;
    return 0;
}





/*
 * lever: POKE_TOOL_CreateEx's matched signature has two u64 inputs; widening the
 * personality result to u64 schedules its high zero before the low-word store.
 */
void *func_0215C40C(void *gameData, PokemonSpec *spec)
{
    void *myStatus;
    void *trainerIdOrMon;
    u32 personalRnd;
    myStatus = func_02012944(gameData);
    trainerIdOrMon = (void *)func_02008530((const struct MyStatus *)func_02012944(gameData));
    personalRnd = func_020186C8((u32)trainerIdOrMon, (u16)spec->species, (u16)spec->form, (u32)spec->natureMode, (u32)spec->genderMode, (u32)spec->shinyMode);
    trainerIdOrMon = POKE_TOOL_CreateEx(spec->species, spec->level, (u32)trainerIdOrMon, -1, personalRnd, spec->heapId);
    func_02017E40(trainerIdOrMon, 0x6F, spec->form);
    func_02017E40(trainerIdOrMon, 6, spec->heldItem);
    if (func_02020FE4(spec->ballItem, 0xF, spec->heapId) == 4)
        func_02017E40(trainerIdOrMon, 0x98, (u32)PALANM_GetPairedCodeForFirst((u16)spec->ballItem));
    func_0202F190(trainerIdOrMon, 0, (void *)myStatus, func_02013E4C(func_02012AC8(func_020127A4(gameData))), spec->heapId);
    func_020185C4(trainerIdOrMon);
    return trainerIdOrMon;
}






int func_0215C4C8(void *gameData, void *spec)
{
    void *boxManager;
    void *mon;

    boxManager = (void *)func_0201293C(gameData);
    if (func_02007984(boxManager) >= 0x2D0)
        return 0;
    mon = func_0215C40C(gameData, spec);
    func_020074D8(boxManager, (const struct BoxPokemonParam *)((u32)POKE_TOOL_GetBoxParam(mon)));
    func_0200CDE0(func_0200CA1C(gameData), mon);
    func_020307B0(mon);
    return 1;
}






int func_0215C510(void *gameData, void *spec)
{
    void *party;
    void *mon;

    party = func_02012934(gameData);
    if ((int)func_0201AA14(party) <= (int)func_0201AA18(party))
        return 0;
    mon = func_0215C40C(gameData, spec);
    func_0201A98C(party, mon);
    func_0200CDE0(func_0200CA1C(gameData), mon);
    func_020307B0(mon);
    return 1;
}





/*
 * interfaces: Lookup results used despite legacy void forwarders; observed inputs retained.
 */
int func_0215C558(int vm,int cmdWork)
{
    void *gameData = func_0215A5E4((void *)cmdWork);
    int value;
    func_020127A4(gameData);
    value = func_02159B10((void *)vm,(void *)cmdWork);
    func_0200C278(func_02012F08(gameData),value);
    return 0;
}





int func_0215C584(int vm,int cmdWork)
{
    void *gameData = func_0215A5E4((void *)cmdWork);
    int value;
    func_020127A4(gameData);
    value = func_02159B10((void *)vm,(void *)cmdWork);
    func_0200C29C(func_02012F08(gameData),value);
    return 0;
}






int func_0215C5B0(void *vm, void *cmdWork)
{
    u16 *resultVar = func_02159AE8(vm, cmdWork);
    unsigned int value = func_02159B10(vm, cmdWork);
    void *gameData = func_0215A5E4(cmdWork);
    func_020127A4(gameData);
    *resultVar = value <= func_0200C274(func_02012F08(gameData)) ? 1 : 0;
    return 0;
}





/*
 * Two overlay lookups on the second argument, the second of them classified
 * by an arm9 call, then submitted together.
 */
int func_0215C5EC(void *vm, void *cmdWork)
{
    void *eventSlot = func_0215A5F4(cmdWork);

    func_0215897C(eventSlot, FIELD_STATUS_CreateFieldOpenEvent(func_0215A5DC(cmdWork)));

    return 1;
}








int func_0215C610(int callArg0, int callArg1)
{
    int cmdWorkCopy;
    void *eventSlot;
    void *gameSystem;
    void *fieldMap;

cmdWorkCopy = callArg1 + 0;
callArg0 = cmdWorkCopy + 0;
    eventSlot = func_0215A5F4((void *)callArg0);
callArg0 = cmdWorkCopy + 0;
    gameSystem = func_0215A5DC((void *)callArg0);
    fieldMap = func_0201210C(gameSystem);
    callArg0 = FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, (int)fieldMap);
callArg1 = callArg0 + 0;
    func_0215897C(eventSlot, (void *)callArg1);
callArg0 = 1;
    return callArg0;}









/*
 * Starts a child process from an overlay on behalf of a script command:
 * allocates the 12-byte hand-off record (work pointer and two words),
 * launches the process over the work with GAMESYSTEM_CallProc, parks the record in the
 * script's slot and waits on func_0215C69C.
 */
void func_0215C63C(void *vm, void *cmdWork, u32 overlayId, const void *procData, void *procWork, u32 onFinish, u32 userData)
{
    void *gameSystem;
    void **handoffSlot;
    ScriptProcHandoff *handoff;

    gameSystem = func_0215A5DC(cmdWork);
    handoffSlot = func_02158FB4(func_0215A5F4(cmdWork));
    handoff = func_02030734(4, sizeof(ScriptProcHandoff), 1, d_021728F0, 0x8B);
    handoff->work = procWork;
    handoff->userData = userData;
    handoff->onFinish = onFinish;
    GAMESYSTEM_CallProc(gameSystem, overlayId, (void *)procData, procWork);
    *handoffSlot = handoff;
    func_020113D0(vm, (int)func_0215C69C);
}









int func_0215C69C(int callArg0, int callArg1)
{
    int cmdWorkOrSlot;
    int handoff;
    void *gameSystem;

cmdWorkOrSlot = callArg1 + 0;
callArg0 = cmdWorkOrSlot + 0;
    gameSystem = func_0215A5DC((void *)callArg0);
callArg0 = cmdWorkOrSlot + 0;
    callArg0 = (int)func_0215A5F4((void *)callArg0); /* int-typed on purpose: pointer local changes codegen */
cmdWorkOrSlot = callArg0 + 0;
    callArg0 = func_02158FB8((void *)callArg0);
handoff = callArg0 + 0;
    callArg0 = GAMESYSTEM_GetProcStatus(gameSystem);
    if (callArg0 == 0) goto checkCallback;
callArg0 = 0;
    return callArg0;
checkCallback:
callArg1 = (int)((ScriptProcHandoff *)handoff)->onFinish;
    if (callArg1 == 0) goto noCallback;
callArg0 = handoff + 0;
    callArg0 = ((int (*)())callArg1)(callArg0);
    goto clearSlot;
noCallback:
callArg0 = (int)((ScriptProcHandoff *)handoff)->work;
    if (callArg0 == 0) goto freeUserData;
    func_020307B0((void *)callArg0);
freeUserData:
callArg0 = (int)((ScriptProcHandoff *)handoff)->userData;
    if (callArg0 == 0) goto clearSlot;
    func_020307B0((void *)callArg0);
clearSlot:
callArg0 = cmdWorkOrSlot + 0;
    callArg0 = func_02158FBC(callArg0);
callArg0 = 1;
    return callArg0;}









int func_0215C6F0(int callArg0, int callArg1)
{
    void *eventSlot;

callArg0 = callArg1 + 0;
    eventSlot = func_0215A5F4((void *)callArg0);
    callArg0 = func_02158FBC(eventSlot);
callArg0 = 1;
    return callArg0;}







/*
 * lever: Stores in both if/else arms retain the zero-first full branch;
 * a local flag (u32, u16, or enum) folds to 42 bytes and DIFF 33.
 */
void func_0215C700(BagCloseData *closeData)
{
    BagParamResult *bagParam = closeData->bagParam;
    BagResultVars *resultVars = closeData->resultVars;
    if (bagParam->selected == 0)
        *resultVars->selectedVar = B_FALSE;
    else
        *resultVars->selectedVar = B_TRUE;
    *resultVars->itemVar = bagParam->itemId;
    func_020307B0(closeData->resultVars);
    func_020307B0(closeData->bagParam);
}








/*
 * Script command: reads a selector and two words, maps the selector
 * (0 -> 4, 1 -> 5, else 0), then opens overlay 0x46 over a work built
 * from BAG_PARAM_Create with an 8-byte hand-off record.
 *
 * 2026-10-05 (wave D9): EXACT. The ov070 token on the d_021BB96C data line
 * (the proc table lives in ov070, the overlay this function opens) gave the
 * witness; ov070_id then resolved through the overlay_id walk (func_0215C63C
 * is a registered consumer). Source unchanged.
 */
int func_0215C72C(void *vm, void *cmdWork)
{
    u32 bagMode;
    u32 selectedVar;
    u32 itemVar;
    u32 bagType;
    void *bagParam;
    u32 *closeData;

    func_0215A5DC(cmdWork);
    func_0215A5F4(cmdWork);
    bagMode = func_02159B10(vm, cmdWork);
    selectedVar = (u32)func_02159AE8(vm, cmdWork);
    itemVar = (u32)func_02159AE8(vm, cmdWork);
    if (bagMode == 0)
        bagType = 4;
    else if (bagMode == 1)
        bagType = 5;
    else
        bagType = 0;
    bagParam = BAG_PARAM_Create((const struct GameData *)func_0215A5E4(cmdWork), 0, bagType, 4);
    closeData = func_02030734(4, 8, 1, d_021728F0, 0x118);
    closeData[0] = selectedVar;
    closeData[1] = itemVar;
    func_0215C63C(vm, cmdWork, (u32)ov070_id, d_021BB96C, bagParam, (u32)func_0215C700, (u32)closeData);
    return 1;
}






/*
 * Unlabelled Thumb leaf (callback of func_0215C7E0): stores whether the
 * first record's word at +4 equals 1 into the halfword the second record
 * points to, then frees the first record's first word.
 */
void func_0215C7C4(GtsCallbackData *callbackData)
{
    if (callbackData->param->result == 1)
        *callbackData->resultVar = 1;
    else
        *callbackData->resultVar = 0;
    func_020307B0(callbackData->param);
}








/*
 * Script command: allocates two 8-byte records (a work holding the
 * system's word, then a hand-off holding the work and one script word),
 * launches overlay 0x88 over them with the func_0215C7C4 callback and
 * parks the result in the script's slot.
 *
 * 2026-10-05 (wave D9): EXACT. d_021C78A4 resolves once its symbols line carries the ov136 token (the overlay the function loads); func_0215C7C4 has its own witness.
 */
int func_0215C7E0(void *vm, void *cmdWork)
{
    void *eventSlot;
    void *gameSystem;
    void *gameData;
    void *fieldMap;
    u32 *gtsParam;
    u32 *callbackData;

    eventSlot = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    gtsParam = func_02030734(4, 8, 0, d_021728F0, 0x14F);
    callbackData = func_02030734(4, 8, 0, d_021728F0, 0x150);
    gtsParam[0] = (u32)gameData;
    callbackData[0] = (u32)gtsParam;
    callbackData[1] = (u32)func_02159AE8(vm, cmdWork);
    func_0215897C(eventSlot, func_02014840(gameSystem, (int)fieldMap, (u32)ov136_id, (int)d_021C78A4, (int)gtsParam, (int)((void *)func_0215C7C4), (int)callbackData));
    return 1;
}








int func_0215C870(int callArg0, int callArg1)
{
    int callbackData;

callbackData = callArg0 + 0;
callArg0 = (int)((RelearnCallbackData *)callbackData)->param;
callArg0 = ((MoveRelearnParam *)callArg0)->learned;
    if (callArg0 == 0) goto notLearned;
    if (callArg0 == 1) goto learned;
notLearned:
callArg1 = 0;
    goto store;
learned:
callArg1 = 1;
store:
callArg0 = (int)((RelearnCallbackData *)callbackData)->resultVar;
*(u16 *)callArg0 = callArg1;
callArg0 = (int)((RelearnCallbackData *)callbackData)->param;
callArg0 = (int)((MoveRelearnParam *)callArg0)->relearnMoves;
    callArg0 = (int)func_020307B0((void *)callArg0);
callArg0 = (int)((RelearnCallbackData *)callbackData)->param;
    callArg0 = func_0216F940(callArg0);
    return callArg0;}








static inline void MoveRelearnParam_Init(MoveRelearnParam *param, void *mon, void *myStatus, void *gameSystem, void *moves)
{
    enum One { ONE = 1 } one;
    param->mon = mon;
    param->myStatus = myStatus;
    param->flags = 0;
    param->gameSystem = gameSystem;
    param->relearnMoves = moves;
    one = ONE;
    param->enabled = one;
}







/*
 * lever: enum one assigned immediately before the enabled store in the inline
 * record initializer separates it from the constant return and selects r0.
 */
int func_0215C89C(void *vm, void *cmdWork)
{
    void *eventSlot;
    void *gameSystem;
    void *gameData;
    void *fieldMap;
    u32 resultVar;
    u32 partyIndex;
    void *mon;
    void *myStatus;
    void *relearnMoves;
    MoveRelearnParam *relearnParam;
    u32 *callbackData;

    eventSlot = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    gameData = func_020120F4(gameSystem);
    fieldMap = func_0201210C(gameSystem);
    resultVar = (u32)func_02159AE8(vm, cmdWork);
    partyIndex = func_02159B10(vm, cmdWork);
    mon = func_0201AB28(func_02012934(gameData), partyIndex);
    myStatus = func_02012944(gameData);
    relearnMoves = func_0216F948(mon, 4);
    relearnParam = func_0216F918(4);
    MoveRelearnParam_Init(relearnParam, mon, myStatus, gameSystem, relearnMoves);
    callbackData = func_02030734(4, 8, 0, d_021728F0, 0x19B);
    callbackData[0] = (u32)relearnParam;
    callbackData[1] = resultVar;
    func_0215897C(eventSlot, func_02014808(gameSystem, (int)fieldMap, (u32)ov173_id, (int)d_021B81D0, (int)relearnParam, (int)((void *)func_0215C870), (int)callbackData));
    return 1;
}








/*
 * Script command: opens the ov071 process on a 0x40-byte work. When the
 * current link record is usable (another player's slot, flagged, and
 * marked at +0x922) the work takes that player's name and profile;
 * otherwise it is filled from the local player. The chosen slot index
 * (0 for the local player) is stored at +0x3C.
 *
 * MATCH, bytes exact (2026-09-28 tree_ov010_4; lever: one `idx` local
 * set in both arms, which is what keeps the r6 zero). Three wildcards:
 * ov011 0x02175FB4 is an unlabelled leaf (`ldrb r0, [r0, #0x10]; bx lr`),
 * and the pooled 0x47 (ov071_id) and 0x021BA758 (the ov071 process
 * template) only reach an overlay loader through func_0215C63C, so no
 * class attests them.
 *
 * 2026-10-05 (wave D9): d_021BA758 now resolves with the ov099 token on its symbols line (`data  ov099  a1`; other covering overlays stay contested or unresolved). Only ov071_id remains: it reaches func_0215C63C, which is not in match.py OVERLAY_ID_CONSUMERS (forwards r2 to GAMESYSTEM_CallProc r1); a data token on the id line does not help. Needs the consumer entry (tools), not C.
 */
int func_0215C95C(void *vm, void *cmdWork)
{
    void *gameSystem;
    void *gameComm;
    void *gameData;
    ProfileProcWork *work;
    CommState *commState;
    u8 playerIndex;

    gameSystem = func_0215A5DC(cmdWork);
    gameComm = (void *)func_02012138(gameSystem);
    gameData = func_020120F4(gameSystem);
    func_0215A5F4(cmdWork);
    commState = (CommState *)func_02158344((int)gameComm);
    work = func_02030734(4, sizeof(ProfileProcWork), 1, d_021728F0, 0x1BC);
    if (commState != 0 && commState->localPlayerId != func_02012B58(gameData)
        && func_02175FB4((u8 *)(&commState->records[func_0215841C(gameData)])) == 1
        && ((u8 *)commState)[0x922] == 1) {
        playerIndex = func_0215841C(gameData);
        work->name = *func_0215840C(commState, playerIndex);
        work->profile = *(PlayerProfile *)((u8 *)commState + 0x914);
        work->isRemote = 1;
    } else {
        func_0200BE48(func_02012EBC(gameData));
        INTRUDE_COMM_BuildLocalProfile(gameData, (struct PlayerProfile *)(&work->profile));
        playerIndex = 0;
        work->isRemote = 0;
    }
    work->gameSystem = gameSystem;
    work->playerIndex = playerIndex;
    func_0215C63C(vm, cmdWork, (u32)ov071_id, d_021BA758, work, 0, 0);
    return 1;
}








/*
 * Script command: reads two words and stores func_02161B90's result
 * (over the system and the script's cell) in the script's slot.
 */
int func_0215CA64(void *vm, void *cmdWork)
{
    void *eventSlot;
    void *gameSystem;
    u32 firstArg;
    u32 secondArg;

    eventSlot = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    firstArg = func_02159B10(vm, cmdWork);
    secondArg = func_02159B10(vm, cmdWork);
    func_0215897C(eventSlot, func_02161B90(gameSystem, func_02158F50(eventSlot), firstArg, secondArg, 0));
    return 1;
}








/*
 * Script command: reads one halfword and the system, boxes them in an
 * 8-byte record and opens overlay 0xAE over it.
 *
 * Bytes exact.
 *
 * 2026-10-05 (wave D9): EXACT. The ov174 token on the d_021B74A0 data line (the
 * proc table lives in ov174, which this function loads) gave the witness; the
 * ov174_id word then resolved through the overlay_id walk. Source unchanged.
 */
int func_0215CAB4(void *vm, void *cmdWork)
{
    u16 value;
    ValueProcParam *param;

    value = func_02159B10(vm, cmdWork);
    param = func_02030734(4, 8, 1, d_021728F0, 0x205);
    param->value = value;
    param->gameData = func_0215A5E4(cmdWork);
    func_0215C63C(vm, cmdWork, (u32)ov174_id, d_021B74A0, param, 0, 0);
    return 1;
}








/*
 * Script command: reads a mode (0-2) and a word; unless the mode is 2
 * calls func_02165344, then boxes the system object (and the word) in a
 * hand-off record and opens overlay 0xDD, 0xDE or 0xE0 over it through
 * func_0215C63C.
 *
 * MATCH, bytes exact. Blockers: the three overlay ids (ABS32 0xDD, 0xDE,
 * 0xE0) have no witness: `overlay_id` would carry them, but func_0215C63C
 * (which forwards its r2 to GAMESYSTEM_CallProc's r1) is not in match.py's
 * OVERLAY_ID_CONSUMERS. d_021BA250 (ov222) and d_021B9BF8 (ov224) are
 * contested hints that resolve once the function loads those overlays
 * through an overlay_id site. d_021BA1A4 (ov221) already resolves.
 *
 * 2026-10-05 (wave D9): re-tried overlay tokens on the contested hints; they stay contested because the id sites do not attest. Residue is the three id words (ov221_id, ov222_id, ov224_id) reaching func_0215C63C, which is not in OVERLAY_ID_CONSUMERS; add that consumer (r2 -> GAMESYSTEM_CallProc r1) and the hints resolve. Not fixable in C.
 */
int func_0215CB08(void *vm, void *cmdWork)
{
    void *gameData;
    void *myStatus;
    u32 screenMode;
    u32 value;
    ModeProcParam *param;
    void **myStatusParam;

    gameData = func_020120F4(func_0215A5DC(cmdWork));
    myStatus = func_02012944(gameData);
    screenMode = func_02159B10(vm, cmdWork);
    value = func_02159B10(vm, cmdWork);
    if (screenMode != 2) {
        func_02165344();
    }
    switch (screenMode) {
    case 0:
        param = func_02030734(4, 8, 1, d_021728F0, 0x22B);
        param->gameData = gameData;
        param->value = value;
        func_0215C63C(vm, cmdWork, (u32)ov221_id, d_021BA1A4, param, 0, 0);
        break;
    case 1:
        param = func_02030734(4, 8, 1, d_021728F0, 0x233);
        param->gameData = gameData;
        param->value = value;
        func_0215C63C(vm, cmdWork, (u32)ov222_id, d_021BA250, param, 0, 0);
        break;
    case 2:
        myStatusParam = func_02030734(4, 4, 1, d_021728F0, 0x23C);
        *myStatusParam = myStatus;
        func_0215C63C(vm, cmdWork, (u32)ov224_id, d_021B9BF8, myStatusParam, 0, 0);
        break;
    }
    return 1;
}








/*
 * Script command: reads one word from the script stream, boxes it in a
 * 4-byte hand-off record and opens overlay 0xDF over it.
 *
 * 2026-10-05 (D9 lane 02): d_021BC8C4 resolves with the ov223 token (the overlay it points into) on its data line; ov223_id resolves as an overlay id word.
 *
 * 2026-10-05 (wave D8): ov223_id and d_021BC8C4 are data with no witness; not fixable in C. Source re-read against the listing, unchanged.
 */
int func_0215CBF0(void *vm, void *cmdWork)
{
    u32 value;
    u32 *param;

    value = (u32)func_02159AE8(vm, cmdWork);
    param = func_02030734(4, 8, 1, d_021728F0, 0x254);
    param[0] = value;
    func_0215C63C(vm, cmdWork, (u32)ov223_id, d_021BC8C4, param, 0, 0);
    return 1;
}








int func_0215CC38(int callArg0, int callArg1)
{
    int cmdWorkCopy;
    void *eventSlot;
    void *gameSystem;

cmdWorkCopy = callArg1 + 0;
callArg0 = cmdWorkCopy + 0;
    eventSlot = func_0215A5F4((void *)callArg0);
callArg0 = cmdWorkCopy + 0;
    gameSystem = func_0215A5DC((void *)callArg0);
callArg0 = 1;
    return callArg0;}








/*
 * Script command: reads a kind (0xF-0x13 mapped to 0-4) and a flag (0/1),
 * builds a four-word request on the stack and launches EVENT_WIFIBATTLEMATCH_Entry
 * (ov002) through func_020124AC, parking the result in the script's slot.
 */
int func_0215CC4C(void *vm, void *cmdWork)
{
    void *eventSlot;
    void *gameSystem;
    u32 kindVar;
    u32 flagVar;
    u32 kindIndex;
    u32 flagValue;
    WifiBattleMatchParam param;

    eventSlot = func_0215A5F4(cmdWork);
    gameSystem = func_0215A5DC(cmdWork);
    kindVar = func_02159B10(vm, cmdWork);
    flagVar = func_02159B10(vm, cmdWork);
    switch (kindVar) {
    case 0xF:
        kindIndex = 0;
        break;
    case 0x10:
        kindIndex = 1;
        break;
    case 0x11:
        kindIndex = 2;
        break;
    case 0x12:
        kindIndex = 3;
        break;
    case 0x13:
        kindIndex = 4;
        break;
    }
    switch (flagVar) {
    case 0:
        flagValue = 0;
        break;
    case 1:
        flagValue = 1;
        break;
    }
    param.fieldMap = func_0201210C(gameSystem);
    param.enabled = 1;
    param.flag = flagValue;
    param.matchKind = kindIndex;
    func_0215897C(eventSlot, func_020124AC(gameSystem, (u32)ov002_id, (void *)EVENT_WIFIBATTLEMATCH_Entry, (u32)(&param)));
    return 1;
}








/*
 * The ov003 callback 0x021543BC (unlabelled leaf, formerly the blocker) is
 * matched in pkt_ov003_021543BC and attests as matched.
 */
int func_0215CCE8(void *vm, void *cmdWork)
{
    MenuProcParam param;
    void *eventSlot = func_0215A5F4(cmdWork);
    void *gameSystem = func_0215A5DC(cmdWork);
    u32 mode = !func_02159B10(vm, cmdWork) ? 1 : 2;
    param.fieldMap = (u32)func_0201210C(gameSystem);
    param.mode = mode;
    func_0215897C(eventSlot, func_020124AC(gameSystem, (u32)ov003_id, (void *)EVENT_MENUPROC_Entry, (u32)(&param)));
    return 1;
}








int func_0215CD3C(void *vm, void *cmdWork)
{
    void *gameSystem = func_0215A5DC(cmdWork);
    u16 *firstVar = func_02159AE8(vm, cmdWork);
    u16 *secondVar = func_02159AE8(vm, cmdWork);
    func_02034AC4((u32)ov037_id);
    func_021F36C0((unsigned int)gameSystem, *firstVar, *secondVar);
    func_02034A5C((u32)ov037_id);
    return 0;
}








int func_0215CD80(void *vm, void *cmdWork)
{
    void *gameSystem = func_0215A5DC(cmdWork);
    int value = func_02159B10(vm, cmdWork);
    func_02034AC4((int)ov037_id);
    func_021F36E8(gameSystem, value);
    func_02034A5C((int)ov037_id);
    return 0;
}







int func_0215CDB8(void *vm, void *cmdWork)
{
    void *gameSystem = func_0215A5DC(cmdWork);
    int value = func_02159B10(vm, cmdWork);
    func_02034AC4((int)ov037_id);
    func_021F3724((unsigned int)gameSystem, value);
    func_02034A5C((int)ov037_id);
    return 0;
}







int func_0215CDF0(void *vm, void *cmdWork)
{
    unsigned short *resultVars[8];
    void *gameSystem = func_0215A5DC(cmdWork);
    resultVars[0] = func_02159AE8(vm, cmdWork);
    resultVars[1] = func_02159AE8(vm, cmdWork);
    resultVars[2] = func_02159AE8(vm, cmdWork);
    resultVars[3] = func_02159AE8(vm, cmdWork);
    resultVars[4] = func_02159AE8(vm, cmdWork);
    resultVars[5] = func_02159AE8(vm, cmdWork);
    resultVars[6] = func_02159AE8(vm, cmdWork);
    resultVars[7] = func_02159AE8(vm, cmdWork);
    func_02034AC4((u32)ov037_id);
    func_021F3768((unsigned int)gameSystem, resultVars);
    func_02034A5C((u32)ov037_id);
    return 0;
}







int func_0215CE70(void *vm, void *cmdWork)
{
    void *gameSystem = func_0215A5DC(cmdWork);
    func_02034AC4((int)ov037_id);
    func_021F3800((unsigned int)gameSystem);
    func_02034A5C((int)ov037_id);
    return 0;
}







/*
 * unblocked: func_021C3400 (ov021, unlabelled leaf) was matched bottom-up
 *   and filed as pkt_021C3400; the `ov021` token then resolves the site as
 *   `matched, overlay`.  Extent runs 36 bytes against 34 compiled: the
 *   unlabelled follower.
 */
int func_0215CE98(int callArg0, int callArg1)
{    int cmdWorkCopy;
    unsigned short *resultVar;
    void *gameSystem;
    void *fieldMap;

cmdWorkCopy = callArg1 + 0;
    resultVar = func_02159AE8((void *)callArg0, (void *)callArg1);
callArg0 = cmdWorkCopy + 0;
    gameSystem = func_0215A5DC((void *)callArg0);
    fieldMap = func_0201210C(gameSystem);
    callArg0 = func_021C3400(func_02188D50(fieldMap));
*resultVar = callArg0;
callArg0 = 0;
    return callArg0;}







int func_0215CEBC(void *vm, void *cmdWork)
{
    void *gameSystem = func_0215A5DC(cmdWork);
    void *party = func_02012934(func_0215A5E4(cmdWork));
    func_021C32F4(func_02188D50(func_0201210C(gameSystem)), (unsigned int)party);
    return 0;
}







int func_0215CEE8(int callArg0, int callArg1)
{
    void *gameSystem;
    void *fieldMap;

callArg0 = callArg1 + 0;
    gameSystem = func_0215A5DC((void *)callArg0);
    fieldMap = func_0201210C(gameSystem);
    func_021C335C((void **)func_02188D50(fieldMap));
callArg0 = 0;
    return callArg0;}







int func_0215CF00(void *vm, void *cmdWork)
{
    void *eventSlot = func_0215A5F4(cmdWork);
    unsigned short *resultVar = func_02159AE8(vm, cmdWork);
    void *gameData = func_0215A5E4(cmdWork);
    void *gameSystem = func_0215A5DC(cmdWork);
    void *fieldMap = func_0201210C(gameSystem);
    func_02012934(gameData);
    func_0200BDB0(func_02012EBC(gameData));
    func_0215897C(eventSlot, func_0215D2A4(gameSystem, fieldMap, resultVar));
    return 1;
}







int func_0215CF54(void *vm, void *cmdWork)
{
    int partyIndex = func_02159B10(vm, cmdWork);
    void *party = func_02012934(func_0215A5E4(cmdWork));
    func_021C3204(func_02188D50(func_0201210C(func_0215A5DC(cmdWork))), (unsigned int)party, partyIndex);
    return 0;
}







int func_0215CF84(void *vm, void *cmdWork)
{
    int daycareSlot = func_02159B10(vm, cmdWork);
    void *party = func_02012934(func_0215A5E4(cmdWork));
    func_021C3270(func_02188D50(func_0201210C(func_0215A5DC(cmdWork))), daycareSlot, (unsigned int)party);
    return 0;
}







int func_0215CFB4(int callArg0, int callArg1)
{    int cmdWorkCopy;
    unsigned short *resultVar;
    void *gameSystem;
    void *fieldMap;

cmdWorkCopy = callArg1 + 0;
    resultVar = func_02159AE8((void *)callArg0, (void *)callArg1);
callArg0 = cmdWorkCopy + 0;
    gameSystem = func_0215A5DC((void *)callArg0);
    fieldMap = func_0201210C(gameSystem);
    callArg0 = func_021C340C(func_02188D50(fieldMap));
*resultVar = callArg0;
callArg0 = 0;
    return callArg0;}







int func_0215CFD8(int callArg0, int callArg1)
{    int cmdWorkCopy;
    unsigned short *resultVar;
    void *gameSystem;
    void *fieldMap;

cmdWorkCopy = callArg1 + 0;
    resultVar = func_02159AE8((void *)callArg0, (void *)callArg1);
callArg0 = cmdWorkCopy + 0;
    gameSystem = func_0215A5DC((void *)callArg0);
    fieldMap = func_0201210C(gameSystem);
    callArg0 = func_021C34C4((void **)func_02188D50(fieldMap));
*resultVar = callArg0;
callArg0 = 0;
    return callArg0;}







/*
 * interface: func_021C34F8 has two observed inputs. Its full ov021 body
 * and 0200BCA8/0200BC2C read r0/r1 only; legacy trailing r2/r3 are omitted.
 */
int func_0215CFFC(void *vm, void *cmdWork)
{
    u16 *resultVar = func_02159AE8(vm, cmdWork);
    int daycareSlot = func_02159B10(vm, cmdWork);
    void *daycareMon = func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(cmdWork))), daycareSlot);
    *resultVar = func_02017E1C(daycareMon, 5, 0);

    return 0;
}







int func_0215D034(void *vm, void *cmdWork)
{
    u16 *resultVar = func_02159AE8(vm, cmdWork);
    int daycareSlot = func_02159B10(vm, cmdWork);
    void *daycareMon = func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(cmdWork))), daycareSlot);
    *resultVar = func_02017E1C(daycareMon, 111, 0);

    return 0;
}







int func_0215D06C(void *vm, void *cmdWork)
{
    u16 *resultVar = func_02159AE8(vm, cmdWork);
    int daycareSlot = func_02159B10(vm, cmdWork);
    void *daycareMon = func_021C34F8(func_02188D50(func_0201210C(func_0215A5DC(cmdWork))), daycareSlot);
    *resultVar = func_02017E1C(daycareMon, 110, 0);

    return 0;
}







int func_0215D0A4(void *vm, void *cmdWork)
{
    u16 *resultVar = func_02159AE8(vm, cmdWork);
    int daycareSlot = func_02159B10(vm, cmdWork);
    *resultVar = func_021C341C(func_02188D50(func_0201210C(func_0215A5DC(cmdWork))), daycareSlot);

    return 0;
}






int func_0215D0D4(void *vm,void *cmdWork)
{
 u16 *resultVar = func_02159AE8(vm,cmdWork);
 int daycareSlot = func_02159B10(vm,cmdWork);
 void **daycare = func_02188D50(func_0201210C(func_0215A5DC(cmdWork)));
 func_021C34F8(daycare,daycareSlot);
 *resultVar = func_021C3490(daycare,daycareSlot);
 return 0;
}






int func_0215D110(void *vm,void *cmdWork)
{
 u16 *resultVar = func_02159AE8(vm,cmdWork);
 int daycareSlot = func_02159B10(vm,cmdWork);
 void **daycare = func_02188D50(func_0201210C(func_0215A5DC(cmdWork)));
 func_021C34F8(daycare,daycareSlot);
 *resultVar = func_021C34B4(daycare,daycareSlot);
 return 0;
}







int func_0215D14C(void *vm, void *cmdWork)
{
    int queryKind;
    u16 *resultVar;
    void *daycareMon;
    void *daycare = func_02188D50(func_0201210C(func_0215A5DC(cmdWork)));
    resultVar = func_02159AE8(vm, cmdWork);
    queryKind = func_02159B10(vm, cmdWork);
    daycareMon = func_021C34F8(daycare, func_02159B10(vm, cmdWork));
    if (queryKind == 0)
        *resultVar = func_0215D198(daycareMon);
    else
        *resultVar = 0;
    return 0;
}







int func_0215D198(void *mon)
{
    int species = func_02017E1C(mon, 5, 0);
    int gender = func_02017E1C(mon, 0x6e, 0);
    if (species == 0x20 || species == 0x1d) {
        species = 0;
        if (func_02017E1C(mon, 0x75, 0) == 0)
            return species;
    }
    switch (gender) {
    case 2:
    default: return 0;
    case 0: return 1;
    case 1: return 2;
    }
}







int func_0215D1E4(void *event, u32 *seq, DaycareEventWork *work)
{
    u32 seqValue = *seq;
    void *gameSystem = work->gameSystem;
    switch (seqValue) {
    case 0:
        func_02012374(event, func_021BE8D4(gameSystem, work->fieldMap, 0, 0));
        *seq = 1;
        break;
    case 1:
        func_02012374(event, (struct GameEvent **)FIELD_STATUS_CreateFieldCloseEvent((int)gameSystem, (int)work->fieldMap));
        work->menuParam->selectedPos = work->menuState->selectedPos;
        *seq = 2;
        break;
    case 2:
        func_02012374(event, func_02014910(gameSystem, (int)work->fieldMap, (int)work->menuParam, (int)work->menuState));
        *seq = 3;
        break;
    case 3:
        func_02012374(event, FIELD_STATUS_CreateFieldOpenEvent(gameSystem));
        *seq = 4;
        break;
    case 4:
        func_02012374(event, func_021BE92C(gameSystem, work->fieldMap, 0, 0, 1, 0, 0));
        *seq = 5;
        break;
    case 5:
        *work->resultVar = work->menuParam->selectedPos;
        func_020307B0(work->menuParam);
        func_020307B0(work->menuState);
        return 1;
    }
    return 0;
}







void *func_0215D2A4(void *gameSystem, void *fieldMap, u16 *resultVar)
{
    void *gameData = func_020120F4(gameSystem);
    void *party = func_02012934(gameData);
    u32 zukanSave = (u32)func_0200CA1C(gameData);
    PartyMenuParam *menuParam = func_02030734(4, 0x98, 0, d_02172900, 0x22B);
    PartyMenuState *menuState;
    DaycareEventWork *work;
    void *event;
    menuParam->party = party;
    menuParam->menuType = 0x12;
    menuParam->cursorPos = 0;
    menuParam->selectedPos = 0;
    menuState = func_02030734(4, 0x28, 0, d_02172900, 0x232);
    menuState->party = menuParam->party;
    menuState->listWork = menuParam->listWork;
    menuState->gameData = (u32)gameData;
    menuState->enabled = 1;
    menuState->partyCount = func_0201AA18(party);
    menuState->cursor = 0;
    menuState->reserved10 = 0;
    menuState->selectedPos = 0;
    menuState->zukanSave = func_0200CA38((struct ZukanSave *)zukanSave);
    event = func_020122C0(gameSystem, 0, (void *)func_0215D1E4, 0x14);
    work = func_020124E8(event);
    work->gameSystem = gameSystem;
    work->fieldMap = fieldMap;
    work->menuParam = menuParam;
    work->menuState = menuState;
    work->resultVar = resultVar;
    return event;
}
