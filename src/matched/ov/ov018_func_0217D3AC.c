/*
 * function: INTRUDE_SUBDISP_Draw
 * address:  0x0217D3AC
 * packet:   pkt_ov018_0217D3AC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   func_02013D5C  0x02013D5C  thumb
 *   func_02026454  0x02026454  thumb
 *   func_0202648C  0x0202648C  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_HasResult  0x02175DA8  thumb  ov011
 *   INTRUDE_COMM_IsSessionAccepted  0x02175B8C  thumb  ov011
 *   INTRUDE_SUBDISP_GetTargetPlayerData  0x0217EBD8  thumb  ov018
 *   INTRUDE_SUBDISP_ReloadBgScreens  0x0217EEB4  thumb  ov018
 *   INTRUDE_SUBDISP_UpdateBgPalette  0x0217EF44  thumb  ov018
 *   INTRUDE_SUBDISP_PrintTitle  0x0217E638  thumb  ov018
 *   INTRUDE_SUBDISP_PrintInfoMessage  0x0217E714  thumb  ov018
 *   INTRUDE_SUBDISP_UpdateTownActors  0x0217DE68  thumb  ov018
 *   INTRUDE_SUBDISP_UpdatePlayerMarkActors  0x0217E014  thumb  ov018
 *   INTRUDE_SUBDISP_UpdatePlayerTownActors  0x0217E0F4  thumb  ov018
 *   INTRUDE_SUBDISP_UpdateMyPlayerActor  0x0217E3D0  thumb  ov018
 *   INTRUDE_SUBDISP_UpdateButtonActors  0x0217E4D0  thumb  ov018
 *   INTRUDE_SUBDISP_UpdateInfoIcon  0x0217E524  thumb  ov018
 *   INTRUDE_SUBDISP_UpdateButtonBlink  0x0217F194  thumb  ov018
 */

typedef struct {
    void *f0;
    unsigned char pad004[0xDC];
    int fE0;
    unsigned char pad0E4[0x88];
    unsigned char f16C;
} Ov018Menu;

typedef struct { unsigned char a : 7; unsigned char b : 1; } FlagsF8;

struct Ctx;
unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Ctx;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
struct Rec44;
unsigned short GAME_DATA_GetPlayerZoneId(const struct Rec44 *);
int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
u32 func_02013D5C(u32 id);
u32 func_02026454(void *obj);
u32 func_0202648C(void *obj);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
int INTRUDE_COMM_HasResult(u8 *p);
int INTRUDE_COMM_IsSessionAccepted(u8 *p);
void *INTRUDE_SUBDISP_GetTargetPlayerData(u8 *p);
void INTRUDE_SUBDISP_ReloadBgScreens(int *p);
void INTRUDE_SUBDISP_UpdateBgPalette(Ov018Menu *, unsigned char *);
void INTRUDE_SUBDISP_PrintTitle(Ov018Menu *, int);
void INTRUDE_SUBDISP_PrintInfoMessage(Ov018Menu *, unsigned char *, int);
void INTRUDE_SUBDISP_UpdateTownActors(Ov018Menu *, int);
void INTRUDE_SUBDISP_UpdatePlayerMarkActors(u8 *p, int a1);
void INTRUDE_SUBDISP_UpdatePlayerTownActors(Ov018Menu *, unsigned char *, int);
void INTRUDE_SUBDISP_UpdateMyPlayerActor(Ov018Menu *, int, int);
void INTRUDE_SUBDISP_UpdateButtonActors(int *p, int a1);
void INTRUDE_SUBDISP_UpdateInfoIcon(Ov018Menu *, int);
void INTRUDE_SUBDISP_UpdateButtonBlink(Ov018Menu *);

void INTRUDE_SUBDISP_Draw(Ov018Menu *w)
{
    void *s1;
    void *s2;
    unsigned char *p;
    int q;
    int flag;
    int k;

    s1 = (void *)GAMESYSTEM_GetGameComm(w->f0);
    s2 = GAMESYSTEM_GetGameData(w->f0);
    p = (unsigned char *)INTRUDE_COMM_GetWorkIfRunning((int)s1);
    q = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork(w->f0));
    flag = 0;
    k = (int)INTRUDE_SUBDISP_GetTargetPlayerData((u8 *)w);
    if (p != 0 && INTRUDE_COMM_HasResult(p + 0x1AC) == 0) {
        flag = 1;
    } else if (p == 0 && GAME_DATA_GetIntrudeCount(s2) == 1 && func_02026454(s1) != 2
               && func_0202648C(s1) == 0 && func_02013D5C(q) == 1) {
        flag = 1;
    }
    if (p != 0 && ((FlagsF8 *)(p + 0x8F8))->b == 1) {
        flag = 0;
    }
    if (flag == 1) {
        INTRUDE_SUBDISP_ReloadBgScreens((int *)w);
        INTRUDE_SUBDISP_UpdateBgPalette(w, p);
        INTRUDE_SUBDISP_PrintTitle(w, q);
        INTRUDE_SUBDISP_PrintInfoMessage(w, p, q);
        INTRUDE_SUBDISP_UpdateTownActors(w, k);
        INTRUDE_SUBDISP_UpdatePlayerMarkActors((u8 *)w, k);
        INTRUDE_SUBDISP_UpdatePlayerTownActors(w, p, k);
        INTRUDE_SUBDISP_UpdateMyPlayerActor(w, k, q);
        INTRUDE_SUBDISP_UpdateButtonActors((int *)w, k);
        INTRUDE_SUBDISP_UpdateInfoIcon(w, k);
        INTRUDE_SUBDISP_UpdateButtonBlink(w);
        return;
    }
    if (p != 0 && INTRUDE_COMM_HasResult(p + 0x1AC) == 1 && INTRUDE_COMM_IsSessionAccepted(p + 0x1AC) == 1
        && w->f16C == 0 && w->fE0 == 0) {
        INTRUDE_SUBDISP_UpdateInfoIcon(w, k);
        w->f16C = 1;
    }
}
