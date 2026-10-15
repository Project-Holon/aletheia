/*
 * function: SCRCMD_GetNpcGreetingMessage
 * address:  0x021D2B54
 * packet:   pkt_ov021_021D2B54
 * region:   ov021
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameSystem  0x0215A5DC  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetMyStatus  0x02012944  thumb
 *   SCRIPT_WORK_GetWordSet  0x02158F74  thumb  ov010
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   func_0201F02C  0x0201F02C  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 *   WORDSET_Callback  0x0201EE60  thumb
 *   GF_STANDARD_SetField00  0x0203F4CC  arm
 *   func_020056EC  0x020056EC  thumb
 *   GAME_DATA_GetTrainerRecord  0x02012F2C  thumb
 *   gGreetingCounterTable     0x021DD774  data  ov021
 *   func_02008DFC  0x02008DFC  thumb
 *   func_0201EFA4  0x0201EFA4  thumb
 *   func_02008550  0x02008550  thumb
 *   SCRCMD_GREETING_AdjustMessageIdByMisc  0x021D2CE8  thumb  ov021
 *   SCRCMD_GREETING_AdjustMessageIdByRandom  0x021D2D24  thumb  ov021
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

typedef struct {
    u32 hour;
    u32 minute;
    u32 second;
} RtcTime;

typedef struct {
    u32 a;
    u32 b;
    u32 c;
    u32 d;
} Entry;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
struct BigObj;
struct Ctx;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
struct Sub02008C20Obj;
struct WordSet;
extern u8 *GAME_DATA_GetMyStatus(void *p);
extern void *SCRIPT_WORK_GetWordSet(void *p);
extern unsigned int SCRIPT_WORK_ReadWorkValue(void *a, void *b);
extern u16 *SCRIPT_WORK_ReadWorkPointer(void *a0, void *a1);
extern void func_0201F02C(struct WordSet *p, u32 i, void *a);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern u32 POKEPARTY_GetCount(void *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern u32 POKE_TOOL_GetPartyValue(void *mon, u32 id, u32 v);
extern void WORDSET_Callback(struct WordSet *p, u32 i, u16 v);
struct RtcTime;
struct Sub0200852CObj;
extern void GF_STANDARD_SetField00(struct RtcTime *time);
extern u32 func_020056EC(u32 v);
extern void *GAME_DATA_GetTrainerRecord(int *p);
extern const Entry gGreetingCounterTable[];
extern u32 func_02008DFC(struct Sub02008C20Obj *obj, int i);
extern void func_0201EFA4(struct WordSet *p, u32 i, u32 a, u32 b, u32 c, u32 d);
extern u8 func_02008550(const struct Sub0200852CObj *obj);
extern u32 SCRCMD_GREETING_AdjustMessageIdByMisc(void *a, int i);
extern u32 SCRCMD_GREETING_AdjustMessageIdByRandom(void *a, u32 v, int c);

int SCRCMD_GetNpcGreetingMessage(u32 a, u32 b)
{
    void *h;
    u32 name, ws, v;
    void *o;
    u16 *out;
    void *party;
    int i, n;
    void *mon;
    RtcTime t;
    int base;
    int k;
    u32 s0, s1;
    u32 tr;
    u32 e0, e1;

    o = SCRCMD_WORK_GetScriptWork((void *)b);
    h = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem((void *)b));
    name = (u32)GAME_DATA_GetMyStatus(h);
    ws = (u32)SCRIPT_WORK_GetWordSet(o);
    v = SCRIPT_WORK_ReadWorkValue((void *)a, (void *)b);
    out = SCRIPT_WORK_ReadWorkPointer((void *)a, (void *)b);
    func_0201F02C((struct WordSet *)ws, 0, (void *)name);
    party = GAME_DATA_GetMyParty(h);
    n = POKEPARTY_GetCount(party);
    for (i = 0; i < n; i++) {
        mon = POKEPARTY_GetMember(party, i);
        if (POKE_TOOL_GetPartyValue(mon, 0x4C, 0) == 0) {
            WORDSET_Callback((struct WordSet *)ws, 3, POKE_TOOL_GetPartyValue(mon, 5, 0));
            break;
        }
    }
    GF_STANDARD_SetField00((struct RtcTime *)(&t));
    if (t.minute < 10) {
        base = 0;
        k = func_020056EC(0x1D);
        s0 = 0;
        s1 = 0;
        tr = (u32)GAME_DATA_GetTrainerRecord(h);
        e0 = gGreetingCounterTable[k].a;
        if (e0 != -1) {
            s0 = func_02008DFC((struct Sub02008C20Obj *)tr, e0);
            func_0201EFA4((struct WordSet *)ws, 1, s0, gGreetingCounterTable[k].c, 0, 1);
        }
        e1 = gGreetingCounterTable[k].b;
        if (e1 != -1) {
            s1 = func_02008DFC((struct Sub02008C20Obj *)tr, e1);
            func_0201EFA4((struct WordSet *)ws, 2, s1, gGreetingCounterTable[k].d, 0, 1);
        }
        if (k < 11) {
            if (e0 != -1 && e1 != -1) {
                if (s0 == 0 || s1 == 0) {
                    k = 0;
                }
            } else if (e1 == -1 && s0 == 0) {
                k = 0;
            }
        }
        if (k < 11) {
            if ((u8)(int)func_02008550((const struct Sub0200852CObj *)name) == 1) {
                k += 11;
            }
        } else {
            k += 11;
        }
    } else if (t.minute < 0x23) {
        base = 0x28;
        k = func_020056EC(0x32);
    } else {
        base = 0x5A;
        k = func_020056EC(0x50);
    }
    *out = SCRCMD_GREETING_AdjustMessageIdByRandom(h, SCRCMD_GREETING_AdjustMessageIdByMisc(h, base + k), v);
    return 0;
}
