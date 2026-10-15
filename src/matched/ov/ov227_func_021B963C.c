/*
 * function: EVENT_PDC_RETURN_Step
 * address:  0x021B963C
 * packet:   pkt_ov227_021B963C
 * region:   ov227
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * 2026-10-05 (wave D4 lane 01): EXACT. Closed by: case 1/2 bodies under `if (r != 1) { ... }`
 * with `return 0;` after the block (late per-case epilogues); the f24 test through an `ok` flag
 * (`ok = 0; if (g->f24 == 1) ok = 1; if (ok)`); `fl = 0;` written after the SAVE_EVENT_Write call;
 * g->f08 as an if/else on fl. Pool words 0xCF/0xC2 are overlay ids (ov207_id, ov194_id).
 *
 * symbols:
 *   func_020074D8  0x020074D8  thumb
 *   func_02007698  0x02007698  thumb
 *   func_020076D0  0x020076D0  thumb
 *   func_02008500  0x02008500  thumb
 *   func_02008DF0  0x02008DF0  thumb
 *   BEACON_GetBlock  0x0200C0F0  thumb
 *   ZUKAN_SAVE_GetFromGameData  0x0200CA1C  thumb
 *   ZUKAN_SAVE_IsNationalDexEnabled  0x0200CA38  thumb
 *   ZUKAN_SAVE_RegisterCaught  0x0200CDE0  thumb
 *   ZUKAN_SAVE_IsCaught  0x0200CED4  thumb
 *   ZUKAN_SAVE_RegisterSeen  0x0200CFA0  thumb
 *   GAME_DATA_GetMyPlayerWork  0x020127A4  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   GAME_DATA_GetBoxManager  0x0201293C  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   GAME_DATA_GetEventWork  0x0201296C  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetSaveControl  0x02012EBC  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   ZONEDATA_GetPlaceNameId  0x02013E4C  thumb
 *   ZONEDATA_CheckEventFlag  0x020142E8  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   POKE_TOOL_SetPartyValue  0x02017E40  thumb
 *   POKE_TOOL_Dummy  0x020185F0  thumb
 *   POKEPARTY_Add  0x0201A98C  thumb
 *   POKEPARTY_GetCapacity  0x0201AA14  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   SAVE_EVENT_Write  0x0202F190  thumb
 *   PROCSYS_Main  0x02031330  arm
 *   PROCSYS_Push  0x02031348  arm
 *   ov207_id  0x000000CF  data
 *   ov194_id  0x000000C2  data
 *   func_02045B38  0x02045B38  arm
 *   MSGDATA_Delete  0x02045C04  arm
 *   func_02045EC0  0x02045EC0  arm
 *   NAMEIN_SETUP_CreateCaptureArgs  0x0216C0A4  thumb  ov010
 *   NAMEIN_SETUP_FreeArgs  0x0216C0C0  thumb  ov010
 *   NAMEIN_SETUP_CopyName  0x0216C0D4  thumb  ov010
 *   NAMEIN_SETUP_IsCanceled  0x0216C0E4  thumb  ov010
 */

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct {
    u32 f0, f1, f2;
} Ctx;

typedef struct {
    u32 f00;
    u32 f04;
    u32 f08;
    u32 f0c;
    u32 f10;
    u32 f14;
    u32 f18;
    u32 f1c;
    u32 f20;
    u32 f24;
    u32 f28;
    u32 f2c;
    u16 f30;
    u16 pad32;
    u32 f34;
} G;

