/*
 * function: FLD_BTL_INST_TOOL_CommResetEventMain
 * address:  0x02168B20
 * packet:   pkt_ov010_02168B20
 * region:   ov010
 * compiler: dsi/1.1p1
 * flags:    -O4,p
 * lang:     c99
 * isa:      thumb
 * status:   EXACT
 *
 * lever: 02026454 reads the live 02012138 result in r0 in cases 0 and 1.
 * symbols:
 *   GAMESYSTEM_GetFieldMap  0x0201210C  thumb
 *   FIELDMAP_GetSubscreen  0x02188CCC  thumb ov021
 *   GAMESYSTEM_GetGameComm  0x02012138  thumb
 *   GAME_COMM_GetKind  0x02026454  thumb
 *   GAME_COMM_RequestExitNoCallback  0x02026400  thumb
 *   GAMESYSTEM_SetAlwaysNetFlag  0x02012158  thumb
 *   GAMESYSTEM_TryStartAutoComm  0x020121CC  thumb
 *   FIELD_SUBSCREEN_RequestModeWithCallback  0x021A0F7C  thumb ov021
 *   FLD_BTL_INST_TOOL_SetDoneFlag  0x02168B18  thumb ov010
 */

struct Ctx;
extern void *GAMESYSTEM_GetFieldMap(const struct Ctx *);
typedef unsigned int   u32;
typedef unsigned char  u8;
struct Comm;
struct IcaAnime;
extern u32 FIELDMAP_GetSubscreen(u8 *p);
extern unsigned int GAMESYSTEM_GetGameComm(const struct Ctx *);
extern u32 GAME_COMM_GetKind(void *obj);
extern void GAME_COMM_RequestExitNoCallback(struct Comm *p);
extern void GAMESYSTEM_SetAlwaysNetFlag(char *p, unsigned int v);
extern u32 GAMESYSTEM_TryStartAutoComm(struct IcaAnime *p);
extern int FIELD_SUBSCREEN_RequestModeWithCallback(u32 a, u32 b, u32 c, u32 d);
extern void FLD_BTL_INST_TOOL_SetDoneFlag(int *);

typedef enum { ST_0, ST_1, ST_2, ST_3, ST_4, ST_5 } State;

int FLD_BTL_INST_TOOL_CommResetEventMain(int a, int *b, int *c)
{
    int s = c[2];
    int x = FIELDMAP_GetSubscreen((u8 *)((int)GAMESYSTEM_GetFieldMap((const struct Ctx *)s)));
    int y = GAMESYSTEM_GetGameComm((const struct Ctx *)s);
    State t = (State)*b;
    switch (t) {
    case 0:
        if (GAME_COMM_GetKind((void *)y) != 0)
            GAME_COMM_RequestExitNoCallback((struct Comm *)y);
        (*b)++;
        break;
    case 1:
        if (GAME_COMM_GetKind((void *)y) != 0)
            break;
        GAMESYSTEM_SetAlwaysNetFlag((char *)s, 0);
        (*b)++;
        break;
    case 2:
        if (c[1] != 0) {
            GAMESYSTEM_SetAlwaysNetFlag((char *)s, 1);
            GAMESYSTEM_TryStartAutoComm((struct IcaAnime *)s);
        }
        (*b)++;
        break;
    case 3:
        FIELD_SUBSCREEN_RequestModeWithCallback(x, 8, (u32)FLD_BTL_INST_TOOL_SetDoneFlag, (u32)c);
        (*b)++;
        break;
    case 4:
        if (c[0] != 0)
            *b = t + 1;
        break;
    case 5:
        return 1;
    }
    return 0;
}
