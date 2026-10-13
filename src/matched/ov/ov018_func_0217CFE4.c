/*
 * function: INTRUDE_SUBDISP_Init
 * address:  0x0217CFE4
 * packet:   pkt_ov018_0217CFE4
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   func_02030734  0x02030734  arm
 *   func_02026454  0x02026454  thumb
 *   func_02026474  0x02026474  thumb
 *   INTRUDE_SUBDISP_InitTownState  0x0217EFCC  thumb  ov018
 *   func_020490F4  0x020490F4  arm
 *   INTRUDE_SUBDISP_SystemSetup  0x0217D624  thumb  ov018
 *   INTRUDE_SUBDISP_BgSetup  0x0217D720  thumb  ov018
 *   INTRUDE_SUBDISP_BmpWinSetup  0x0217D890  thumb  ov018
 *   INTRUDE_SUBDISP_ClactResourceLoad  0x0217D918  thumb  ov018
 *   INTRUDE_SUBDISP_ClactActorCreate  0x0217DA54  thumb  ov018
 *   ARC_TOOL_DeleteHandle  0x02049238  arm
 *   GFL_NET_RestartWithDefaultTimeout  0x0203D34C  arm
 *   GFL_NET_WM_ICON_EasyObjWindowOn  0x02037174  arm
 *   func_020056A0  0x020056A0  thumb
 *   INTRUDE_SUBDISP_VBlankTask  0x0217D5AC  thumb  ov018
 *   GAMESYSTEM_GetMyPlayerWork  0x020120F8  thumb
 *   GAME_DATA_GetPlayerZoneId  0x02012AC8  thumb
 *   INTRUDE_SUBDISP_GetTargetPlayerData  0x0217EBD8  thumb  ov018
 *   INTRUDE_SUBDISP_PrintTitle  0x0217E638  thumb  ov018
 *   INTRUDE_SUBDISP_UpdateTownActors  0x0217DE68  thumb  ov018
 *   INTRUDE_SUBDISP_UpdatePlayerMarkActors  0x0217E014  thumb  ov018
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_SUBDISP_UpdatePlayerTownActors  0x0217E0F4  thumb  ov018
 *   INTRUDE_SUBDISP_UpdateMyPlayerActor  0x0217E3D0  thumb  ov018
 *   INTRUDE_SUBDISP_UpdateButtonActors  0x0217E4D0  thumb  ov018
 *   INTRUDE_SUBDISP_UpdateInfoIcon  0x0217E524  thumb  ov018
 *   str_02183B14   0x02183B14  data  a1
 */
#include "../include/Obj02674.h"

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef struct { u8 a : 7; u8 b : 1; } FlagsF8;

extern char str_02183B14[];

struct Ctx;
u32 GAMESYSTEM_GetGameComm(const struct Ctx *p);
void *func_02030734(u32 heapId, u32 size, int clear, const char *site, u16 tag);
u32 func_02026454(void *obj);
u32 func_02026474(void *obj);
struct State;
void INTRUDE_SUBDISP_InitTownState(char *p, char *q);
void *func_020490F4(u32 id, u32 heap);
void INTRUDE_SUBDISP_SystemSetup(struct State *o);
void INTRUDE_SUBDISP_BgSetup(u8 *w, void *bg);
void INTRUDE_SUBDISP_BmpWinSetup(u8 *w);
void INTRUDE_SUBDISP_ClactResourceLoad(u8 *w, void *bg);
void INTRUDE_SUBDISP_ClactActorCreate(void *p, void *bg);
void ARC_TOOL_DeleteHandle(void *bg);
void GFL_NET_RestartWithDefaultTimeout(u32 a, u32 b);
void GFL_NET_WM_ICON_EasyObjWindowOn(void);
void *func_020056A0(void (*cb)(void), void *arg, int pri);
void INTRUDE_SUBDISP_VBlankTask(int a0, u8 *p);
u8 *GAMESYSTEM_GetMyPlayerWork(const struct Ctx *p);
struct Rec44;
u16 GAME_DATA_GetPlayerZoneId(const struct Rec44 *p);
void *INTRUDE_SUBDISP_GetTargetPlayerData(u8 *p);
void INTRUDE_SUBDISP_PrintTitle(u8 *w, int);
void INTRUDE_SUBDISP_UpdateTownActors(u8 *w, int);
void INTRUDE_SUBDISP_UpdatePlayerMarkActors(u8 *w, int);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
void INTRUDE_SUBDISP_UpdatePlayerTownActors(u8 *w, u8 *, int);
void INTRUDE_SUBDISP_UpdateMyPlayerActor(u8 *w, int, int);
void INTRUDE_SUBDISP_UpdateButtonActors(int *p, int a1);
void INTRUDE_SUBDISP_UpdateInfoIcon(u8 *w, int);

