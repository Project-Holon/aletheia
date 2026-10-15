/*
 * function: POKETRADE_SAVE_ApplyTradeResult
 * address:  0x021E049C
 * packet:   pkt_ov119_021E049C
 * region:   ov119
 * compiler: 1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * closed:   blocking arm9 callees labelled and matched by seeds_3 (2026-09-28)
 *
 * pokemontrade_save.c.  The first two buffer copies are inlined statics
 * (their arguments are spilled before the body, and each carries its own
 * copy of the __FILE__ string); the rest call the out-of-line copies.
 * Every copy goes through the GFL_STD_MemCopy inline wrapper, whose
 * arguments are evaluated last to first: the size call, then the
 * destination load, then the source call.
 *
 * symbols:
 *   POKETRADE_PROC_IsHostSide  0x021D8AA8  thumb
 *   POKETRADE_SAVE_BackupSaveControl  0x021E0138  thumb
 *   POKETRADE_SAVE_BackupZukan  0x021E01A0  thumb
 *   POKETRADE_SAVE_BackupBlock1F  0x021E0200  thumb
 *   POKETRADE_SAVE_ConsumePerapVoice  0x021E0410  thumb
 *   GFL_HEAP_Alloc   0x02030734  arm
 *   MI_CpuCopy8    0x02082D44  arm
 *   func_020307B0  0x020307B0  arm
 *   MAIL_GetBoxSize   0x02008FFC  thumb
 *   MAIL_GetBox   0x02008FEC  thumb
 *   RECORD_GetSize   0x02008C20  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   GAME_DATA_GetPlayTime  0x02012FCC  thumb
 *   PLAYTIME_GetStamp   0x020086F0  thumb
 *   BOX_SAVEDATA_GetUsableBoxCount   0x020076A4  thumb
 *   POKEPARTY_Create  0x0201A920  thumb
 *   POKEPARTY_Copy  0x0201AC2C  thumb
 *   BOX_SAVEDATA_GetBoxPageSize   0x02007A9C  thumb
 *   BOX_SAVEDATA_GetBoxPokemon   0x02007AF4  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   FILE_UTIL_Check136C  0x0202136C  thumb
 *   MAIL_FindEmptySlot  0x02009020  thumb
 *   MAIL_Create  0x02008F08  thumb
 *   MAIL_SetSlot   0x0200903C  thumb
 *   func_02008EAC  0x02008EAC  thumb
 *   func_0200856C  0x0200856C  thumb
 *   func_02008570  0x02008570  thumb
 *   func_02008564  0x02008564  thumb
 *   func_02025C1C  0x02025C1C  thumb
 *   func_02025C30  0x02025C30  thumb
 *   func_02008574  0x02008574  thumb
 *   GAME_DATA_GetSaveBlock1F  0x02012F14  thumb
 *   TRADE_HISTORY_AddPartner   0x02009DE8  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   func_02009470  0x02009470  thumb
 *   WIFI_HISTORY_GetCountryRegionState   0x0200949C  thumb
 *   WIFI_HISTORY_SetCountryRegionState   0x020094D8  thumb
 *   POKE_TOOL_HealFull  0x0201B9F0  thumb
 *   func_0202F190  0x0202F190  thumb
 *   RECORD_AddOne   0x02008DF0  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   TRADE_HISTORY_IncrementTradeCount   0x02009EB0  thumb
 *   POKE_TOOL_ChangeForm  0x02017988  thumb
 *   POKEPARTY_SetMember   0x0201AB48  thumb
 *   POKE_TOOL_GetBoxParam   0x020185F4  thumb
 *   func_020075B0  0x020075B0  thumb
 *   sub_0201283C   0x0201283C  thumb
 *   WIFILIST_AddFriendBattleRecord   0x02009BB8  thumb
 *   WIFILIST_FindFriendByStatus   0x02009D1C  thumb
 *   gSaveBufferAllocTag     0x021E8108  data  ov119
 *   gMailBufferAllocTag     0x021E811C  data  ov119
 *   gSaveControlAllocTag     0x021E8130  data  ov119
 *
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

struct Big;
struct Blk37;
struct Party;
struct PartyMon;
struct PlayTime;
struct PlayTimeStamp;
struct Rec534;
struct Sub02007AC8Entry;
struct Sub0200852CObj;
struct Sub02008EACObj;
struct Sub02008F80Obj;
struct Sub02009470Obj;
struct Sub020097BCObj;
struct Sub02009D9CObj;
extern int POKETRADE_PROC_IsHostSide(void *p);
extern void *POKETRADE_SAVE_BackupSaveControl(void *sys, u16 heapId);
extern void *POKETRADE_SAVE_BackupZukan(void *src, u16 heapId);
extern void *POKETRADE_SAVE_BackupBlock1F(void *sys, u16 heapId);
extern int POKETRADE_SAVE_ConsumePerapVoice(char *p, void *party, int idx);
extern void *GFL_HEAP_Alloc(u32 heapId, u32 size, int clear, const char *file, u16 line);
extern void MI_CpuCopy8(const void *src, void *dst, u32 size);
extern u32 func_020307B0(void *p);
extern u32 MAIL_GetBoxSize(void);
extern struct Sub02008F80Obj *MAIL_GetBox(void *sys);
extern u32 RECORD_GetSize(void);
extern void *GAME_DATA_GetTrainerRecord(int *p);
struct BigObj;
struct Sub020075B0Entry;
struct Sub02008C20Obj;
extern int GAME_DATA_GetPlayTime(int p0);
extern void PLAYTIME_GetStamp(const struct PlayTime *p, struct PlayTimeStamp *out);
extern u8 BOX_SAVEDATA_GetUsableBoxCount(void *save);
extern struct Party *POKEPARTY_Create(u32 heap);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern u32 BOX_SAVEDATA_GetBoxPageSize(void);
extern struct Sub02007AC8Entry *BOX_SAVEDATA_GetBoxPokemon(void **save, u32 box);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 FILE_UTIL_Check136C(u16 v);
extern int MAIL_FindEmptySlot(void *obj, int v);
extern void *MAIL_Create(int a0);
extern void MAIL_SetSlot(struct Sub02008F80Obj *arr, u32 unused, int i, const struct Sub02008F80Obj *src);
extern void func_02008EAC(struct Sub02008EACObj *obj);
extern u8 func_0200856C(const struct Sub0200852CObj *obj);
extern u8 func_02008570(const struct Sub0200852CObj *obj);
extern u8 func_02008564(const struct Sub0200852CObj *obj);
extern u32 func_02025C1C(u32 a, u32 b, u32 c);
extern u32 func_02025C30(u32 a, u32 b, u32 c);
extern void func_02008574(struct Sub0200852CObj *obj, u8 a, u8 b);
extern void *GAME_DATA_GetSaveBlock1F(void **h);
extern void TRADE_HISTORY_AddPartner(struct Sub02009D9CObj *obj, struct Sub0200852CObj *p);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern struct Sub02009470Obj *func_02009470(void *sys);
extern u32 WIFI_HISTORY_GetCountryRegionState(const struct Sub02009470Obj *obj, int row, int col);
extern void WIFI_HISTORY_SetCountryRegionState(struct Sub02009470Obj *obj, int row, int col, int value);
extern void POKE_TOOL_HealFull(void *mon);
extern void func_0202F190(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 RECORD_AddOne(struct Sub02008C20Obj *obj, int i);
extern void *ZUKAN_SAVE_GetFromGameData(void *sys);
extern void ZUKAN_SAVE_RegisterCaught(struct Blk37 *p, void *m);
extern void TRADE_HISTORY_IncrementTradeCount(struct Sub02009D9CObj *obj);
extern u32 POKE_TOOL_ChangeForm(void *p, u32 a);
extern void POKEPARTY_SetMember(struct Party *p, u32 idx, const struct PartyMon *src);
extern void *POKE_TOOL_GetBoxParam(void *mon);
extern int func_020075B0(void *save, u32 box, u32 slot, const struct Sub020075B0Entry *src);
extern u32 sub_0201283C(const struct BigObj *p);
extern void WIFILIST_AddFriendBattleRecord(struct Sub020097BCObj *obj, int i, int a, int b, int c);
extern int WIFILIST_FindFriendByStatus(struct Sub020097BCObj *obj, struct Sub0200852CObj *p, u32 *out);
extern const char gSaveBufferAllocTag[];
extern const char gMailBufferAllocTag[];
extern const char gSaveControlAllocTag[];

typedef struct {
    u8   pad0[0x1C];
    void *party;
    u8   pad20[8];
    u16  box;
    u16  slot;
    u16  count;
} Trade;

#define I(p, o) (*(void **)((p) + (o)))
#define W(p, o) (*(int *)((p) + (o)))
#define H(p, o) (*(u16 *)((p) + (o)))
#define T(p)    (*(Trade **)((p) + 8))

static inline void GFL_STD_MemCopy(const void *src, void *dst, u32 size)
{
    MI_CpuCopy8(src, dst, size);
}

static inline void *copy_a(void *sys, u16 heapId)
{
    void *buf = GFL_HEAP_Alloc(heapId, MAIL_GetBoxSize(), 0, gMailBufferAllocTag, 0x163);

    GFL_STD_MemCopy(MAIL_GetBox(sys), buf, MAIL_GetBoxSize());
    return buf;
}

static inline void *copy_b(void *sys, u16 heapId)
{
    void *buf = GFL_HEAP_Alloc(heapId, RECORD_GetSize(), 0, gSaveBufferAllocTag, 0x182);

    GFL_STD_MemCopy(GAME_DATA_GetTrainerRecord(sys), buf, RECORD_GetSize());
    return buf;
}

void POKETRADE_SAVE_ApplyTradeResult(char *p)
{
    void *mon;
    void *obj;
    void *list[2];
    int i;
    int out;

    if (POKETRADE_PROC_IsHostSide(p) == 0) {
        I(p, 0x60C) = copy_a(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x610) = copy_b(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x614) = POKETRADE_SAVE_BackupSaveControl(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x618) = POKETRADE_SAVE_BackupZukan(I(p, 0x82C), H(p, 0x5F4));
        I(p, 0x61C) = POKETRADE_SAVE_BackupBlock1F(I(p, 0x82C), H(p, 0x5F4));
        PLAYTIME_GetStamp((void *)GAME_DATA_GetPlayTime((int)I(p, 0x82C)), (struct PlayTimeStamp *)(p + 0x628));
        if (T(p)->box == BOX_SAVEDATA_GetUsableBoxCount(I(p, 0x828))) {
            I(p, 0x620) = POKEPARTY_Create(H(p, 0x5F4));
            POKEPARTY_Copy(I(p, 0x838), I(p, 0x620));
            W(p, 0x62C) = POKETRADE_SAVE_ConsumePerapVoice(p, I(p, 0x838), T(p)->slot);
        } else {
            I(p, 0x624) = GFL_HEAP_Alloc(H(p, 0x5F4), BOX_SAVEDATA_GetBoxPageSize(), 0, gSaveControlAllocTag, 0x271);
            GFL_STD_MemCopy(BOX_SAVEDATA_GetBoxPokemon(I(p, 0x828), T(p)->box), I(p, 0x624), BOX_SAVEDATA_GetBoxPageSize());
        }
    } else {
        Trade *t = T(p);
        if (t->box == BOX_SAVEDATA_GetUsableBoxCount(I(p, 0x828)))
            POKETRADE_SAVE_ConsumePerapVoice(p, I(p, 0x838), t->slot);
        p[0x11F7] = 1;
    }

    {
        Trade *t = T(p);
        if (t->box != BOX_SAVEDATA_GetUsableBoxCount(I(p, 0x828))) {
            mon = POKEPARTY_GetMember(t->party, 0);
            if (FILE_UTIL_Check136C(POKE_TOOL_GetPartyValue(mon, 6, 0))) {
                void *o = MAIL_GetBox(I(p, 0x82C));
                int idx = MAIL_FindEmptySlot(o, 0);
                if (idx != -1) {
                    void *buf = MAIL_Create(H(p, 0x5F4));
                    POKE_TOOL_GetPartyValue(mon, 0xA7, (u32)buf);
                    MAIL_SetSlot(o, 0, idx, buf);
                    func_02008EAC(buf);
                    POKE_TOOL_SetPartyValue(mon, 0xA7, (u32)buf);
                    POKE_TOOL_SetPartyValue(mon, 6, 0);
                    func_020307B0(buf);
                }
            }
        }
    }

    {
        u8 a = func_0200856C(I(p, 0x834));
        u8 b = func_02008570(I(p, 0x834));
        u32 ra = func_02025C1C(a, b, func_02008564(I(p, 0x834)));
        u32 rb = func_02025C30(a, b, func_02008564(I(p, 0x834)));
        if (a != ra || b != rb)
            func_02008574(I(p, 0x834), 0, 0);
    }

    TRADE_HISTORY_AddPartner(GAME_DATA_GetSaveBlock1F(I(p, 0x82C)), I(p, 0x834));
    obj = func_02009470(GAME_DATA_GetSaveControl(I(p, 0x82C)));
    list[0] = I(p, 0x830);
    list[1] = I(p, 0x834);
    for (i = 0; i < 2; i++) {
        void *q = list[i];
        if (q) {
            u8 row = func_0200856C(q);
            u8 col = func_02008570(q);
            func_02008564(q);
            if (!WIFI_HISTORY_GetCountryRegionState(obj, row, col))
                WIFI_HISTORY_SetCountryRegionState(obj, row, col, 1);
        }
    }

    mon = POKEPARTY_GetMember(T(p)->party, 0);
    obj = GAME_DATA_GetTrainerRecord(I(p, 0x82C));
    POKE_TOOL_HealFull(mon);
    if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0)
        POKE_TOOL_SetPartyValue(mon, 9, (u32)((void *)0x46));
    if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0))
        func_0202F190(mon, 6, (u32)I(p, 0x830), 0x7533, H(p, 0x5F4));
    switch (W(p, 0x118C)) {
    case 2:
    case 3:
        RECORD_AddOne(obj, 0x10);
        break;
    case 1:
        RECORD_AddOne(obj, 0xC);
        break;
    case 0:
        RECORD_AddOne(obj, 0x24);
        break;
    }
    ZUKAN_SAVE_RegisterCaught(ZUKAN_SAVE_GetFromGameData(I(p, 0x82C)), mon);
    if (W(p, 0x118C) == 3)
        TRADE_HISTORY_IncrementTradeCount(GAME_DATA_GetSaveBlock1F(I(p, 0x82C)));
    if (POKE_TOOL_GetPartyValue(mon, 5, 0) == 0x1EC && POKE_TOOL_GetPartyValue(mon, 0x6F, 0) == 1) {
        POKE_TOOL_ChangeForm(mon, 0);
        ZUKAN_SAVE_RegisterCaught(ZUKAN_SAVE_GetFromGameData(I(p, 0x82C)), mon);
    }
    {
        Trade *t = T(p);
        if (t->box == BOX_SAVEDATA_GetUsableBoxCount(I(p, 0x828))) {
            POKEPARTY_SetMember(I(p, 0x838), t->slot, mon);
        } else {
            t = T(p);
            func_020075B0(I(p, 0x828), t->box, t->slot, POKE_TOOL_GetBoxParam(mon));
        }
    }
    switch (W(p, 0x118C)) {
    case 2:
        WIFILIST_AddFriendBattleRecord((void *)sub_0201283C(I(p, 0x82C)), T(p)->count - 1, 0, 0, 1);
        break;
    case 0:
    case 1:
        if (WIFILIST_FindFriendByStatus((void *)sub_0201283C(I(p, 0x82C)), I(p, 0x834), (u32 *)(&out)))
            WIFILIST_AddFriendBattleRecord((void *)sub_0201283C(I(p, 0x82C)), out, 0, 0, 1);
        break;
    }
}
