/*
 * function: SCRCMD_POKEMON_FLD_StoreMonName
 * address:  0x021B65D8
 * packet:   pkt_ov021_021B65D8
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
 *   SCRIPT_WORK_ReadWorkValue  0x02159B10  thumb  ov010
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAME_DATA_GetSaveBlock43  0x02012FD8  thumb
 *   GAME_DATA_GetMyParty  0x02012934  thumb
 *   POKEPARTY_GetMember  0x0201AB28  thumb
 *   MON_SNAPSHOT_Fill  0x0200E7BC  thumb
 * Addresses are Black-image addresses.
 */

typedef unsigned char  u8;
typedef unsigned short u16;
typedef unsigned int   u32;

extern void *SCRCMD_WORK_GetScriptWork(void *p);
extern void *SCRCMD_WORK_GetGameSystem(void *a0);
extern u32 SCRIPT_WORK_ReadWorkValue(void *, void *);
struct BigObj;
struct Ctx;
struct Rec0200E7BC;
extern void *GAMESYSTEM_GetGameData(const struct Ctx *p);
extern void *GAME_DATA_GetSaveBlock43(void **p);
extern void *GAME_DATA_GetMyParty(const struct BigObj *p);
extern void *POKEPARTY_GetMember(void *p, u32 idx);
extern void MON_SNAPSHOT_Fill(struct Rec0200E7BC *o, int idx, void *mon);

u32 SCRCMD_POKEMON_FLD_StoreMonName(void *a, void *b)
{
    void *t;
    void *w;
    int i;
    int j;

    SCRCMD_WORK_GetScriptWork(b);
    t = GAMESYSTEM_GetGameData(SCRCMD_WORK_GetGameSystem(b));
    w = GAME_DATA_GetSaveBlock43(t);
    t = GAME_DATA_GetMyParty(t);
    i = SCRIPT_WORK_ReadWorkValue(a, b);
    j = SCRIPT_WORK_ReadWorkValue(a, b);
    MON_SNAPSHOT_Fill(w, j, POKEPARTY_GetMember(t, i));
    return 0;
}
