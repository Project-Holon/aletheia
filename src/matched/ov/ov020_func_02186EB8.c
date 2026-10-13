/*
 * function: FIELD_WFBC_DATA_LOCAL_ScrCmdFindTargetPokemonInParty
 * address:  0x02186EB8
 * packet:   pkt_ov020_02186EB8
 * region:   ov020
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * symbols:
 *   SCRCMD_WORK_GetScriptWork  0x0215A5F4  thumb  ov010
 *   SCRCMD_WORK_GetGameData  0x0215A5E4  thumb  ov010
 *   GAME_DATA_GetSecondUnionInfo  0x020127C4  thumb
 *   GAME_DATA_GetMysteryRecvFlagB  0x020127F0  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   SCRIPT_WORK_ReadWorkPointer  0x02159AE8  thumb  ov010
 *   POKEPARTY_GetCount  0x0201AA18  thumb
 *   FIELD_WFBC_DATA_LOCAL_ReadValue  0x021869D0  thumb  ov020
 *   func_0203F4E4  0x0203F4E4  arm
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   POKE_TOOL_GetPartyValue  0x02017E1C  thumb
 */

typedef unsigned short u16;
typedef unsigned int u32;

void *SCRCMD_WORK_GetScriptWork(void *a);
void *SCRCMD_WORK_GetGameData(void *a);
typedef unsigned char  u8;
u8 *GAME_DATA_GetSecondUnionInfo(void *p);
int GAME_DATA_GetMysteryRecvFlagB(int a0);
struct BigObj;
void *GAME_DATA_GetMyParty(const struct BigObj *p);
u16 *SCRIPT_WORK_ReadWorkPointer(void *a, void *b);
u32 POKEPARTY_GetCount(void *a);
u16 FIELD_WFBC_DATA_LOCAL_ReadValue(char *p);
struct RtcDate;
void func_0203F4E4(struct RtcDate *date);
void *POKEPARTY_GetMember(void *a, u32 i);
u32 POKE_TOOL_GetPartyValue(void *p, u32 id, u32 v);

int FIELD_WFBC_DATA_LOCAL_ScrCmdFindTargetPokemonInParty(void *a0, void *a1)
{
    void *s;
    void *w;
    void *b;
    u16 *f0;
    u16 *f1;
    u16 *f2;
    u32 n;
    int key;
    int d[4];
    u32 i;
    void *e;
    int v5, v92, v93, v94, v96, v4c, v8f, v90, v91;

    SCRCMD_WORK_GetScriptWork(a1);
    s = SCRCMD_WORK_GetGameData(a1);
    GAME_DATA_GetSecondUnionInfo(s);
    w = (void *)GAME_DATA_GetMysteryRecvFlagB((int)s);
    b = GAME_DATA_GetMyParty(s);
    f0 = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    f1 = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    f2 = SCRIPT_WORK_ReadWorkPointer(a0, a1);
    n = POKEPARTY_GetCount(b);
    key = FIELD_WFBC_DATA_LOCAL_ReadValue(w);
    func_0203F4E4((struct RtcDate *)d);
    *f0 = 0;
    *f1 = 0;
    *f2 = 0xFFFF;
    for (i = 0; i < n; i++) {
        e = POKEPARTY_GetMember(b, i);
        v5 = POKE_TOOL_GetPartyValue(e, 5, 0);
        v92 = POKE_TOOL_GetPartyValue(e, 0x92, 0);
        v93 = POKE_TOOL_GetPartyValue(e, 0x93, 0);
        v94 = POKE_TOOL_GetPartyValue(e, 0x94, 0);
        v96 = POKE_TOOL_GetPartyValue(e, 0x96, 0);
        v4c = POKE_TOOL_GetPartyValue(e, 0x4c, 0);
        v8f = POKE_TOOL_GetPartyValue(e, 0x8f, 0);
        v90 = POKE_TOOL_GetPartyValue(e, 0x90, 0);
        v91 = POKE_TOOL_GetPartyValue(e, 0x91, 0);
        if (v5 == key && v4c == 0 && v96 == 0x33 && v8f + v91 + v90 == 0) {
            *f0 = 1;
            if (*f2 == 0xFFFF)
                *f2 = i;
            if (v92 == d[0] && v93 == d[1] && v94 == d[2]) {
                *f1 = 1;
                *f2 = i;
            }
        }
    }
    return 0;
}