#define REG_DB_DISPCNT_SUB (*(volatile u32 *)0x04001000)
#define REG_WINOUT_SUB     (*(volatile u16 *)0x0400104A)

u8 *INTRUDE_SUBDISP_Init(void *a)
{
    void *s;
    u8 *w;
    u8 *p;
    void *bg;
    int i;
    int q;
    int k;
    u32 tmp;

    s = (void *)GAMESYSTEM_GetGameComm(a);
    w = func_02030734(0x70, 0x170, 1, str_02183B14, 0x240);
    ((struct Obj02674 *)w)->f0 = a;
    w[0x105] = 0xFF;
    w[0x11B] = 0xFF;
    w[0x169] = 4;
    w[0x16A] = 4;
    ((struct Obj02674 *)w)->f10A = -1;
    for (i = 0; i < 3; i++) {
        *(u16 *)(w + 0xF0 + i * 8) = 0x1AB;
    }
    p = 0;
    if (func_02026454(s) == 2) {
        p = (u8 *)func_02026474(s);
    }
    if (p != 0 && ((FlagsF8 *)(p + 0x8F8))->b == 1) {
        p = 0;
    }
    INTRUDE_SUBDISP_InitTownState((char *)w, (char *)p);
    w[0x11E] = w[0xDA];
    bg = func_020490F4(0x24, 0x15);
    INTRUDE_SUBDISP_SystemSetup((struct State *)w);
    INTRUDE_SUBDISP_BgSetup(w, bg);
    INTRUDE_SUBDISP_BmpWinSetup(w);
    INTRUDE_SUBDISP_ClactResourceLoad(w, bg);
    INTRUDE_SUBDISP_ClactActorCreate(w, bg);
    ARC_TOOL_DeleteHandle(bg);
    GFL_NET_RestartWithDefaultTimeout(0, 0x15);
    GFL_NET_WM_ICON_EasyObjWindowOn();
    REG_WINOUT_SUB = (u16)((REG_WINOUT_SUB & ~0x3F00) | (0x1F << 8));
    tmp = (REG_WINOUT_SUB & ~0x3F) | 0x1F;
    tmp |= 0x20;
    REG_WINOUT_SUB = (u16)tmp;
    REG_DB_DISPCNT_SUB = (REG_DB_DISPCNT_SUB & ~0xE000) | 0x8000;
    ((struct Obj02674 *)w)->f34 = func_020056A0((void (*)(void))INTRUDE_SUBDISP_VBlankTask, w, 10);
    q = GAME_DATA_GetPlayerZoneId((const struct Rec44 *)GAMESYSTEM_GetMyPlayerWork(((struct Obj02674 *)w)->f0));
    k = (int)INTRUDE_SUBDISP_GetTargetPlayerData(w);
    INTRUDE_SUBDISP_PrintTitle(w, q);
    INTRUDE_SUBDISP_UpdateTownActors(w, k);
    INTRUDE_SUBDISP_UpdatePlayerMarkActors(w, k);
    INTRUDE_SUBDISP_UpdatePlayerTownActors(w, (u8 *)INTRUDE_COMM_GetWorkIfRunning((int)s), k);
    INTRUDE_SUBDISP_UpdateMyPlayerActor(w, k, q);
    INTRUDE_SUBDISP_UpdateButtonActors((int *)w, k);
    INTRUDE_SUBDISP_UpdateInfoIcon(w, k);
    return w;
}