typedef signed int     s32;
struct Big;
struct BigObj;
struct Blk37;
struct MsgBank;
struct Party;
struct PartyMon;
struct Rec;
struct Rec44;
struct SaveBlock;
struct Sub02007454Entry;
struct Sub02008C20Obj;
extern unsigned int PROCSYS_Main(void *p);
extern unsigned char ov207_id[];
extern unsigned char ov194_id[];
extern u32 PROCSYS_Push(u32 a, u32 b, u32 c, void *d);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *ZUKAN_SAVE_GetFromGameData(void *a);
extern u32 GAME_DATA_GetBoxManager(const struct BigObj *p);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern u32 func_02008DF0(struct Sub02008C20Obj *obj, int i);
extern void func_02008500(void *a, void *b);
extern void POKE_TOOL_SetPartyValue(void *p, u32 id, u32 v);
extern u32 POKEPARTY_GetCount(void *p);
extern u32 POKEPARTY_GetCapacity(void *p);
extern u32 func_02007698(void *save);
extern int func_020076D0(void *save, int *pbox, int *pslot);
extern struct MsgBank *func_02045B38(u32 resident, u32 arcId, u32 fileId, u32 heapId);
extern u32 GAME_DATA_GetEventWork(const struct BigObj *p);
extern u32 ZONEDATA_CheckEventFlag(void *bitmap, s32 id);
extern void *func_02045EC0(struct MsgBank *bank, u32 index);
extern u32 MSGDATA_Delete(struct Rec *rec);
extern void *GAME_DATA_GetMyPlayerWork(struct SaveBlock *p);
extern u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
extern u32 ZONEDATA_GetPlaceNameId(u32 a);
extern void SAVE_EVENT_Write(void *a0, u32 a1, u32 a2, u32 a3, u16 a4);
extern u32 ZUKAN_SAVE_IsNationalDexEnabled(struct Blk37 *p);
extern u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);
extern u32 ZUKAN_SAVE_IsCaught(struct Blk37 *p, u16 id);
extern void ZUKAN_SAVE_RegisterSeen(struct Blk37 *p, void *m);
extern void ZUKAN_SAVE_RegisterCaught(struct Blk37 *p, void *m);
extern void *GAME_DATA_GetSaveControl(struct Big *p);
extern void *BEACON_GetBlock(void *sys);
extern int *NAMEIN_SETUP_CreateCaptureArgs(unsigned short a, int b, int c, int d, int e, int f, int g, int h);
extern int NAMEIN_SETUP_IsCanceled(int *p);
extern void NAMEIN_SETUP_CopyName(int *p, int a1);
extern int NAMEIN_SETUP_FreeArgs(int a0);
extern u32 POKEPARTY_Add(struct Party *p, const struct PartyMon *src);
extern u32 POKE_TOOL_Dummy(u32 a);
extern int func_020074D8(void **save, const struct Sub02007454Entry *src);

