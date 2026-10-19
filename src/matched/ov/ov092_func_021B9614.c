/*
 * function: EVENT_BATTLE_RETURN_Main
 * address: 0x021B9614
 * packet: pkt_ov092_021B9614
 * region: ov092
 * compiler: dsi/1.1p1
 * flags: -O4,p
 * lang: c99
 * isa: thumb
 * status: EXACT
 * note: 2026-10-05 matched. Loader order (context, id, descriptor, argument). Closing forms: case 1, 2 and 5 are
 *   `if (busy != 1) { body; break; } return 0;` (return block after the body); `ok = 0; if (f == 1) ok = 1;`;
 *   `if (flag) x = 0; else x = 1;`; `case 6: default: return 1;`; the case 4 tail `r68 = 1; break;` written in
 *   the guarded arm and again after it (cross-jumped copy leaves the b stub); species and slot as u16 locals,
 *   box/bslot declared first; the source record pointer s is not const. Case 4 mask and slot use a two-field view.
 * symbols:
 *   PROCSYS_Main 0x02031330 arm
 *   GAME_DATA_GetMyParty 0x02012934 thumb
 *   GAME_DATA_GetMyStatus 0x02012944 thumb
 *   ZUKAN_SAVE_GetFromGameData 0x0200CA1C thumb
 *   GAME_DATA_GetBoxManager 0x0201293C thumb
 *   EVENT_BATTLE_RETURN_FlagLeveledUpMembers 0x021B9A14 thumb ov092
 *   POKEPARTY_Copy 0x0201AC2C thumb
 *   POKERUS_TryInfectParty 0x0201B038 thumb
 *   POKERUS_SpreadParty 0x0201B170 thumb
 *   EVENT_BATTLE_RETURN_ApplyPickupAndHoneyGather 0x021B9AA0 thumb ov092
 *   EVENT_BATTLE_RETURN_GetBurmyForm 0x021B9C80 thumb ov092
 *   EVENT_BATTLE_RETURN_ApplyBurmyForms 0x021B9C34 thumb ov092
 *   EVENT_BATTLE_RETURN_RegisterShayminForms 0x021B9CA4 thumb ov092
 *   GAME_DATA_GetMiscSave 0x02012F08 thumb
 *   BEACON_AddMoney 0x0200C278 thumb
 *   BEACON_SubMoney 0x0200C29C thumb
 *   EVENT_BATTLE_RETURN_ApplyNaturalCure 0x021B9BD8 thumb ov092
 *   POKEPARTY_GetMember 0x0201AB28 thumb
 *   func_02008500 0x02008500 thumb
 *   POKE_TOOL_SetPartyValue 0x02017E40 thumb
 *   POKEPARTY_GetCount 0x0201AA18 thumb
 *   POKEPARTY_GetCapacity 0x0201AA14 thumb
 *   func_02007698 0x02007698 thumb
 *   func_020076D0 0x020076D0 thumb
 *   func_02045B38 0x02045B38 arm
 *   GAME_DATA_GetEventWork 0x0201296C thumb
 *   ZONEDATA_CheckEventFlag 0x020142E8 thumb
 *   func_02045EC0 0x02045EC0 arm
 *   MSGDATA_Delete 0x02045C04 arm
 *   GAME_DATA_GetMyPlayerWork 0x020127A4 thumb
 *   GAME_DATA_GetPlayerZoneId 0x02012AC8 thumb
 *   ZONEDATA_GetPlaceNameId 0x02013E4C thumb
 *   SAVE_EVENT_Write 0x0202F190 thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled 0x0200CA38 thumb
 *   POKE_TOOL_GetPartyValue 0x02017E1C thumb
 *   ZUKAN_SAVE_IsCaught 0x0200CED4 thumb
 *   ZUKAN_SAVE_RegisterSeen 0x0200CFA0 thumb
 *   ZUKAN_SAVE_RegisterCaught 0x0200CDE0 thumb
 *   PROCSYS_Push 0x02031348 arm
 *   GAME_DATA_GetSaveControl 0x02012EBC thumb
 *   BEACON_GetBlock 0x0200C0F0 thumb
 *   NAMEIN_SETUP_CreateCaptureArgs 0x0216C0A4 thumb ov010
 *   NAMEIN_SETUP_IsCanceled 0x0216C0E4 thumb ov010
 *   NAMEIN_SETUP_CopyName 0x0216C0D4 thumb ov010
 *   GAME_DATA_GetTrainerRecord 0x02012F2C thumb
 *   func_02008DF0 0x02008DF0 thumb
 *   NAMEIN_SETUP_FreeArgs 0x0216C0C0 thumb ov010
 *   EVENT_BATTLE_RETURN_ApplyHealBall 0x021B9D04 thumb ov092
 *   POKEPARTY_Add 0x0201A98C thumb
 *   POKE_TOOL_CastToBoxParam 0x020185F0 thumb
 *   func_020074D8 0x020074D8 thumb
 *   GFL_USE_FadeOutBgm 0x02005E30 thumb
 *   GFL_USE_IsBgmFading 0x02005E50 thumb
 *   GFL_USE_CancelChangeAndStopBgm 0x02005D28 thumb
 *   GAME_DATA_GetSeason 0x02012984 thumb
 *   SHINKA_CHECK_CheckEvolution 0x0201B2B0 thumb
 *   func_02030734 0x02030734 arm
 *   func_020307B0 0x020307B0 arm
 *   gCatchRegistrationProcData 0x0220BAB0 data a4 ov207
 *   data_021F5580 0x021F5580 data a4 ov194
 *   data_02208C40 0x02208C40 data a4 ov195
 *   ov207_id 0x000000CF data a1
 *   ov194_id 0x000000C2 data a1
 *   ov195_id 0x000000C3 data a1
 *   sSourceFileName 0x021B9DC0 data a1
 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct { u8 pad[0x38]; u16 idx, mask; } Rec;
typedef struct { void *save, *party; u16 species; u8 slot, method; u32 x, flag; } Extra;
extern const u8 gCatchRegistrationProcData[], data_021F5580[], data_02208C40[], sSourceFileName[];
extern const u8 ov207_id[], ov194_id[], ov195_id[];
extern u32 PROCSYS_Main(void *);
typedef signed int     s32;
struct Big;
struct BigObj;
struct Blk34;
struct Blk37;
struct MsgBank;
struct Party;
struct PartyMon;
struct Rec;
struct Rec44;
struct Rec534;
struct S;
struct SaveBlock;
struct Sub02007454Entry;
struct Sub02008C20Obj;
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u8 *GAME_DATA_GetMyStatus(void *);
extern void *ZUKAN_SAVE_GetFromGameData(void *);
extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
extern void EVENT_BATTLE_RETURN_FlagLeveledUpMembers(u8 *a0, struct S *s);
extern void POKEPARTY_Copy(const struct Rec534 *src, struct Rec534 *dst);
extern void POKERUS_TryInfectParty(void *);
extern void POKERUS_SpreadParty(void *);
extern void EVENT_BATTLE_RETURN_ApplyPickupAndHoneyGather(void *);
extern u32 EVENT_BATTLE_RETURN_GetBurmyForm(u32, u32);
extern void EVENT_BATTLE_RETURN_ApplyBurmyForms(struct S *s, void *party, int c);
extern void EVENT_BATTLE_RETURN_RegisterShayminForms(struct S *s, void *party);
extern void *GAME_DATA_GetMiscSave(int *p);
extern u32 BEACON_AddMoney(struct Blk34 *p, u32 v);
extern u32 BEACON_SubMoney(struct Blk34 *p, u32 v);
extern void EVENT_BATTLE_RETURN_ApplyNaturalCure(void *);
extern void *POKEPARTY_GetMember(void *, u32);
extern void func_02008500(void *, void *);
extern void POKE_TOOL_SetPartyValue(void *, u32, u32);
extern u32 POKEPARTY_GetCount(void *p);
extern u32 POKEPARTY_GetCapacity(void *p);
extern u32 func_02007698(void *);
extern int func_020076D0(void *, int *, int *);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 ZONEDATA_GetPlaceNameId(u32);
extern void SAVE_EVENT_Write(void *, u32, u32, u32, u16);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
extern u32 POKE_TOOL_GetPartyValue(void *, u32, u32);
extern u32 ZUKAN_SAVE_IsCaught(struct Blk37 *p, u16 id);
extern void ZUKAN_SAVE_RegisterSeen(struct Blk37 *p, void *m);
extern void ZUKAN_SAVE_RegisterCaught(struct Blk37 *p, void *m);
extern void PROCSYS_Push(void *, u32, const u8 *, void *);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BEACON_GetBlock(void *);
extern int *NAMEIN_SETUP_CreateCaptureArgs(unsigned short a, int b, int c, int d, int e, int f, int g, int h);
extern int NAMEIN_SETUP_IsCanceled(int *p);
extern void NAMEIN_SETUP_CopyName(int *p, int a1);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern int NAMEIN_SETUP_FreeArgs(int a0);
extern void EVENT_BATTLE_RETURN_ApplyHealBall(void *);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern void *POKE_TOOL_CastToBoxParam(void *);
extern int func_020074D8(void **save, const struct Sub02007454Entry *src);
extern void GFL_USE_FadeOutBgm(u32);
extern int GFL_USE_IsBgmFading(void);
extern void GFL_USE_CancelChangeAndStopBgm(void);
extern u8 GAME_DATA_GetSeason(const struct BigObj *p);
extern u16 SHINKA_CHECK_CheckEvolution(void *, void *, u32, u32, u8, u32 *, u16);
extern void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
extern u32 func_020307B0(void *p);
int EVENT_BATTLE_RETURN_Main(void *unused, u32 *step, u8 *s, u8 *r)
{
    u32 busy;
    void *party;
    int box, bslot;
    u32 method;
    void *mon;
    u8 *buf;
    void *dex, *save, *bank;
    int amount, used, index;
    int flag;
    unsigned long dexno;
    u16 species;
    u16 slot;
    Extra *e;
    busy = PROCSYS_Main((*(void **)((u8 *)(r)+( 64))));
    if (busy == 1) return 0;
    switch (*step) {
    case 0:
        party = GAME_DATA_GetMyParty((*(void **)((u8 *)(s)+( 0))));
        buf = GAME_DATA_GetMyStatus((*(void **)((u8 *)(s)+( 0))));
        dex = ZUKAN_SAVE_GetFromGameData((*(void **)((u8 *)(s)+( 0))));
        save = (void *)GAME_DATA_GetBoxManager((*(void **)((u8 *)(s)+( 0))));
        (((Rec *)r)->idx) = 0;
        (((Rec *)r)->mask) = 0;
        if ((*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 0))) <= 1) {
            EVENT_BATTLE_RETURN_FlagLeveledUpMembers(r, (struct S *)s);
            POKEPARTY_Copy((*(void **)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 36))), party);
            POKERUS_TryInfectParty(party);
            POKERUS_SpreadParty(party);
            if ((*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 140))) == 1) EVENT_BATTLE_RETURN_ApplyPickupAndHoneyGather(party);
            EVENT_BATTLE_RETURN_ApplyBurmyForms((struct S *)s, party, EVENT_BATTLE_RETURN_GetBurmyForm((u32)(*(void **)((u8 *)(s)+( 4))) + 8, (*(u16 *)((u8 *)(r)+( 60)))));
            EVENT_BATTLE_RETURN_RegisterShayminForms((struct S *)s, party);
            amount = (*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 136)));
            if (amount > 0) BEACON_AddMoney(GAME_DATA_GetMiscSave((*(void **)((u8 *)(s)+( 0)))), amount);
            else if (amount < 0) BEACON_SubMoney(GAME_DATA_GetMiscSave((*(void **)((u8 *)(s)+( 0)))), -amount);
        }
        EVENT_BATTLE_RETURN_ApplyNaturalCure(party);
        if ((*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 140))) == 5) {
            (*(void **)((u8 *)(r)+( 8))) = POKEPARTY_GetMember((*(void **)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 40))), *((u8 *)(*(void **)((u8 *)(s)+( 4))) + 144));
            func_02008500(buf, (*(void **)((u8 *)(r)+( 4))));
            POKE_TOOL_SetPartyValue((*(void **)((u8 *)(r)+( 8))), 141, (*(u32 *)((u8 *)(r)+( 4))));
            used = (int)POKEPARTY_GetCount(party);
            if (used >= (int)POKEPARTY_GetCapacity(party)) {
                box = func_02007698(save); bslot = 0;
                func_020076D0(save, &box, &bslot);
                (*(u32 *)((u8 *)(r)+( 48))) = box;
                bank = func_02045B38(0, 2, 234, 82);
                index = ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork((*(void **)((u8 *)(s)+( 0)))), 0x96d) ? 177 : 176;
                (*(void **)((u8 *)(r)+( 44))) = func_02045EC0(bank, index);
                MSGDATA_Delete(bank);
            }
            SAVE_EVENT_Write((*(void **)((u8 *)(r)+( 8))), 0, (u32)buf, ZONEDATA_GetPlaceNameId(GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((*(void **)((u8 *)(s)+( 0)))))), (*(u16 *)((u8 *)(r)+( 60))));
            flag = 0;
            dexno = ZUKAN_SAVE_IsNationalDexEnabled(dex);
            if (ZUKAN_SAVE_IsCaught(dex, POKE_TOOL_GetPartyValue((*(void **)((u8 *)(r)+( 8))), 5, 0)) == 0) flag = 1;
            ZUKAN_SAVE_RegisterSeen(dex, (*(void **)((u8 *)(r)+( 8))));
            ZUKAN_SAVE_RegisterCaught(dex, (*(void **)((u8 *)(r)+( 8))));
            (*(u32 *)((u8 *)(r)+( 20))) = dexno;
            (*(void **)((u8 *)(r)+( 16))) = (*(void **)((u8 *)(r)+( 8)));
            (*(void **)((u8 *)(r)+( 24))) = (*(void **)((u8 *)(r)+( 44)));
            (*(void **)((u8 *)(r)+( 28))) = save;
            (*(u32 *)((u8 *)(r)+( 32))) = (*(u32 *)((u8 *)(r)+( 48)));
            (*(void **)((u8 *)(r)+( 36))) = (*(void **)((u8 *)(s)+( 0)));
            if (flag) (*(u32 *)((u8 *)(r)+( 12))) = 0; else (*(u32 *)((u8 *)(r)+( 12))) = 1;
            PROCSYS_Push((*(void **)((u8 *)(r)+( 64))), (u32)ov207_id, gCatchRegistrationProcData, r + 12);
            ++*step;
        } else *step = 4;
        break;
    case 1:
        if (busy != 1) {
        save = (void *)GAME_DATA_GetBoxManager((*(void **)((u8 *)(s)+( 0))));
        flag = 0;
        if ((*(u32 *)((u8 *)(r)+( 40))) == 1) flag = 1;
        if (flag) {
            bank = BEACON_GetBlock(GAME_DATA_GetSaveControl((*(void **)((u8 *)(s)+( 0)))));
            (*(void **)((u8 *)(r)+( 0))) = NAMEIN_SETUP_CreateCaptureArgs((*(u16 *)((u8 *)(r)+( 60))), (int)(*(void **)((u8 *)(r)+( 8))), 10, 0, (int)(*(void **)((u8 *)(r)+( 44))), (int)save, (*(u32 *)((u8 *)(r)+( 48))), (int)bank);
            PROCSYS_Push((*(void **)((u8 *)(r)+( 64))), (u32)ov194_id, data_021F5580, (*(void **)((u8 *)(r)+( 0))));
            ++*step;
        } else *step = 3;
        break;
        }
        return 0;
    case 2:
        if (busy != 1) {
        if (!NAMEIN_SETUP_IsCanceled((*(void **)((u8 *)(r)+( 0))))) {
            NAMEIN_SETUP_CopyName((*(void **)((u8 *)(r)+( 0))), (u32)(*(u32 *)((u8 *)(r)+( 4))));
            POKE_TOOL_SetPartyValue((*(void **)((u8 *)(r)+( 8))), 115, (*(u32 *)((u8 *)(r)+( 4))));
            func_02008DF0(GAME_DATA_GetTrainerRecord((*(void **)((u8 *)(s)+( 0)))), 30);
        }
        NAMEIN_SETUP_FreeArgs((int)(*(void **)((u8 *)(r)+( 0))));
        (*(void **)((u8 *)(r)+( 0))) = 0;
        ++*step;
        break;
        }
        return 0;
    case 3:
        party = GAME_DATA_GetMyParty((*(void **)((u8 *)(s)+( 0))));
        EVENT_BATTLE_RETURN_ApplyHealBall((*(void **)((u8 *)(r)+( 8))));
        if (!(*(void **)((u8 *)(r)+( 44)))) POKEPARTY_Add(party, (*(void **)((u8 *)(r)+( 8))));
        else {
            save = (void *)GAME_DATA_GetBoxManager((*(void **)((u8 *)(s)+( 0))));
            func_020074D8(save, POKE_TOOL_CastToBoxParam((*(void **)((u8 *)(r)+( 8)))));
        }
        ++*step;
        break;
    case 4: {
        void *party;
        if (!(*(u32 *)((u8 *)(r)+( 68)))) {
            if ((*(u32 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 140))) == 5 && (((Rec *)r)->mask)) {
                if (!(*(u32 *)((u8 *)(r)+( 72)))) { GFL_USE_FadeOutBgm(30); (*(u32 *)((u8 *)(r)+( 72))) = 1; break; }
                if (GFL_USE_IsBgmFading()) break;
                GFL_USE_CancelChangeAndStopBgm();
                (*(u32 *)((u8 *)(r)+( 68))) = 1;
                break;
            }
            (*(u32 *)((u8 *)(r)+( 68))) = 1;
            break;
        }
        if ((((Rec *)r)->mask)) {
            species = 0;
            party = GAME_DATA_GetMyParty((*(void **)((u8 *)(s)+( 0))));
            *step = 6;
            while ((((Rec *)r)->mask)) {
                if ((((Rec *)r)->mask) & 1) {
                    mon = POKEPARTY_GetMember(party, (((Rec *)r)->idx));
                    species = SHINKA_CHECK_CheckEvolution(party, mon, 0, (*(u16 *)((u8 *)((*(void **)((u8 *)(s)+( 4))))+( 18))), GAME_DATA_GetSeason((*(void **)((u8 *)(s)+( 0)))), &method, (*(u16 *)((u8 *)(r)+( 60))));
                    slot = (((Rec *)r)->idx);
                }
                (((Rec *)r)->mask) = (((Rec *)r)->mask) >> 1;
                (((Rec *)r)->idx)++;
                if (species) {
                    e = func_02030734((*(u16 *)((u8 *)(r)+( 60))), 20, 0, (const char *)sSourceFileName, 0x1ca);
                    e->save = (*(void **)((u8 *)(s)+( 0))); e->party = party; e->species = species; e->slot = slot; e->method = method; e->x = 0; e->flag = 1;
                    (*(void **)((u8 *)(r)+( 52))) = e;
                    PROCSYS_Push((*(void **)((u8 *)(r)+( 64))), (u32)ov195_id, data_02208C40, e);
                    *step = 5;
                    break;
                }
            }
        } else *step = 6;
        break;
    }
    case 5:
        if (busy != 1) {
        func_020307B0((*(void **)((u8 *)(r)+( 52))));
        (*(void **)((u8 *)(r)+( 52))) = 0;
        if ((((Rec *)r)->mask)) *step = 4;
        else ++*step;
        break;
        }
        return 0;
    case 6:
    default:
        return 1;
    }
    return 0;
}
