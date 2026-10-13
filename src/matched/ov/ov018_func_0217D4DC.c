/*
 * function: INTRUDE_SUBDISP_EventCheck
 * address:  0x0217D4DC
 * packet:   pkt_ov018_0217D4DC
 * region:   ov018
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 * symbols:
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAMESYSTEM_GetGameData  0x020120F4  thumb
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   GAME_DATA_GetIntrudeCount  0x02012B70  thumb
 *   INTRUDE_COMM_GetWorkIfRunning  0x02158344  thumb  ov010
 *   INTRUDE_COMM_GetPlayerNetId  0x02158378  thumb  ov010
 *   GFL_USE_PlaySeDefaultVolume  0x020061E4  thumb
 *   INTRUDE_SUBDISP_StartButtonBlink  0x0217F174  thumb  ov018
 *   INTRUDE_SUBDISP_StartTownBlink  0x0217F0C4  thumb  ov018
 *   INTRUDE_SUBDISP_CreateBrightFadeEvent  0x0217CEE8  thumb  ov018
 *   INTRUDE_SUBDISP_CreateTownWarpEvent  0x0217CE08  thumb  ov018
 *   INTRUDE_SUBDISP_CreatePlayerWarpEvent  0x0217CE6C  thumb  ov018
 */

typedef struct {
    void *f0;
    unsigned char pad004[0x10C];
    unsigned short f110;
    unsigned char f112;
    unsigned char pad113[0x55];
    unsigned char f168;
} Ov018Menu;

struct Ctx;
unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *p);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct BigObj;
struct Ctx;
void *GAMESYSTEM_GetGameData(const struct Ctx *p);
void *GAMESYSTEM_GetFieldMap(const struct Ctx *p);
int GAME_DATA_GetIntrudeCount(const struct BigObj *p);
int INTRUDE_COMM_GetWorkIfRunning(int a0);
int INTRUDE_COMM_GetPlayerNetId(void *);
void GFL_USE_PlaySeDefaultVolume(u32 a);
void INTRUDE_SUBDISP_StartButtonBlink(u8 *p);
void INTRUDE_SUBDISP_StartTownBlink(u8 *p);
void *INTRUDE_SUBDISP_CreateBrightFadeEvent(void *p, int a, int b);
void *INTRUDE_SUBDISP_CreateTownWarpEvent(void *, void *, int, int);
void *INTRUDE_SUBDISP_CreatePlayerWarpEvent(void *, void *, int);

void *INTRUDE_SUBDISP_EventCheck(Ov018Menu *w, int b, int c)
{
    void *s1;
    void *s2;
    void *r;
    void *ret;

    s1 = (void *)GAMESYSTEM_GetGameComm(w->f0);
    s2 = GAMESYSTEM_GetGameData(w->f0);
    r = GAMESYSTEM_GetFieldMap(w->f0);
    ret = 0;
    if (b == 0 || r == 0) {
        return 0;
    }
    if (w->f168 == 1 || (GAME_DATA_GetIntrudeCount(s2) == 0 && INTRUDE_COMM_GetWorkIfRunning((int)s1) == 0)) {
        GFL_USE_PlaySeDefaultVolume(0x551);
        INTRUDE_SUBDISP_StartButtonBlink((u8 *)w);
        return INTRUDE_SUBDISP_CreateBrightFadeEvent(w->f0, (int)r, c);
    }
    switch (w->f112) {
    case 1:
        GFL_USE_PlaySeDefaultVolume(0x737);
        INTRUDE_SUBDISP_StartTownBlink((u8 *)w);
        ret = INTRUDE_SUBDISP_CreateTownWarpEvent(w->f0, r, w->f110, 0);
        break;
    case 2:
        GFL_USE_PlaySeDefaultVolume(0x737);
        ret = INTRUDE_SUBDISP_CreatePlayerWarpEvent(w->f0, r, INTRUDE_COMM_GetPlayerNetId(s1));
        break;
    }
    if (ret != 0) {
        w->f112 = 0;
        return ret;
    }
    return 0;
}