u32 EVENT_PDC_RETURN_Step(u32 a0, u32 *state, Ctx *c, G *g)
{
    u32 r, x30, x20, x24, x1c, x28, x18, h, r7;
    int x2c, fl, ok;

    r = PROCSYS_Main((void *)g->f34);
    if (r == 1) {
        return 0;
    }
    switch (*state) {
    case 0:
        x24 = (u32)GAME_DATA_GetMyParty((const struct BigObj *)c->f0);
        x20 = (u32)GAME_DATA_GetMyStatus((void *)c->f0);
        r7 = (u32)ZUKAN_SAVE_GetFromGameData((void *)c->f0);
        x1c = GAME_DATA_GetBoxManager((const struct BigObj *)c->f0);
        if (c->f1 == 1) {
            x28 = (u32)GAME_DATA_GetTrainerRecord((int *)c->f0);
            func_02008DF0((struct Sub02008C20Obj *)x28, (u32)7);
            func_02008DF0((struct Sub02008C20Obj *)x28, (u32)0x54);
            func_02008500((void *)x20, (void *)g->f04);
            POKE_TOOL_SetPartyValue((void *)c->f2, 0x8d, g->f04);
            x2c = (int)POKEPARTY_GetCount((void *)x24);
            if (x2c >= (int)POKEPARTY_GetCapacity((void *)x24)) {
                u32 a, b;
                a = func_02007698((void *)x1c);
                b = 0;
                func_020076D0((void *)x1c, (int *)(&a), (int *)(&b));
                g->f2c = a;
                h = (u32)func_02045B38(0, 2, 0xea, 0x8b);
                g->f28 = (u32)func_02045EC0((struct MsgBank *)h, ZONEDATA_CheckEventFlag((void *)GAME_DATA_GetEventWork((const struct BigObj *)c->f0), (u32)0x96d) != 0 ? 0xb1 : 0xb0);
                MSGDATA_Delete((struct Rec *)h);
            }
            x30 = ZONEDATA_GetPlaceNameId((u32)GAME_DATA_GetPlayerZoneId(GAME_DATA_GetMyPlayerWork((struct SaveBlock *)c->f0)));
            SAVE_EVENT_Write((void *)c->f2, 0, x20, x30, (u32)g->f30);
            fl = 0;
            x18 = ZUKAN_SAVE_IsNationalDexEnabled((struct Blk37 *)r7);
            if (ZUKAN_SAVE_IsCaught((struct Blk37 *)r7, (u16)POKE_TOOL_GetPartyValue((void *)c->f2, 5, 0)) == 0) {
                fl = 1;
            }
            ZUKAN_SAVE_RegisterSeen((struct Blk37 *)r7, (void *)c->f2);
            ZUKAN_SAVE_RegisterCaught((struct Blk37 *)r7, (void *)c->f2);
            g->f0c = c->f2;
            g->f10 = x18;
            g->f14 = g->f28;
            g->f18 = x1c;
            g->f1c = g->f2c;
            g->f20 = c->f0;
            if (fl) {
                g->f08 = 0;
            } else {
                g->f08 = 1;
            }
            PROCSYS_Push(g->f34, (u32)ov207_id, 0x0220BAB0, &g->f08);
            (*state)++;
            break;
        }
        if (c->f1 == 2) {
            ZUKAN_SAVE_RegisterSeen((struct Blk37 *)r7, (void *)c->f2);
        }
        *state = 4;
        break;
    case 1:
        if (r != 1) {
        r7 = GAME_DATA_GetBoxManager((const struct BigObj *)c->f0);
        ok = 0;
        if (g->f24 == 1) {
            ok = 1;
        }
        if (ok) {
            g->f00 = (u32)NAMEIN_SETUP_CreateCaptureArgs((u32)g->f30, (u32)c->f2, (u32)0xa, (u32)0, (u32)g->f28, (u32)r7, (u32)g->f2c, (u32)BEACON_GetBlock(GAME_DATA_GetSaveControl((struct Big *)c->f0)));
            PROCSYS_Push(g->f34, (u32)ov194_id, 0x021F5580, (void *)g->f00);
            (*state)++;
            break;
        }
        *state = 3;
        break;
        }
        return 0;
    case 2:
        if (r != 1) {
        if ((u32)NAMEIN_SETUP_IsCanceled((int *)g->f00) == 0) {
            NAMEIN_SETUP_CopyName((int *)g->f00, (u32)g->f04);
            POKE_TOOL_SetPartyValue((void *)c->f2, 0x73, g->f04);
            func_02008DF0(GAME_DATA_GetTrainerRecord((int *)c->f0), (u32)0x1e);
        }
        NAMEIN_SETUP_FreeArgs((u32)g->f00);
        g->f00 = 0;
        (*state)++;
        break;
        }
        return 0;
    case 3:
        x24 = (u32)GAME_DATA_GetMyParty((const struct BigObj *)c->f0);
        if (g->f28 == 0) {
            POKEPARTY_Add((struct Party *)x24, (const struct PartyMon *)c->f2);
        } else {
            r7 = GAME_DATA_GetBoxManager((const struct BigObj *)c->f0);
            func_020074D8((void **)r7, (const struct Sub02007454Entry *)POKE_TOOL_Dummy(c->f2));
        }
        (*state)++;
        break;
    case 4:
    default:
        return 1;
    }
    return 0;
}
